/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:50:57 by vomelchu          #+#    #+#             */
/*   Updated: 2018/08/06 11:51:00 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/wolf.h"

void	init_all(t_data *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error(3);
	if (!(data->win = SDL_CreateWindow("HI", 400, 400, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error(3);
	if (!(data->ren = SDL_CreateRenderer(data->win, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC)))
		ft_error(3);

	data->way_x = -1;
	data->way_y = 0;
}

void 	make_int_array(t_data *data, char **str)
{
	first_ar(data, str);
	check_str(data, str);
	int_malloc(data);
	make_arr(data, str);
}

int 	main(int argc, char *argv[])
{
	int q = 1;

	q = 0;
	if (argc == 2)
	{
		t_data *data;

		if (!(data = (t_data *)malloc(sizeof(t_data))))
			ft_error(0);
		data->name = argv[1];
		make_int_array(data, open_read(data));
		init_all(data);
		data->tex1 = load_img(data->ren, data->bmp, "swirl_effect.bmp");
		applySurface(0,0, data->tex1, data->ren);
		SDL_RenderPresent(data->ren);
		SDL_DestroyTexture(data->tex1);
		SDL_Delay(2000);
		
	}
	else
		ft_error(1);
	return 0;
}

/*void	exiting()
{
	ft_putstr("error\n");
	exit (1);
}

void Slock(SDL_Surface *screen){ 
 if ( SDL_MUSTLOCK(screen) ){ 
   if ( SDL_LockSurface(screen) < 0 ){ 
     return; 
   } 
 } 
} 
void Sulock(SDL_Surface *screen){
 if ( SDL_MUSTLOCK(screen) ){ 
   SDL_UnlockSurface(screen); 
 } 
} 

void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B){ 
 Uint32 color = SDL_MapRGB(screen->format, R, G, B); 
 switch (screen->format->BytesPerPixel){ 
   case 1:  // Assuming 8-bpp 
   { 
     Uint8 *bufp; 
     bufp = (Uint8 *)screen->pixels + y*screen->pitch + x; *bufp = color; 
   } break; 
   case 2: // Probably 15-bpp or 16-bpp 
   { 
     Uint16 *bufp; 
     bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x; *bufp = color; 
   } break; 
   case 3: // Slow 24-bpp mode, usually not used 
   { 
     Uint8 *bufp; 
     bufp = (Uint8 *)screen->pixels + y*screen->pitch + x * 3; 
     if(SDL_BYTEORDER == SDL_LIL_ENDIAN){ 
       bufp[0] = color; 
       bufp[1] = color >> 8; 
       bufp[2] = color >> 16; 
     }else{ 
       bufp[2] = color; 
       bufp[1] = color >> 8; 
       bufp[0] = color >> 16; 
     } 
   } break; 
   case 4: // Probably 32-bpp 
   { 
     Uint32 *bufp; 
     bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x; 
     *bufp = color; 
   } break; 
 } 
}

void	applySurface(int x, int y, SDL_Texture *tex, t_data *data)
{
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	pos.w = 400;
	pos.h = 200;
	//SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(data->ren, tex, NULL, &pos);
}


void	init_all(t_data *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		exiting();
	if (!(data->win = SDL_CreateWindow("HI", 400, 400, 640, 480, SDL_WINDOW_SHOWN)))
		exiting();
	if (!(data->ren = SDL_CreateRenderer(data->win, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC)))
		exiting();
}

int main(int argc, char const *argv[])
{
	printf("%s%d\n", argv[0], argc);
	t_data *data;
	SDL_Texture *text1;
	SDL_Texture *text2;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exiting();
	init_all(data);
	text1 = load_img(data, "swirl_effect.bmp");
	applySurface(0, 0, text1, data);
	text2 = load_img(data, "swirl_effect.bmp");
	applySurface(100, 100, text2, data);
	//SDL_RenderClear(data->ren);
	//SDL_RenderCopy(data->ren, text1, NULL, NULL);

	//SDL_Surface* icon = IMG_Load("icon.png");
	//SDL_SetWindowIcon(window, icon);

	SDL_RenderPresent(data->ren);
	SDL_DestroyTexture(text1);
	SDL_DestroyTexture(text2);
	SDL_Delay(5000);
	 SDL_SetRenderDrawColor(data->ren, 0, 0, 0, 0);
    SDL_RenderClear(data->ren);
	for(int x=0;x<640;x++)
	{ 
			SDL_SetRenderDrawColor(data->ren, x, 0, 0, x);
	   		SDL_RenderDrawPoint(data->ren, x, x); 
 	} 
 	SDL_RenderPresent(data->ren);
 	SDL_Delay(5000);
	SDL_DestroyRenderer(data->ren);
	SDL_DestroyWindow(data->win);
	SDL_Quit();

	return 0;
}
*/