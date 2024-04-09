/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:14:16 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:19:01 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	random_number(void)
{
	return (rand() % 4);
}

void	hit_enemy(t_solong_state *state, int new_pos)
{
	if (state->str_map[new_pos] == 'F' || state->str_map[new_pos] == 'P')
	{
		ft_printf("\n\e[1;95mYou lost\e[0m\n\n");
		usleep(1000000);
		clean_exit(state);
	}
}

void	moves_counter(t_solong_state *state)
{
	char	*num;

	state->moves++;
	num = ft_itoa(state->moves);
	ft_printf("\e[1;37mMoves:\e[0m %d\n", state->moves);
	if (BONUS == 1)
	{
		mlx_delete_image(state->mlx, state->visual_moves_counter);
		state->visual_moves_counter
			= mlx_put_string(state->mlx, num, 50, 30);
	}
	free(num);
}

int	contains_value(t_solong_state *state, char value)
{
	int	counter;
	int	amount;

	counter = 0;
	amount = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == value)
			amount++;
		counter++;
	}
	return (amount);
}

void	is_rectangular(t_solong_state *state)
{
	int	counter;
	int	subcounter;

	counter = 0;
	subcounter = 0;
	while (state->str_map[counter] != '\0')
	{
		if (state->str_map[counter] == '\n')
		{
			if (subcounter != state->sl_width)
				solong_pre_error("Not rectangular Map");
			subcounter = 0;
		}
		else
		{
			subcounter++;
		}
		counter++;
	}
	if (subcounter != state->sl_width)
		solong_pre_error("Not rectangular Map");
}
