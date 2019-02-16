#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <fcntl.h>
#include <errno.h>

#include "TerminalDefine.h"
#include "TerminalStruct.h"

#include <event2/queue.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>


#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libevent.lib")

struct event_base *evbaseclient = NULL;

/*测试客户端: 对应的是AccessGateway*/
/*测试的是循环的登录协议*/
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
    evbaseclient = event_base_new();
    if ( NULL == evbaseclient)
    {
        return -1;
    }

    event_base_free(evbaseclient);

    return 0;
}



