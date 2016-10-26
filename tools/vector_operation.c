/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:42:47 by fdel-car          #+#    #+#             */
/*   Updated: 2016/10/21 15:42:49 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	normalize_vec(t_vect u)
{
	t_vect	w;
	float	length;

	length = sqrt((u.x * u.x) + (u.y * u.y) + (u.z * u.z));
	w.x = u.x / length;
	w.y = u.y / length;
	w.z = u.z / length;
	return (w);
}

t_vect	cross_pr(t_vect u, t_vect v)
{
	t_vect w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.z * v.x) - (u.x * v.z);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}

t_vect	add_vec(t_vect u, t_vect v)
{
	t_vect w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vect	multiple_vec(t_vect u, float value)
{
	t_vect w;

	w.x = u.x * value;
	w.y = u.y * value;
	w.z = u.z * value;
	return (w);
}

t_vect	sub_vec(t_vect u, t_vect v)
{
	t_vect w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}