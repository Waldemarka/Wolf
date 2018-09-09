  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:44:13 by vomelchu          #+#    #+#             */
/*   Updated: 2018/09/07 18:44:14 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void	skybox(t_data *data) // 7661 972
{
	int start_x;
	int x;
	int y;

	start_x = 0;
	if (data->dir_y <= 0)
		start_x = (int)(WIDTH_SKY / 2 - (data->dir_x / (2 /360.0) * ((double)WIDTH_SKY / 2 / 360.0)));
	else
		start_x = (int)(data->dir_x / (2.0 / 360.0) * ((double)WIDTH_SKY / 2 /360.0));

	x = 0;
	while (x != WIDTH)
	{
		y = 0;
		start_x++;
		while (y != HEIGHT)
		{
			data->buf[y][x] = get_pixel_int(data->sky[data->nbr_sky], start_x, y);
			y++;
		}
		x++;
	}
}
