/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:31:57 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:24:09 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char *argv[])
{
	char	*str_map;

	start_message();
	if (argc != 2)
		solong_error(NULL, "Invalid number of arguments");
	str_map = read_map(argc, argv);
	start_game(str_map);
	return (EXIT_SUCCESS);
}

// static void	leaks(void)
// {
// 	system("leaks so_long");
// }

// int32_t	main(int argc, char *argv[])
// {
// 	char	*str_map;

// 	atexit(leaks);
// 	start_message();
// 	if (argc != 2)
// 		solong_error(NULL, "Invalid number of arguments");
// 	str_map = read_map(argc, argv);
// 	start_game(str_map);
// 	return (EXIT_SUCCESS);
// }
