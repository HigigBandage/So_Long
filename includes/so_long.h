/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:23:31 by dfinn             #+#    #+#             */
/*   Updated: 2023/09/24 16:41:37 by dfinn            ###   ########.fr       */
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

int		ft_check_ber(char *file, char *str);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int	on_keypress(int i, t_data *data);

#endif