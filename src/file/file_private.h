/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:59:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 14:03:02 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PRIVATE_H
# define FILE_PRIVATE_H
# include "file.h"

struct s_parse_info
{
	const char	*type;
	size_t		size;
	int			(*parse)(void *, char **);
};

extern int	parse_rgb(struct s_rgb *rgb, char *curr);
extern int	parse_vector3(t_vector3 *vector, char *curr, int scope);

extern int	parse_ambient_light(void *param, char **argv);
extern int	parse_camera(void *param, char **argv);
extern int	parse_light(void *param, char **argv);
extern int	parse_sphere(void *param, char **argv);
extern int	parse_plane(void *param, char **argv);
extern int	parse_cylinder(void *param, char **argv);

#endif
