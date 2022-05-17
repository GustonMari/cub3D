/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:10:41 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 09:54:30 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	ft_word_len(char *str, char *charset)
{
	int	j;

	j = 0;
	while (str[j] && (ft_is_sep(str[j], charset) == 0))
		j++;
	return (j + 1);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	count;
	int	new_word;

	i = 0;
	new_word = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset))
			new_word = 0;
		if (new_word == 0)
		{
			if (ft_is_sep(str[i], charset) != 1)
			{
				new_word = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

char	**ft_cut(char *str, char *charset, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		count;

	i = 0;
	j = 0;
	count = ft_word_count(str, charset);
	while (j < count)
	{	
		k = 0;
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		tab[j] = malloc(sizeof(char) * ft_word_len(&str[i], charset));
		while (str[i] && (ft_is_sep(str[i], charset) != 1))
		{
			tab[j][k] = str[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}	

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	tab = NULL;
	if (str[0] == '\0' || !str || !charset)
	{
		tab = malloc(sizeof(char *));
		tab[0] = 0;
		return (tab);
	}
	if (ft_word_count(str, charset))
		tab = malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	else
	{
		tab = malloc(sizeof(char *));
		tab[0] = 0;
		return (tab);
	}
	tab = ft_cut(str, charset, tab);
	return (tab);
}
