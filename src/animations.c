/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:29:35 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/03 15:50:03 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_enemy_2(t_solong_state *state, int number, int counter)
{
	if (number == 2)
	{
		if (state->str_map[counter + state->sl_width] == '0'
			|| state->str_map[counter - state->sl_width] == 'P')
		{
			hit_enemy(state, counter + state->sl_width);
			state->str_map[counter + state->sl_width] = 'F';
			state->str_map[counter] = '0';
		}
	}
	if (number == 3)
	{
		if (state->str_map[counter + 1] == '0'
			|| state->str_map[counter + 1] == 'P')
		{
			hit_enemy(state, counter + 1);
			state->str_map[counter + 1] = 'F';
			state->str_map[counter] = '0';
		}
	}
}

void	animate_enemy_1(t_solong_state *state, int number, int counter)
{
	if (number == 0)
	{
		if (state->str_map[counter - state->sl_width] == '0'
			|| state->str_map[counter - state->sl_width] == 'P')
		{
			hit_enemy(state, counter - state->sl_width);
			state->str_map[counter - state->sl_width] = 'F';
			state->str_map[counter] = '0';
		}
	}
	if (number == 1)
	{
		if (state->str_map[counter - 1] == '0'
			|| state->str_map[counter - state->sl_width] == 'P')
		{
			hit_enemy(state, counter - 1);
			state->str_map[counter - 1] = 'F';
			state->str_map[counter] = '0';
		}
	}
}

void	animate_enemy(t_solong_state *state)
{
	int	counter;
	int	number;

	counter = 0;
	number = rand() % 4;
	usleep(200000);
	while (state->str_map[counter] != 'F')
		counter++;
	animate_enemy_1(state, number, counter);
	animate_enemy_2(state, number, counter);
	mlx_delete_image(state->mlx, state->img_enemy);
	state->img_enemy = set_img(state, "./textures/player/ghost_red.png");
	mlx_resize_image(state->img_enemy, state->block_size / 2, state->block_size
		/ 2);
	update_enemy(state, counter);
}

void	animation_handler(void *param)
{
	t_solong_state	*state;

	state = (t_solong_state *)param;
	animate_enemy(state);
}
