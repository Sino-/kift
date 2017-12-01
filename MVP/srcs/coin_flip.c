/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_flip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:07:48 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/28 20:22:34 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*coin_flip(void)
{
	char	*coin_string;
	int		coin;

	srand(time(NULL));
	coin = rand();
	if (coin % 13 == 0)
	{
		coin = rand();
		say("sorry, I dont know my own strength.");
		sleep(1);
		say("I flipped the coin too high");
		sleep(2);
		say("ah, it finally came back down");
	}
	if (coin % 2)
		coin_string = ft_strdup("Heads wins this time");
	else
		coin_string = ft_strdup("Tails wins this time");
	say(coin_string);
	return (coin_string);
}
