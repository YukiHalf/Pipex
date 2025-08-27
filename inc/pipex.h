#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open_file(char *file ,bool In_Out);
char *filter_env(char **env);
char *get_path(char *cmd,char **env);
void exec(char *cmd,char **env);
#endif
