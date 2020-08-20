/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:33:08 by kbethel           #+#    #+#             */
/*   Updated: 2019/09/16 16:58:53 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_checkminus(int *n)
{
	int minus;

	minus = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		minus = 1;
	}
	return (minus);
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*res;
	int		m;

	len = 2;
	m = ft_itoa_checkminus(&n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	len += m;
	if (!(res = (char *)malloc(sizeof(char) * len)))
		return (0);
	res[--len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	if (m == 1)
		res[0] = '-';
	return (res);
}
