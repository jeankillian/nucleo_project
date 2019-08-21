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
#include <mysocket_client.h>


//la socket sera fermé par l'appelant après utilisation
//return -1 si probleme sinon
//return le socket descriptor si ok

int lets_connect(const char *addr, int port)
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
		printf("socket client created\n");

		server.sin_addr.s_addr = inet_addr(addr);
		server.sin_family = AF_INET;
		server.sin_port = htons(port);

		//Connect to remote server
		ret = connect(socket , (struct sockaddr *)&server , sizeof(server));
		if (ret < 0)
		{
			printf("connect error! code d'erreur (n°%d) -%s\n", errno, strerror(errno));
			close(socket);
			socket = -1;
		}
		else
		{
			printf("Connected\n");
		}
	}
	return socket;
}
