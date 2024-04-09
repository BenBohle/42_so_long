/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:46:44 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/07 16:12:54 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(t_solong_state *state)
{
	int	sl_height_counter;
	int	counter;
	int	switcher;

	counter = 0;
	switcher = 0;
	sl_height_counter = 1;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == '\n')
		{
			sl_height_counter++;
			if (switcher == 0)
			{
				state->sl_width = counter;
				switcher = 1;
			}
		}
		counter++;
	}
	state->sl_height = sl_height_counter;
	return (0);
}

mlx_image_t	*set_img(t_solong_state *state, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		solong_error(state, "texture failed");
	img = mlx_texture_to_image(state->mlx, texture);
	if (!img)
		solong_error(state, "image failed");
	mlx_delete_texture(texture);
	return (img);
}

void	struct_settings(t_solong_state *state)
{
	state->collect_counter = 0;
	state->moves = 0;
	state->exit_remainder = 0;
	state->state_collectible = 0;
	state->block_sl_height = 100;
	state->block_sl_width = 100;
}

void	responsive_handler(t_solong_state *state)
{
	state->has_to_resize = 0;
	state->block_size = 100;
	if (state->sl_width * 100 > 1800)
	{
		state->block_sl_width = 1800 / state->sl_width;
		state->has_to_resize = 1;
	}
	if (state->sl_height * 100 > 1000)
	{
		state->block_sl_height = 1000 / state->sl_height;
		state->has_to_resize = 1;
	}
	if (state->has_to_resize == 1)
	{
		if (state->block_sl_width > state->block_sl_height)
			state->block_size = state->block_sl_height;
		else
			state->block_size = state->block_sl_width;
	}
	state->window_sl_height = state->sl_height * state->block_size;
	state->window_sl_width = state->sl_width * state->block_size;
}

int32_t	start_game(char *map)
{
	t_solong_state	state;

	state.str_map = map;
	if (get_map_size(&state) < 0)
		return (-1);
	validate_map(&state);
	responsive_handler(&state);
	state.mlx = mlx_init(state.window_sl_width, state.window_sl_height,
			"SOOO LONG", false);
	if (!state.mlx)
		solong_error(&state, "initalize failed");
	game_settings(&state);
	struct_settings(&state);
	create_map_pers(&state);
	mlx_close_hook(state.mlx, &window_close_hook, &state);
	mlx_key_hook(state.mlx, &move_keyhook, &state);
	if (BONUS == 1)
		mlx_loop_hook(state.mlx, animation_handler, &state);
	mlx_loop(state.mlx);
	clean_up(&state);
	mlx_terminate(state.mlx);
	return (EXIT_SUCCESS);
}
