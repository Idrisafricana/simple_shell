#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024
#define MAX_CMD_LENGTH 128

extern char **environ;

void display_prompt(void);
void shell_print(const char *string);
int input_command(char *command, size_t size);
void exec_command(const char *cmd);
void exit_shell(void);
void print_env(void);
int token_command(const char *cmd, char *args[]);
size_t parse_args(const char *cmd, char *args[], size_t max_args);
int build_full_path(const char *command, char *full_path);
void execute_child(char *args[], const char *cmd);

#endif /**SHELL_H*/
