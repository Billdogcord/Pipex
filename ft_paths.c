/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:18:39 by bsaeed            #+#    #+#             */
/*   Updated: 2022/07/24 18:50:45 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
		env[i][2] == 'T' && env[i][3] == 'H')
			break ;
		i++;
	}
	return (&env[i][5]);
}

char	*finalpath(char *cmd, char **env)
{
	char	**res;
	char	*path;
	char	*filepath;
	int		i;

	i = 0;
    if (access(cmd, F_OK) == 0)
        return(cmd);
	path = pathfinder(env);
	res = ft_split(path, ':');
	while (res[i])
	{
		filepath = ft_strjoin(res[i], "/");
		filepath = ft_strjoin(filepath, cmd);
		if (access(filepath, F_OK) == 0)
			break ;
		free (filepath);
		i++;
	}
	return (filepath);
}
