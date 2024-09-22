/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:40:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/22 15:41:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int n, t_list *tab, int *start)
{
	int	i;
	int	ten;

	i = 0;
	ten = poweroften(n);
	if (ten >= 100)
		ft_print(n / ten, tab, start);
	if (*start == 0)
		write(1, " ", 1);
	*start = 0;
	while (tab[i].nb != ten)
		i++;
	ft_putstr(tab[i].val);
	if (ten != 0 && n % ten != 0)
		ft_print(n % ten, tab, start);
}

int	ft_multipleoften(int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

int	ft_poweroften(int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (ft_multipleoften(nb));
}
