/*
 * socket.c
 *
 *  Created on: 16 mai 2019
 *      Author: killian
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <inet.h>	//inet_addr
#include <errno.h>
#include <string.h>
#include "connection.h"



int lets_connect(const char *addr, int port)
{
	int socket_desc;
	struct sockaddr_in server;

	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
		printf("code d'erreur (n°%d) -%s\n", errno, strerror(errno));
	}
	server.sin_addr.s_addr = inet_addr(addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("connect error\n");
		return 1;
	}

	printf("Connected\n");
	close(socket_desc);

	return 0;
}

