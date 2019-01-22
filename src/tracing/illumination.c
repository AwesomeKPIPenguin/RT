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

int				ft_iscollide
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
			ft_3_pointcmp(ft_3_unitvectornew(coll, origin),
				ft_3_unitvectornew(light, coll), 1e-6))
			return (1);
		o_node = o_node->next;
	}
	return (0);
}

static void		ft_check_coll(t_parg *parg, t_coll *coll, t_light *l)
{
	double			cos[2];
	double			cl_len;

	cos[0] = ft_3_vector_cos(coll->norm,
		ft_3_vectornew(coll->coll_pnt, l->origin));
	if (cos[0] >= 0 && !ft_iscollide(parg->e->scn, coll->coll_pnt,
		ft_3_unitvectornew(coll->coll_pnt, l->origin), l->origin))
	{
		
	}
}

void			ft_illuminate(t_parg *parg, t_coll *coll)
{
	t_list			*node;
	t_light			*l;

	coll->illum = 0.0;
	coll->phong = 127.0;
	node = parg->e->scn->lights;
	while (node)
	{
		l = (t_light *)(node->content);
		ft_check_coll(parg, coll, l);
		node = node->next;
	}
	coll->illum = ft_limitf(0.0, 1.0, coll->illum);
}
