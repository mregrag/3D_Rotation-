/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:23:47 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 17:32:38 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.h"
#include "../include/define.h"
#include "../include/cube.h"
#include <math.h>

static void project_point(t_point3d p, int *x, int *y)
{
    float z = p.z + 5.0f;
    *x = (int)((p.x * 500) / z) + WINDOW_WIDTH / 2;
    *y = (int)((p.y * 500) / z) + WINDOW_HIEGHT / 2;
}

static t_point3d rotate_point(t_point3d p, t_angle *angle)
{
    t_point3d result = p;
    float temp_x, temp_y, temp_z;

    temp_y = result.y * cos(angle->x) - result.z * sin(angle->x);
    temp_z = result.y * sin(angle->x) + result.z * cos(angle->x);
    result.y = temp_y;
    result.z = temp_z;

    temp_x = result.x * cos(angle->y) + result.z * sin(angle->y);
    temp_z = -result.x * sin(angle->y) + result.z * cos(angle->y);
    result.x = temp_x;
    result.z = temp_z;

    temp_x = result.x * cos(angle->z) - result.y * sin(angle->z);
    temp_y = result.x * sin(angle->z) + result.y * cos(angle->z);
    result.x = temp_x;
    result.y = temp_y;

    return (result);
}

void draw_cube(t_cube *cube)
{
    int x[8];
    int y[8];
    t_point3d rotated[8];


    for (int i = 0; i < 8; i++)
    {
	rotated[i] = rotate_point(cube->points[i], cube->angle);
	project_point(rotated[i], &x[i], &y[i]);
    }

    draw_line(cube->img, x[0], y[0], x[1], y[1]);
    draw_line(cube->img, x[1], y[1], x[2], y[2]);
    draw_line(cube->img, x[2], y[2], x[3], y[3]);
    draw_line(cube->img, x[3], y[3], x[0], y[0]);

    draw_line(cube->img, x[4], y[4], x[5], y[5]);
    draw_line(cube->img, x[5], y[5], x[6], y[6]);
    draw_line(cube->img, x[6], y[6], x[7], y[7]);
    draw_line(cube->img, x[7], y[7], x[4], y[4]);

    draw_line(cube->img, x[0], y[0], x[4], y[4]);
    draw_line(cube->img, x[1], y[1], x[5], y[5]);
    draw_line(cube->img, x[2], y[2], x[6], y[6]);
    draw_line(cube->img, x[3], y[3], x[7], y[7]);

    cube->angle->x += 0.02;
    cube->angle->y += 0.03;
    cube->angle->z += 0.01;
}

