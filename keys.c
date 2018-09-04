/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:05:22 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/27 15:05:24 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/wolf.h"

void	key_s(t_data *data)
{
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x * 0.15)] == 0)
		data->pos_x -= data->dir_x * 0.15;
	if (data->array[(int)(data->pos_y - data->dir_y * 0.15)][(int)(data->pos_x)] == 0)
		data->pos_y -= data->dir_y * 0.15;
}

void	key_w(t_data *data)
{
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x * 0.15)] == 0)
		data->pos_x += data->dir_x * 0.15;
	if (data->array[(int)(data->pos_y + data->dir_y * 0.15)][(int)(data->pos_x)] == 0)
		data->pos_y += data->dir_y * 0.15;
}

void	key_a(t_data *data)
{
	float dirx;
	float diry;

	dirx = data->dir_x * cos(1.55) - data->dir_y * sin(1.55);
	diry = data->dir_x * sin(1.55) + data->dir_y * cos(1.55);
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x + dirx * 0.15)] == 0)
		data->pos_x += dirx * 0.15;
	if (data->array[(int)(data->pos_y + diry * 0.3)][(int)(data->pos_x)] == 0)
		data->pos_y += diry * 0.15;

}

void	key_d(t_data *data)
{
	float dirx;
	float diry;

	dirx = data->dir_x * cos(-1.55) - data->dir_y * sin(-1.55);
	diry = data->dir_x * sin(-1.55) + data->dir_y * cos(-1.55);
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x + dirx * 0.15)] == 0)
		data->pos_x += dirx * 0.15;
	if (data->array[(int)(data->pos_y + diry * 0.3)][(int)(data->pos_x)] == 0)
		data->pos_y += diry * 0.15;
}

void	key_event(t_data *data)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || C_Q)
			data->for_exit = 1;
		if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_w
			|| event.key.keysym.sym == SDLK_UP))
			key_w(data);
		else if (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_s
			|| event.key.keysym.sym == SDLK_DOWN))
			key_s(data);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
			key_left(data);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
			key_right(data);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a)
			key_a(data);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d)
			key_d(data);
		other_keys(data, event);
	}
}
