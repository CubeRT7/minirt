/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 21:01:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../common.h"

typedef struct s_light
{
	struct s_vector4	coordinate;
	struct s_vector4	asix;
	struct s_rgb		rgb;
	float				ratio;
}	t_light;

extern void	debug_light(void *param);
extern int	parse_light(t_list **head, char **argv);

#endif 
