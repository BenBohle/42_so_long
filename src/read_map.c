/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:53:09 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/09 18:19:29 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_filetype(char *argv)
{
	int	counter;
	int	switcher;

	counter = 0;
	switcher = 0;
	while (argv[counter] != '\0')
	{
		counter++;
	}
	if (argv[counter - 4] != '.' || argv[counter - 3] != 'b'
		|| argv[counter - 2] != 'e' || argv[counter - 1] != 'r')
	{
		solong_pre_error("Invalid file type");
	}
}

char	*read_map(int argc, char *argv[])
{
	char	*str_map;
	char	tmp[2];
	int		rb_fd[2];

	str_map = NULL;
	if (argc != 2)
		solong_pre_error("Invalid number of arguments");
	rb_fd[0] = 1;
	valid_filetype(argv[1]);
	rb_fd[1] = open(argv[1], O_RDONLY);
	if (rb_fd[1] < 0)
		solong_pre_error("Cant open file");
	while (rb_fd[0] > 0)
	{
		rb_fd[0] = read(rb_fd[1], tmp, 1);
		if (rb_fd[0] > 0)
			tmp[rb_fd[0]] = '\0';
		if (str_map == NULL && rb_fd[0] > 0)
			str_map = ft_strdup(tmp);
		else if (str_map != NULL && rb_fd[0] > 0)
			str_map = ft_strjoin(str_map, tmp);
	}
	return (str_map);
}
