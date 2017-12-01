#include "../kift.h"

void		values_init(t_mlx *env)
{
	if (!(env->mlx = mlx_init()))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INITIALIZE MLX");
		exit(0);
	}
	else if (!(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "KIFT")))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INITIALIZE WINDOW");
		exit(0);
	}
	else if (!(env->img_ptr = mlx_new_image(env->mlx, WIN_X, WIN_Y)))
	{
		ft_putendl("\nSTART UP ERROR: FAILD TO INIZIALIZE IMAGE");
		exit(0);
	}
	else if (!(env->img = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->size_line, &env->endian)))
	{
		ft_putendl("\nSTART UP ERROR: FAILED TO INIZIALIZE IMG PTR");
		exit(0);
	}
    clear_window(env);
    start_window(env);
}

void		clear_window(t_mlx *env)
{
	ft_memset(env->img, 0, (WIN_Y * WIN_X * 4));
}

void        start_window(t_mlx *env)
{
	int bg_x;
	int bg_y;
	int fc_x;
	int fc_y;

	bg_x = 800;
	bg_y = 600;
	fc_x = 377;
	fc_y = 419;
	env->back_ground = mlx_xpm_file_to_image(env->mlx, "../assets/background.xpm", &bg_x, &bg_y);
	env->face = mlx_xpm_file_to_image(env->mlx, "../assets/gaetan_face.xpm", &fc_x, &fc_y);
	image_draw(env);
}

void		display_command(t_mlx *env, char *command, char *response)
{
	mlx_string_put(env->mlx, env->win, 60, 150, 0xffffff, command);			//If I have time, make a proper window with this where it can cross multiple lines and the command is
	mlx_string_put(env->mlx, env->win, 60, 180, 0xffffff, response);			//properly placed below it with the same spacing look below.
}

void		image_draw(t_mlx *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->back_ground, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->face, 0, 0);
}

void		mlx_events(t_mlx *env)
{
	mlx_do_key_autorepeaton(env->mlx);
	mlx_hook(env->win, 1, 0, &key_hook, &env);
	//mlx_hook(env.win, 2, 0, &key_hook, &env);
	mlx_hook(env->win, 17, 0, &exit_hook, &env);
}

int		key_hook(int keycode, t_mlx *env)
{
	int n;
	char buffer[4096];
	if (keycode == KEY_ESCAPE)
		exit_hook(env);
	if (keycode == KEY_SPACE)
	{
		bzero(buffer, strlen(buffer));
		system("rec -c 1 -L -e signed -b 16 -r 16000 src.wav silence 1 0.05 3% 1 2.0 3% &> /dev/null");
		system("nc 10.112.7.12 7000 < src.wav");
		n = read(env->sockfd, buffer, 4096);
		command_logs(buffer);
		display_command(env, buffer, "NO SOUP FOR YOU");
	}
	return (0);
}

int		exit_hook(t_mlx *env)
{
	int n;
	char end;

	end = 'x';
	(void)env;
	n = write(env->sockfd, &end, 1);
	if (n < 0)
		error("Error on writing.");
	close(env->sockfd);
	exit(0);
}
