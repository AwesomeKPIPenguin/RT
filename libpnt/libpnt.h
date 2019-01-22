/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpnt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:53:06 by domelche          #+#    #+#             */
/*   Updated: 2018/09/19 10:53:13 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPNT_H

# define LIBPNT_H

# include <math.h>
# include <float.h>

typedef struct			s_point3
{
	double				x;
	double				y;
	double				z;
}						t_point3;

/*
**	point
*/

t_point3				ft_3_pointnew(double x, double y, double z);
t_point3				ft_3_nullpointnew(void);
int						ft_3_isnullpoint(t_point3 point);
double					ft_3_point_point_dist(t_point3 pnt_0, t_point3 pnt_1);
double					ft_3_line_point_dist
							(t_point3 origin, t_point3 direct, t_point3 point);
double					ft_3_plane_point_dist
							(t_point3 origin, t_point3 norm, t_point3 point);
double					ft_3_line_line_dist
							(t_point3 o1, t_point3 d1,
							t_point3 o2, t_point3 d2);
t_point3				ft_3_line_line_inter
							(t_point3 o1, t_point3 d1,
							t_point3 o2, t_point3 d2);
t_point3				ft_3_line_plane_inter
							(t_point3 pln_o, t_point3 pln_norm,
							t_point3 ln_o, t_point3 ln_d);
t_point3				ft_3_line_point_proj
							(t_point3 origin, t_point3 direct, t_point3 point);
int						ft_3_pointcmp
							(t_point3 pnt_0, t_point3 pnt_1, double prec);

/*
**	vector
*/

t_point3				ft_3_vectornew(t_point3 origin, t_point3 direct);
t_point3				ft_3_unitvectornew(t_point3 origin, t_point3 direct);
t_point3				ft_3_tounitvector(t_point3 vec);
t_point3				ft_3_add_vector(t_point3 vec_1, t_point3 vec_2);
t_point3				ft_3_vector_scale(t_point3 vec, double k);
double					ft_3_vector_dot(t_point3 vec_1, t_point3 vec_2);
t_point3				ft_3_vector_cross(t_point3 vec_1, t_point3 vec_2);
double					ft_3_vector_len(t_point3 vec);
double					ft_3_vector_cos(t_point3 vec_1, t_point3 vec_2);
t_point3				ft_3_reflect_vector
							(t_point3 origin, t_point3 coll, t_point3 norm);
t_point3				ft_3_turn_vector
							(t_point3 proj, t_point3 norm, double angle);
t_point3				ft_3_project_vector(t_point3 norm, t_point3 vec);
t_point3				ft_3_rotate_vector
							(t_point3 vec, double alpha,
							double beta, double gamma);
t_point3				ft_3_turn_vector_near
							(t_point3 vec, t_point3 axis, double angle);

#endif
