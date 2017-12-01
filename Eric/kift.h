/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:41:40 by enunes            #+#    #+#             */
/*   Updated: 2017/11/28 22:17:30 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_H
# define KIFT_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/stat.h>
#include <termios.h>
#include <ctype.h>
#include <time.h>
#include <pocketsphinx.h>
#include "libft/libft.h"
#include "minilibx/mlx.h"

#define PORT 1337
#define HOST "10.112.7.12"
#define WIN_X 800
#define WIN_Y 600
#define KEY_ESCAPE 53
#define KEY_SPACE 49


typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
    void        *img;
    void        *img_ptr;
    void        *back_ground;
    void        *face;
    int         bpp;
    int         size_line;
    int         endian;
    int         sockfd;
}               t_mlx;

char 		getch(void);
void		error(const char *msg);
const char	*call_to_sphinx(void);
int			command_logs(char *command);

int		exit_hook(t_mlx *env);
int		key_hook(int keycode, t_mlx *env);
void		mlx_events(t_mlx *env);
void		image_draw(t_mlx *env);
void		display_command(t_mlx *env, char *command, char *response);
void        start_window(t_mlx *env);
void		clear_window(t_mlx *env);
void		values_init(t_mlx *env);




#endif
