/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:09:58 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 09:47:40 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void	*ft_free_tab_2d(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*ft_strjoin_free_safe(char *s1, char *s2, int del)
{
	if (del == 1)
		free(s1);
	if (del == 2)
		free(s2);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2, int del)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (ft_strjoin_free_safe(s1, s2, del));
	while (s1[i])
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	i = -1;
	while (s2[++i])
		dest[j + i] = s2[i];
	dest[j + i] = '\0';
	if (del == 1)
		free(s1);
	if (del == 2)
		free(s2);
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
