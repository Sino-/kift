/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_netflix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:30:26 by cweather          #+#    #+#             */
/*   Updated: 2017/11/30 15:33:18 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char				*watch_netflix(void)
{
	system("open https://netflix.com/");
	say("Another sad netflix and chill with your computer");
	return ("Another sad netflix and chill with your computer");
}
