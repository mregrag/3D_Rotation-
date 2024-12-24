/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:23:18 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 17:33:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include <stdlib.h>

void render(void *param)
{
    t_cube *cube;

    cube = param;

    clear_screen(cube->img, ft_color(0, 0, 0, 255));
    draw_cube(cube);
}


int main(void)
{
    t_cube cube;

    ft_init_cube(&cube);
    mlx_loop_hook(cube.window, &render, &cube);
    mlx_loop(cube.window);

    return(0);
}
