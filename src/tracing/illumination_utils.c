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

int		ft_iscollide
			(t_scene *scn, t_point3 origin, t_point3 direct, t_point3 light)
{
	t_list		*o_node;
	t_object	*o;
	t_point3	coll;

	origin = ft_3_add_vector(origin, direct);
	o_node = scn->objs;
	while (o_node)
	{
		o = (t_object *)(o_node->content);
		coll = o->ft_collide(o->fig, origin, direct);
		if (!ft_3_isnullpoint(coll) &&
			(ft_3_pointcmp(
				ft_3_unitvectornew(coll, origin),
				ft_3_unitvectornew(light, coll),
				1e-6
			) || ft_3_isnullpoint(light)))
			return (1);
		o_node = o_node->next;
	}
	return (0);
}

void	ft_illuminate_direct(t_parg *parg, t_coll *coll, t_light *l)
{
	double		cos[2];
	double		cl_len;
	t_point3	ldir;

	ldir =
	cos[0] = ft_3_vector_cos(coll->norm, ldir);
	if (cos[0] >= 0 &&
		!ft_iscollide(parg->e->scn, coll->coll_pnt, ldir, ft_3_nullpointnew()))
	{
		cos[1] = ft_3_vector_cos(coll->spclr_vec,
			ft_3_vectornew(coll->coll_pnt, l->origin));
		cl_len = ft_3_point_point_dist(coll->coll_pnt, l->origin);
		coll->illum += (!cl_len) ? l->bright :
			l->bright * cos[0] / (pow(cl_len / BRIGHT_UNIT, 2));
		if (cos[1] > 0.9)
			coll->phong = MAX(coll->phong, pow(cos[1] - 0.9, 2) *
				coll->o->phong * 100.0 * 255.0);
	}

}

void	ft_affect_illumination
			(t_coll *coll, t_light *l, t_point3 ldir, double norm_light_cos)
{
	double		phong_cos;
	double		cl_len;

	phong_cos = ft_3_vector_cos(coll->spclr_vec, ldir);
	cl_len = (l->type == POINT) ?
		ft_3_point_point_dist(coll->coll_pnt, l->origin) : 1.0;
	coll->illum += (!cl_len) ? l->bright :
		l->bright * norm_light_cos / (pow(cl_len / BRIGHT_UNIT, 2));
	if (phong_cos > 0.9)
		coll->phong = MAX(coll->phong, pow(phong_cos - 0.9, 2) *
			coll->o->phong * 100.0 * 255.0);
}
