#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <inet.h>	//inet_addr
#include <errno.h>
#include <mysocket_client.h>
#include <string.h>
#include "send_message.h"


//return -1 si il y a eu un problème sinon
//return la longueur du message

int message_sent(int socket_desc)
{
	char *message;
	int ret;

	message = "Je suis un message\n";
	ret = send(socket_desc , message , strlen(message) , 0);

	if(ret == -1)
	{
		printf("Send failed! code d'erreur (n°%d) -%s\n", errno, strerror(errno));
		ret = -1;
	}
	else
	{
		printf("Data Send: %d --> %s", ret, message);
	}
	return ret;
}

