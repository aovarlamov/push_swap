/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:57:16 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 19:05:45 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int		ft_delsplit(char ***split, int j)
{
	while ((*split)[j])
	{
		ft_strdel(&(*split)[j++]);
	}
	free(*split);
	return (0);
}

int		ft_check_maxint(long int *num, char *split)
{
	*num = ft_atoi(split);
	if (*num > 2147483647 || *num < -2147483648)
		return (0);
	return (1);
}

int		ft_check_argv(int argc, char **argv, t_intstk **stack1)
{
	if (argc == 1)
		return (0);
	if (!(ft_checkargv(&*stack1, argc, argv)))
		return (ft_fulldelintstack(&*stack1) || ft_msgs(1) == 0);
	if (!(*stack1))
		return (0);
	if (!(ft_check_same(*stack1)))
		return (ft_fulldelintstack(&*stack1) || ft_msgs(1) == 0);
	return (1);
}

int		chcker_writer(char **line, t_intstk **stack1, t_intstk **stack2)
{
	if (!(ft_check_wr(*line)))
	{
		free(*line);
		return (0);
	}
	ft_sort(*line, &*stack1, &*stack2, 0);
	free(*line);
	return (1);
}
