/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 20:21:44 by yonshin          ###   ########.fr       */
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
	float				radio;
}	t_light;

extern int	parse_light(t_list **head, char **argv);
extern void	clear_light(void *param);

#endif 
