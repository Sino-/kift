/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_email.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:11:30 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/28 20:31:13 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*send_email(void)
{
	char	*email_string;

	email_string = ft_strdup("echo \" Looks like you made something useful...\
			\"| mail -s \"Someone is using your K.I.F.T.\"\
			sino@42.us.org nonfat.cow@gmail.com eocnunes@gmail.com");
	system(email_string);
	free(email_string);
	email_string = ft_strdup("I let the overlords know that their app is being\
			used by such a wonderful corrector");
	say(email_string);
	return (email_string);
}
