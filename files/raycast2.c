  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:40:24 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/20 16:40:26 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void	find_floorwall(t_data *data)
{
	if (SIDE == 0 && RAY_DIR_X > 0)
	{
		data->floor_wall_x = MAP_X;
		data->floor_wall_y = MAP_Y + data->wall_x;
	}
	else if (SIDE == 0 && RAY_DIR_X < 0)
	{
		data->floor_wall_x = MAP_X + 1.0;
		data->floor_wall_y = MAP_Y + data->wall_x;
	}
	else if (SIDE == 1 && RAY_DIR_Y > 0)
	{
		data->floor_wall_x = MAP_X + data->wall_x;
		data->floor_wall_y = MAP_Y;
	}
	else
	{
		data->floor_wall_x = MAP_X + data->wall_x;
		data->floor_wall_y = MAP_Y + 1.0;	
	}
}

void	dr_floor(t_data *data)
{
	data->dist_player = 0.0;
	if (DRAW_END < 0)
		DRAW_END = HEIGHT;
	data->y = DRAW_END - 1;
	while (++data->y < HEIGHT)
	{
		data->current_dist = HEIGHT / (2.0 * data->y - HEIGHT);
		data->weight = (data->current_dist - data->dist_player) /
			(PERP_WALL_DIST - data->dist_player);
		data->current_floor_x = data->weight * data->floor_wall_x +
			(1.0 - data->weight) * POS_X;
		data->current_floor_y = data->weight * data->floor_wall_y +
			(1.0 - data->weight) * POS_Y;
		data->floor_tex_x = (int)(data->current_floor_x * 256) % 256;
		data->floor_tex_y = (int)(data->current_floor_y * 256) % 256;
		if (data->key_floor != 2 && data->key_floor != 4)
			data->buf[data->y][data->x] = get_pixel_int(data->floor, data->floor_tex_x, data->floor_tex_y);
		if (data->key_floor != 1 && data->key_floor != 4)
		data->buf[WIDTH / 4 * 3 - data->y][data->x] = get_pixel_int(data->up, data->floor_tex_x, data->floor_tex_y);
	}
}

void 	draw_wall(t_data *data)
{
	int n;
	int color;

	n = data->array[MAP_Y][MAP_X] - 1;
	if (SIDE == 0)
		data->wall_x = POS_Y + PERP_WALL_DIST * RAY_DIR_Y;
	else
		data->wall_x = POS_X + PERP_WALL_DIST * RAY_DIR_X;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * 256.0);
	if (SIDE == 0 && RAY_DIR_X > 0)
		data->tex_x = 256.0 - data->tex_x - 1;
	if (SIDE == 1 & RAY_DIR_Y < 0)
		data->tex_x = 256.0 - data->tex_x  - 1;
	data->y = DRAW_START;
	while (++data->y < DRAW_END)
	{
		data->d = data->y * 256 - HEIGHT * 128 + LINE_HEIGHT * 128;
		data->tex_y = ((data->d * 256.0) / LINE_HEIGHT / 256);
		if ((color = get_pixel_int(data->wall[n], data->tex_x, data->tex_y)) != 0)
			data->buf[data->y][data->x] = color;
	}
}
