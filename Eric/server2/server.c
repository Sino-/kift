/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:56:18 by enunes            #+#    #+#             */
/*   Updated: 2017/11/29 18:58:14 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kift.h"

void	loop(int newsockfd)
{
	int		n;
	char	check;
	char	cmd[1028];

	while (1)
	{
		n = read(newsockfd, &check, 1);
		(n < 0) ? error("Error on writing") : (0);
		if (check == 'x')
			break ;
		if (check == 'A')
		{
			system("nc -l 7000 > src.wav");
			strcpy(cmd, (char *)call_to_sphinx());
			n = write(newsockfd, cmd, strlen(cmd));
			(n < 0) ? error("Error on writing") : (0);
		}

	}
}

int		main(void)
{
	int					sockfd;
	int					newsockfd;
	socklen_t			clilen;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR on binding");
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	if (newsockfd < 0)
		error("ERROR on accept");
	loop(newsockfd);
	close(sockfd);
	return (0);
}
