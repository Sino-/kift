/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:31:49 by cweather          #+#    #+#             */
/*   Updated: 2017/11/28 21:11:20 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				parse(char *input)
{
	char		arg[1000];
	int			j;
	int			i;

	i = 19;
	j = 0;
	if (strncmp(input, "SEARCH THE WEB FOR", 18) == 0)
	{
		while (input[i])
		{
			arg[j] = ft_tolower(input[i]);
			j++;
			i++;
		}
	arg[j] = '\0';
	search_web(arg);
	}
	if (strcmp(input, "TURN THE LIGHTS UP") == 0)
		set_lights("UP");
	else if (strcmp(input, "TURN THE LIGHTS DOWN") == 0)
		set_lights("DOWN");
	else if (strcmp(input, "TURN THE LIGHTS ON") == 0)
		set_lights("ON");
	else if (strcmp(input, "TURN THE LIGHTS OFF") == 0)
		set_lights("OFF");
	else if (strcmp(input, "TURN THE LIGHTS NEGATIVE") == 0)
		set_lights("NEGATIVE");
	else if (strcmp(input, "TELL ME A JOKE") == 0)
		tell_joke();
	else if (strcmp(input, "WHAT TIME IS IT") == 0)
		check_event("Time");
	return (0);
}
