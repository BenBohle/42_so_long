/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:27:31 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/04 17:45:19 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map_pers_2_utils(t_solong_state *state, int counter,
		int hcounter, int vcounter)
{
	counter = 0;
	if (mlx_image_to_window(state->mlx, state->img_grass, hcounter
			* state->block_size, vcounter * state->block_size) < 0)
		solong_error(state, "image failed");
	if (mlx_image_to_window(state->mlx, state->img_collectible, hcounter
			* state->block_size + state->block_size / 4, vcounter
			* state->block_size + state->block_size / 4) < 0)
		solong_error(state, "image failed");
}

void	create_map_pers_1_utils_utils(t_solong_state *state,
		int counter, int hcounter, int vcounter)
{
	if (state->str_map[counter + state->sl_width + 1] == '1'
		&& state->str_map[counter + 1] != '1')
	{
		if (mlx_image_to_window(state->mlx, state->img_wall_left, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
	}
	if (state->str_map[counter + state->sl_width + 1] != '1'
		&& state->str_map[counter + 1] != '1')
	{
		if (mlx_image_to_window(state->mlx, state->img_wall_bottom, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
	}
}

int	create_map_pers_1_utils(t_solong_state *state,
		int counter, int hcounter, int vcounter)
{
	int	subcounter;

	subcounter = 0;
	if (state->str_map[counter] == '1')
	{
		if (state->str_map[counter + state->sl_width + 1] == '1'
			&& ft_strlen(state->str_map) > counter + state->sl_width + 1
			&& state->str_map[counter + 1] == '1')
		{
			if (mlx_image_to_window(state->mlx, state->img_wall, hcounter
					* state->block_size, vcounter * state->block_size) < 0)
				solong_error(state, "image failed");
		}
		if ((state->str_map[counter + state->sl_width + 1] != '1'
				&& state->str_map[counter + 1] != '0')
			|| (ft_strlen(state->str_map) < counter + state->sl_width + 1))
		{
			if (mlx_image_to_window(state->mlx, state->img_wall_bottom, hcounter
					* state->block_size, vcounter * state->block_size) < 0)
				solong_error(state, "image failed");
		}
		create_map_pers_1_utils_utils(state, counter, hcounter, vcounter);
		subcounter++;
	}
	return (subcounter);
}
