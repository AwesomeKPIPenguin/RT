/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_turn_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:44:07 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 11:44:30 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpnt.h"

t_point3		ft_3_turn_vector(t_point3 proj, t_point3 norm, double angle)
{
	return (ft_3_add_vector(
			ft_3_vector_scale(proj, sin(angle)),
			ft_3_vector_scale(norm, cos(angle))));
}
