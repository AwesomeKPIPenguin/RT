/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:25:05 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 12:17:52 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		ft_apply_phong(t_color color, double phong, t_color light_color)
{
	color.argb[2] += (t_byte)((255.0 - color.argb[2]) * phong *
		((double)light_color.argb[2] / 255.0));
	color.argb[1] += (t_byte)((255.0 - color.argb[1]) * phong *
		((double)light_color.argb[1] / 255.0));
	color.argb[0] += (t_byte)((255.0 - color.argb[0]) * phong *
		((double)light_color.argb[0] / 255.0));
	return (color);
}
