/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:43:34 by cweather          #+#    #+#             */
/*   Updated: 2017/11/28 21:07:46 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <time.h>

int					parse(char *input);
void				set_lights(char *input);
void				search_web(char *input);
void				check_event(char *input);
void				tell_joke(void);
char				*ft_itoa(int n);
int					ft_tolower(int c);

#endif
