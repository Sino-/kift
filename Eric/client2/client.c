/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:21:14 by enunes            #+#    #+#             */
/*   Updated: 2017/11/29 18:57:59 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kift.h"

int		main(void)
{
	int sockfd, portno, n;
	char buffer[1028];
	struct sockaddr_in serv_addr;
	struct hostent *server;

	portno = PORT;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("Error opening socket");

	server = gethostbyname(HOST);

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

	serv_addr.sin_port = htons(portno);

	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Connection failed");

	char check;
	while(1)
	{

		char ch;

		char check;
		while (1)
		{
			//Wait for user input using an implemented version of getch(), that waits for a key press
			puts("Press SPACE for next command\nPress X to exit");
			ch = getch();
			if (ch == ' ' || ch == 'x' || ch == 'X')
				break ;
		}
		//From the user input, it sends a signal in the form of a character 
		//to the server so it can decide to  which step proceed (either repeat or end service).
		
		//If server should record another command:
		if (ch == ' ')
		{
			check = 'A';
			//sends signal
			n = write(sockfd, &check, 1);
			if (n < 0)
				error("Error on writing.");
		}
		//If server should end, and the client loop as well:
		if (ch == 'x' || ch == 'X')
		{
			check = 'x';
			//sends signal
			n = write(sockfd, &check, 1);
			if (n < 0)
				error("Error on writing.");
			break ;
		}
		bzero(buffer, strlen(buffer));
		puts("Recording...");
		//Records WAV file with Sox setting up proper specs and stopping on silence, also trimming it out
		system("rec -c 1 -L -e signed -b 16 -r 16000 src.wav silence 1 0.05 3% 1 2.0 3% &> /dev/null");

		puts("Done!\n");
		
		//Sends WAV file created to host ip using port 7000 with NetCat
		system("nc 10.112.7.12 7000 < src.wav");
		//here the parsed string should be read (working on it)
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		n = read(sockfd, buffer, 1028);

		//log_add(buff);
		command_logs(buffer);
		puts(buffer);
		
	}

	close(sockfd);
	return(0);
}
