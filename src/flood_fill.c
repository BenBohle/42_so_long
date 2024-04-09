/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:42:43 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:18:15 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	zero_rest(t_solong_state *state)
{
	int	counter;

	counter = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == '0')
			return (counter);
		counter++;
	}
	return (0);
}

int	check_end(t_solong_state *state)
{
	if (state->found_end == 1
		&& state->collectible_reachable == state->collect_amount)
		return (1);
	return (0);
}

int	get_start_pos(t_solong_state *state)
{
	int	counter;

	counter = 0;
	state->collectible_reachable = 0;
	state->found_end = 0;
	state->collect_amount = contains_value(state, 'C');
	state->flood_map = ft_strdup(state->str_map);
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == 'P')
			return (counter);
		counter++;
	}
	return (0);
}

void	flood_fill_recursiv(t_solong_state *state, int start, int way)
{
	if (start + way >= 0 && start + way < ft_strlen(state->flood_map)
		&& state->flood_map[start + way] != '1'
		&& state->flood_map[start + way] != 'x'
		&& state->flood_map[start + way] != '\n')
	{
		state->flood_map[start] = 'x';
		flood_fill(state, start + way);
	}
	state->flood_map[start] = 'x';
}

int	flood_fill(t_solong_state *state, int start)
{
	if (check_end(state) == 1)
		return (1);
	if (state->flood_map[start] == 'E')
		state->found_end = 1;
	if (state->flood_map[start] == 'C')
		state->collectible_reachable += 1;
	flood_fill_recursiv(state, start, 1);
	flood_fill_recursiv(state, start, -1);
	flood_fill_recursiv(state, start, state->sl_width + 1);
	flood_fill_recursiv(state, start, -state->sl_width - 1);
	if (check_end(state) == 1)
		return (1);
	return (0);
}
