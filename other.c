/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 18:15:35 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/09 18:15:38 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/wolf.h"

void 	ft_error(int num)
{
	if (num == 0)
		ft_putstr("BAD MALLOC!\n");
	if (num == 1)
		ft_putstr("1 ARGC / NOT DIRECTORY \n");
	if (num == 2)
		ft_putstr("BAD READ / NOT VALID MAP\n");
	if (num == 3)
		ft_putstr("INIT ERROR\n");
	if (num == 4)
		ft_putstr("BAD LOAD\n");
	if (num == 5)
		ft_putstr("FINISH\n");
	exit (1);
}

int 	len_int(char *str)
{
	int q;
	int i;

	q = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[q])
	{
		if (str[q] <= '9' && str[q] >= '0')
		{
			while (str[q] <= '9' && str[q] >= '0')
				q++;
			i++;
			q--;
		}
		q++;
	}
	return (i);
}

void	check_rest(t_data *data)
{
	int q;

	q = -1;
	while (++q != data->width_arr)
		if (data->array[0][q] != 1 || data->array[data->height_arr - 1][q] != 1)
			ft_error(1);
	q = -1;
	while (++q != data->height_arr)
		if (data->array[q][0] != 1 || data->array[q][data->width_arr - 1] != 1)
			ft_error(1);
	if (data->array[(int)data->pos_y][(int)data->pos_x] != 0)
		ft_error(1);
	if ((int)data->pos_y == 0 || (int)data->pos_y == 1 ||
		(int)data->pos_y == data->height_arr - 1 || (int)data->pos_y == data->height_arr - 2)
		ft_error(1);
	if ((int)data->pos_x == 0 || (int)data->pos_x == 1 ||
		(int)data->pos_x == data->width_arr - 1 || (int)data->pos_x == data->width_arr - 2)
		ft_error(1);
}

void	load_texture(t_data *data)
{
	data->up = load_image("texture/upper.png");
	data->floor = load_image("texture/flor.jpg");
	data->wall[0] = load_image("texture/wall1.jpg");
	data->wall[1] = load_image("texture/wall2.jpg");
	data->wall[2] = load_image("texture/wall3.jpg");
	data->wall[3] = load_image("texture/wall4.jpg");
	data->pist[0] = load_image("texture/guns/pist1.png");
	data->pist[1] = load_image("texture/guns/pist2.png");
	data->pist[2]= load_image("texture/guns/pist3.png");
	data->drob[0] = load_image("texture/guns/drob1.png");
	data->drob[1] = load_image("texture/guns/drob2.png");
	data->drob[2] = load_image("texture/guns/drob3.png");
	data->drob[3] = load_image("texture/guns/drob4.png");
	data->drob[4] = load_image("texture/guns/drob5.png");
	data->drob[5] = load_image("texture/guns/drob6.png");
	data->drob[6] = load_image("texture/guns/drob7.png");
}






/*

# include "includes/wolf.h"

void	put_buf(t_data *data, int x, int y, SDL_Surface *textu)
{
	if (get_pixel_int(textu, data->sprite_tex_x, data->sprite_tex_y) != 0)
	{
		data->buf[y][x] = get_pixel_int(textu, data->sprite_tex_x, data->sprite_tex_y);
		data->buf[y + 1][x] = get_pixel_int(textu, data->sprite_tex_x, data->sprite_tex_y);
		data->buf[y][x + 1] = get_pixel_int(textu, data->sprite_tex_x, data->sprite_tex_y);
		data->buf[y + 1][x + 1] = get_pixel_int(textu, data->sprite_tex_x, data->sprite_tex_y);
	}
}

void	draw_splits(t_data *data, SDL_Surface *textu)
{
	int x;
	int y;

	x = data->sprit.min_coord_x;
	data->spr_x = 1;
	while (x < data->sprit.max_coord_x)
	{
		y = data->sprit.min_coord_y;
		data->spr_y = 1;
		while (y < data->sprit.max_coord_y)
		{
			data->sprite_tex_x = data->sprit.pixel_wid + data->spr_x;
			data->sprite_tex_y = data->sprit.pixel_wid + data->spr_y;
			put_buf(data, x, y, textu);
			data->spr_y++;
			y += 2;
		}
		data->spr_x++;
		x += 2;
	}
}

void	check_sprite(t_data *data)
{
	if (data->nb_weapon == 1)
	{
		data->sprit.iterat = 1;
		data->sprit.pixel_wid = 100;
		data->now = data->pist[data->q];
	}
	else if (data->nb_weapon == 2)
	{
		data->sprit.pixel_wid = 180;
		data->sprit.iterat = 6;
		data->now = data->drob[data->q];
	}
	data->sprit.timing = 50;
	data->sprit.min_coord_x = WIDTH - data->sprit.pixel_wid * 2;
	data->sprit.min_coord_y = HEIGHT - data->sprit.pixel_wid * 2;
	data->sprit.max_coord_x = WIDTH;
	data->sprit.max_coord_y = HEIGHT;
}

void	sprite_fire(t_data *data)
{
	data->time = SDL_GetTicks();
	data->check = data->q;
	if (data->key_space == 1)
	{
		check_sprite(data);
		if (data->time <= data->start_time + (data->sprit.timing * (data->q)))
		{
			draw_splits(data, data->now);
		}
		if (data->time >= data->start_time + (data->sprit.timing * (data->q)))
			data->q++;
		if (data->q > data->sprit.iterat)
		{
			data->q = 0;
			data->key_space = 0;
		}
	}
	if (data->key_space == 0)
		data->q = 0;
}

void	hands(t_data *data)
{
	if (data->nb_weapon == 1)
	{
		data->sprit.pixel_wid = 100;
		data->now = data->pist[0];
	}
	else if (data->nb_weapon == 2)
	{
		data->sprit.pixel_wid = 180;
		data->now = data->drob[0];
	}
	if (data->key_space == 0)
	{
		data->sprit.min_coord_x = WIDTH - data->sprit.pixel_wid;
		data->sprit.min_coord_y = HEIGHT - data->sprit.pixel_wid;
		data->sprit.max_coord_x = WIDTH;
		data->sprit.max_coord_y = HEIGHT;
		draw_splits(data, data->now);
	}
}

void	sprites(t_data *data)
{
	hands(data);
 	sprite_fire(data);

}




*/







