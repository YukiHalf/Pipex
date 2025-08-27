
#include "../inc/pipex.h"

void exec(char *cmd,char **env)
{
  char **s_cmd;
  char *path;
  s_cmd = ft_split(cmd,' ');
  path = get_path(s_cmd[0],env);
  if(execve(path,s_cmd,env) == -1)
  {
    free2d(s_cmd);
    display_error("Command not found",1);
  }
}


void ParentProcess(char **argv,int *fd_m,char **env)
{
  int fd;
  fd = open(argv[4],O_RDONLY);
  if(fd < 0)
  display_error("Open failed",1);
  dup2(fd,STDIN_FILENO);
  dup2(fd_m[1],STDOUT_FILENO);
  close(fd_m[0]);
  exec(argv[3],env);
}


void ChildProcess(char **argv,int *fd_m,char **env)
{
  int fd;
  fd = open(argv[1],O_RDONLY);
  if(fd < 0)
  display_error("Open failed",1);
  dup2(fd,STDIN_FILENO);
  dup2(fd_m[1],STDOUT_FILENO);
  close(fd_m[0]);
  exec(argv[2],env);
}


int main(int argc, char **argv, char **env)
{
  int fd_m[2];
  pid_t pid;

  if(argc != 5)
    display_error("Format not good",1);
  if(pipe(fd_m) == -1)
    display_error("",1);
  pid = fork();
  if(pid == -1)
    display_error("",1);
  if(pid == 0)
    ChildProcess(argv,fd_m,env);
  else
  ParrentProcess(argv,fd_m,env);
}



