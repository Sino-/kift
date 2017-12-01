/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <cweather@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:10:34 by cweather          #+#    #+#             */
/*   Updated: 2017/11/29 21:35:25 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*search_web(char *input)
{
	int				i;
	char			*str;

	i = 32;
	if (input)
	{
		str = ft_strjoin("open https://google.com/search?q=", input);
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			if ((str[i] == ' ') && (i > 5))
				str[i] = '+';
			i++;
		}
		if ((ft_strcmp(input, "Google") == 0) || \
				(ft_strcmp(input, "google") == 0))
			system("open https://google.com/");
		else
			system(str);
		say("This is what I found:");
		return ("This is what I found:");
	}
	return ("");
}

char	*check_event(char *input)
{
	time_t			rawtime;
	struct tm		*timeinfo;
	char			*time_string;
	char			*tmp;

	time_string = ft_strdup("The time is ");
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	tmp = ft_strjoin(time_string, ft_itoa(timeinfo->tm_hour));
	free(time_string);
	time_string = ft_strjoin(tmp, ":");
	free(tmp);
	tmp = ft_strjoin(time_string, ft_itoa(timeinfo->tm_min));
	free(time_string);
	time_string = tmp;
	free(tmp);
	if (ft_strcmp(input, "Time") == 0)
	{
		say(time_string);
		return (time_string);
	}
	else
		return (search_web(input));
}
