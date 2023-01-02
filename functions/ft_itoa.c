/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:23:59 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/02 17:22:39 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	checklen(long nbr)
{
	long	size;

	size = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		size++;
	}
	else if (nbr == 0)
		size++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char	*fullstr(long nbr, int len)
{
	int		i ;
	char	*str;

	str = malloc (len + 1);
	if (! str)
		return (NULL);
	str[len] = '\0';
	len--;
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (len >= i)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = checklen (nbr);
	str = fullstr (nbr, len);
	return (str);
}
