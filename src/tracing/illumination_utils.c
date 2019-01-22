/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:29:01 by domelche          #+#    #+#             */
/*   Updated: 2019/01/22 17:29:10 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_illuminate_point(t_coll *coll, t_light *l, double cos_0)
{
	double	cl_len;
	double	cos_1;

	cos_1 = ft_3_vector_cos(coll->spclr_vec,
							 ft_3_vectornew(coll->coll_pnt, l->origin));
	cl_len = ft_3_point_point_dist(coll->coll_pnt, l->origin);
	coll->illum += (!cl_len) ? l->bright :
		l->bright * cos_0 / (pow(cl_len / BRIGHT_UNIT, 2));
	if (cos_1 > 0.9)
		coll->phong = MAX(coll->phong, pow(cos_1 - 0.9, 2) *
			coll->o->phong * 100.0 * 255.0);
}

void	ft_illuminate_direct()
{

}
