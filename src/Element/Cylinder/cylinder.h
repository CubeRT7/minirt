/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 08:06:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../common.h"

typedef struct s_cylinder
{
	struct s_coordinate	center;
	struct s_coordinate	vector;
	float				diameter;
	float				height;
	struct s_rgb		rgb;
}	t_cylinder;

extern int	parse_cylinder(t_list **head, char **argv);
extern void	clear_cylinder(void *param);

#endif 
