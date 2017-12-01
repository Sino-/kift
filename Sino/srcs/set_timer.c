/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:18:33 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/29 17:20:17 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"
#define CMP ft_strcmp

static int	time_in_seconds(char *time_str)
{
	char	**time;
	int		seconds;
	int		mult;
	int		curr;

	seconds = 0;
	mult = 1;
	curr = 0;
	time = ft_strsplit(time_str, ' ');
	while (time[curr])
		curr++;
	while (curr--)
	{
		if (CMP(time[curr], "HOURS") == 0 || CMP(time[curr], "HOUR") == 0)
			mult = 3600;
		if (CMP(time[curr], "MINUTES") == 0 || CMP(time[curr], "MINUTE") == 0)
			mult = 60;
		if (CMP(time[curr], "SECONDS") == 0 || CMP(time[curr], "SECOND") == 0)
			mult = 1;
		else
			seconds += ft_atoi(time[curr]) * mult;
	}
	return (seconds);
}

char		*set_timer(char *time)
{
	char	*timer_string;
	char	*tmp;
	int		seconds;

	seconds = time_in_seconds(time);
	tmp = ft_strjoin("sleep ", ft_itoa(seconds));
	timer_string = ft_strjoin(tmp, "&& afplay ./assets/sounds/alarm.mp3 &");
	free(tmp);
	system(timer_string);
	free(timer_string);
	tmp = ft_strjoin("Timer has been set for ", ft_itoa(seconds));
	timer_string = (ft_strjoin(tmp, " seconds"));
	free(tmp);
	say(timer_string);
	while (--seconds > 0)
	{
		sleep(1);
		if (seconds % 30 == 0)
		{
			tmp = ft_strjoin(ft_itoa(seconds), " seconds remaining");
			say(tmp);
			free(tmp);
		}
	}
	return (tmp);
}
