/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:25:05 by domelche          #+#    #+#             */
/*   Updated: 2018/08/23 13:26:05 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone		*ft_conenew(void)
{
	t_cone	*cone;

	cone = ft_smemalloc(sizeof(t_cone), "ft_conenew");
	cone->base = ft_3_pointnew(0.0, 0.0, -200.0);
	cone->base_rad = 100;
	cone->vert = ft_3_pointnew(0.0, 0.0, 200.0);
	cone->vert_rad = 100;
	return (cone);
}

char		*ft_parse_cone(char *attr, t_scene *scn)
{
	t_object	*obj;
	t_cone		*cone;

	obj = ft_parse_object(attr);
	obj->ft_collide = ft_collide_cone;
	obj->ft_is_reachable = ft_is_reachable_cone;
	obj->ft_get_norm = ft_get_norm_cone;
	cone = ft_conenew();
	attr = ft_get_curve(attr, '{');
	ft_get_attr_in_scope(attr, "base:", (void *)(&(cone->base)), PNT);
	ft_get_attr_in_scope(attr, "base_rad:", (void *)(&(cone->base_rad)), DBL);
	ft_get_attr_in_scope(attr, "vert:", (void *)(&(cone->vert)), PNT);
	ft_get_attr_in_scope(attr, "vert_rad:", (void *)(&(cone->vert_rad)), DBL);
	if (cone->base_rad < 0 && cone->vert_rad < 0)
	{
		cone->base_rad *= -1.0;
		cone->vert_rad *= -1.0;
	}
	ft_cone_init(obj, cone);
	ft_lstpush(&(scn->objs), ft_nodenew((void *)obj, sizeof(obj)));
	return (ft_get_curve(attr, '}'));
}

int			ft_is_reachable_cone(void *fig, t_point3 origin, t_point3 direct)
{
	(void)fig;
	(void)origin;
	(void)direct;
	return (1);
}

t_point3	ft_collide_cone(void *fig, t_point3 origin, t_point3 direct)
{
	t_cone		*cone;
	t_point3	pnt[4];

	cone = (t_cone *)fig;
	pnt[0] = origin;
	pnt[1] = direct;
	ft_get_coll_pnts(cone, &pnt, cone->base_rad == cone->vert_rad);
	ft_is_between_planes(&pnt, cone->base, cone->vert);
	ft_collide_cone_planes(cone, origin, direct, &pnt);
	return (ft_get_closest(origin, pnt));
}

t_point3	ft_get_norm_cone(void *fig, t_point3 coll)
{
	t_cone		*cone;
	t_point3	proj;
	double		sign;

	cone = (t_cone *)fig;
	proj = ft_3_line_point_proj(cone->base, cone->bv, coll);
	if (ft_3_pointcmp(proj, cone->base, 1e-3))
		return (ft_3_vector_scale(cone->bv, -1));
	if (ft_3_pointcmp(proj, cone->vert, 1e-3))
		return (cone->bv);
	if (cone->base_rad == cone->vert_rad)
		return (ft_3_unitvectornew(proj, coll));
	sign = (cone->base_rad > cone->vert_rad) ? 1.0 : -1.0;
	sign *= (ft_3_vector_cos(ft_3_vectornew(cone->main_vert, cone->base),
		ft_3_vectornew(cone->main_vert, proj)) < 0) ? -1.0 : 1.0;
	return (ft_3_tounitvector(ft_3_turn_vector(cone->bv,
		ft_3_unitvectornew(proj, coll), sign * cone->side_norm_angle)));
}
