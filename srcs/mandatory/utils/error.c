/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:09:16 by dfinn             #+#    #+#             */
/*   Updated: 2023/09/24 14:14:08 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error (char *str)
{
	ft_printf("%s", str);
	return 0;
}

int ft_check_ber(char *file, char *str) 
{
    int len_file = ft_strlen(file);
    int len_str = ft_strlen(str);

    if (len_file < len_str) 
        return 0;
    if (ft_strcmp(file + len_file - len_str, str) == 0) 
	{
        ft_printf("succeed\n");
        return 1;
    } 
	else 
	{
        ft_printf("failed\n");
        return 0;
    }
}