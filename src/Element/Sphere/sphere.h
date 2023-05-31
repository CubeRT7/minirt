/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 20:21:47 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../common.h"

typedef struct s_sphere
{
	struct s_vector4	coordinate;
	struct s_vector4	axis;
	struct s_rgb		rgb;
	float				diameter;
}	t_sphere;

extern int	parse_sphere(t_list **head, char **argv);
extern void	clear_sphere(void *param);

#endif 
