/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:34:23 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 06:00:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include "Element/common.h"
# include "simulate.h"

void	hook_key_event(void *param);
void	hook_draw(void *param);
void	hook_draw_setting(void *param);
void	hook_resize_event(int width, int height, void *param);
void	hook_close_event(void *param);

void	rotate_camera(void *param);
void	hook_mouse_event(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
#endif
