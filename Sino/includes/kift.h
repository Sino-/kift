/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:20:08 by yolabi            #+#    #+#             */
/*   Updated: 2017/11/28 20:20:47 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_H
# define KIFT_H
# include "libft.h"
# include <time.h>

char	*set_timer(char *time);
char	*execute_command(int cmd, int opt);
void	say(char *phrase);
char	*play_music(void);
char	*send_email(void);
char	*roll_dice(void);
char	*coin_flip(void);
char	*light_control(char *opt);
char	*joke(void);
char	*parse(char *input);
char	*search_web(char *input);
char	*check_event(char *input);
char	*who_are_you(void);
char	*where_are_you(void);

#endif
