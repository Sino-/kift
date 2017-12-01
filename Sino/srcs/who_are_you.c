/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_are_you.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:35:20 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/29 18:35:29 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*who_are_you(void)
{
	char	*uid;
	char	*uid_string;

	uid = getenv("USER");
	uid_string = ft_strjoin("Looks like some degenerate that goes by ", uid);
	say(uid_string);
	return (uid_string);
}
