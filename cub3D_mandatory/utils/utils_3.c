/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:14:35 by ndormoy           #+#    #+#             */
/*   Updated: 2022/05/17 18:28:03 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/function.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (FALSE);
	else
		return (TRUE);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nb;
	long	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (ft_is_space(str[i]) == TRUE)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return ((int)(nb * sign));
}

/*retourne TRUE si str n'est compose que de whitespaces*/

int	line_is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_space(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	print_tab_2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_putstr_fd(strs[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}
