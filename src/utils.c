#include "../inc/pipex.h"

int	open_file(char *file, bool In_Out)
{
	int	bytes;

	if (In_Out == 0)
		bytes = open(file, O_RDONLY, 0777);
	if (In_Out == 1)
		bytes = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (bytes == -1)
		display_error("", 1);
	return (bytes);
}

char	*filter_env(char **env)
{
	int		i;
	int		j;
	char	*env_box;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		env_box = ft_substr(env[i], 0, j);
		if (ft_strcmp("PATH", env_box) == 0)
		{
			free(env_box);
			return (env[i] + j + 1);
		}
		free(env_box);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	**s_cmd;
	char	*check_path;
	char	*exec;

	path = ft_split(filter_env(env), ':');
	s_cmd = ft_split(cmd, ' ');
	i = -1;
	while (path[++i])
	{
		check_path = ft_strjoin(path[i], "/");
		exec = ft_strjoin(check_path, s_cmd[0]);
		free(check_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free2d(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free2d(s_cmd);
	free2d(path);
	return (cmd);
}
