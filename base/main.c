#include <string.h>
#include <stdio.h>
#include <event2/event.h>
#include <event2/util.h>

int main()
{
    
	printf("******Redis Api Start******\n");
	printf("hello world!\n");
	struct event_base *base = NULL;
   	base = event_base_new();
        if (NULL == base  )
	{
		printf("event base new failed!\n");
		return 0;
	}

	printf("******Redis Api End******\n");
	return 0;
}                                                                                                                                  
