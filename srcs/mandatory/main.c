/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:22:41 by dfinn             #+#    #+#             */
/*   Updated: 2023/09/27 21:35:51 by dfinn            ###   ########.fr       */
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

t_img   ft_new_sprite(void *mlx, char *path)
{
    t_img   img;
    img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
    img.pixel = mlx_get_data_addr(&img.reference, &img.bit_per_pixel, &img.line_size, &img.endian);
    return (img);
}

int main()
{
    t_program   program;
    t_mlx       mlx;
    t_data      data;
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
    program.sprite = ft_new_sprite(program.mlx_ptr, "block.xpm");
    program.sprite_pos.x = 0;
    program.sprite_pos.y = 0;
    mlx_put_image_to_window(program.mlx_ptr, program.window.reference, program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
    
    mlx_hook(data.win_ptr, 2, 0, handle_key_press, &data);
    //mlx_hook(data.win_ptr, 3, 0, handle_key_release, &data);
    mlx_loop(data.mlx_ptr);
    //map_init(mlx.map, &mlx);

    return 0;
}


