
#include "../inc/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		free2d(s_cmd);
		display_error("Command not found", 1);
	}
}

void	ParentProcess(char **argv, int *fd_main, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	if (fd < 0)
		display_error("Open failed", 1);
	dup2(fd, STDOUT_FILENO);
	dup2(fd_main[0], STDIN_FILENO);
	close(fd_main[1]);
	exec(argv[3], env);
}

void	ChildProcess(char **argv, int *fd_main, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	if (fd < 0)
		display_error("Open failed", 1);
	dup2(fd, STDIN_FILENO);
	dup2(fd_main[1], STDOUT_FILENO);
	close(fd_main[0]);
	exec(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_main[2];
	pid_t	pid;

	if (argc != 5)
		display_error("Format not good", 1);
	if (pipe(fd_main) == -1)
		display_error("", 1);
	pid = fork();
	if (pid == -1)
		display_error("", 1);
	if (pid == 0)
		ChildProcess(argv, fd_main, env);
	else
	{
		ParentProcess(argv, fd_main, env);
		waitpid(pid, NULL, 0);
	}
}
