/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#define IS_RANGE(x) (x > 0 && x < 100) ? 1 : 0

typedef struct map {
	int row;
	int max_matchs;
	int success;
	int *match;
} map_t;

int is_num(char c);
int my_atoi(char *str);
char *my_strcat(char *buffer, char *ret, int i);
map_t prepare_map(map_t map);

int check_buffer(char *buff);
int my_strlen2(char *str, char c);
char *my_strjoin(char *begin, char *end, int i);
char *get_next_line(int fd);

void error_match(int max_matchs);
void error_line(void);
void print_starts(int nb);
void print_map(map_t map);
void print_void_map(map_t map);

int get_line(map_t map);
int get_matchs(map_t map);

int get_player_input(int input, map_t map);
map_t player_turn(map_t map);
int *get_xor_line(map_t map);
int get_free_line(map_t map);
map_t ai_turn(map_t map);

int is_won(map_t map);
void exit_match(int turn);
void matchstick(map_t map, int turn);
void main_loop(map_t map);
