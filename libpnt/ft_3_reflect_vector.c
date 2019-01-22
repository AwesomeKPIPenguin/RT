/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_reflect_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:43:26 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 11:43:47 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpnt.h"

t_point3		ft_3_reflect_vector
	(t_point3 origin, t_point3 coll, t_point3 norm)
{
	t_point3		oc;

	oc = ft_3_vectornew(origin, coll);
	return (ft_3_unitvectornew(coll, ft_3_add_vector(origin, ft_3_vector_scale(
		ft_3_vectornew(origin, ft_3_add_vector(coll, ft_3_vector_scale(norm,
			(ft_3_vector_len(oc) * -ft_3_vector_cos(oc, norm))))), 2.0))));
}
