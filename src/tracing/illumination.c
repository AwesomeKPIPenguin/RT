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

void			ft_illuminate(t_parg *parg, t_coll *coll)
{
	t_list		*node;
	t_light		*l;
	t_point3	ldir;

	coll->illum = 0.0;
	coll->phong = 127.0;
	node = parg->e->scn->lights;
	while (node)
	{
		l = (t_light *)(node->content);
		ldir = (l->type == POINT) ? ft_3_vectornew(coll->coll_pnt, l->origin) :
			ft_3_unitvectornew(coll->coll_pnt,
				ft_3_vector_scale(l->direct, -1.0));

		node = node->next;
	}
	coll->illum = ft_limitf(0.0, 1.0, coll->illum);
}
