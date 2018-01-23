/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:26:24 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/26 21:46:46 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/include/libft.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <OpenCL/opencl.h>
# include "../mlx/el_capitan/mlx.h"

typedef	struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct	s_pos
{
	t_vect	*ori;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	double	fov;
}				t_pos;

typedef struct	s_obj
{
	char	*name;
	int		status;
	double	rayon;
	double	k;
	double	t;
	t_color	*clr;
	t_pos	*c;
	t_vect	*o_axis;
	t_vect	*abc;
	t_vect	*origintoobj;
}				t_obj;

typedef	struct	s_light
{
	t_vect	*dir;
	t_vect	*ori;
	t_color	*clr;
}				t_light;

typedef struct	s_win
{
	void	*win;
	void	*win_opt;
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		width;
	int		height;
	int		tmp;
}				t_win;

typedef struct	s_scene
{
	t_vect	*lookatpoint;
	t_vect	*viewdirection;
	t_vect	*u;
	t_vect	*up;
	t_vect	*v;
	double	aspectratio;
	double	viewplanewidth;
	double	viewplaneheight;
	t_vect	*viewplaneupleftpoint;
	double	xincvect;
	double	yincvect;
	t_vect	*viewplanepoint;
	t_vect	*ray;
}				t_scene;

typedef struct	s_inter
{
	t_color	*clr;
	double	t;
	int		x;
	int		y;
	t_vect	*point;
	t_vect	*norm;
}				t_inter;

typedef struct	s_tmp
{
	double	t1;
	double	t2;
	double	m1;
	double	det;
	double	tmp;
	double	th;
	double	length;
	double	ombre;
	t_vect	*tmp_vect;
	t_vect	*tmp_vect_bis;
	t_vect	*rfl_ray;
	t_color	*diffuse;
	t_color *phong;
	t_color	*ambient;
	t_color	*clr;
	t_color	*light_clr;
	t_color	*inter_clr;
}				t_tmp;

typedef struct	s_env
{
	char	*name;
	int		status;
	int		status_tmp;
	void	*mlx;
	t_win	*win;
	t_pos	*cam;
	int		x;
	int		y;
	int		s1;
	int		s2;
	int		c_o;
	int		c_l;
	int		n_obj;
	int		n_light;
	t_list	*list;
	t_list	*light;
	t_list	*inter;
	t_scene	*scene;
	t_tmp	*tmp;
}				t_env;

void			delete_env(t_env **e);
void			delete_win(t_env *e, t_win *win);
void			delete_obj(void *obj, size_t n);
void			delete_light(void *obj, size_t n);
void			delete_inter(void *obj, size_t n);
void			delete_scene(t_scene *scene);
void			delete_tmp(t_tmp *tmp);
void			basic_error(char *argv, t_env **e);
void			malloc_error(t_env **e);
void			syntax_error(t_env **e);
void			empty_file(t_env **e);
int				red_cross(t_env *e);
int				key_hook_rt(int keycode, t_env *e);
int				key_hook_setup(int keycode, t_env *e);
int				key_hook_setup_bis(int keycode, t_env *e);
int				key_hook_setup_ter(int keycode, t_env *e);
int				key_hook_camera(int keycode, t_env *e);
void			key_hook_camera_bis(t_env *e);
int				key_hook_object(int keycode, t_env *e);
int				key_hook_object_bis(int keycode, t_env *e);
void			key_hook_object_ori(t_env *e);
void			key_hook_object_rot(t_env *e);
int				key_hook_light(int keycode, t_env *e);
void			key_hook_light_ori(t_env *e);
void			valid_file(t_env **e);
void			valid_file_bis(t_env **e);
void			valid_object_param(t_obj *obj, t_env **e);
void			read_file(char *argv, t_env **e);
void			read_line(t_env **e, char *line);
void			read_line_bis(t_env **e, char *line);
int				check_param(char *line, t_env **e);
int				check_param_bis(char *line, t_env **e);
int				check_param_ter(char *line, t_env **e);
t_env			*init_env(void);
t_win			*init_screen(t_env **e);
void			num_obj_light(t_env *e);
int				correct_number(char *str);
double			change_value(char *str, t_env *e);
void			name_prog(char *line, t_env **e);
void			screen_size(char *line, t_env **e);
void			screen_size_bis(char *line, int i, t_env **e);
t_pos			*init_pos(t_env **e);
void			camera_settings(char *line, t_env **e);
int				camera_option(char *line, t_env **e);
int				camera_option_bis(char *line, t_env **e);
void			camera_origin_coordinates(char *line, int i, t_env **e);
void			camera_origin_coordinates_bis(char *line, int i, int j,
					t_env **e);
void			camera_rotation(char *line, int i, t_env **e);
void			camera_rotation_bis(char *line, int i, int j, t_env **e);
void			camera_fov(char *line, t_env **e);
void			init_object(t_env **e);
void			object_settings(char *line, t_env **e);
int				object_option(char *line, t_env **e);
int				object_option_bis(char *line, t_env **e);
void			name_object(char *line, t_env **e);
void			object_type(char *line, t_obj *obj, t_env **e);
int				object_type_option(char *line, t_obj *obj, t_env **e);
int				object_type_option_bis(char *line, t_obj *obj);
void			object_type_option_ter(char *line, t_obj *obj, t_env **e);
void			object_type_option_quater(char *line, t_obj *obj, t_env **e);
void			object_origin_coordinates(char *line, int i, t_env **e);
void			object_origin_coordinates_bis(char *line, int i, int j,
					t_env **e);
void			object_rotation(char *line, int i, t_env **e);
void			object_rotation_bis(char *line, int i, int j, t_env **e);
void			object_ori_rot_final(char *line, t_env **e);
void			object_color(char *line, int i, t_env **e);
void			object_color_bis(char *line, int i, int j, t_env **e);
void			init_sphere(char *line, t_obj *obj, t_env **e);
void			init_plane(char *line, t_obj *obj, t_env **e);
void			init_cylinder(char *line, t_obj *obj, t_env **e);
void			init_cone(char *line, t_obj *obj, t_env **e);
int				get_color(char *line, t_env **e);
int				ret_power(int nbr, int power);
int				hex_to_int(char *str, int power);
void			init_light(t_env **e);
void			light_settings(char *line, t_env **e);
int				light_option(char *line, t_env **e);
void			light_origin_coordinates(char *line, int i, t_env **e);
void			light_origin_coordinates_bis(char *line, int i, int j,
					t_env **e);
void			light_color(char *line, int i, t_env **e);
void			light_color_bis(char *line, int i, int j, t_env **e);
void			mlx_put_pixel_to_image(t_win *win, int x, int y,
					t_inter *inter);
void			rt(t_env *e);
void			rt_bis(t_win *win, t_env *e);
void			rotation(t_env *e);
void			rotation_bis(double x, double y, double z, t_obj *obj);
double			rotation_ter(double e, double tmp1, double tmp2);
void			set_camera_scene(t_scene *scene, t_pos *cam, t_win *win,
					t_env *e);
void			set_camera_scene_bis(t_scene *sceme, t_env *e);
void			render(t_env *e);
void			render_bis(t_env *e);
t_color			*trace(t_vect *ori, t_vect *dir, t_inter *inter, t_env *e);
t_color			*shade(t_vect *dir, t_inter *inter, t_env *e);
void			shade_bis(t_color *radiance, t_vect *dir, t_inter *inter,
				t_env *e);
void			shade_ter(t_light *light, t_inter *inter, t_env *e);
t_color			*phong(double shade, t_vect *dir, t_light *light, t_env *e);
void			init_inter(t_env *e);
t_scene			*init_scene(t_env *e);
t_vect			*create_vect(t_env *e);
t_color			*create_color(t_env *e);
void			reinit_color(t_color *clr);
void			add_color(t_color *clr, t_color *tmp);
void			mult_color(t_color *clr, t_color *tmp1, t_color *tmp2);
void			mult_color_real(t_color *tmp, t_color *clr, double n);
void			div_color_real(t_color *clr, double n);
void			mod_color(t_color *clr, t_color *tmp);
void			color_cpy(t_color *tmp, t_color *clr);
void			init_vect(t_vect *vect, double x, double y, double z);
void			add_vect(t_vect *rslt, t_vect *i, t_vect *j);
void			minus_vect(t_vect *rslt, t_vect *i, t_vect *j);
void			mult_vect_real(t_vect *rslt, t_vect *i, double n);
void			div_vect_real(t_vect *rslt, t_vect *i, double n);
void			cpy_vect(t_vect *t1, t_vect *t2);
void			cross_product(t_vect *rslt, t_vect *i, t_vect *j);
double			dot_product(t_vect *i, t_vect *j);
void			normalize(t_vect *i);
void			neg_vect(t_vect *i);
double			vect_length(t_vect *t1);
void			reflected_ray(t_tmp *tmp, t_vect *ray, t_vect *norm);
void			get_ray(t_scene *scene, t_env *e);
int				get_first_inter(t_inter *inter, t_vect *ori, t_vect *dir,
					t_env *e);
void			get_first_inter_bis(t_vect *ori, t_vect *dir, t_obj *obj,
					t_env *e);
int				intersection(t_vect *ori, t_vect *dir, t_env *e);
int				intersection_bis(t_vect *ori, t_vect *dir, t_obj *obj,
					t_env *e);
int				intersection_ter(t_vect *ori, t_vect *dir, t_obj *obj,
					t_env *e);
int				draw_sphere(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
void			inter_sphere(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
int				draw_plane(t_vect *ori, t_vect *dir, t_obj *obj);
void			inter_plane(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
int				draw_cylinder(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
int				draw_cc(t_vect *dir, t_obj *obj, t_env *e);
t_tmp			*init_tmp(t_env *e);
void			inter_cylinder(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
int				draw_cone(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
int				draw_cone_bis(t_vect *dir, t_obj *obj, t_env *e);
int				draw_cone_ter(t_obj *obj, t_env *e);
void			inter_cone(t_vect *ori, t_vect *dir, t_obj *obj, t_env *e);
void			main_menu_setup(t_env *e);
void			camera_menu_setup(t_env *e);
void			object_menu_setup(t_env *e);
void			object_menu_setup_bis(char *str, void *opt, t_env *e);
void			light_menu_setup(t_env *e);
void			light_menu_setup_bis(char *str, void *opt, t_env *e);
void			ol_menu_setup(char **str, int i, int j, char *type);
void			terminal_menu_setup(t_env *e);

#endif
