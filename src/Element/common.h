/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/04 23:33:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "libcustom.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

enum e_vector4_type
{
	Vector,
	Coordinate
};

typedef struct s_vector4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector4;

extern int	parse_rgb(struct s_rgb *rgb, char *curr);
extern int	parse_vector3(struct s_vector4 *vector, char *curr, float w);

#endif
