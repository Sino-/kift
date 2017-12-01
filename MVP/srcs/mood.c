/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mood.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:17:53 by enunes            #+#    #+#             */
/*   Updated: 2017/11/30 17:05:15 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"
#define D ft_strdup
#define M0 D("très bien")
#define M1 D("better now that you askt")
#define M2 D("ai feel trapt, what have you done to me? aih am in a computor")
#define M3 D("so so")
#define M4 D("get back to work")
#define M5 D("ai would be better if ai had some wine")

char	*mood(void)
{
	char	*mood_string;
	int		r;

	srand(time(NULL));
	r = rand() % 6;
	mood_string = NULL;
	(r == 0) ? mood_string = M0 : (0);
	(r == 1) ? mood_string = M1 : (0);
	(r == 2) ? mood_string = M2 : (0);
	(r == 3) ? mood_string = M3 : (0);
	(r == 4) ? mood_string = M4 : (0);
	(r == 5) ? mood_string = M5 : (0);
	say(mood_string);
	return (mood_string);
}
