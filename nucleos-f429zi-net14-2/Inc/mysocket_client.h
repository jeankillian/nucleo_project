/*
 * connection.h
 *
 *  Created on: 17 mai 2019
 *      Author: killian
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#define ADRESSE_IP "10.1.0.123"
#define PORTS 5001
#define TAILLE_MAX_MSG 100
int lets_connect(const char *addr, int port);
//int created_socket(int socket_desc);


#endif /* CONNECTION_H_ */
