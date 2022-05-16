/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:44:43 by gmary             #+#    #+#             */
/*   Updated: 2022/05/16 10:44:44 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_gnl_strjoin_bis(char *s1, char *s2)
{
	if (!s1)
		return (FALSE);
	if (!s1 && !s2)
		return (FALSE);
	return (TRUE);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char			*dest;
	size_t			len_dest;
	unsigned int	i;

	if (!s1)
		s1 = ft_strdup("");
	if (ft_gnl_strjoin_bis(s1, s2) == FALSE)
		return (NULL);
	len_dest = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
		*dest++ = s1[i++];
	i = 0;
	while (s2 && s2[i])
		*dest++ = s2[i++];
	*dest = '\0';
	free(s1);
	return (dest - len_dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
