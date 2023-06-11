/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:27:50 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:27:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAL_H
# define METAL_H
# include "material/material.h"

extern int	metal_scatter(t_ray *ray, t_hit *hit, t_color *color);

#endif
