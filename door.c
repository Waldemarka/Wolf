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

# include "includes/wolf.h"

int		plus_minus(t_data *data, int y, int x)
{
	if ((data->array[y][x + 1] < 6 && data->array[y][x + 1] > 0)
		&& (data->array[y][x - 1] < 6 && data->array[y][x - 1] > 0))
		return (1);
	if ((data->array[y + 1][x] < 6 && data->array[y + 1][x] > 0)
		&& (data->array[y - 1][x] < 6 && data->array[y - 1][x] > 0))
		return (1);
	return (0);
}

int		check_door(t_data *data, int step)
{
	if (data->array[((int)data->pos_y) + step][(int)data->pos_x] >= 5
		&& plus_minus(data,((int)data->pos_y) + step, (int)data->pos_x) == 1
		&& data->array[((int)data->pos_y) + step][(int)data->pos_x] < 12)
	{
		data->dr_map_x = (int)data->pos_x;
		data->dr_map_y = ((int)data->pos_y) + step;
		return (1);
	}
	else if (data->array[((int)data->pos_y) - step][(int)data->pos_x] >= 5
		&& plus_minus(data,((int)data->pos_y) - step, (int)data->pos_x) == 1
		&& data->array[((int)data->pos_y) - step][(int)data->pos_x] < 12)
	{
		data->dr_map_x = (int)data->pos_x;
		data->dr_map_y = ((int)data->pos_y) - step;
		return (1);
	}
	else if (data->array[(int)data->pos_y][((int)data->pos_x) + step] >= 5
		&& plus_minus(data,(int)data->pos_y, ((int)data->pos_x) + step) == 1
		&& data->array[(int)data->pos_y][((int)data->pos_x) + step] < 12)
	{
		data->dr_map_x = ((int)data->pos_x) + step;
		data->dr_map_y = ((int)data->pos_y);
		return (1);
	}
	else if (data->array[(int)data->pos_y][((int)data->pos_x) - step] >= 5
		&& plus_minus(data,(int)data->pos_y, ((int)data->pos_x) - step) == 1
		&& data->array[(int)data->pos_y][((int)data->pos_x) - step] < 12)
	{
		data->dr_map_x = ((int)data->pos_x) - step;
		data->dr_map_y = ((int)data->pos_y);
		return (1);
	}
	return (0);
}

void	door_cont(t_data *data)
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
	}
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
		}
	}
	data->max_box = 6;
}
