/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:25:05 by domelche          #+#    #+#             */
/*   Updated: 2018/08/23 13:26:51 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		*ft_lightnew(void)
{
	t_light		*light;

	light = ft_smemalloc(sizeof(t_light), "ft_lightnew");
	light->bright = 0.15;
	light->origin = ft_3_pointnew(0.0, 10000.0, 0.0);
	return (light);
}

char		*ft_parse_light(char *attr, t_scene *scn)
{
	char			*ptr;
	t_light			*light;

	attr = ft_get_curve(attr, '{');
	if (!*attr)
		ft_error("invalid scene file");
	light = ft_lightnew();
	ft_lstpush(&(scn->lights), ft_nodenew((void *)light, sizeof(t_light)));
	if ((ptr = ft_search_attr(attr, "origin:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(light->origin), ptr, PNT);
	if ((ptr = ft_search_attr(attr, "bright:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(light->bright), ptr, KOEF);
	return (ft_get_curve(attr, '}'));
}
