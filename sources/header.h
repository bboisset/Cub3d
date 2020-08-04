/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:53:28 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/04 17:40:03 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TEXT_W 64
# define TEXT_H 64
# define SPRITE_H 100
# define SPRITE_W 100
# define MOVESPEED 0.18
# define MOVESPEEDSEC 0.36
# define ROT_SPEED 0.12
# define SCREEN_MAX_W 2560
# define SCREEN_MAX_H 1440
# define SCALE_SPRITE 1
# define VMOVE 64
# define PI 3.1415926535
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ARR_RIGHT 124
# define KEY_ARR_LEFT 123
# define KEY_M 46
# define KEY_SPACE 49
# define KEY_ESC 53
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include "../includes/libft/libft.h"
# include "../includes/Get-Next-Line/get_next_line.h"

typedef struct				s_dimension
{
	double					x;
	double					y;
}							t_dimension;

typedef struct				s_img_data
{
	char					*data_img;
	int						bpp;
	int						sizeline;
	int						endian;
	int						index;
	t_dimension				dimension;
	void					*temp;
}							t_img_data;

typedef struct				s_active_action
{
	int						up_active;
	int						down_active;
}							t_active_action;

typedef struct				s_gun
{
	int						ammo;
	int						call_count;
	t_dimension				gun_pos;
	t_img_data				*img;
}							t_gun;

typedef struct				s_minimap
{
	int						cub_sz;
	int						cub_color;
	t_dimension				dim;
	t_img_data				*data;
	t_img_data				*player_icon;
}							t_minimap;

typedef struct				s_texture
{
	int						loaded_texture;
	char					*north_texture_path;
	char					*south_texture_path;
	char					*west_texture_path;
	char					*east_texture_path;
	char					*sprite_texture_path;
	t_img_data				*north_texture;
	t_img_data				*south_texture;
	t_img_data				*west_texture;
	t_img_data				*east_texture;
	t_img_data				*sprite_texture;
	t_img_data				*sprite_texture_dst;
}							t_texture;

typedef struct				s_rgb_color
{
	int						red;
	int						green;
	int						blue;
	int						integer;
}							t_rgb_color;

typedef struct				s_draw_info
{
	int						draw_start;
	int						draw_end;
}							t_draw_info;

typedef struct				s_drw_spt
{
	t_dimension				sprite_co;
	t_dimension				transform;
	t_dimension				draw_start;
	t_dimension				draw_end;
	t_dimension				spt_dim;
	double					inv_det;
	int						v_screen_move;
	int						spt_scr_x;
}							t_drw_spt;

typedef struct				s_sprite_list
{
	t_dimension				dimension;
	t_drw_spt				param;
	struct s_sprite_list	*next;
}							t_sprite_list;

typedef struct				s_map_config
{
	t_dimension				res;
	t_dimension				map_w;
	t_dimension				init_dir;
	t_dimension				init_pos;
	t_dimension				init_sprite_pos;
	t_texture				*textures;
	t_rgb_color				ground_color;
	t_rgb_color				sky_color;
	char					**map;
	t_list					*temp_map;
	t_sprite_list			*sprt_lst;
	double					*z_buffer;
	int						wall_dir;
	int						orientation;
	int						minimap_on;
	int						save_img;
	int						config_error;
	int						step;
	int						player_count;
}							t_map_config;

typedef struct				s_display
{
	int						orientation;
	int						move_speed;
	int						rot_speed;
	t_dimension				fov;
	t_dimension				dir;
	t_dimension				pos;
}							t_display;

typedef struct				s_data
{
	void					*mlx_ptr;
	void					*mlx_win;
	void					*mlx_img;
	t_img_data				*data;
	double					loop_count;
	t_drw_spt				spt_info;
}							t_data;

typedef struct				s_full_conf
{
	t_display				*camera;
	t_map_config			*config;
	t_data					*data;
	t_minimap				*minimap;
	t_gun					*gun;
	t_active_action			key;
}							t_full_conf;

typedef struct				s_raycast
{
	int						map_x;
	int						map_y;
	int						line_height;
	double					camera_x;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	t_draw_info				draw;
}							t_raycast;

int							read_file(int fd, t_map_config *config);

int							config_error(char *str);
int							get_post_wo_spaces(char *str, char *set, int max);

t_data						*init_data(t_map_config *config);
t_full_conf					*join_full_conf(t_display *display,
	t_map_config *config, t_data *data);

t_dimension					init_dimensions(void);
t_map_config				*init_config(void);
t_display					*init_display(t_map_config *config);

int							init_gun(t_full_conf *full_conf);
int							init_icon_player(t_full_conf *full_conf);
int							init_minimap(t_full_conf *full_conf);

void						play_sound(char *path, int volume,
	t_full_conf	*full_conf);
void						sprite_in_front(t_full_conf *full_conf,
	t_sprite_list *temp_sprt);

int							ft_edit_atoi(const char *str, int start);
void						define_direction(char c, t_map_config *config,
	t_display *camera);
char						*ft_strtrim_all(char const *s1, char const *set);

char						*get_path(int start, char *str,
	t_map_config *config);
int							assign_ground(char *str, t_map_config *config);
int							assign_sky(char *str, t_map_config *config);
int							assign_resolutions(char *str, t_map_config *config);

void						handle_go_up(t_full_conf *full_conf);
void						handle_go_down(t_full_conf *full_conf);
void						handle_go_left(t_full_conf *full_conf);
void						handle_go_right(t_full_conf *full_conf);

void						handle_cam_right(t_full_conf *full_conf);
void						handle_cam_left(t_full_conf *full_conf);

void						reload_scene(t_full_conf *full_conf,
	int gun_anim);

int							key_press(int keycode,
	t_full_conf *full_conf);
int							handle_exit(t_full_conf *full_conf);
int							key_realease(int keycode,
	t_full_conf *full_conf);
void						check_active_key(t_full_conf *full_conf);

int							read_map(char *str, t_map_config *config);

int							load_textures(t_map_config *config, t_data *data);
t_img_data					*load_textures_struct(void *img_ptr,
	t_map_config *config);

int							raycasting_loop(t_full_conf *full_conf);
void						game_loop(t_full_conf *full_conf);
int							floor_sky_cast(t_full_conf *full_conf);
void						draw_texture(int x, int tex_x,
	t_full_conf *full_conf, t_raycast *param);
void						draw_stripe(t_drw_spt *param,
	t_full_conf *full_conf);

void						draw_vertical_line(t_dimension start_pos, int y2,
	const int color, t_data *data);
void						draw_circle(int x, int y, int r, t_img_data *img);
void						fill_img(int x, int y, int color, t_img_data *img);

int							mimimap(t_full_conf *full_conf);
void						place_player(t_full_conf *full_conf);

int							rgb_to_int(int r, int g, int b);
int							check_color(int red, int green, int blue);
int							is_in_set(char c, const char *set);
int							last_char_is_wall(char *str);

int							gun(t_full_conf *full_conf,
	int animation);

void						fish_eye(int side, t_raycast *param,
	t_display *camera, t_dimension step);
void						define_draw(t_raycast *param, t_display *camera,
	t_map_config *config);
int							wall_distance(t_raycast *param, t_display *camera,
	t_map_config *config);
int							loop_till_hit(int side, t_raycast *param,
	t_display *camera, t_map_config *config);
void						init_raycast(int x, t_raycast *param,
	t_display *camera, t_map_config *config);

int							main_error(int n);
void						free_textures(t_map_config	*config, void *mlx_ptr);
void						free_data(t_data *data);
void						free_image(void *mlx_ptr, t_img_data *img_data);
int							texture_error(t_map_config *config, t_data *data);
int							full_error_d(t_full_conf *full_conf,
	int type, int code);
int							full_error(t_map_config *config, t_data *data,
	t_display *display, int code);

int							temp_map_switcher_error(char **map, int i,
	char **ptr_temp_map);
int							map_error(t_map_config	*config, int code);
int							cam_mall_err(t_map_config *config,
	t_data*data, int code);

void						code_error(int code);

int							exit_pr(t_full_conf *full_conf);
void						free_gun(t_data *data, t_gun *gun);
void						free_minimap(t_data *data, t_minimap *minimap,
	int type);

void						free_sprites(t_sprite_list **sprt_lst);

int							create_bitmap(t_map_config *config,
	t_img_data *data);

int							first_launch(t_map_config	*config);

void						fire(t_full_conf *full_conf);

void						enable_minimap(t_full_conf *full_conf);

void						free_config(t_map_config *confi, t_data *data);

int							check_map_wall(t_map_config *config);

t_sprite_list				*ft_sprt_lst_nw(int x, int y);
void						ft_sprt_lst_back(t_sprite_list **a_sprt_lst,
	t_sprite_list *new);
void						sprite_loop(t_full_conf *full_conf);
int							ft_sprt_lstsize(t_sprite_list *lst);

int							char_is_sprite(char *str, int i, int map_y,
	t_map_config *config);
int							inspect_line_end(char *str, t_map_config *config);
void						char_is_player(t_map_config *config, char *str,
	int i, int map_y);
#endif
