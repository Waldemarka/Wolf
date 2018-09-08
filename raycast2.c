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

# include "includes/wolf.h"

void	find_floorwall(t_data *data)
{
	if (data->side == 0 && data->ray_dir_x > 0)
	{
		data->floor_wall_x = data->map_x;
		data->floor_wall_y = data->map_y + data->wall_x;
	}
	else if (data->side == 0 && data->ray_dir_x < 0)
	{
		data->floor_wall_x = data->map_x + 1.0;
		data->floor_wall_y = data->map_y + data->wall_x;
	}
	else if (data->side == 1 && data->ray_dir_y > 0)
	{
		data->floor_wall_x = data->map_x + data->wall_x;
		data->floor_wall_y = data->map_y;
	}
	else
	{
		data->floor_wall_x = data->map_x + data->wall_x;
		data->floor_wall_y = data->map_y + 1.0;	
	}
}

void	dr_floor(t_data *data)
{
	data->dist_player = 0.0;
	if (data->draw_end < 0)
		data->draw_end = HEIGHT;
	data->y = data->draw_end - 1;
	while (++data->y < HEIGHT)
	{
		data->current_dist = HEIGHT / (2.0 * data->y - HEIGHT);
		data->weight = (data->current_dist - data->dist_player) /
			(data->perp_wall_dist - data->dist_player);
		data->current_floor_x = data->weight * data->floor_wall_x +
			(1.0 - data->weight) * data->pos_x;
		data->current_floor_y = data->weight * data->floor_wall_y +
			(1.0 - data->weight) * data->pos_y;
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

	n = data->array[data->map_y][data->map_x] - 1;
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * 256.0);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = 256.0 - data->tex_x - 1;
	if (data->side == 1 & data->ray_dir_y < 0)
		data->tex_x = 256.0 - data->tex_x  - 1;
	data->y = data->draw_start;
	while (++data->y < data->draw_end)
	{
		data->d = data->y * 256 - data->h * 128 + data->line_height * 128;
		data->tex_y = ((data->d * 256.0) / data->line_height / 256);
		if ((color = get_pixel_int(data->wall[n], data->tex_x, data->tex_y)) != 0)
			data->buf[data->y][data->x] = color;
	}
}
