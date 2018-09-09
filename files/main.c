  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:13:20 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/12 11:13:21 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void	init_all(t_data *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(3);
	if (!(data->win = SDL_CreateWindow("Wolf3D", 400, 400, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE)))
		ft_error(3);
	if (!(data->ren = SDL_CreateRenderer(data->win, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC)))
		ft_error(3);
	if (!(data->screen = SDL_CreateTexture(data->ren,
		SDL_PIXELFORMAT_ARGB8888	, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_error(3);
	if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
		ft_error(3);
	data->dir_x = -1.0;
	data->dir_y = 0.0;
	data->plan_x = 0.0;
	data->plan_y = 0.66;
	data->nb_weapon = 1;
	data->max_box = 7;
	data->speed = 0.08;
	data->h = HEIGHT;
	data->w = WIDTH;
	data->key_floor = 1;
	load_media(data);
}

void	ft_read(t_data *data)
{
	char **reading;
	int q;

	q = 0;
	reading = open_read(data);
	first_ar(data, reading);
	check_str(data, reading);
	int_malloc(data);
	make_arr(data, reading);
	check_rest(data);
	while (reading[q])
	{
		free(reading[q]); 
		q++;
	}
	free(reading);
}

void	game(t_data *data)
{
	while (data->for_exit == 0)
	{
		SDL_UpdateTexture(data->screen, NULL, data->buf, WIDTH << 2);
		SDL_RenderCopy(data->ren, data->screen, NULL, NULL);
		SDL_RenderPresent(data->ren);
		if (data->key_floor != 3)
			skybox(data);
		raycasting(data);
		door(data);
		key_event(data);
	}
}

int main(int argc, char *argv[])
{
	t_data *data;  

	if (argc == 2)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			ft_error(1);
		data->name = argv[1];
		ft_read(data);
		init_all(data);
		game(data);
	}
	else
		ft_error(1);
	return 0;
}
