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
	attr = ft_get_curve(attr, '{');
	ft_get_attr_in_scope(attr, "origin:", (void *)&(scn->cam->origin), PNT);
	ft_get_attr_in_scope(attr, "alpha:", (void *)&(scn->cam->alpha), DBL);
	ft_get_attr_in_scope(attr, "beta:", (void *)&(scn->cam->beta), DBL);
	ft_get_attr_in_scope(attr, "gamma:", (void *)&(scn->cam->gamma), DBL);
	ft_get_attr_in_scope(attr, "fov:", (void *)&(scn->cam->fov), DBL);
	scn->cam->fov = ft_limitf(FOV_MIN, FOV_MAX, scn->cam->fov);
	scn->cam->fov = ft_torad(scn->cam->fov);
	scn->cam->alpha = ft_torad(scn->cam->alpha);
	scn->cam->beta = ft_torad(scn->cam->beta);
	scn->cam->gamma = ft_torad(scn->cam->gamma);
	return (ft_get_curve(attr, '}'));
}

void		ft_get_camera_refr(t_scene *scn)
{

}
