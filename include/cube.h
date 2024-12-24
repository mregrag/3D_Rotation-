/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:22:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 17:33:19 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE_H
# define CUBE_H

#include "../include/data.h"

int ft_init_cube(t_cube *cube);
int32_t ft_color(int32_t r, int32_t g, int32_t b, int32_t a);
void clear_screen(mlx_image_t *img, int32_t color);
void draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2);
void draw_cube(t_cube *cube);

#endif
