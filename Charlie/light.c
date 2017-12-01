/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:17:32 by cweather          #+#    #+#             */
/*   Updated: 2017/11/28 18:45:54 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void				set_lights(char *input)
{
	if (strcmp(input, "ON") == 0)
		system("sh ./scripts/light_on.script");
	else if (strcmp(input, "OFF") == 0)
		system("sh ./scripts/light_off.script");
	else if (strcmp(input, "UP") == 0)
		system("sh ./scripts/light_up.script");
	else if (strcmp(input, "DOWN") == 0)
		system("sh ./scripts/light_down.script");
	else if (strcmp(input, "NEGATIVE") == 0)
		system("sh ./scripts/light_negative.script");
}
