/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:29:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 17:40:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "../include/data.h"
#include "../include/define.h"

int32_t ft_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void clear_screen(mlx_image_t *img, int32_t color)
{
    for (uint32_t y = 0; y < img->height; y++)
	for (uint32_t x = 0; x < img->width; x++)
	    mlx_put_pixel(img, x, y, color);
}

void draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = 1;
    if (x1 > x2)
        sx = -1;
    sy = 1;
    if (y1 > y2)
        sy = -1;

    err = dx - dy;

    while (1)
    {
        if (x1 >= 0 && x1 < WINDOW_WIDTH && y1 >= 0 && y1 < WINDOW_HIEGHT)
            mlx_put_pixel(img, x1, y1, ft_color(0, 255, 0, 255));

        if (x1 == x2 && y1 == y2)
            break;

        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

