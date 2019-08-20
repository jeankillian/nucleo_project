/*
 * mysocket_server.c
 *
 *  Created on: 23 mai 2019
 *      Author: killian
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <inet.h>	//inet_addr
#include <errno.h>
#include <mysocket_server.h>
#include <string.h>

int lets_set_server(int port)
{
	struct sockaddr_in server;
	int socket;
	int ret;

	socket = socket(AF_INET , SOCK_STREAM , 0);
	if (socket == -1)
	{
		printf("Could not create socket! code d'erreur (n°%d) -%s\n", errno, strerror(errno));
	}
	else
	{
		printf("socket server created\n");

		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_family = AF_INET;
		server.sin_port = htons(port);

		//Connect to remote server
		ret = bind(socket , (struct sockaddr *)&server , sizeof(server));
		if (ret < 0)
		{
			printf("bind error! code d'erreur (n°%d) -%s\n", errno, strerror(errno));
			close(socket);
			socket = -1;
		}
		else
		{
			printf("binded (server)\n");
		}
		listen(socket, 3);
		printf("listening (server)\n");
	}
	return socket;
}
