/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:03:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../common.h"

typedef struct s_cylinder
{
	struct s_vector4	coordinate;
	struct s_vector4	axis;
	struct s_rgb		rgb;
	float				diameter;
	float				height;
}	t_cylinder;

extern void	debug_cylinder(void *param);
extern int	parse_cylinder(void *param, char **argv);

#endif 
