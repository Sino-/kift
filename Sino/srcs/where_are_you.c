/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_are_you.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:35:20 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/29 18:35:29 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*where_are_you(void)
{
	char	host[100];
	char	*host_string;
	gethostname(host, 100);
	host_string = ft_strjoin("They seem to be connected from ", host);
	say(host_string);
	return (host_string);
}
