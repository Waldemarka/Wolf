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
	system("leaks wolf");
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
	data->up = load_image("texture/walls_etc/upper.png");
	data->floor = load_image("texture/walls_etc/flor.jpg");
	data->wall[0] = load_image("texture/walls_etc/wall1.jpg");
	data->wall[1] = load_image("texture/walls_etc/wall2.jpg");
	data->wall[2] = load_image("texture/walls_etc/wall3.jpg");
	data->wall[3] = load_image("texture/walls_etc/wall4.jpg");
	data->wall[4] = load_image("texture/door/door_1.png");
	data->wall[5] = load_image("texture/door/door_2.png");
	data->wall[6] = load_image("texture/door/door_3.png");
	data->wall[7] = load_image("texture/door/door_4.png");
	data->wall[8] = load_image("texture/door/door_5.png");
	data->wall[9] = load_image("texture/door/door_6.png");
	data->wall[10] = load_image("texture/door/door_7.png");
	data->wall[11] = load_image("texture/door/door_8.png");
	data->wall[12] = load_image("texture/door/door_9.png");
	data->pist[0] = load_image("texture/guns/pist1.png");
	data->pist[1] = load_image("texture/guns/pist2.png");
	data->pist[2] = load_image("texture/guns/pist3.png");
	data->drob[0] = load_image("texture/guns/drob1.png");
	data->drob[1] = load_image("texture/guns/drob2.png");
	data->drob[2] = load_image("texture/guns/drob3.png");
	data->drob[3] = load_image("texture/guns/drob4.png");
	data->drob[4] = load_image("texture/guns/drob5.png");
	data->drob[5] = load_image("texture/guns/drob6.png");
	data->drob[6] = load_image("texture/guns/drob7.png");
}
