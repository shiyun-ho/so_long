/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:33:07 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/02/22 21:56:20 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <mlx.h>
#include <math.h>

// Struct to hold both pointers grouped together
typedef struct	s_program
{
	void	*mlx;
	void	*win;
}				t_program;

/**
	Use param for event handlers in MLX
	https://gontjarow.github.io/MiniLibX/mlx-tutorial-event-param.html
 */
int mouse_event(int button, int x, int y, void *param)
{
	// Typecast param to t_program
	t_program	*tutorial;

	tutorial = param;
	
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	
	mlx_pixel_put(tutorial->mlx, tutorial->win, 640/2, 360/2, 0xFFFFFF);

	return (1);
}

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Event Param");

	t_program tutorial_params_event;

	// assign mlx in struct to mlx pointer value
	tutorial_params_event.mlx = mlx;
	tutorial_params_event.win = win;
	
	mlx_mouse_hook(win, &mouse_event, &tutorial_params_event);

	mlx_loop(mlx);
}

/**
	Register event with MLX
 */
// int mouse_event(int button, int x, int y, void *param)
// {
// 	(void)x;
//     (void)y;
//     (void)param;
	
// 	//Whenever event is triggered, print value of button to console
// 	ft_printf("%i\n", button);
// 	return (button);
// }

// int main()
// {
// 	void *mlx;
// 	void *win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "Registering Events");
	
// 	mlx_mouse_hook(win, &mouse_event, 0);
	
// 	(void)mlx;
// 	(void)win;

// 	mlx_loop(mlx);
// }

// int rgb_to_int(double r, double g, double b)
// {
// 	int color;

// 	color = 0;
// 	color |= (int)(b * 255);
// 	color |= (int)(g * 255) << 8;
// 	color |= (int)(r * 255) << 16;

// 	return (color);
// }
/**
	Draw a line
	https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-line.html
 */
// void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	// Get the direction of line
// 	double deltaX = endX - beginX; //10
// 	double deltaY = endY - beginY; //0

// 	// Approximate number of pixels drawn 
// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

// 	deltaX = deltaX / pixels;
// 	deltaY = deltaY / pixels;
	
// 	double pixelX = beginX;
// 	double pixelY = beginY;

// 	while (pixels){
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX = pixelX + deltaX;
// 		pixelY = pixelY + deltaY;
// 		pixels--;
// 	}
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*win;
	
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "Helo World!"); //window init
	
// 	// Draws a DOT in the MIDDLE of window of colour WHITE
// 	draw_line(mlx, win, 500, 500, 0, 0, 0xFFFFFF);

// 	mlx_loop(mlx);
// }

/**
Put a dot in the window
	https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-pixel.html
 */
// int main(void)
// {
// 	void	*mlx;
// 	void	*win;
	
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "Helo World!"); //window init
	
// 	// Draws a DOT in the MIDDLE of window of colour WHITE
// 	mlx_pixel_put(mlx, win, 500/2, 500/2, 0xFFFFFF);

// 	mlx_loop(mlx);
// }