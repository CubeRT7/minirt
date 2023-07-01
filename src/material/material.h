/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:30:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:30:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include "Element/common.h"

enum e_material
{
	PHONG,
	METAL,
	LAMBERTIAN,
	MAX_MATERIAL_TYPE
};

t_func	scatter(enum e_material material_type);

#endif
