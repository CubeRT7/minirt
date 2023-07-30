/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpmap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:22:34 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:23:10 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUMPMAP_BONUS_H
# define BUMPMAP_BONUS_H
# define BUMPMAP_ARR_SIZE 10
# define BITMAP 0
# define NORMALMAP 1
# include "libvector.h"
# include "stdlib.h"

typedef struct s_img
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		sizeline;
}	t_img;

typedef union u_bump_map
{
	struct
	{
		t_img	bit;
		t_img	normal;
	};
	struct
	{
		t_img	map[2];
	};
}	t_bump_map;

extern int			create_bumpmap(int idx, void *mlx, char *bit, char *normal);
extern void			clear_bumpmaps(void);
extern t_vector3	get_bumpmap_pixel(int idx, t_vector3 uv, int type);

#endif
