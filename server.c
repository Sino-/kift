#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define __BUFF_SIZE 256

int echoline(int fd, char *str); //My write function

int main(int argc, char **argv)
{
	int		socket_fd;
	int		port_num;
	int		connection_fd;
	int		client_addr_len;
	int		res;
	char	buffer[__BUFF_SIZE];
	struct	sockaddr_in		server_address;
	struct	sockaddr_in		client_address;

    if (argc < 2)								//check args
		 return (echoline(2, "No port provided.\n") || 1);
	if (argc > 3)
		 return (echoline(2, "Too many arguments.\n") || 1);
		if (argc == 3) 
		{
			if(strcmp(argv[2], "-D") == 0)	
				daemon(0,1);
			else
				return (echoline(2, "Invalid option\n") || 1);
		}
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);//0=system determines prtocl
	// socket([ipv4 address domain],[socket type], [protocol]
	if(socket_fd < 0)
		return(echoline(2, "Error opening socket\n") || 1);
	bzero((char *) &server_address, sizeof(server_address)); //zero memory
	port_num = atoi(argv[1]);			//Use atoi to get port number
	
	//set struct vars
	server_address.sin_family = AF_INET;//part of serv_addr struct -addr family ip4
	server_address.sin_addr.s_addr = INADDR_ANY; //host ip addr
	server_address.sin_port = htons(port_num); 
		// htons converts to network byte order
	if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
		return (echoline(2, "Error on binding\n") || 1);
	listen(socket_fd, 5);
	echoline(1, "Waiting for connections...");
	//listen ([sock_fd], [num of connections that can be waiting])
	client_addr_len = sizeof(client_address);	
	connection_fd = accept(socket_fd, (struct sockaddr *) &client_address, (socklen_t *) &client_addr_len);
	if (connection_fd < 0)
		return (echoline(2, "Error on accept\n") || 1);

	bzero(buffer, __BUFF_SIZE);		//zero buffer
	res = read(connection_fd, buffer, __BUFF_SIZE - 1);
	if (res < 0)
		return(echoline(2, "Error on socket read\n") || 1);
	if(strcmp(buffer, "ping\n") == 0)
		echoline(connection_fd, "pong pong\n");
	return (0);
}