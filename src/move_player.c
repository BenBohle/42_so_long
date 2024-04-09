/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:39:46 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:18:37 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collectible(t_solong_state *state, int new_pos)
{
	char	*str;
	char	*num;

	if (state->str_map[new_pos] == 'C')
	{
		state->collect_counter++;
		ft_printf("\e[1;97mCollectibles:\e[0m %d / %d\n",
			state->collect_counter, state->collect_amount);
		if (BONUS == 1)
		{
			str = ft_itoa(state->collect_counter);
			num = ft_itoa(state->collect_amount);
			str = ft_strjoin(str, " / ");
			str = ft_strjoin(str, num);
			mlx_delete_image(state->mlx, state->visual_collect_counter);
			state->visual_collect_counter = mlx_put_string(state->mlx, str, 50,
					10);
			free(str);
			free(num);
		}
		return (1);
	}
	return (0);
}

void	move_player_w(t_solong_state *state)
{
	int	counter;
	int	position;
	int	length;
	int	exit_status;

	counter = 0;
	position = 0;
	length = state->sl_width + 1;
	while (state->str_map[counter] != 'P')
		counter++;
	position = counter;
	if ((position - length > 0) && (state->str_map[position - length] != '1')
		&& (state->str_map[position - length] != '\n'))
	{
		hit_enemy(state, position - length);
		if (is_collectible(state, position - length) == 1)
			update_collectibles(state, position - length);
		exit_status = is_valid_exit(state, position, position - length);
		if (exit_status == 1)
			clean_exit(state);
		if (exit_status == 0 || exit_status == -1)
			move_player_utils(state);
	}
}

void	move_player_s(t_solong_state *state)
{
	int	counter;
	int	position;
	int	length;
	int	exit_status;

	counter = 0;
	position = 0;
	length = state->sl_width + 1;
	while (state->str_map[counter] != 'P')
		counter++;
	position = counter;
	if ((position + length < ft_strlen(state->str_map))
		&& (state->str_map[position + length] != '1')
		&& (state->str_map[position + length] != '\n'))
	{
		hit_enemy(state, position + length);
		if (is_collectible(state, position + length) == 1)
			update_collectibles(state, position + length);
		exit_status = is_valid_exit(state, position, position + length);
		if (exit_status == 1)
			clean_exit(state);
		if (exit_status == 0 || exit_status == -1)
			move_player_utils(state);
	}
}

void	move_player_a(t_solong_state *state)
{
	int	counter;
	int	position;
	int	exit_status;

	counter = 0;
	position = 0;
	while (state->str_map[counter] != 'P')
		counter++;
	position = counter;
	if (state->str_map[position - 1] != '1'
		&& state->str_map[position - 1] != '\n')
	{
		hit_enemy(state, position - 1);
		if (is_collectible(state, position - 1) == 1)
			update_collectibles(state, position - 1);
		exit_status = is_valid_exit(state, position, position - 1);
		if (exit_status == 1)
			clean_exit(state);
		if (exit_status == 0 || exit_status == -1)
			move_player_utils(state);
	}
}

void	move_player_d(t_solong_state *state)
{
	int	counter;
	int	position;
	int	exit_status;

	counter = 0;
	position = 0;
	while (state->str_map[counter] != 'P')
		counter++;
	position = counter;
	if (state->str_map[position + 1] != '1'
		&& state->str_map[position + 1] != '\n')
	{
		hit_enemy(state, position + 1);
		if (is_collectible(state, position + 1) == 1)
			update_collectibles(state, position + 1);
		exit_status = is_valid_exit(state, position, position + 1);
		if (exit_status == 1)
			clean_exit(state);
		if (exit_status == 0 || exit_status == -1)
			move_player_utils(state);
	}
}
