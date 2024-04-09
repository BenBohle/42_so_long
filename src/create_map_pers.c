/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_pers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:30:42 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:17:17 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_map_enemy(t_solong_state *state, int counter, int hcounter,
		int vcounter)
{
	int	subcounter;

	subcounter = 0;
	if (state->str_map[counter] == 'F')
	{
		if (mlx_image_to_window(state->mlx, state->img_grass, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
		if (mlx_image_to_window(state->mlx, state->img_enemy, hcounter
				* state->block_size + state->block_size / 4, vcounter
				* state->block_size + state->block_size / 4) < 0)
			solong_error(state, "image failed");
		subcounter++;
	}
	return (subcounter);
}

void	create_map_stats(t_solong_state *state)
{
	char	*str;
	char	*num;

	if (mlx_image_to_window(state->mlx, state->img_game_stats, 5, 5) < 0)
		solong_error(state, "image failed");
	num = ft_itoa(state->collect_amount);
	str = strdup("0 / ");
	str = ft_strjoin(str, num);
	state->visual_collect_counter = mlx_put_string(state->mlx, str, 50, 10);
	free(str);
	free(num);
	state->visual_moves_counter = mlx_put_string(state->mlx, "0", 50, 30);
}

int	create_map_pers_1(t_solong_state *state, int counter, int hcounter,
	int vcounter)
{
	int	subcounter;

	subcounter = 0;
	if (state->str_map[counter] == '0')
	{
		if (mlx_image_to_window(state->mlx, state->img_grass, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
		subcounter++;
	}
	subcounter += create_map_pers_1_utils(state, counter, hcounter, vcounter);
	if (state->str_map[counter] == 'P')
	{
		if (mlx_image_to_window(state->mlx, state->img_grass, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
		if (mlx_image_to_window(state->mlx, state->img_player, hcounter
				* state->block_size + state->block_size / 4, vcounter
				* state->block_size + state->block_size / 4) < 0)
			solong_error(state, "image failed");
		subcounter++;
	}
	return (subcounter);
}

int	create_map_pers_2(t_solong_state *state, int counter, int hcounter,
		int vcounter)
{
	int	subcounter;

	subcounter = 0;
	if (state->str_map[counter] == 'E')
	{
		if (mlx_image_to_window(state->mlx, state->img_grass, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
		if (mlx_image_to_window(state->mlx, state->img_exit, hcounter
				* state->block_size, vcounter * state->block_size) < 0)
			solong_error(state, "image failed");
		subcounter++;
	}
	if (state->str_map[counter] == 'C')
	{
		create_map_pers_2_utils(state, counter, hcounter, vcounter);
		subcounter++;
	}
	if (BONUS == 1)
		subcounter += create_map_enemy(state, counter, hcounter, vcounter);
	return (subcounter);
}

void	create_map_pers(t_solong_state *state)
{
	int	counter;
	int	vcounter;
	int	hcounter;

	counter = 0;
	vcounter = 0;
	hcounter = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == '\n')
		{
			hcounter = 0;
			vcounter++;
			counter++;
		}
		if (BONUS == 1)
			create_map_stats(state);
		hcounter += create_map_pers_1(state, counter, hcounter, vcounter);
		hcounter += create_map_pers_2(state, counter, hcounter, vcounter);
		counter++;
	}
}
