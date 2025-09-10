#include "pipex_bonus.h"

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
void here_doc_get_in(char **argv,int *p_fd)
{
  char *line;

  close(p_fd[0]);
  while(1)
  {
    line = get_next_line(0);
    if(ft_strncmp(line,argv[2],ft_strlen(argv[2])) == 0)
    {
      free(line);
      exit(0);
    }
    ft_putstr_fd(line,p_fd[1]);
    free(line);
  }
}

void here_doc(char **argv)
{
  pid_t pid;
  int p_fd[2];

  if(pipe(p_fd) == -1)
  display_error("",1);
  pid = fork();
  if(pid == -1)
  display_error("",1);
  if(pid == 0)
  here_doc_get_in(argv,p_fd);
  else
  {
    close(p_fd[1]);
    dup2(p_fd[0],STDIN_FILENO);
    wait(NULL);
  }
}

void make_pipe(char *cmd,char **env)
{
  pid_t pid;
  int p_fd[2];

  if(pipe(p_fd) == -1)
  display_error("",1);
  pid = fork();
  if(pid == -1)
  display_error("",1);
  if(pid == 0)
  {
    close(p_fd[0]);
    dup2(p_fd[1],STDOUT_FILENO);
    exec(cmd,env);
  }
  else
  {
    close(p_fd[1]);
    dup2(p_fd[0],STDIN_FILENO);
    wait(NULL);  // Wait for the child process
  }
}


int main(int argc,char **argv,char **env)
{
  int i;
  int fd_in;
  int fd_out;

  if(argc < 5)
  display_error("",1);
  if(ft_strcmp(argv[1],"here_doc") == 0)
  {
    if(argc < 6)
     display_error("",1);
    i = 3;
    fd_out = open(argv[argc - 1],2);
    here_doc(argv);
  }
  else
  {
   i = 2;
   fd_in = open_file(argv[1],0);
   fd_out = open_file(argv[argc - 1],1);
   dup2(fd_in,STDIN_FILENO);
  }
  while( i < argc - 2)
    make_pipe(argv[i++],env);
  dup2(fd_out,STDOUT_FILENO);
  exec(argv[argc - 2],env);
}
