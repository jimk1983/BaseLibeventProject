// WinServerProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <fcntl.h>
#include <errno.h>

#include <event2/queue.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libevent.lib")

struct client {
    int fd;
    struct bufferevent *buf_ev;
    //  TAILQ_ENTRY(client) entries;
};
struct event_base *evbase = NULL;

void buffered_on_read(struct bufferevent *bev, void *arg)
{
    struct client *client = (struct client *)arg;
    //    struct client *this_client;
    unsigned char data[8192] = { 0 };
    size_t n;


    /* Read 8k at a time and send it to all connected clients. */
    for (;;) {
        n = bufferevent_read(bev, data, sizeof(data));
        if (n <= 0) {
            /* Done. */
            printf("bufferevent read error=%zu\n", n);
            break;
        }

        /* Send data to all connected clients except for the
         * client that sent the data. */

         // TAILQ_FOREACH(client, &client_tailq_head, entries) {
              //if (client != this_client) {
        bufferevent_write(client->buf_ev, data, n);
        printf("bufferevent write data=%s\n", data);
        //}
    //}
    }
}

void on_accept(int fd, short ev, void *arg)
{
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    struct client *clientinfo;

    client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        printf("accept failed!errno=%d\n", errno);
        return;
    }

    /* Set the client socket to non-blocking mode. */
    //if (setnonblock(client_fd) < 0)
   //     warn("failed to set client socket non-blocking");
    
    evutil_make_socket_nonblocking(client_fd);

    /* We've accepted a new client, create a client object. */
    clientinfo = (struct client*)calloc(1, sizeof(struct client));
    if (clientinfo == NULL)
        printf("malloc failed\n");
    clientinfo->fd = client_fd;

    clientinfo->buf_ev = bufferevent_socket_new(evbase, client_fd, 0);
    bufferevent_setcb(clientinfo->buf_ev, buffered_on_read, NULL, NULL, clientinfo);

    /* We have to enable it before our callbacks will be
    * called. */
    bufferevent_enable(clientinfo->buf_ev, EV_READ);

    /* Add the new client to the tailq. */
   // TAILQ_INSERT_TAIL(&client_tailq_head, client, entries);

    printf("Accepted connection from sin_addr=%s\n", inet_ntoa(client_addr.sin_addr));
}

int main(int argc, char **argv)
{
    int listen_fd;
    struct sockaddr_in listen_addr;
    struct event ev_accept;
    int reuseaddr_on;

    WORD      wVersionRequested;
    WSADATA wsaData;
    INT32       err;

    /*请求2.2版本的winsock库*/
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (0 != err)
    {
        return -1;
    }

    /* Initialize libevent. */
    evbase = event_base_new();

    /* Initialize the tailq. */
    //TAILQ_INIT(&client_tailq_head);

    /* Create our listening socket. */
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
        printf("socket failed, Error=%d\n", GetLastError());

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8899);

    reuseaddr_on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuseaddr_on, sizeof(int));

    if (bind(listen_fd, (struct sockaddr *)&listen_addr,
        sizeof(listen_addr)) < 0)
        printf("bind failed, Error=%d\n", GetLastError());

    if (listen(listen_fd, 5) < 0)
        printf("listen failed, Error=%d\n", GetLastError());


    reuseaddr_on = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuseaddr_on, sizeof(reuseaddr_on));

    /* Set the socket to non-blocking, this is essential in event
     * based programming with libevent. */
     //if (setnonblock(listen_fd) < 0)
     //err(1, "failed to set server socket to non-blocking");

     /* We now have a listening socket, we create a read event to
     * be notified when a client connects. */
    event_assign(&ev_accept, evbase, listen_fd, EV_READ | EV_PERSIST, on_accept, NULL);
    event_add(&ev_accept, NULL);

    /* Start the event loop. */
    event_base_dispatch(evbase);

    return 0;
}