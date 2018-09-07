/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:42:49 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/01 12:44:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/wolf.h"

void	key_left(t_data *data)
{
	double plan;
	double dr;

	dr = data->dir_x;
	data->dir_x = data->dir_x * cos(0.05) - data->dir_y * sin(0.05);
	data->dir_y = dr * sin(0.05) + data->dir_y * cos(0.05);
	plan = data->plan_x;
	data->plan_x = data->plan_x * cos(0.05) - data->plan_y * sin(0.05);
	data->plan_y = plan * sin(0.05) + data->plan_y * cos(0.05);
}

void	key_right(t_data *data)
{ 
	double plan;
	double dr;

	dr = data->dir_x;
	data->dir_x = data->dir_x * cos(-0.05) - data->dir_y * sin(-0.05);
	data->dir_y = dr * sin(-0.05) + data->dir_y * cos(-0.05);
	plan = data->plan_x;
	data->plan_x = data->plan_x * cos(-0.05) - data->plan_y * sin(-0.05);
	data->plan_y = plan * sin(-0.05) + data->plan_y * cos(-0.05);
}

void	other_keys(t_data *data, const Uint8 *keys, SDL_Event	event)
{
	if (keys[SDL_SCANCODE_SPACE] && data->key_space != 1)
	{
		data->key_space = 1;
		data->start_time = SDL_GetTicks();
	}
	if (keys[SDL_SCANCODE_Q] && data->key_space == 0)
	{
		if (data->nb_weapon == 1)
			data->nb_weapon = 2;
		else if (data->nb_weapon == 2)
			data->nb_weapon = 1;
	}
	if (keys[SDL_SCANCODE_E] && data->key_door != 1)
	{
		if (check_door(data) == 1)
			data->key_door = 1;
		data->start_time_door = SDL_GetTicks();
	}
	if (keys[SDL_SCANCODE_LSHIFT])
		data->speed = 0.08;
	else
		data->speed = 0.04;
}
