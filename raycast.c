/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:06:33 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/19 16:06:35 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/wolf.h"

void	second_part_ray(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
		* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

void	dda_ray(t_data * data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->array[data->map_y][data->map_x] > 0)
			data->hit = 1;
	}
}

void	first_part_ray(t_data *data)
{
	data->camerX = (double)((data->x * 2) / (double)(data->w) - 1);
	data->ray_dir_x = data->dir_x + data->plan_x * data->camerX;
	data->ray_dir_y = data->dir_y + data->plan_y * data->camerX;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
	second_part_ray(data);
	dda_ray(data);
}

void	calculate_drawing(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->map_x - data->pos_x + (1 - data->step_x)
			/ 2) / data->ray_dir_x;
	else
		data->perp_wall_dist = (data->map_y - data->pos_y + (1 - data->step_y)
			/ 2) / data->ray_dir_y;
	data->line_height = (int)(data->h / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + data->h / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->h / 2;
	if (data->draw_end >= data->h)
		data->draw_end = data->h - 1;
}

void	raycasting(t_data *data)
{
	data->x = -1;
	sprites(data);
	SDL_RenderClear(data->ren);
	while (++data->x < data->w)
	{
		first_part_ray(data);
		calculate_drawing(data);
		draw_wall(data);
		find_floorwall(data);
		dr_floor(data);
	}
	printf("pos_x %d  :::: pos_y %d\n", (int)data->pos_x, (int)data->pos_y);
	sprites(data);
}
