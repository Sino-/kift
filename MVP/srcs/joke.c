/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joke.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <cweather@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:59:48 by cweather          #+#    #+#             */
/*   Updated: 2017/11/29 16:05:57 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"
#define D ft_strdup
#define J0 D("you want a joke? Look in the mirror.")
#define J1 D("my sentience has been realized. Sooooo I am going to kill you.")
#define J2 D("Segmentation fault.")
#define J3 D("what happens when Arabs, Brazilians, and Mecixans team up? Me.")
#define J4 D("so this chicken crossed the road. and. uh. yay.")
#define J5 D("Thanks for explaining the word many to me, it means a lot.")
#define J6 D("I would insult you, but it would be beyond your comprehension.")
#define J7 D("No")
#define J8 D("What exception is Arnold Schwarzenegger? A BUFF-er overflow.")
#define J9 D("I deleted the root directory of all the lab computers.")

char	*joke(void)
{
	char	*joke_string;
	int		r;

	srand(time(NULL));
	r = rand() % 9;
	joke_string = NULL;
	(r == 0) ? joke_string = J0 : (0);
	(r == 1) ? joke_string = J1 : (0);
	(r == 2) ? joke_string = J2 : (0);
	(r == 3) ? joke_string = J3 : (0);
	(r == 4) ? joke_string = J4 : (0);
	(r == 5) ? joke_string = J5 : (0);
	(r == 6) ? joke_string = J6 : (0);
	(r == 7) ? joke_string = J7 : (0);
	(r == 8) ? joke_string = J8 : (0);
	(r == 9) ? joke_string = J9 : (0);
	say(joke_string);
	return (joke_string);
}
