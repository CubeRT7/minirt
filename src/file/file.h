/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:18:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 14:01:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <fcntl.h>
# include "../Element/AmbientLight/ambient_light.h"
# include "../Element/Camera/camera.h"
# include "../Element/Light/light.h"
# include "../Element/Plane/plane.h"
# include "../Element/Sphere/sphere.h"
# include "../Element/Cylinder/cylinder.h"

struct s_rt_file
{
	t_list	*objs;
	t_list	*lights;
	t_list	*camera;
	t_list	*ambient_light;
};

extern int	import_file(struct s_rt_file *rt, int argc, char **argv);
extern void	clean_rt(struct s_rt_file *rt);

#endif
