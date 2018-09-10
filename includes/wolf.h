/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:51:23 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/06 11:51:25 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include "../source/libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1024
# define HEIGHT 768
# define WIDTH_SKY 4320
# define HEIGHT_SKY 900
# define POS_X data->raycast.pos_x
# define POS_Y data->raycast.pos_y
# define DIR_X data->raycast.dir_x
# define DIR_Y data->raycast.dir_y
# define RAY_DIR_X data->raycast.ray_dir_x
# define RAY_DIR_Y data->raycast.ray_dir_y
# define PLAN_X data->raycast.plan_x
# define PLAN_Y data->raycast.plan_y
# define MAP_X data->raycast.map_x
# define MAP_Y data->raycast.map_y
# define CAMER_X data->raycast.camerX
# define DELTA_DIST_X data->raycast.delta_dist_x
# define DELTA_DIST_Y data->raycast.delta_dist_y
# define SIDE_DIST_X data->raycast.side_dist_x
# define SIDE_DIST_Y data->raycast.side_dist_y
# define PERP_WALL_DIST data->raycast.perp_wall_dist
# define HIT data->raycast.hit
# define SIDE data->raycast.side
# define LINE_HEIGHT data->raycast.line_height
# define DRAW_START data->raycast.draw_start
# define DRAW_END data->raycast.draw_end

#define C_Q (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)

typedef struct  s_sprites
{
	int 		iterat;
	int 		pixel_wid;
	int 		timing;	
	int 		min_coord_x;
	int 		min_coord_y;
	int 		max_coord_x;
	int 		max_coord_y;
}				t_sprites;

typedef struct s_raycast
{
	double		camerX;
	double		pos_x;
	double 		pos_y;
	double		dir_x;
	double		dir_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		plan_x;
	double		plan_y;
	int 		map_x;
	int 		map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int 		line_height;	
	int 		side;
	int			hit;
	int			draw_start;
	int			draw_end;
}				t_raycast;

typedef struct s_data
{
	SDL_Window	*win;
	SDL_Renderer	*ren;
	SDL_Surface *bmp;
	SDL_Texture *screen;
	SDL_Surface *up;
	SDL_Surface *floor;
	SDL_Surface *sec;
	SDL_Surface *now;
	SDL_Surface *wall[13];
	SDL_Surface *pist[3];
	SDL_Surface *drob[7];
	SDL_Surface *sky[3];
	Mix_Music	*mus[3];
	Mix_Music	*shots[2];
	t_sprites	sprit;
	t_raycast	raycast;
	int			fd;
	char		*name;
	int			height_arr;
	int			width_arr;
	int 		**array;
	int			buf[HEIGHT][WIDTH];
	
	int			step_x;
	int			step_y;
	double		speed;

	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		floor_wall_x;
	double		floor_wall_y;
	double		dist_player;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
	double		weight;
	double		current_dist;

	int			key_space;
	unsigned int time;
	unsigned int start_time;
	int 		sprite_tex_x;
	int			sprite_tex_y;
	int 		spr_x;
	int 		spr_y;
	int			nb_weapon;
	int 		key_door;
	int 		door_cen;
	int 		start_time_door;
	int 		time_door;
	int 		max_box;
	int			q_door;
	int			dr_map_x;
	int			dr_map_y;
	int 		check_door;
	int			key_floor;
	int			nbr_sky;

	int			for_exit;
	int 		x;
	int			y;
	int			d;
	int 		count;
}				t_data;

SDL_Texture *load_img(SDL_Renderer *ren, SDL_Surface *bmp, char *imag);

char			*ft_joinfree(char *s1, char *s2, int j);
void 			ft_error(int num);
char			**open_read(t_data *data);
void			first_ar(t_data *data, char **str);
void			check_str(t_data *data, char **str);
void			make_arr(t_data *data, char **str);
int				**int_malloc(t_data *data);
void			check_rest(t_data *data);
int 			len_int(char *str);
void			load_media(t_data *data);
void			raycasting(t_data *data);
void			find_floorwall(t_data *data);
void			dr_floor(t_data *data);
void 			draw_wall(t_data *data);
void			key_event(t_data *data);
unsigned int	get_pixel_int(SDL_Surface *surface, int x, int y);
void			put_pixel32(SDL_Surface *surface, int x, int y, int pixel);
SDL_Surface		*load_image(char *path);
void			key_left(t_data *data);
void			key_right(t_data *data);
void			other_keys(t_data *data, const Uint8 *keys);
void			sprites(t_data *data);
void			chek_door(t_data *data);
void			door(t_data *data);
void			skybox(t_data *data);
Mix_Music		*load_music(char *path);

#endif 