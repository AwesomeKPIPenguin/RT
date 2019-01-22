/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:17:57 by domelche          #+#    #+#             */
/*   Updated: 2018/08/23 13:25:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera	*ft_cameranew(void)
{
	t_camera	*cam;

	cam = ft_smemalloc(sizeof(t_camera), "ft_cameranew");
	cam->origin = ft_3_pointnew(-500.0, 0.0, 0.0);
	cam->fov = ft_torad(100.0);
	return (cam);
}

char		*ft_parse_camera(char *attr, t_scene *scn)
{
	char	*ptr;

	attr = ft_get_curve(attr, '{');
	if ((ptr = ft_search_attr(attr, "origin:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(scn->cam->origin), ptr, PNT);
	if ((ptr = ft_search_attr(attr, "alpha:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(scn->cam->alpha), ptr, DBL);
	if ((ptr = ft_search_attr(attr, "beta:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(scn->cam->beta), ptr, DBL);
	if ((ptr = ft_search_attr(attr, "gamma:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(scn->cam->gamma), ptr, DBL);
	if ((ptr = ft_search_attr(attr, "fov:", FTSA_IN_SCOPE)))
		ft_read_attr((void *)&(scn->cam->fov), ptr, DBL);
	scn->cam->fov = ft_limitf(FOV_MIN, FOV_MAX, scn->cam->fov);
	scn->cam->fov = ft_torad(scn->cam->fov);
	scn->cam->alpha = ft_torad(scn->cam->alpha);
	scn->cam->beta = ft_torad(scn->cam->beta);
	scn->cam->gamma = ft_torad(scn->cam->gamma);
	return (ft_get_curve(attr, '}'));
}
