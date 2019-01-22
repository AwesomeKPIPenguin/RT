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

t_color		ft_apply_a(t_color color, double bright)
{
	double	k;

	bright = ft_limitf(0.0, 255.0, bright);
	k = bright - 127.0;
	color.argb[2] += (double)((k > 0) ? 255 - color.argb[2] : color.argb[2]) /
		128.0 * k;
	color.argb[1] += (double)((k > 0) ? 255 - color.argb[1] : color.argb[1]) /
		128.0 * k;
	color.argb[0] += (double)((k > 0) ? 255 - color.argb[0] : color.argb[0]) /
		128.0 * k;
	return (color);
}
