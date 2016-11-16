#include "rt.h"

int			ft_limit(int v, int min, int max)
{
	v > max ? v = max : 0;
	v < min ? v = min : 0;
	return (v);
}

t_color		get_texel(t_text tex, int i, int j)
{
	t_color	r;

	r.r = tex.text[j *
	(tex.tex_w * 3) + (i * 3)];
	r.g = tex.text[j *
	(tex.tex_w * 3) + (i * 3) + 1];
	r.b = tex.text[j *
	(tex.tex_w * 3) + (i * 3) + 2];
	return (r);
}

t_color		getex_sphere(t_data ray)
{
	t_vect	d;
	float	u;
	float	v;
	int		i;
	int		j;

	if (!ray.obj_hit || !ray.obj_hit->mater.tex)
		return (ray.obj_hit->mater.color);
	d = vec_norm(vec_sub(ray.hit_point, ray.obj_hit->pos));
	u = 0.5 + atan2(d.z, d.x) / M_PI * 0.5;
	v = 0.5 - asin(d.y) / M_PI;
	i = ft_limit(u * ray.obj_hit->mater.tex->tex_w, 0, ray.obj_hit->mater.tex->tex_w - 1);
	j = ft_limit(v * ray.obj_hit->mater.tex->tex_h, 0, ray.obj_hit->mater.tex->tex_h - 1);
	return (get_texel(*ray.obj_hit->mater.tex, i, j));
}

t_color		getex_cyl(t_data ray)
{
	t_vect	d;
	float	u;
	float	v;
	int		i;
	int		j;

	d = vec_sub(ray.hit_point, vec_mul(ray.obj_hit->pos, ray.obj_hit->dir));
	u = 0.5 + atan2(d.z, d.x) / M_PI * 0.5;
	v = d.y / 10;//10 correspond a la hauteur du repeat de la texture
	v = v - floor(v);
	i = ft_limit(u * ray.obj_hit->mater.tex->tex_w, 0, ray.obj_hit->mater.tex->tex_w - 1);
	j = ft_limit(v * ray.obj_hit->mater.tex->tex_h, 0, ray.obj_hit->mater.tex->tex_h - 1);
	return (get_texel(*ray.obj_hit->mater.tex, i, j));
}

t_color		get_texture(t_data ray)
{
	t_color r;

	r = color_new(0, 0, 0);
	if (ray.obj_hit->type == SPHERE)
		return (getex_sphere(ray));
	if (ray.obj_hit->type == CYLINDER ||
	ray.obj_hit->type == CONE)
		return (getex_cyl(ray));
	return (r);
}
