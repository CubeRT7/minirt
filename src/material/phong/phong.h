/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:27:09 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:27:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H
# include "material/material.h"

extern int	phong_scatter(t_ray *ray, t_hit *hit, t_color *color);

#endif
