/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <cweather@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:31:49 by cweather          #+#    #+#             */
/*   Updated: 2017/11/29 18:04:01 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*parse(char *input)
{
	char		*response;

	response = NULL;
	if (ft_strncmp(input, "SEARCH THE WEB", 14) == 0 && ft_strlen(input) > 18)
		response = search_web(ft_strsub(input, 19, ft_strlen(input) - 19));
	if (ft_strncmp(input, "TURN THE LIGHTS", 15) == 0 && ft_strlen(input) > 15)
		response = light_control(ft_strsub(input, 16, ft_strlen(input) - 16));
	if (ft_strcmp(input, "TELL ME A JOKE") == 0)
		response = joke();
	if (ft_strcmp(input, "WHAT TIME IS IT") == 0)
		response = check_event("Time");
	if (ft_strcmp(input, "SEND AN EMAIL") == 0)
		response = send_email();
	if (ft_strcmp(input, "FLIP A COIN") == 0)
		response = coin_flip();
	if (ft_strcmp(input, "ROLL THE DICE") == 0)
		response = roll_dice();
	if (ft_strncmp(input, "SET A TIMER FOR", 15) == 0 && ft_strlen(input) > 15)
		response = set_timer(ft_strsub(input, 16, ft_strlen(input) - 16));
	if (ft_strcmp(input, "WHO IS CONNECTED") == 0)
		response = who_are_you();
	if (ft_strcmp(input, "WHERE ARE THEY CONNECTED") == 0)
		response = where_are_you();
	return (response);
}
