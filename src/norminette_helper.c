/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:12:41 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/07 15:17:28 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_utils(t_solong_state *state)
{
	moves_counter(state);
	update_map(state);
}

int	is_valid_exit(t_solong_state *state, int old_pos, int new_pos)
{
	if (state->str_map[new_pos] == 'E'
		&& state->collect_counter == state->collect_amount)
	{
		ft_printf("\n\e[1;92mYou won\e[0m\n\n");
		return (1);
	}
	else if (state->str_map[new_pos] == 'E'
		&& state->collect_counter != state->collect_amount)
	{
		ft_printf("You need to collect all collectibles\n");
		state->str_map[old_pos] = '0';
		state->exit_remainder = new_pos;
		state->str_map[new_pos] = 'P';
		return (0);
	}
	if (state->exit_remainder != 0)
	{
		state->str_map[old_pos] = 'E';
		state->exit_remainder = 0;
	}
	else
		state->str_map[old_pos] = '0';
	state->str_map[new_pos] = 'P';
	return (-1);
}

void	contains_illegal_values(t_solong_state *state)
{
	int	counter;

	counter = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] != '1' && state->str_map[counter] != '0'
			&& state->str_map[counter] != 'P' && state->str_map[counter] != 'E'
			&& state->str_map[counter] != 'C'
			&& state->str_map[counter] != '\n')
		{
			solong_pre_error("Invalid Charactersob");
		}
		counter++;
	}
}

void	resize_game_settings(t_solong_state *state)
{
	if (state->has_to_resize == 1)
	{
		mlx_resize_image(state->img_player, state->block_size / 2,
			state->block_size / 2);
		mlx_resize_image(state->img_exit, state->block_size, state->block_size);
		mlx_resize_image(state->img_collectible, state->block_size / 2,
			state->block_size / 2);
		mlx_resize_image(state->img_grass, state->block_size,
			state->block_size);
		mlx_resize_image(state->img_wall, state->block_size, state->block_size);
		mlx_resize_image(state->img_wall_bottom, state->block_size,
			state->block_size);
		mlx_resize_image(state->img_wall_left, state->block_size,
			state->block_size);
	}
}

void	game_settings(t_solong_state *state)
{
	state->img_player = set_img(state, "./textures/player/ghost_50.png");
	if (BONUS == 1)
	{
		state->img_enemy = set_img(state, "./textures/player/ghost_red.png");
		state->img_game_stats = set_img(state,
				"./textures/utilys/realtime_stats_40.png");
		mlx_resize_image(state->img_enemy, state->block_size / 2,
			state->block_size / 2);
		mlx_resize_image(state->img_game_stats, state->window_size,
			state->window_size);
	}
	state->img_exit = set_img(state, "./textures/blocks/exit/portal.png");
	state->img_collectible = set_img(state, "./textures/utilys/coin_50.png");
	state->img_grass = set_img(state, "./textures/blocks/dungeon/floor.png");
	state->img_wall = set_img(state, "./textures/blocks/dungeon/wall.png");
	state->img_wall_bottom = set_img(state,
			"./textures/blocks/dungeon/wall_bottom.png");
	state->img_wall_left = set_img(state,
			"./textures/blocks/dungeon/wall_left.png");
	resize_game_settings(state);
}
