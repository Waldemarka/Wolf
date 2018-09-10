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

# include "wolf.h"

void	key_s(t_data *data)
{
	if (data->array[(int)(POS_Y)][(int)(POS_X
		- DIR_X * data->speed)] == 0)
			POS_X -= DIR_X * data->speed;
	if (data->array[(int)(POS_Y - DIR_Y
		* data->speed)][(int)(POS_X)] == 0)
			POS_Y -= DIR_Y * data->speed;
}

void	key_w(t_data *data)
{
	if (data->array[(int)(POS_Y)][(int)(POS_X
		+ DIR_X * data->speed)] == 0)
			POS_X += DIR_X * data->speed;
	if (data->array[(int)(POS_Y + DIR_Y
		* data->speed)][(int)(POS_X)] == 0)
			POS_Y += DIR_Y * data->speed;
}

void	key_a(t_data *data)
{
	float dirx;
	float diry;

	dirx = DIR_X * cos(1.55) - DIR_Y * sin(1.55);
	diry = DIR_X * sin(1.55) + DIR_Y * cos(1.55);
	if (data->array[(int)(POS_Y)][(int)(POS_X
		+ dirx * data->speed)] == 0)
			POS_X += dirx * data->speed;
	if (data->array[(int)(POS_Y + diry * data->speed)]
		[(int)(POS_X)] == 0)
			POS_Y += diry * data->speed;

}

void	key_d(t_data *data)
{
	float dirx;
	float diry;

	dirx = DIR_X * cos(-1.55) - DIR_Y * sin(-1.55);
	diry = DIR_X * sin(-1.55) + DIR_Y * cos(-1.55);
	if (data->array[(int)(POS_Y)][(int)(POS_X
		+ dirx * data->speed)] == 0)
			POS_X += dirx * data->speed;
	if (data->array[(int)(POS_Y + diry
		* data->speed)][(int)(POS_X)] == 0)
			POS_Y += diry * data->speed;
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
			other_keys(data, keys);
	}
}
