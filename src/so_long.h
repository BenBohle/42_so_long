/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:43:19 by bbohle            #+#    #+#             */
/*   Updated: 2024/04/07 16:12:03 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_solong_state
{
	char		*str_map;
	int			sl_width;
	int			sl_height;
	mlx_t		*mlx;
	mlx_image_t	*img_grass;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_wall_bottom;
	mlx_image_t	*img_wall_left;
	mlx_image_t	*img_player;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collectible;
	mlx_image_t	*img_enemy;
	mlx_image_t	*img_game_stats;
	int			collect_amount;
	int			collect_counter;
	int			moves;
	char		*flood_map;
	int			collectible_reachable;
	int			found_end;
	int			has_enemys;
	int			exit_remainder;
	int			state_collectible;
	int			has_to_resize;
	int			window_sl_height;
	int			window_sl_width;
	int			window_size;
	int			block_size;
	int			block_sl_width;
	int			block_sl_height;
	mlx_image_t	*visual_moves_counter;
	mlx_image_t	*visual_collect_counter;
}				t_solong_state;

int32_t			main(int argc, char *argv[]);
int32_t			start_game(char *map);

void			responsive_handler(t_solong_state *state);
mlx_image_t		*set_img(t_solong_state *state, char *path);
void			struct_settings(t_solong_state *state);
void			game_settings(t_solong_state *state);
int				get_map_size(t_solong_state *state);

char			*read_map(int argc, char *argv[]);
void			valid_filetype(char *argv);

void			validate_map(t_solong_state *state);
void			contains_illegal_values_bonus(t_solong_state *state);
void			valid_borders(t_solong_state *state);
void			border_right(t_solong_state *state);
void			border_lastline(t_solong_state *state, int subcounter);

int				flood_fill(t_solong_state *state, int start);
void			flood_fill_recursiv(t_solong_state *state, int start, int way);
int				get_start_pos(t_solong_state *state);
int				check_end(t_solong_state *state);
int				zero_rest(t_solong_state *state);

void			create_map_pers(t_solong_state *state);
int				create_map_pers_2(t_solong_state *state, int counter,
					int hcounter, int vcounter);
int				create_map_pers_1(t_solong_state *state, int counter,
					int hcounter, int vcounter);
void			create_map_stats(t_solong_state *state);
int				create_map_enemy(t_solong_state *state, int counter,
					int hcounter, int vcounter);

void			solong_error(t_solong_state *state, char *str);
void			solong_pre_error(char *str);
void			clean_exit(t_solong_state *state);
void			clean_up(t_solong_state *state);
void			clean_up_bonus(t_solong_state *state);

void			update_map(t_solong_state *state);
void			update_collectibles(t_solong_state *state, int pos);
void			update_enemy(t_solong_state *state, int pos);

void			move_keyhook(mlx_key_data_t keydata, void *param);
void			window_close_hook(void *param);

void			move_player_d(t_solong_state *state);
void			move_player_a(t_solong_state *state);
void			move_player_s(t_solong_state *state);
void			move_player_w(t_solong_state *state);
int				is_valid_exit(t_solong_state *state, int old_pos, int new_pos);
void			move_player_utils(t_solong_state *state);
int				is_collectible(t_solong_state *state, int new_pos);

void			animation_handler(void *param);
void			animate_enemy(t_solong_state *state);
void			animate_collectible(t_solong_state *state);

void			is_rectangular(t_solong_state *state);
int				contains_value(t_solong_state *state, char value);
void			moves_counter(t_solong_state *state);
void			hit_enemy(t_solong_state *state, int new_pos);
int				random_number(void);

void			contains_illegal_values(t_solong_state *state);

void			start_message(void);

int				create_map_pers_1_utils(t_solong_state *state, int counter,
					int hcounter, int vcounter);
void			create_map_pers_1_utils_utils(t_solong_state *state,
					int counter, int hcounter, int vcounter);
void			create_map_pers_2_utils(t_solong_state *state, int counter,
					int hcounter, int vcounter);

#endif