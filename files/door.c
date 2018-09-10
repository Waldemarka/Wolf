 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/012/04 18:33:24 by vomelchu          #+#    #+#             */
/*   Updated: 2018/012/04 18:33:25 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void	chek_door(t_data *data)
{
	if (data->door_cen == 1 &&
		data->array[data->map_y][data->map_x] >= 5 &&
		data->array[data->map_y][data->map_x] < 12 &&
		((data->array[data->map_y + 1][data->map_x] > 0 &&
		data->array[data->map_y - 1][data->map_x] > 0) ||
		(data->array[data->map_y][data->map_x + 1] > 0 &&
		data->array[data->map_y][data->map_x - 1] > 0)) &&
		data->perp_wall_dist < 2.5)
	{
		data->key_door = 1;
		data->dr_map_x = data->map_x;
		data->dr_map_y = data->map_y;
	}
	data->door_cen = 0;
}

void	door(t_data *data)
{
	data->time_door = SDL_GetTicks();

	if (data->key_door == 1)
	{
		if (data->time_door <= data->start_time_door + (150 * (data->q_door + 1)))
		{
			data->max_box += data->q_door;
			raycasting(data);
		}
		if (data->time_door >= data->start_time_door + (150 * (data->q_door + 1)))
		{
			data->max_box += data->q_door;
			raycasting(data);
			data->array[data->dr_map_y][data->dr_map_x] += 1;
			data->q_door++;
		}
		if (data->q_door > 8)
		{
			data->q_door = 0;
			data->key_door = 0;
			data->array[data->dr_map_y][data->dr_map_x] = 0;
			data->door_cen = 0;
		}
	}
	data->max_box = 6;
}
