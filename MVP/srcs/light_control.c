/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <cweather@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:17:32 by cweather          #+#    #+#             */
/*   Updated: 2017/11/30 02:00:37 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

static char	*dim_lights(void)
{
	return ("osascript -e \'tell application \"System Events\" \
	\nkey code 145\n	end tell\'\n");
}

static char	*brighten_lights(void)
{
	return ("osascript -e \'tell application \"System Events\" \
	\nkey code 144\n	end tell\'\n");
}

static char	*invert_lights(void)
{
	return ("osascript -e \'tell application \"System Events\" \
	\nkey code 28 using {control down, option down, command down} \
	\nend tell\'");
}

char		*light_control(char *opt)
{
	char	*light_str;
	int		repeat;

	repeat = 15;
	light_str = NULL;
	if (ft_strcmp(opt, "DOWN") == 0 || ft_strcmp(opt, "OFF") == 0)
		light_str = dim_lights();
	if (ft_strcmp(opt, "UP") == 0 || ft_strcmp(opt, "ON") == 0)
		light_str = brighten_lights();
	if (ft_strcmp(opt, "NEGATIVE") == 0)
		light_str = invert_lights();
	if (ft_strcmp(opt, "ON") == 0 || ft_strcmp(opt, "OFF") == 0)
		while (repeat--)
			system(light_str);
	system(light_str);
	light_str = ft_strdup("Fine, but why cant you accept me as I already am?");
	say(light_str);
	return (light_str);
}
