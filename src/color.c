/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.point                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:43:54 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/30 13:23:34 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(point *p1, point *p2)
{
	unsigned int color;
	unsigned int color1;

	color = p1->color;
	color1 = p2->color;

	if (color != 0)
		return (color);
	if (color1 != 0)
		return (color1);
	
	if (p1->z > 0 || p2->z > 0)
		return (0x0000FFFF);
	return (WHITE);
}