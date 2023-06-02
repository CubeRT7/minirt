/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 21:02:03 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../common.h"

typedef struct s_plane
{
	struct s_vector4	coordinate;
	struct s_vector4	axis;
	struct s_rgb		rgb;
}	t_plane;

extern void	debug_plane(void *param);
extern int	parse_plane(t_list **head, char **argv);

#endif 
