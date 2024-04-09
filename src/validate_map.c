/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:07:14 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/07 17:16:58 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	border_lastline(t_solong_state *state, int subcounter)
{
	int	counter;

	counter = 0;
	while (counter != state->sl_width)
	{
		if (state->str_map[subcounter] != '1')
			solong_pre_error("Invalid Map");
		counter++;
		subcounter++;
	}
	if (state->sl_height > 150)
		solong_pre_error("Map too big. max 150 x 150 allowed");
	if (state->sl_width > 150)
		solong_pre_error("Map too big. max 150 x 150 allowed");
}

void	border_right(t_solong_state *state)
{
	int	counter;
	int	subcounter;

	counter = 0;
	subcounter = state->sl_width - 1;
	while (counter != state->sl_height)
	{
		if (state->str_map[subcounter] != '1')
			solong_pre_error("Invalid Map");
		counter++;
		if (counter == state->sl_height - 1)
			break ;
		subcounter = subcounter + state->sl_width + 1;
	}
}

void	valid_borders(t_solong_state *state)
{
	int	counter;
	int	subcounter;

	counter = 0;
	subcounter = 0;
	while (counter != state->sl_width)
	{
		if (state->str_map[counter] != '1')
			solong_pre_error("Invalid Map");
		counter++;
	}
	counter = 0;
	while (counter < state->sl_height - 1)
	{
		subcounter = subcounter + state->sl_width + 1;
		if (state->str_map[subcounter] != '1')
			solong_pre_error("Invalid Map");
		counter++;
	}
	border_right(state);
	border_lastline(state, subcounter);
}

void	contains_illegal_values_bonus(t_solong_state *state)
{
	int	counter;

	counter = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] != '1' && state->str_map[counter] != '0'
			&& state->str_map[counter] != 'P' && state->str_map[counter] != 'E'
			&& state->str_map[counter] != 'C'
			&& state->str_map[counter] != '\n'
			&& state->str_map[counter] != 'F')
		{
			solong_pre_error("Invalid Characters");
		}
		counter++;
	}
}

void	validate_map(t_solong_state *state)
{
	int	counter;

	counter = 0;
	if (state->str_map == NULL)
		solong_pre_error("tInvalid Map");
	is_rectangular(state);
	if (contains_value(state, 'P') != 1)
		solong_pre_error("No valid Player");
	if (BONUS == 1)
	{
		state->has_enemys = contains_value(state, 'F');
		if (state->has_enemys > 1)
			solong_pre_error("Too many Enemys. Only 1 allowed");
	}
	if (contains_value(state, 'E') != 1)
		solong_pre_error("No valid Exit");
	if (contains_value(state, 'C') < 1 || contains_value(state, 'C') > 500)
		solong_pre_error("Invalid Collectibles Amount. Min 1, Max 500");
	valid_borders(state);
	if (BONUS == 1)
		contains_illegal_values_bonus(state);
	else
		contains_illegal_values(state);
	if (flood_fill(state, get_start_pos(state)) == 0)
		solong_pre_error("no win possible");
}
