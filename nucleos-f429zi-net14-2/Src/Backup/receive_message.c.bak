#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <inet.h>	//inet_addr
#include <errno.h>
#include <mysocket_client.h>
#include <string.h>
#include "receive_message.h"

int received_message(int socket_desc, char *server_reply, int taille_max)
{
	int ret;
	ret = recv(socket_desc, server_reply , taille_max-1 , 0);
	if( ret < 0)
	{
	  printf("recv failed\n");
	}
	else
	{
		server_reply[taille_max - 1] = '\0';
		printf("Data Received: %d --> %s", ret, server_reply);

		for(int i = 0; i < taille_max; i++)
		{
			server_reply[i] = '\0';
		}
	}
	return ret;
}
