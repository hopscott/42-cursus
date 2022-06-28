
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_cmdl
{
	char			*cmd;
	char			**args;
	int				pid;
	struct s_cmdl	*next;
}					t_cmdl;

// ==================================

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;
	int		len_src;

	len_src = ft_strlen(src);
	dst = malloc(sizeof(char) * (len_src + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 1;
	while ((i < n) && str1[i - 1] && str2[i - 1])
	{
		if (str1[i - 1] != str2[i - 1])
			return (str1[i - 1] - str2[i - 1]);
		i++;
	}
	return (str1[i - 1] - str2[i - 1]);
}

// ==================================

char	**ft_freetbl(char **tbl, int pos)
{
	int	free_ptr;

	free_ptr = 1;
	if (pos == -2)
		free_ptr = 0;
	if (pos < 0)
	{
		pos = 0;
		while (tbl && tbl[pos])
			pos++;
	}
	while (pos >= 0)
	{
		if (tbl[pos])
			free(tbl[pos]);
		pos--;
	}
	if (free_ptr)
		free(tbl);
	return (0);
}

int	ft_wordcount(char *str, char c)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	while (str && str[i])
	{
		while ((c == str[i]) && str[i])
			i++;
		if ((c != str[i]) && str[i])
			wrd++;
		while ((c != str[i]) && str[i])
			i++;
	}
	return (wrd);
}

int	ft_wordlen(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && (c == str[i]))
		i++;
	while (str[i] && (c != str[i]))
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_fillelem(char *s, char c, int i, char *elm)
{
	int	j;

	j = 0;
	while ((c != s[i]) && s[i])
		elm[j++] = s[i++];
	elm[j] = '\0';
	return (elm);
}

char	**ft_split(char *s, char c)
{
	char	**tbl;
	char	*elem;
	int		i;
	int		x;

	if (!s)
		return (0);
	tbl = malloc((ft_wordcount(s, c) + 1) * sizeof(tbl));
	if (!tbl)
		return (0);
	i = 0;
	x = 0;
	while (s[i] && (ft_wordlen(&s[i], c) != 0))
	{
		while ((c == s[i]) && s[i])
			i++;
		elem = malloc((ft_wordlen(&s[i], c) + 1) * sizeof(elem));
		if (!elem)
			return (ft_freetbl(tbl, x));
		tbl[x++] = ft_fillelem(s, c, i, elem);
		while ((c != s[i]) && s[i])
			i++;
	}
	tbl[x] = 0;
	return (tbl);
}

// ==================================

int	env_findkeypos(char *key, char **env)
{
	char	**tbl;
	char	*str;
	int		i;

	i = 0;
	while (env && env[i])
	{
		tbl = ft_split(env[i], '=');
		str = tbl[0];
		if (ft_strncmp(str, key, ft_strlen(key)) == 0
			&& ft_strlen(key) == ft_strlen(str))
		{
			ft_freetbl(tbl, -1);
			return (i);
		}
		ft_freetbl(tbl, -1);
		i++;
	}
	return (-1);
}

char	*env_findkeyvalue(char *key, char **env)
{
	int		i;
	char	**tbl;
	char	*val;

	i = env_findkeypos(key, env);
	if (i == -1)
		return (NULL);
	tbl = ft_split(env[i], '=');
	val = ft_strdup(tbl[1]);
	ft_freetbl(tbl, -1);
	return (val);
}


void	cmd_pathfinder(char **pcmd, char **env)
{
	char	*cmd;
	char	**paths;
	char	*env_path;
	char	*cmd_path;
	size_t	i;

	env_path = env_findkeyvalue("PATH", env);
	if (*pcmd && env_path)
	{
		cmd = ft_strjoin("/", (*pcmd));
		paths = ft_split(env_path, ':');
		i = 0;
		*pcmd = NULL;
		while (paths && paths[i])
		{
			cmd_path = ft_strjoin(paths[i], cmd);
			if (access(cmd_path, F_OK) == 0)
			{
				*pcmd = cmd_path;
				break ;
			}
			free(cmd_path);
			i++;
		}
		free(cmd);
		ft_freetbl(paths, -1);
	}
	free(env_path);
}

// ==================================

t_cmdl	*ft_cmdlnew(char *str, char **env)
{
	char	**tbl;
	char	*cmd;
	char	*flags;
	t_cmdl	*cmdl;
	t_cmdl	**args;

	tbl = ft_split(str, ' ');
	cmd = ft_strdup(tbl[0]);
	flags = ft_strdup(tbl[1]);
	cmdl = malloc(sizeof(t_cmdl));
	if (!cmdl)
		return (0);
	cmdl->cmd = cmd;
	cmd_pathfinder(&cmdl->cmd, env);
	cmdl->args = malloc(sizeof(char *) * 3);
	cmdl->args[0] = cmdl->cmd;
	cmdl->args[1] = flags;
	cmdl->args[2] = NULL;
	cmdl->next = NULL;
	// ft_freetbl(tbl, -1);
	return (cmdl);
}	

void	ft_lstadd_back(t_cmdl **lst, t_cmdl *new)
{
	t_cmdl	*last;

	if (*lst)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}

// ==================================
// ==================================
// http://web.cse.ohio-state.edu/~mamrak.1/CIS762/pipes_lab_notes.html


// int	execute_pipes(t_cmdl **lst, char **env, int fdin, int fdout)
// {
// 	int 	i;
// 	int 	n;
// 	int 	npipe;
// 	int 	pid;
// 	int 	*pids;
// 	int 	**fd;
// 	t_cmdl	*cmdl;

// 	// count pipes
// 	npipe = 0;
// 	cmdl = *lst;
// 	cmdl = cmdl->next;
// 	while (cmdl)
// 	{
// 		npipe++;
// 		cmdl = cmdl->next;
// 	}

// 	// if single cmd
// 	cmdl = *lst;
// 	if (npipe == 0)
// 	{
// 		pid = fork();
// 		if (pid < 0)
// 			return (-1);
// 		if (pid == 0) 
// 			execve(cmdl->cmd, cmdl->args, env);
// 		wait(NULL);
// 		return (0);
// 	}

// 	// malloc tbls
// 	pids = malloc(sizeof(int) * (npipe + 1));
// 	if (!pids)
// 		return (-1);
// 	fd = malloc(sizeof(int *) * npipe);
// 	if (!fd)
// 		return (-1);
// 	i = 0;
// 	while (i < npipe)
// 	{
// 		fd[i] = malloc(sizeof(int) * 2);
// 		if (!fd[i])
// 			return (-1);
// 		i++;
// 	}

// 	// instantiate pipes in tbl
// 	i = 0;
// 	while (i < npipe)
// 		if (pipe(fd[i++]) == -1)
// 			return (-1);

// 	// loop over commands
// 	i = 0;
// 	while (cmdl)
// 	{
// 		// printf("Running cmd[%d]: %s\n", i, cmdl->cmd);
// 		pid = fork();
// 		if (pid < 0)
// 			return (-1);
// 		// child process
// 		if (pid == 0) 
// 		{
// 			// dups
// 			if (i == 0)
// 				dup2(fdin, STDIN_FILENO);
// 			if (i > 0)
// 				dup2(fd[i - 1][0], STDIN_FILENO);
// 			if (i < npipe - 1)
// 				dup2(fd[i][1], STDOUT_FILENO);
// 			if (i == npipe - 1)
// 				dup2(fdout, STDOUT_FILENO);
// 			// close all pipes
// 			n = 0;
// 			while (n < npipe)
// 			{
// 				close(fd[n][0]);
// 				close(fd[n][1]);
// 				n++;
// 			}
// 			// exec
// 			execve(cmdl->cmd, cmdl->args, env);
// 		}
// 		pids[i] = pid;
// 		cmdl = cmdl->next;
// 		i++;
// 	}

// 	// parent process
// 	// close all pipes
// 	n = 0;
// 	while (n < npipe)
// 	{
// 		close(fd[n][0]);
// 		close(fd[n][1]);
// 		n++;
// 	}

// 	// wait for all processes in parallel
// 	// waitpid(-1, NULL, 0);
// 	while (wait(NULL) != -1)
// 		;
// 	// i = 0;
// 	// while (i < npipe + 1)
// 	// {
// 	// 	waitpid(pids[i], NULL, 0);
// 	// 	i++;
// 	// }
    
// 	// free tbls
// 	i = 0;
// 	while (i < npipe)
// 		free(fd[i++]);
// 	free(fd);
// 	free(pids);
	
//     return (0);
// }

// ==================================



// int	execute_pipes(t_cmdl **lst, char **env, int fdin, int fdout)
// {
// 	int 	i;
// 	int 	n;
// 	int 	npipe;
// 	int 	pid;
// 	int 	*pids;
// 	int 	**fd;
// 	t_cmdl	*cmdl;

// 	// count pipes
// 	npipe = 0;
// 	cmdl = *lst;
// 	cmdl = cmdl->next;
// 	while (cmdl)
// 	{
// 		npipe++;
// 		cmdl = cmdl->next;
// 	}

// 	// if single cmd
// 	cmdl = *lst;
// 	if (npipe == 0)
// 	{
// 		pid = fork();
// 		if (pid < 0)
// 			return (-1);
// 		if (pid == 0) 
// 			execve(cmdl->cmd, cmdl->args, env);
// 		wait(NULL);
// 		return (0);
// 	}

// 	// malloc tbls
// 	pids = malloc(sizeof(int) * (npipe + 1));
// 	if (!pids)
// 		return (-1);
// 	fd = malloc(sizeof(int *) * npipe);
// 	if (!fd)
// 		return (-1);
// 	i = 0;
// 	while (i < npipe)
// 	{
// 		fd[i] = malloc(sizeof(int) * 2);
// 		if (!fd[i])
// 			return (-1);
// 		i++;
// 	}

// 	// instantiate pipes in tbl
// 	i = 0;
// 	while (i < npipe)
// 		if (pipe(fd[i++]) == -1)
// 			return (-1);

// 	// loop over commands
// 	i = 0;
// 	while (cmdl)
// 	{
// 		// printf("Running cmd[%d]: %s\n", i, cmdl->cmd);
// 		pid = fork();
// 		if (pid < 0)
// 			return (-1);
// 		// child process
// 		if (pid == 0) 
// 		{
// 			// dups
// 			if (i == 0)
// 				dup2(fdin, STDIN_FILENO);
// 			if (i > 0)
// 				dup2(fd[i - 1][0], STDIN_FILENO);
// 			if (i < npipe - 1)
// 				dup2(fd[i][1], STDOUT_FILENO);
// 			if (i == npipe - 1)
// 				dup2(fdout, STDOUT_FILENO);
// 			// close all pipes
// 			n = 0;
// 			while (n < npipe)
// 			{
// 				close(fd[n][0]);
// 				close(fd[n][1]);
// 				n++;
// 			}
// 			// exec
// 			execve(cmdl->cmd, cmdl->args, env);
// 		}
// 		pids[i] = pid;
// 		cmdl = cmdl->next;
// 		i++;
// 	}

// 	// parent process
// 	// close all pipes
// 	n = 0;
// 	while (n < npipe)
// 	{
// 		close(fd[n][0]);
// 		close(fd[n][1]);
// 		n++;
// 	}

// 	// wait for all processes in parallel
// 	// waitpid(-1, NULL, 0);
// 	while (wait(NULL) != -1)
// 		;
// 	// i = 0;
// 	// while (i < npipe + 1)
// 	// {
// 	// 	waitpid(pids[i], NULL, 0);
// 	// 	i++;
// 	// }
    
// 	// free tbls
// 	i = 0;
// 	while (i < npipe)
// 		free(fd[i++]);
// 	free(fd);
// 	free(pids);
	
//     return (0);
// }

// ==================================
// https://stackoverflow.com/questions/8082932/connecting-n-commands-with-pipes-in-a-shell?answertab=trending#tab-top
// ==================================

int	spawn_process(int fdin, int fdout, t_cmdl *cmdl, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (fdin != STDIN_FILENO)
		{
			dup2(fdin, STDIN_FILENO);
			close(fdin);
		}
		if (fdout != STDOUT_FILENO)
		{
			dup2(fdout, STDOUT_FILENO);
			close(fdout);
		}
		execve(cmdl->cmd, cmdl->args, env);
		return (0);
	}
	return (pid);
}

int	execute_pipes(int fdin, int fdout, t_cmdl **lst, char **env)
{
	t_cmdl	*cmdl;
	int 	i;
	int 	n;
	int		fd[2];

	n = 0;
	cmdl = *lst;
	cmdl = cmdl->next;
	while (cmdl)
	{
		n++;
		cmdl = cmdl->next;
	}

	cmdl = *lst;
	i = 0;
	while (i < n)
	{
		pipe(fd);
		spawn_process(fdin, fd[1], cmdl, env);
		close(fd[1]);
		fdin = fd[0];
		cmdl = cmdl->next;
		i++;
	}
	spawn_process(fdin, fdout, cmdl, env);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

// ==================================

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fdin;
	int		fdout;
	t_cmdl	*head;
	t_cmdl	*cmdl;

	if (ac < 4)
		return (1);

	head = NULL;
	i = 1;
	while (i < ac)
	{
		if (i == 1)
			fdin = open(av[i], O_RDONLY);
		else if (i == ac - 1)
			fdout = open(av[i], O_WRONLY);
		else
		{
			cmdl = ft_cmdlnew(av[i], env);
			ft_lstadd_back(&head, cmdl);
		}
		i++;
	}

	cmdl = head;
	while (cmdl)
	{
		printf("> %s [%s]\n", cmdl->cmd, cmdl->args[1]);
		cmdl = cmdl->next;
	}

	execute_pipes(fdin, fdout, &head, env);
	
	close(fdin);
	close(fdout);

	cmdl = head;
	while (cmdl)
	{
		head = cmdl->next;
		ft_freetbl(cmdl->args, -1);
		free(cmdl);
		cmdl = head;
	}
	return (0);
}
