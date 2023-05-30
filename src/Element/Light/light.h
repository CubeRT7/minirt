/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 08:06:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../common.h"

typedef struct s_light
{
	struct s_coordinate	viewport;
	float				radio;
	struct s_rgb		rgb;
}	t_light;

extern int	parse_light(t_list **head, char **argv);
extern void	clear_light(void *param);

#endif 
