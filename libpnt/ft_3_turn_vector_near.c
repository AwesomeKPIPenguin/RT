/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_turn_vector_near.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:46:26 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 11:46:57 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpnt.h"

t_point3		ft_3_turn_vector_near(t_point3 vec, t_point3 axis, double angle)
{
	t_point3	rotated;
	double		sin_a;
	double		cos_a;
	double		va;

	sin_a = sin(angle);
	cos_a = cos(angle);
	va = 1 - cos_a;
	rotated.x = vec.x * (axis.x * axis.x * va + cos_a) +
				vec.y * (axis.x * axis.y * va - axis.z * sin_a) +
				vec.z * (axis.x * axis.z * va + axis.y * sin_a);
	rotated.y = vec.x * (axis.x * axis.y * va + axis.z * sin_a) +
				vec.y * (axis.y * axis.y * va + cos_a) +
				vec.z * (axis.y * axis.z * va - axis.x * sin_a);
	rotated.z = vec.x * (axis.x * axis.z * va - axis.y * sin_a) +
				vec.y * (axis.y * axis.z * va + axis.x * sin_a) +
				vec.z * (axis.z * axis.z * va + cos_a);
	return (rotated);
}
