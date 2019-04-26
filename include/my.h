/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

void my_putchar(char c);
void my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(char *a, char *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
void my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
void my_show_word_array(char *const *tab);
char *my_strconcat(char *str1, char *str2);
char *int_to_char(int number);
char *number_in_array(char *str, int value);
char *get_next_line(int fd);
int check_exit(char *input);
int check_commands(char *input, char **env);
int my_cd(char *input);
void display_env(char **env);
int my_printf(char *arg1, ...);
int my_setenv(char *input, char **env);
int my_exec(char *input, char **env);
char **create_env(char **env);
char *counter_file(char *input);
int my_unsetenv(char *input, char **env);
int find_env_var(char *input, char **env, int j);
int my_pwd(void);
int find_char(char *input, int i, char c);
int count_semicolon(char *input);
int check_sep(char *input, char **env);
int compare_args(char *input, char *str);
void my_ls(char *input, char **env);
char **argv_in_double_array(char *input);
int exec_command(char *input, char **env);
void command_not_found(char *str);
void permission_denied(char *str);
void my_error(char *str);
void delete_spaces(char *str, char *dest);
char *transform_input(int i, char *input, char sep, char *str);
int find_right_redirect(char *input);
int right_redir(char *input, char **env);
int redirections(char **env, char *input);
void check_double_malloc(char **str);
int pipes(char **env, char *input);
void pipe_func(char **env, char *str, char *str2);
int check_alphanum(char *input);
int find_equal(char *name);
void free_assets(char **my_env, char *input);
void free_double_array(char **array);
int left_redir(char **env, char *input);
char **create_args(char *input, char c);
int find_left_redirect(char *input);
void error_message(char *first_name, char *message);
char **path_double_array(char *input);