/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:26:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 17:26:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/define.h"
#include "../include/data.h"

static int ft_init_window(t_cube *cube)
{
    if (!(cube->window = mlx_init(WINDOW_WIDTH, WINDOW_HIEGHT, "CUBE3D", false)))
	return (0);

    return (1);
}

static int ft_init_img(t_cube *cube)
{
    if (!(cube->img = mlx_new_image(cube->window, WINDOW_WIDTH, WINDOW_HIEGHT)))
	return (0);

    if(!(mlx_image_to_window(cube->window, cube->img, 0, 0)))
	return (0);

    return (1);
}


int ft_init_cube(t_cube *cube)
{
    cube->angle = malloc(sizeof(*cube->angle));
    if (!cube->angle)
	return (0);

    cube->points[0] = (t_point3d){-1, -1, -1};
    cube->points[1] = (t_point3d){1, -1, -1};
    cube->points[2] = (t_point3d){1, 1, -1};
    cube->points[3] = (t_point3d){-1, 1, -1};
    cube->points[4] = (t_point3d){-1, -1, 1};
    cube->points[5] = (t_point3d){1, -1, 1};
    cube->points[6] = (t_point3d){1, 1, 1};
    cube->points[7] = (t_point3d){-1, 1, 1};

    cube->angle->x = 0;
    cube->angle->y = 0;
    cube->angle->z = 0;

    if (!ft_init_window(cube))
	return (0);
    if (!ft_init_img(cube))
	return (0);

    return (1);
}
