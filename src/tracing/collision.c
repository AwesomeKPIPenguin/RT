/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:21:02 by domelche          #+#    #+#             */
/*   Updated: 2018/08/23 13:25:52 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_point3		ft_get_collision_point
	(t_list *objs, t_object **obj, t_point3 od[2])
{
	t_list		*node;
	t_point3	pnt[2];
	double		dist[2];
	t_object	*o;

	node = objs;
	pnt[0] = ft_3_nullpointnew();
	dist[0] = DBL_MAX;
	while (node)
	{
		o = (t_object *)(node->content);
		if (o->ft_is_reachable(o->fig, od[0], od[1]) &&
			!ft_3_isnullpoint(pnt[1] = o->ft_collide(o->fig, od[0], od[1])) &&
			(dist[1] = ft_3_point_point_dist(od[0], pnt[1])) < dist[0])
		{
			pnt[0] = pnt[1];
			dist[0] = dist[1];
			*obj = o;
		}
		node = node->next;
	}
	return (pnt[0]);
}

t_coll				ft_get_collision
	(t_parg *parg, t_point3 origin, t_point3 direct)
{
	t_coll		coll;
	t_point3	od[2];

	coll.o = NULL;
	od[0] = ft_3_add_vector(origin, direct);
	od[1] = direct;
	if (ft_3_isnullpoint(coll.coll_pnt =
		ft_get_collision_point(parg->e->scn->objs, &(coll.o), od)))
		return (coll);
	coll.norm = coll.o->ft_get_norm(coll.o->fig, coll.coll_pnt);
	if (ft_3_vector_cos(coll.norm, direct) > 0)
		coll.norm = ft_3_vector_scale(coll.norm, -1);
	if (coll.o->spclr)
		coll.spclr_vec = ft_3_reflect_vector(origin, coll.coll_pnt, coll.norm);
	ft_illuminate(parg, &coll);
	return (coll);
}
