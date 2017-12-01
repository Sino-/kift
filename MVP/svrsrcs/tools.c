/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:37:32 by enunes            #+#    #+#             */
/*   Updated: 2017/11/29 20:31:37 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

static struct termios old;
static struct termios new;

void	inittermios(int echo)
{
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~ICANON;
	new.c_lflag &= echo ? ECHO : ~ECHO;
	tcsetattr(0, TCSANOW, &new);
}

void	resettermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

char	getch(void)
{
	char ch;

	inittermios(0);
	ch = getchar();
	resettermios();
	return (ch);
}

void	error(const char *msg)
{
	perror(msg);
	exit(1);
}
