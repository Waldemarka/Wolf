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
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x
		- data->dir_x * data->speed)] == 0)
			data->pos_x -= data->dir_x * data->speed;
	if (data->array[(int)(data->pos_y - data->dir_y
		* data->speed)][(int)(data->pos_x)] == 0)
			data->pos_y -= data->dir_y * data->speed;
}

void	key_w(t_data *data)
{
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x
		+ data->dir_x * data->speed)] == 0)
			data->pos_x += data->dir_x * data->speed;
	if (data->array[(int)(data->pos_y + data->dir_y
		* data->speed)][(int)(data->pos_x)] == 0)
			data->pos_y += data->dir_y * data->speed;
}

void	key_a(t_data *data)
{
	float dirx;
	float diry;

	dirx = data->dir_x * cos(1.55) - data->dir_y * sin(1.55);
	diry = data->dir_x * sin(1.55) + data->dir_y * cos(1.55);
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x
		+ dirx * data->speed)] == 0)
			data->pos_x += dirx * data->speed;
	if (data->array[(int)(data->pos_y + diry * data->speed)]
		[(int)(data->pos_x)] == 0)
			data->pos_y += diry * data->speed;

}

void	key_d(t_data *data)
{
	float dirx;
	float diry;

	dirx = data->dir_x * cos(-1.55) - data->dir_y * sin(-1.55);
	diry = data->dir_x * sin(-1.55) + data->dir_y * cos(-1.55);
	if (data->array[(int)(data->pos_y)][(int)(data->pos_x
		+ dirx * data->speed)] == 0)
			data->pos_x += dirx * data->speed;
	if (data->array[(int)(data->pos_y + diry
		* data->speed)][(int)(data->pos_x)] == 0)
			data->pos_y += diry * data->speed;
}

void	key_event(t_data *data)
{
	SDL_Event	event;
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || C_Q)
		{
			data->for_exit = 1;
			ft_error(5);
		}
		if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W])
			key_w(data);
		if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S])
			key_s(data);
		if (keys[SDL_SCANCODE_LEFT])
			key_left(data);
		if (keys[SDL_SCANCODE_RIGHT])
			key_right(data);
		if (keys[SDL_SCANCODE_A])
			key_a(data);
		if (keys[SDL_SCANCODE_D])
			key_d(data);
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			other_keys(data, keys, event);
	}
}
