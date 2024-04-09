/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:01 by bbohle            #+#    #+#             */
/*   Updated: 2024/03/25 15:48:32 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_close_hook(void *param)
{
	t_solong_state	*state;

	state = (t_solong_state *)param;
	clean_exit(state);
	exit(EXIT_SUCCESS);
}

void	move_keyhook(mlx_key_data_t keydata, void *param)
{
	t_solong_state	*state;

	state = (t_solong_state *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		move_player_w(state);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		move_player_a(state);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		move_player_s(state);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		move_player_d(state);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		clean_exit(state);
	}
}
