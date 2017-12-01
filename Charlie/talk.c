/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:59:48 by cweather          #+#    #+#             */
/*   Updated: 2017/11/28 19:29:27 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void				tell_joke(void)
{
	char			*joke_0;
	char			*joke_1;
	char			*joke_2;
	char			*joke_3;
	int				r;

	srand(time(NULL));
	joke_0 = "say joke 0";
	joke_1 = "say joke 1";
	joke_2 = "say joke 2";
	joke_3 = "say joke 3";
	r = rand() % 4;
	(r == 0) ? system(joke_0) : (0);
	(r == 1) ? system(joke_1) : (0);
	(r == 2) ? system(joke_2) : (0);
	(r == 3) ? system(joke_3) : (0);
}
