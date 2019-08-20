/*
 * server_accept.c
 *
 *  Created on: 23 mai 2019
 *      Author: killian
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <inet.h>	//inet_addr
#include <errno.h>
#include <server_accept.h>
#include <string.h>

int server_accept(int socket)
{
	char *message;
	struct sockaddr_in client;
	int c, new_socket;

	c = sizeof(struct sockaddr_in);
	while((new_socket = accept(socket, (struct sockaddr *)&client, (socklen_t*)&c))>=0)
	{
		printf("accepted (server)\n");
		message = "COUCOU TOI !\n";
		write(new_socket, message, strlen(message));
//		ret = read(new_socket, message_r, 100);
//		if(ret >= 0)
//		{
//			printf("%s\n", message_r);
//		}
	}
	close(socket);

//	ret = accept(socket, (struct sockaddr *)&client, (socklen_t*)&c);
//	if (ret < 0)
//	{
//		printf("accept error! code d'erreur (n°%d) -%s\n", errno, strerror(errno));
//	}
//	else
//	{
//		printf("accepted (server)\n");
//		message = "COUCOU TOI !";
//		write(socket, message, strlen(message));
//		new_socket = 1;
//	}
	return new_socket;
}
