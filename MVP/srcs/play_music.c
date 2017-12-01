/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:09:37 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/30 17:20:53 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*play_music(void)
{
	char	*music_string;

	music_string = ft_strdup("open https://youtu.be/UNVtM9P-yLM?t=52s");
	system(music_string);
	free(music_string);
	music_string = ft_strdup("Dropping some sick beats for ya");
	say(music_string);
	return (music_string);
}
