/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-la-s <vde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:43:09 by fdel-car          #+#    #+#             */
/*   Updated: 2016/11/16 01:53:15 by vde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H
# define EPSILON 0.01

float		quadratic_root(float a, float b, float c);
float		*cubic_root(float a, float b, float c, float d);
float		quartic_root(float a, float b, float c, float d, float e);
void		switch_key_focus(void);
gboolean	key_event(GtkWidget *win, GdkEventKey *event);
t_data		intersect_obj(t_data ray);
t_color		render_ray(t_data ray);
float		intersect_torus(t_obj *obj, t_data ray);
float		intersect_triangle(t_obj *obj, t_data ray);
float		intersect_sphere(t_obj *obj, t_data ray);
float		intersect_cylinder(t_obj *obj, t_data ray);
float		intersect_cone(t_obj *obj, t_data ray);
float		intersect_plane(t_obj *obj, t_data ray);
t_color		compute_light(t_data ray, int r_max);
t_color		get_texture(t_data ray);
t_vect		vec_new(float x, float y, float z);
t_vect		cross_pr(t_vect u, t_vect v);
t_vect		vec_mult(t_vect u, float value);
t_vect		vec_mul(t_vect u, t_vect v);
t_vect		vec_sub(t_vect u, t_vect v);
t_vect		vec_add(t_vect u, t_vect v);
t_vect		vec_norm(t_vect u);
t_vect		rot_x(float theta, t_vect u);
t_vect		rot_y(float theta, t_vect u);
t_vect		rot_z(float theta, t_vect u);
t_vect		rot_any(t_vect u, t_vect a, float theta);
float		vec_dotp(t_vect u, t_vect v);
float		dist_p(t_vect u, t_vect v);
void		*raytracing(void *arg);
void		put_pixel(int x, int y, t_color color);
void		get_norm(t_data *ray);
void		launch_thread(void);
void		init_view(void);
void		launch_preview(void);
void		desactivate_preview(void);
void		spin_button(void);
void		aa_check();

#endif
