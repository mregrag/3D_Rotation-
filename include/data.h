/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:23:04 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/24 16:43:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_H
# define DATA_H

# include <MLX42.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_point3d
{
    float	x;
    float	y;
    float	z;

}	t_point3d;

typedef struct s_angle
{
    float	x;
    float	y;
    float	z;
}	t_angle;

typedef struct s_cube
{
    t_point3d points[8];
    mlx_image_t	*img;
    mlx_t	*window;
    t_angle	*angle;

}	t_cube;

#endif
