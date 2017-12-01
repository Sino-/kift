/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_news.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:07:02 by cweather          #+#    #+#             */
/*   Updated: 2017/11/30 18:40:16 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char			*check_news(void)
{
	system("open https://news.google.com/");
	say("Here are todays top stories");
	return ("Here are todays top stories");
}
