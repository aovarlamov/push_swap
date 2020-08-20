/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:09:01 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 19:11:28 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_msgs(int n)
{
	if (n == 1)
		write(2, "Error\n", 6);
	else if (n == 2)
		write(1, "OK\n", 3);
	else if (n == 3)
		write(1, "KO\n", 3);
	return (1);
}

int		ft_endprog(int **avrg_mas, int **sort_mas, t_intstk **stack1)
{
	if (*avrg_mas)
		free(*avrg_mas);
	if (*sort_mas)
		free(*sort_mas);
	ft_fulldelintstack(&*stack1);
	return (1);
}
