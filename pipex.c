/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:10:42 by bsaeed            #+#    #+#             */
/*   Updated: 2022/07/31 23:47:52 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_arg_check(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("[usage]: need 5 arguments", 2);
		exit(EXIT_FAILURE);
	}
}

/* Creates outfile & processed
	cmd even though infile
		doesnt exist          */
void	ft_wrong_infile(char *av)
{
	int	fd;

	fd = open(av, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
		exit(EXIT_FAILURE);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	write(2, "no such file or directory", 26);
}

void	closer(int file1, int file2)
{
	if (file1 == -1)
	{
		if (close(file2) == -1)
			exit(EXIT_FAILURE);
		return ;
	}
	if (close(file1) == -1)
		exit(EXIT_FAILURE);
	if (close(file2) == -1)
		exit(EXIT_FAILURE);
}

void	duped(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit(EXIT_FAILURE);
}

int	main(int ac, char *av[], char **ev)
{
	t_pipex	pipex;

	ft_arg_check(ac);
	pipex.infile_fd = open(av[1], O_RDONLY);
	if (pipex.infile_fd == -1)
		ft_wrong_infile(av[4]);
	pipex.outfile_fd = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.outfile_fd == -1)
		exit(EXIT_FAILURE);
	piper(pipex.pipefd);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		daughter(&pipex, av, ev);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		son(pipex, av, ev);
	closer(pipex.infile_fd, pipex.outfile_fd);
	closepipes(pipex.pipefd);
	waitpid(pipex.pid1, NULL, 0);
	if (waitpid(pipex.pid2, &pipex.status, 0) == -1)
		return (EXIT_FAILURE);
	if (WIFEXITED(pipex.status))
		exiter(pipex.status);
}
