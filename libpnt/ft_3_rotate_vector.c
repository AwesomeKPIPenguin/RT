/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_rotate_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:45:49 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 11:46:09 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpnt.h"

t_point3		ft_3_rotate_vector
	(t_point3 vec, double alpha, double beta, double gamma)
{
	t_point3	rotated;
	double		sin_[3];
	double		cos_[3];

	sin_[0] = sin(alpha);
	sin_[1] = sin(beta);
	sin_[2] = sin(gamma);
	cos_[0] = cos(alpha);
	cos_[1] = cos(beta);
	cos_[2] = cos(gamma);
	rotated.x = vec.x * cos_[2] * cos_[1] +
				vec.y * (cos_[2] * sin_[1] * sin_[0] - sin_[2] * cos_[0]) +
				vec.z * (sin_[2] * sin_[0] + cos_[0] * cos_[2] * sin_[1]);
	rotated.y = vec.x * cos_[1] * sin_[2] +
				vec.y * (cos_[0] * cos_[2] + sin_[0] * sin_[1] * sin_[2]) +
				vec.z * (cos_[0] * sin_[1] * sin_[2] - sin_[0] * cos_[2]);
	rotated.z = vec.x * -(sin_[1]) +
				vec.y * sin_[0] * cos_[1] +
				vec.z * cos_[0] * cos_[1];
	return (rotated);
}
