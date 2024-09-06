/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:14:02 by bsaeed            #+#    #+#             */
/*   Updated: 2022/07/31 23:38:11 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/errno.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

typedef struct t_pipex
{
	pid_t		pid1;
	pid_t		pid2;
	int			index;
	int			status;
	int			pipefd[2];
	int			infile_fd;
	int			outfile_fd;
	char		**cmd1_args;
	char		**cmd2_args;
	char		*path1;
	char		*path2;
	char		*cmdpath;
	char		**res;
	char		*path;
	char		*temp;
}	t_pipex;

char	*pathfinder(char **env);
char	*finalpath(char **cmds, char **env);
void	printerr(char *str);
void	daughter(t_pipex *pipex, char *av[], char **ev);
void	son(t_pipex pipex, char *av[], char **ev);
void	free_split(char **str);
void	piper(int *pipefd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	closepipes(int *pipefd);
void	exiter(int status);
void	piper(int *pipefd);
void	ft_arg_check(int ac);
void	ft_wrong_infile(char *av);
void	duped(int oldfd, int newfd);

#endif
