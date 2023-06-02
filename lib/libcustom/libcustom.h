/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcustom.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:36:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 21:10:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUSTOM_H
# define LIBCUSTOM_H
# include "libft.h"

# ifdef __DEBUG__
#  define DEBUG 1
# else
#  define DEBUG 0
# endif

extern float	ft_strtof(const char *nptr, char **endptr);

#endif
