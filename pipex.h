/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:14:02 by bsaeed            #+#    #+#             */
/*   Updated: 2022/07/24 14:24:07 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/errno.h>

//LIBFT
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

//PIPEX BABY
char	*pathfinder(char **env);
char	*finalpath(char *cmd, char **env);


typedef struct t_pipex
{
	pid_t		pid;
	int		pipefd[2];
	int		infile_fd;
	int		outfile_fd;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*path1;
	char	*path2;
}	t_pipex;

#endif