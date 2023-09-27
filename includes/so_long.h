/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:23:31 by dfinn             #+#    #+#             */
/*   Updated: 2023/09/27 21:34:08 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/mlx/mlx.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2 
# define CLOSE 53  

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct{
	int x;
	int y;
}	t_vector;

typedef	struct s_player
{
	int	x;
	int	y;
	int	moves;	
	int	items;
}	t_player;

typedef struct s_window{
	void	*reference;
	t_vector	size;
}	t_window;

typedef	struct {
	void	*reference;
	void 	*pointer;
	t_vector	size;
	char		*pixel;
	int			bit_per_pixel;
	int			line_size;
	int			endian;
	
}	t_img;


typedef struct s_mlx
{
	void	*ptr;
	void	*mlx;
	char	**map;
	t_img	img;
	t_player	player;
}	t_mlx;

typedef struct {
	t_data		data;
	t_window	window;
	t_vector	sprite_pos;
	t_img		sprite;
	void		*mlx_ptr;
}	t_program;

int			ft_check_ber(char *file, char *str);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			on_keypress(int i, t_data *data);
static int	count_lines(char *file);

#endif