/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:11:08 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/30 19:00:10 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"
#define VOICE "say -v Victoria -i -r 190 [[pbas 50]] "

void	say(char *phrase)
{
	char	*syscall_string;

//	mlx_putstr(phrase);
	syscall_string = ft_strjoin(VOICE, phrase);
	system(syscall_string);
	free(syscall_string);
}
