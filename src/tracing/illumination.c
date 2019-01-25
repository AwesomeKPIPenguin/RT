/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:25:05 by domelche          #+#    #+#             */
/*   Updated: 2018/08/23 13:26:31 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	by now, the searching ray would stop if any object will be found
**	(specularity and transparency will be taken into account latter)
*/

int		ft_iscollide
			(t_scene *scn, t_point3 origin, t_point3 direct, t_light *l)
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
			(l->type != POINT ||
				ft_3_pointcmp(
					ft_3_unitvectornew(coll, origin),
					ft_3_unitvectornew(l->origin, coll),
					1e-6
				)))
			return (1);
		o_node = o_node->next;
	}
	return (0);
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

void	ft_illuminate_with(t_parg *parg, t_coll *coll, t_light *l)
{
	double		norm_light_cos;
	t_point3	ldir;

	ldir = (l->type == POINT) ? ft_3_vectornew(coll->coll_pnt, l->origin) :
		ft_3_unitvectornew(coll->coll_pnt,
			ft_3_vector_scale(l->direct, -1.0));
	norm_light_cos = ft_3_vector_cos(coll->norm, ldir);
	if (norm_light_cos >= 0 &&
		!ft_iscollide(parg->e->scn, coll->coll_pnt, ldir, l))
		ft_affect_illumination(coll, l, ldir, norm_light_cos);
}

void	ft_illuminate(t_parg *parg, t_coll *coll)
{
	t_list		*node;
	t_light		*l;

	coll->illum = 0.0;
	coll->phong = 127.0;
	node = parg->e->scn->lights;
	while (node)
	{
		l = (t_light *)(node->content);
		ft_illuminate_with(parg, coll, l);
		node = node->next;
	}
	coll->illum = ft_limitf(0.0, 1.0, coll->illum);
}
