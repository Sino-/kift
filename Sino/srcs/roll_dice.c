/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_dice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:10:23 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/28 20:21:34 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*roll_dice(void)
{
	char	*dice_string;
	int		dice;

	srand(time(NULL));
	dice = (rand() % 6) + 1;
	dice_string = ft_strdup("Feeling lucky? Okay, rolling the dice...");
	say(dice_string);
	free(dice_string);
	sleep(1);
	dice_string = ft_strjoin("You rolled a ", ft_itoa(dice));
	say(dice_string);
	return (dice_string);
}
