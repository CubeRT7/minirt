/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:26:16 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:26:38 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "material/lambertian/lambertian.h"
#include "material/metal/metal.h"
#include "material/phong/phong.h"

t_func	scatter(enum e_material type)
{
	static int	(*functions[MAX_MATERIAL_TYPE])() = {
	[PHONG] = phong_scatter,
	[METAL] = metal_scatter,
	[LAMBERTIAN] = lambertian_scatter};

	return (functions[type]);
}
