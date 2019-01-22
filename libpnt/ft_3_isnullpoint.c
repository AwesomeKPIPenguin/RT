/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_isnullpoint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:21:55 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 11:22:23 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpnt.h"

int			ft_3_isnullpoint(t_point3 point)
{
	return (point.x == DBL_MIN && point.y == DBL_MIN && point.z == DBL_MIN);
}
