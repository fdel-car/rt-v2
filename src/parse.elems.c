/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:44:04 by fdel-car          #+#    #+#             */
/*   Updated: 2016/10/24 17:44:08 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mater	load_material(char **t)
{
	t_mater	new;
	int		n;

	n = 1;
	new = init_mater();
	if (ft_sii(t[n], "{"))
		while (t[++n] && !ft_sii(t[n], "{"))
		{
			if (ft_sii(t[n], "brillance:"))
				new.shiny = ft_atof(get_after(t[n], "brillance:"));
			if (ft_sii(t[n], "reflection:"))
				new.int_refl = ft_atof(get_after(t[n], "reflection:"));
			if (ft_sii(t[n], "transparence:"))
				new.int_trans = ft_atof(get_after(t[n], "transparence:"));
			if (ft_sii(t[n], "color:"))
				new.color = read_color(get_after(t[n], "color:"));
			if (ft_sii(t[n], "texture:"))
				new.text = ft_strdup(get_after(t[n], "texture:"));
		}
	return (new);
}

void	set_func(t_obj *o)
{
	if (o->type == SPHERE)
		o->func = &intersect_sphere;
	if (o->type == PLANE)
		o->func = &intersect_plane;
}

void	load_object(char **t)
{
	t_obj	*new;
	int		n;

	new = malloc(sizeof(t_obj));
	new->next = NULL;
	new->name = ft_strdup(*t);
	if ((n = 1) && ft_sii(t[n], "{"))
		while (t[++n] && !ft_sii(t[n], "{"))
		{
			if (ft_sii(t[n], "pos:"))
				new->pos = read_vec(get_after(t[n], "pos:"));
			if (ft_sii(t[n], "dir:"))
				new->dir = read_vec(get_after(t[n], "dir:"));
			if (ft_sii(t[n], "rayon:"))
				new->rayon = ft_atof(get_after(t[n], "rayon:"));
			if (ft_sii(t[n], "type:"))
				new->type = get_type(get_after(t[n], "type:"));
			if (ft_sii(t[n], "normal:"))
				new->norm = vec_norm(read_vec(get_after(t[n], "normal:")));
			if (ft_sii(t[n], "materiel"))
				new->mater = load_material(&(t[n]));
		}
	set_func(new);
	push_obj(new);
}

void	load_light(char **t)
{
	t_light	*new;
	int		n;

	n = 1;
	new = malloc(sizeof(t_light));
	new->next = NULL;
	new->name = ft_strdup(*t);
	if (ft_sii(t[n], "{"))
		while (t[++n] && !ft_sii(t[n], "{"))
		{
			if (ft_sii(t[n], "pos:"))
				new->pos = read_vec(get_after(t[n], "pos:"));
			if (ft_sii(t[n], "rayon:"))
				new->rayon = ft_atof(get_after(t[n], "rayon:"));
			if (ft_sii(t[n], "type:"))
				new->type = ft_strdup(get_after(t[n], "type:"));
			if (ft_sii(t[n], "color:"))
				new->color = read_color(get_after(t[n], "color:"));
			if (ft_sii(t[n], "intensity:"))
				new->intensity = ft_atof(get_after(t[n], "intensity:"));
			if (ft_sii(t[n], "blur:"))
				new->blur = ft_atoi(get_after(t[n], "blur:"));
		}
	push_lgt(new);
}

void	load_elems(char **t, unsigned char type)
{
	int	n;

	n = 0;
	while (t[n])
	{
		if (!ft_strcmp(clean_line(t[n]), "}"))
			break ;
		type == 'l' ?
			load_light(&(t[n])) : load_object(&(t[n]));
		++n;
		if (!ft_strcmp(clean_line(t[n]), "{") && ++n)
			while (t[n] && ft_strcmp(clean_line(t[n]), "}"))
				++n;
		n += type == 'l' ? 1 : 2;
	}
}