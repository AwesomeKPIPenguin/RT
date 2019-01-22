/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:20:16 by domelche          #+#    #+#             */
/*   Updated: 2018/09/21 13:20:28 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_set_coll_pnts_null(t_point3 *pnt1, t_point3 *pnt2)
{
	*pnt1 = ft_3_nullpointnew();
	*pnt2 = *pnt1;
}

void		ft_cone_init(t_object *obj, t_cone *cone)
{
	obj->fig = cone;
	cone->bv_dist = ft_3_point_point_dist(cone->base, cone->vert);
	cone->base = ft_3_add_vector(cone->base, obj->translate);
	cone->vert = ft_3_add_vector(cone->vert, obj->translate);
	cone->bv = ft_3_rotate_vector(ft_3_unitvectornew(cone->base, cone->vert),
		obj->rotate.x, obj->rotate.y, obj->rotate.z);
	cone->vert = ft_3_add_vector(cone->base,
		ft_3_vector_scale(cone->bv, cone->bv_dist));
	cone->side_norm_angle = acos((cone->bv_dist * sin(atan((cone->base_rad -
		cone->vert_rad) / cone->bv_dist))) / (cone->base_rad - cone->vert_rad));
	cone->main_vert = ft_3_add_vector(cone->base, ft_3_vector_scale(cone->bv,
		cone->base_rad * cone->bv_dist / (cone->base_rad - cone->vert_rad)));
}
