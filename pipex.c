/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:20:05 by bsaeed            #+#    #+#             */
/*   Updated: 2022/07/24 16:34:34 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	opener(char *file, int flag)
{
	if (flag == 0)
	{
		if (access(file, F_OK))
		{
			write(2, "File not found\n", 15);
			return (0);
		}
		return(open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_TRUNC | O_RDWR, 0644));
}

void	son(t_pipex pipex, char *av[], char **ev)
{
	pipex.cmd1_args = ft_split(av[2], ' ');
	pipex.path1 = finalpath(pipex.cmd1_args[0], ev);
	pipex.infile_fd = opener(av[1], 0);
	if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
		strerror(errno);
	if (dup2(pipex.pipefd[1], STDOUT_FILENO) == -1)
		strerror(errno);
	close(pipex.infile_fd);
	close(pipex.pipefd[1]);
	close(pipex.pipefd[0]);
	if (execve(pipex.path1, pipex.cmd1_args, ev) == -1)
		strerror(errno);
	return ;
}

void	dad(t_pipex pipex, char *av[], char **ev)
{
	waitpid(pipex.pid, NULL, 0);
	pipex.cmd2_args = ft_split(av[3], ' ');
	pipex.path2 = finalpath(pipex.cmd2_args[0], ev);
	pipex.outfile_fd = opener(av[4], 1);
	if (dup2(pipex.outfile_fd, STDOUT_FILENO) == -1)
		strerror(errno);
	if (dup2(pipex.pipefd[0], STDIN_FILENO) == -1)
		strerror(errno);
	close(pipex.outfile_fd);
	close(pipex.pipefd[1]);
	close(pipex.pipefd[0]);
	if (execve(pipex.path2, pipex.cmd2_args, ev) == -1)
		strerror(errno);
	return ;
}

int main(int ac, char *av[], char **ev)
{
	t_pipex	pipex;

	if (ac == 5)
	{
		pipe(pipex.pipefd);
		pipex.pid = fork();
		if (pipex.pid == 0)
			son(pipex, av, ev);
		else
			dad(pipex, av, ev);
	}
	else
		write(1, "Need 5 arguments\n", 17);
}