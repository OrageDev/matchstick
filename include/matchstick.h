/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

typedef struct map {
	int row;
	int max_matches;
	int success;
	int turn;
	int *match;
} map_t;

/* get_player.c :
** stdlib | unistd | my | gnl | matchstick
*/

int get_line(void);
int get_matches(void);
void get_player_turn(map_t *map);

/* get_ai.c
** unistd | matchstick
*/

void ai_turn(map_t *map);

/* utilities.c :
** stdlib | unistd | my | matchstick
*/

void print_stars(int stars);
void print_map(map_t *map);
void prepare_map(map_t *map, char **av);

/* main.c
** sys/types | fcntl | sys/stat | stdlib | unistd | my | gnl | matchstick
*/

void sub_matches(map_t *map, int line, int matches);
void matchstick(map_t *map);
