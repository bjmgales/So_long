/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:53:59 by bgales            #+#    #+#             */
/*   Updated: 2023/04/28 19:17:23 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <mlx.h>
# include "ft_printf.h"

typedef struct s_chars {
	int	p;
	int	c;
	int	e;
	int	line;
	int	i;
}	t_chars;

struct s_game
{
	char	**map;
	void	*p;
	void	*item;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*soft;
	void	*win;
	int		width;
	int		height;
	int		map_h;
	int		map_w;
	int		c_nbr;
	int		c_mv;
};
typedef struct s_game	t_game;

/**
@brief Reads a map file and returns a 2D array of characters
representing the game board.
 *
@param map_path Path to the map file to read.
@param game_ptr Pointer to a t_game struct containing game information.
 *
@return A 2D array of characters representing the game board.
 */
char **get_map(const char *map_path, t_game *game_ptr);

/**
@brief Loads game textures from XPM files.
 *
@param game_ptr Pointer to a t_game struct containing game information.
 */
void load_texture(t_game *game_ptr);

/**
@brief Counts the number of items (C) on the game board.
 *
@param game_ptr Pointer to a t_game struct containing game information.
 *
@return The number of items on the game board.
 */
int		item_nb(t_game *game_ptr);

/**
@brief Moves the player on the game board based on user input.
 *
@param key The key that was pressed to trigger the movement.
@param g Pointer to a t_game struct containing game information.
 *
@return 1 if the move was successful, 0 otherwise.
 */
int move_player(int key, t_game *g);

/**
@brief Initializes game information, starts the game loop, and opens the game window.
 *
@param map_path Path to the map file to use for the game.
 */
void so_long(const char *map_path);

/**

@brief Check if the given map file has a valid ".ber" extension.
@param map The name of the file to check.
*/
void ber_check(const char *map);
/**

@brief The main function of the program.
@param argc The number of arguments passed to the program.
@param argv An array of strings containing the arguments.
@return An integer value indicating the success of the program.
*/
int main(int argc, char **argv);
/**

@brief Prints the given string to the standard output and exits the program.
@param str The string to print.
*/
void print_and_exit(char *str);
/**

@brief Removes the newline character from the end of the given string.
@param str The string to modify.
*/
void del_nl(char *str);
/**

@brief Prints the map of the game to the screen.
@param game_ptr A pointer to the game structure.
*/
void print_map(t_game game_ptr);
/**

@brief Checks if the map of the game has the correct number of players, exits, and collectibles.
@param game_ptr A pointer to the game structure.
*/
void pce_check(t_game *game_ptr);
/**

@brief Checks if the map of the game is valid.
@param game_ptr A pointer to the game structure.
*/
void check_map(t_game *game_ptr);
/**

@brief Ends the game by destroying the window and printing a message to the standard output.
@param g A pointer to the game structure.
@return An integer value indicating the success of the program.
*/
int endgame(t_game *g);
/**

@brief Moves the player one tile to the right.
@param g A pointer to the game structure.
@param key The input key from user
@return An integer value indicating the success of the move.
*/
int move_right(t_game *g, int key);
/**

@brief Moves the player one tile to the left.
@param g A pointer to the game structure.
@param key The input key from user
@return An integer value indicating the success of the move.
*/
int move_left(t_game *g, int key);
/**

@brief Moves the player one tile up.
@param g A pointer to the game structure.
@param key The input key from user
@return An integer value indicating the success of the move.
*/
int move_up(t_game *g, int key);
/**

@brief Moves the player one tile down.
@param g A pointer to the game structure.
@param key The input key from user
@return An integer value indicating the success of the move.
*/
int move_down(t_game *g, int key);

/**
@brief Print the move count and update it
 *
@param key The input key from user
@param g A pointer to the t_game struct
 */
void	print_move(int key, t_game *g);

/**
@brief Move the player one tile to the right
 *
@param g A pointer to the t_game struct
@param l The row index of the player
@param i The column index of the player
@param key The input key from user
 */
void	move_right_norm(t_game *g, int l, int i, int key);

/**
@brief Move the player one tile to the left
 *
@param g A pointer to the t_game struct
@param l The row index of the player
@param i The column index of the player
@param key The input key from user
 */
void	move_left_norm(t_game *g, int l, int i, int key);

/**
@brief Move the player one tile up
 *
@param g A pointer to the t_game struct
@param l The row index of the player
@param i The column index of the player
@param key The input key from user
 */
void	move_up_norm(t_game *g, int l, int i, int key);

/**
@brief Move the player one tile down
 *
@param g A pointer to the t_game struct
@param l The row index of the player
@param i The column index of the player
@param key The input key from user
 */
void	move_down_norm(t_game *g, int l, int i, int key);

/**
@brief Get the number of rows in the map
 *
@param map_path The path to the map file
@return The number of rows in the map
 */
int		get_y(const char *map_path);

/**

@brief Initializes a t_chars struct with default values.
This function sets the fields of the t_chars struct pointed to by z to their
default values. The fields that are set are: p, c, e, i, and line.
@param z A pointer to a t_chars struct to be initialized.
@return This function does not return a value.
*/
void	ft_init(t_chars *z);
#endif
