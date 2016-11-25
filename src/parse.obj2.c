/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:33:19 by fdel-car          #+#    #+#             */
/*   Updated: 2016/11/25 16:37:52 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*get_after(char *s, char *a)
{
	while (*s == ' ' || *s == '\t')
		s++;
	while (*s == *a && (++s))
		++a;
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

void	ctab_free(char **t)
{
	int	i;

	i = -1;
	while (t[++i])
		free(t[i]);
}

int		get_val(char *s, int r)
{
	int i;
	int c;

	i = -1;
	c = 1;
	while (s[++i] && c < r)
		s[i] == '/' || s[i] == ' ' ? ++c : 0;
	return (ft_atoi(&(s[i])));
}

void	read_triangle(t_obj *o, char *line, t_vect **v, t_mater mat)
{
	char **t;

	t = ft_strsplit(line, ' ');
	if (t[0] && t[1] && t[2] && t[3])
	{
		o->name = ft_strdup("mesh_triangle");
		o->type = TRIANGLE;
		o->norm = v[1][get_val(t[1], 3) - 1];
		o->v0 = v[0][get_val(t[1], 1) - 1];
		o->v1 = v[0][get_val(t[2], 1) - 1];
		o->v2 = v[0][get_val(t[3], 1) - 1];
		o->mater = mat;
		o->next = 0;
	}
	ctab_free(t);
}
