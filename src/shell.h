#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

#define MAX_LINE 1024
#define MAX_ARGS 32
#define MAX_PIPES 32

void init_terminal(void);

int tokenize(char *line, char **argv);

int run_pipeline(char ***cmds, int ncmds); // triple pointer because its an array of args

int run_command(char **argv);

#endif
