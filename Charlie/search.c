/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:10:34 by cweather          #+#    #+#             */
/*   Updated: 2017/11/28 21:05:37 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void				search_web(char *input)
{
	int				i;
	char			str[1000];

	i = 0;
	strcpy(str, "open https://google.com/search?q=");
	strcat(str, input);
	while (str[i])
	{
		if ((str[i] == ' ') && (i > 5))
			str[i] = '+';
		i++;
	}
	if ((strcmp(input, "Google") == 0) || (strcmp(input, "google") == 0))
		system("open https://google.com/");
	else
		system(str);
	system("say this is what I found");
}

void				check_event(char *input)
{
	time_t			rawtime;
	struct tm		*timeinfo;
	char			*date;
	char			store_time[1000];
	char			*tmp;

	strcpy(store_time, "say the time is ");
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	date = asctime(timeinfo);
	tmp = ft_itoa(timeinfo->tm_hour);
	strcat(store_time, tmp);
	tmp = ft_itoa(timeinfo->tm_min);
	strcat(store_time, " ");
	strcat(store_time, tmp);
	if (strcmp(input, "Time") == 0)
		system(store_time);
	else
		search_web(input);
}
