/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:08:59 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/29 15:57:27 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

/*
**	1.	Set an alarm / timer.				-	DONE
**	2.	Turn on / off lights.				-	DONE
**	3.	Send email. 						-	DONE
**	4.	Check events / weather / traffic.	-	DONE
**	5.	Who is connected?					-	DONE
**	6.	Where is (user) connected?			-	DONE
**	7.	Play music.							-	DONE
**	8.	Search the web for (term).			-	DONE
**	9.	Check history.
**	10.	Flip a coin.						-	DONE
**	11.	Roll a die.							-	DONE
**	12.	Tell a joke.						-	DONE
*/

int	main(int argc, char *argv[])
{
	if (argc == 2)
		parse(argv[1]);
	return (0);
}
