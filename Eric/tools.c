/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:37:32 by enunes            #+#    #+#             */
/*   Updated: 2017/11/27 19:31:52 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
	 tcgetattr(0, &old); /* grab old terminal i/o settings */
	 new = old; /* make new settings same as old settings */
	 new.c_lflag &= ~ICANON; /* disable buffered i/o */
	 new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	 tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

void resetTermios(void)
{
	  tcsetattr(0, TCSANOW, &old);
}

char getch(void)
{
	char ch;
	initTermios(0);
	ch = getchar();
	resetTermios();
	return ch;
}

void	error(const char *msg)
{
	perror(msg);
	exit(1);
}
