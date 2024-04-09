/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:24 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/07 15:15:38 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up_bonus(t_solong_state *state)
{
	if (state->img_enemy != NULL)
		mlx_delete_image(state->mlx, state->img_enemy);
	if (state->img_game_stats != NULL)
		mlx_delete_image(state->mlx, state->img_game_stats);
	if (state->visual_collect_counter != NULL)
		mlx_delete_image(state->mlx, state->visual_collect_counter);
	if (state->visual_moves_counter != NULL)
		mlx_delete_image(state->mlx, state->visual_moves_counter);
}

void	clean_up(t_solong_state *state)
{
	if (state != NULL)
	{
		if (state->str_map != NULL)
			free(state->str_map);
		if (state->flood_map != NULL)
			free(state->flood_map);
		if (state->img_grass != NULL)
			mlx_delete_image(state->mlx, state->img_grass);
		if (state->img_wall != NULL)
			mlx_delete_image(state->mlx, state->img_wall);
		if (state->img_wall_bottom != NULL)
			mlx_delete_image(state->mlx, state->img_wall_bottom);
		if (state->img_wall_left != NULL)
			mlx_delete_image(state->mlx, state->img_wall_left);
		if (state->img_player != NULL)
			mlx_delete_image(state->mlx, state->img_player);
		if (state->img_exit != NULL)
			mlx_delete_image(state->mlx, state->img_exit);
		if (state->img_collectible != NULL)
			mlx_delete_image(state->mlx, state->img_collectible);
		if (BONUS == 1)
			clean_up_bonus(state);
	}
}

void	clean_exit(t_solong_state *state)
{
	clean_up(state);
	if (state->mlx != NULL)
		mlx_terminate(state->mlx);
	exit(EXIT_SUCCESS);
}

void	solong_pre_error(char *str)
{
	ft_printf("\e[1;31mError:\e[0m %s\n\n", str);
	exit(EXIT_FAILURE);
}

void	solong_error(t_solong_state *state, char *str)
{
	if (state == NULL)
	{
		ft_printf("\e[1;31m Error:\e[0m %s\n\n", str);
		exit(EXIT_FAILURE);
	}
	ft_printf("\e[1;31m Error:\e[0m %s\n\n", str);
	clean_up(state);
	if (state->mlx != NULL)
		mlx_terminate(state->mlx);
	exit(EXIT_FAILURE);
}
