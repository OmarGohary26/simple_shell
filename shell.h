#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* read/write buffers */
#define READ_BUF_SZ 1024
#define WRITE_BUF_SZ 1024
#define BUF_FLSH -1

/* command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* conv_num() */
#define CONV_LOWER 1
#define CONV_UNS 2

/* 1 if using sys getline() */
#define UDE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: field number
 * @str: string input
 * @next: next node pointer
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - has pseudocode arguments to pass to
 * functions, to allow uniform prototype for func pointer struct
 * @arg: a string from getline has arguments
 * @argv: an array of strings from arg
 * @path: string path
 * @argc: argument count
 * @line_cnt: error count
 * @err_num: error code for exit()s
 * @linecnt_flag: flag line count
 * @fname: program filename
 * @env: linked list copy of environ
 * @environ: custom modif copy of environ from LL
 * @hist: the history node
 * @alias: alias node
 * @env_changed: on if env is changed
 * @stat: the return status of last exc cmd
 * @cmd_buf: address of ptr to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type || && ;
 * @readfd: the fd to read line input
 * @hist_cnt: history line number count
*/
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_cnt;
	int err_num;
	int linecnt_flag;
	char *fname;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environ;
	int env_changed;
	int stat;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int hist_cnt;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - has a builtin string and rel func
 * @type: builtin cmd flag
 * @func: function
*/
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* hsh.c */
int hsh(info_t *, char **);
int find_bltin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* err_string_funcs.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string_funcs.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string_funcs2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_funcs3.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* string_funcs4.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* mem_funcs */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* mem_funcs2.c */
int bfree(void **);

/* more_funcs.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* more_funcs2.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_dec(int, int);
char *conv_num(long int, int, int);
void rmv_cmnts(char *);

/* builtin_emulators.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builtin_emulators2.c */
int _myhist(info_t *);
int _myalias(info_t *);

/* get_line.c module */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* info.c module */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* env.c module */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* env2.c module */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* file_io_funcs.c */
char *get_hist_file(info_t *info);
int write_hist(info_t *info);
int read_hist(info_t *info);
int build_hist_list(info_t *info, char *buf, int linecnt);
int renum_hist(info_t *info);

/* list_string.c module */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_indx(list_t **, unsigned int);
void free_list(list_t **);

/* list_string2.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_indx(list_t *, list_t *);

/* chain.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

