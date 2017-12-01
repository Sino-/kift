/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <cweather@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:31:49 by cweather          #+#    #+#             */
/*   Updated: 2017/11/30 18:06:43 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

static char			*parse_more(char *input)
{
	char *response;

	response = NULL;
	if (ft_strncmp(input, "PLAY ME SOME MUSIC", 18) == 0)
		response = play_music();
	if (ft_strncmp(input, "WHO IS CONNECTED", 16) == 0)
		response = who_are_you();
	if (ft_strncmp(input, "WHERE ARE THEY CONNECTED", 24) == 0)
		response = where_are_you();
	if (ft_strncmp(input, "HOW ARE YOU DOING TODAY", 23) == 0)
		response = mood();
	if (ft_strncmp(input, "LETS WATCH NETFLIX", 18) == 0)
		response = watch_netflix();
	if (ft_strncmp(input, "CHECK THE NEWS", 14) == 0)
		response = check_news();
	return (response);
}

char				*parse(char *input)
{
	char		*response;

	response = NULL;
	response = parse_more(input);
	if (ft_strncmp(input, "SEARCH THE WEB", 14) == 0 && ft_strlen(input) > 18)
		response = search_web(ft_strsub(input, 19, ft_strlen(input) - 19));
	if (ft_strncmp(input, "TURN THE LIGHTS", 15) == 0 && ft_strlen(input) > 15)
		response = light_control(ft_strsub(input, 16, ft_strlen(input) - 16));
	if (ft_strncmp(input, "TELL ME A JOKE", 14) == 0)
		response = joke();
	if (ft_strncmp(input, "WHAT TIME IS IT", 15) == 0)
		response = check_event("Time");
	if (ft_strncmp(input, "SEND AN EMAIL", 13) == 0)
		response = send_email();
	if (ft_strncmp(input, "FLIP A COIN", 11) == 0)
		response = coin_flip();
	if (ft_strncmp(input, "ROLL THE DICE", 13) == 0)
		response = roll_dice();
	if (ft_strncmp(input, "SET A TIMER FOR", 15) == 0 && ft_strlen(input) > 15)
		response = set_timer(ft_strsub(input, 16, ft_strlen(input) - 16));
	(!response) ? response = command_error() : (0);
	return (response);
}
