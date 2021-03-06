/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:26:54 by jsivanes          #+#    #+#             */
/*   Updated: 2017/03/14 18:27:23 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_julia2(t_var *var)
{
	if (!ft_strcmp(FRACTOL, "julia"))
	{
		CR = 0.285 + V;
		CI = V ? 0.01 / V * V : 0.01;
	}
	else
	{
		CR = 0.3 + V;
		CI = V ? 0.5 / V * V : 0.5;
	}
	ZR = ((ZOOM ? ZOOM : 1) + X - NX) / ZOOM_X + X1;
	ZI = ((ZOOM ? ZOOM : 1) + Y - NY) / ZOOM_Y + Y1;
	I = -1;
	while ((ZR * ZR + ZI * ZI) < 4 && ++I < I_MAX)
	{
		TMP_D = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * TMP_D + CI;
	}
	if (I == I_MAX)
		put_pixel(var, BLACK);
	else
		put_pixel(var, M_COLOR ? (I * COLOR / I_MAX) : I * COLOR);
}

void			ft_julia(t_var *var)
{
	X1 = -1 + POS_X;
	X2 = 1 + POS_X;
	Y1 = -1.2 + POS_Y;
	Y2 = 1.2 + POS_Y;
	I_MAX = IM + 150;
	ZOOM_X = (WIDTH_WIN / (X2 - X1) + (ZOOM ? ZOOM : 1));
	ZOOM_Y = (HEIGHT_WIN / (Y2 - Y1) + (ZOOM ? ZOOM : 1));
	X = -1;
	while (++X < WIDTH_WIN)
	{
		Y = -1;
		while (++Y < HEIGHT_WIN)
			ft_julia2(var);
	}
}
