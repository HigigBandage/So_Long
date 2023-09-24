/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:22:41 by dfinn             #+#    #+#             */
/*   Updated: 2023/09/24 17:19:08 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

int j_is_pressed = 0;

void close_window(void *param)
{
    if (j_is_pressed == 1)
    {
        mlx_destroy_window(((t_data *)param)->mlx_ptr, "Hi");
        exit(0);
    }
}

int handle_key_press(int keycode, void *param)
{
    if (keycode == 38)
    {
        j_is_pressed = 1;
        close_window(param);
    }
    return 0;
}

/*int handle_key_release(int keycode, void *param)
{
	(void)param;
    if (keycode == 108)
        j_is_pressed = 0;
    return 0;
}*/

int main()
{
    t_data data;
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 500, "Hi"); //
    if (!data.win_ptr)
    {
        if (data.mlx_ptr != NULL)
            free(data.mlx_ptr);
        return 1;
    }

    mlx_hook(data.win_ptr, 2, 0, handle_key_press, &data);
    //mlx_hook(data.win_ptr, 3, 0, handle_key_release, &data);

    mlx_loop(data.mlx_ptr);

    return 0;
}


