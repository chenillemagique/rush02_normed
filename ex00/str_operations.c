/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:28:13 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 15:35:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strdup(char *str)
{
	int		i;
	int		str_l;
	char	*dest;

	str_l = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * (str_l + 1))))
		return (0);
	i = 0;
	while (i < str_l)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_readvalue(int nb, char *n)
{
	int		i;
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	while (n[0] != '\n')
	{
		str[i] = n[0];
		read(nb, n, 1);
		i++;
	}
	return (str);
}

char	*ft_readnbr(int nb)
{
	int		i;
	char	n[1];
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	read(nb, n, 1);
	while (n[0] == '\n')
		read(nb, n, 1);
	while (n[0] >= '0' && n[0] <= '9')
	{
		str[i] = n[0];
		read(nb, n, 1);
		i++;
	}
	return (str);
}
