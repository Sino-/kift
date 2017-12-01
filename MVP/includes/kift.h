/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:41:40 by enunes            #+#    #+#             */
/*   Updated: 2017/12/01 02:14:40 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_H
# define KIFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <sys/stat.h>
# include <termios.h>
# include <ctype.h>
# include <time.h>
# include <pocketsphinx.h>
# include "libft.h"

# define PORT 1337
# define HOST "10.112.7.12"

char		getch(void);
void		error(const char *msg);
const char	*call_to_sphinx(void);
int			command_logs(char *command);

char		*set_timer(char *time);
char		*execute_command(int cmd, int opt);
void		say(char *phrase);
char		*play_music(void);
char		*send_email(void);
char		*roll_dice(void);
char		*coin_flip(void);
char		*light_control(char *opt);
char		*joke(void);
char		*parse(char *input);
char		*search_web(char *input);
char		*check_event(char *input);
char		*who_are_you(void);
char		*where_are_you(void);
char		*command_error(void);
char		*mood(void);
void		goodbye(void);
char		*watch_netflix(void);
char		*check_news(void);
void		mlx_putstr(char *phrase);

#endif
