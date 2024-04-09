/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:03:31 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/05 00:26:25 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemy(t_solong_state *state, int pos)
{
	int	counter;
	int	hcounter;
	int	vcounter;

	counter = 0;
	hcounter = 0;
	vcounter = 0;
	while (counter != pos)
	{
		if (state->str_map[counter] == '\n')
		{
			hcounter = 0;
			vcounter++;
			counter++;
		}
		hcounter++;
		counter++;
	}
	mlx_image_to_window(state->mlx, state->img_enemy,
		hcounter * state->block_size + state->block_size / 4,
		vcounter * state->block_size + state->block_size / 4);
}

void	update_collectibles(t_solong_state *state, int pos)
{
	int	counter;
	int	hcounter;
	int	vcounter;

	counter = 0;
	hcounter = 0;
	vcounter = 0;
	while (counter != pos)
	{
		if (state->str_map[counter] == '\n')
		{
			hcounter = 0;
			vcounter++;
			counter++;
		}
		hcounter++;
		counter++;
	}
	mlx_image_to_window(state->mlx, state->img_grass,
		hcounter * state->block_size, vcounter * state->block_size);
}

void	proccess_map(t_solong_state *state, int hcounter,
	int vcounter, int counter)
{
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == '\n')
		{
			hcounter = 0;
			vcounter++;
			counter++;
		}
		if (state->str_map[counter] == 'P')
		{
			if (mlx_image_to_window(state->mlx, state->img_player,
					hcounter * state->block_size + state->block_size / 4,
					vcounter * state->block_size + state->block_size / 4) < 0)
				solong_error(state, "image rendering error");
			break ;
		}
		hcounter++;
		counter++;
	}
}

void	update_map(t_solong_state *state)
{
	int	counter;
	int	vcounter;
	int	hcounter;

	counter = 0;
	vcounter = 0;
	hcounter = 0;
	mlx_delete_image(state->mlx, state->img_player);
	state->img_player = set_img(state, "./textures/player/ghost_50.png");
	if (state->has_to_resize == 1)
		mlx_resize_image(state->img_player, state->block_size / 2,
			state->block_size / 2);
	counter = 0;
	proccess_map(state, hcounter, vcounter, counter);
}
