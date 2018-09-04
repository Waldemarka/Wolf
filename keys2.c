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
	data->dir_x = data->dir_x * cos(0.1) - data->dir_y * sin(0.1);
	data->dir_y = dr * sin(0.1) + data->dir_y * cos(0.1);
	plan = data->plan_x;
	data->plan_x = data->plan_x * cos(0.1) - data->plan_y * sin(0.1);
	data->plan_y = plan * sin(0.1) + data->plan_y * cos(0.1);
}

void	key_right(t_data *data)
{ 
	double plan;
	double dr;

	dr = data->dir_x;
	data->dir_x = data->dir_x * cos(-0.1) - data->dir_y * sin(-0.1);
	data->dir_y = dr * sin(-0.1) + data->dir_y * cos(-0.1);
	plan = data->plan_x;
	data->plan_x = data->plan_x * cos(-0.1) - data->plan_y * sin(-0.1);
	data->plan_y = plan * sin(-0.1) + data->plan_y * cos(-0.1);
}

void	other_keys(t_data *data, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && data->check == 0)
	{
		data->key_space = 1;
		data->start_time = SDL_GetTicks();
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q && data->check == 0)
	{
		if (data->nb_weapon == 1)
			data->nb_weapon = 2;
		else if (data->nb_weapon == 2)
			data->nb_weapon = 1;
	}
}
