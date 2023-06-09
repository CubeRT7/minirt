/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:18:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 23:56:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <fcntl.h>
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"
# include "Element/Light/light.h"
# include "Element/Plane/plane.h"
# include "Element/Sphere/sphere.h"
# include "Element/Cylinder/cylinder.h"

struct s_parse_info
{
	const char	*type;
	size_t		size;
	int			(*parse)(void *, char **);
};

extern int	import_file(t_list **result, int argc, char **argv);

#endif
