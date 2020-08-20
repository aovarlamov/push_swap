/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noobsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 20:54:37 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/05 17:15:53 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_mintoup(t_intstk **stack1)
{
	int			min;
	int			min_i;

	min_i = (*stack1)->index;
	min = (*stack1)->num;
	*stack1 = (*stack1)->next;
	while ((*stack1)->index != 1)
	{
		if ((*stack1)->num < min)
		{
			min = (*stack1)->num;
			min_i = (*stack1)->index;
		}
		(*stack1) = (*stack1)->next;
	}
	if (min_i <= (*stack1)->previous->index / 2)
	{
		while ((*stack1)->num != min)
			ft_sort("ra", &*stack1, NULL, 1);
	}
	else
	{
		while ((*stack1)->num != min)
			ft_sort("rra", &*stack1, NULL, 1);
	}
}

void	ft_sortthree(t_intstk **stack1)
{
	if ((*stack1)->num > (*stack1)->next->num && (*stack1)->next->num <
	(*stack1)->previous->num && (*stack1)->num < (*stack1)->previous->num)
		ft_sort("sa", &*stack1, NULL, 1);
	else if ((*stack1)->num > (*stack1)->next->num && (*stack1)->next->num >
	(*stack1)->previous->num && (*stack1)->num > (*stack1)->previous->num)
	{
		ft_sort("sa", &*stack1, NULL, 1);
		ft_sort("rra", &*stack1, NULL, 1);
	}
	else if ((*stack1)->num > (*stack1)->next->num && (*stack1)->next->num <
	(*stack1)->previous->num && (*stack1)->num > (*stack1)->previous->num)
		ft_sort("ra", &*stack1, NULL, 1);
	else if ((*stack1)->num < (*stack1)->next->num && (*stack1)->next->num >
	(*stack1)->previous->num && (*stack1)->num < (*stack1)->previous->num)
	{
		ft_sort("sa", &*stack1, NULL, 1);
		ft_sort("ra", &*stack1, NULL, 1);
	}
	else if ((*stack1)->num < (*stack1)->next->num && (*stack1)->next->num >
	(*stack1)->previous->num && (*stack1)->num > (*stack1)->previous->num)
		ft_sort("rra", &*stack1, NULL, 1);
}

void	ft_noobsortplus(int count, t_intstk **stack1, t_intstk **stack2)
{
	if (count > 3)
	{
		while ((*stack1)->previous->index != 3)
		{
			ft_mintoup(&*stack1);
			ft_sort("pb", &*stack1, &*stack2, 1);
		}
		ft_sortthree(&*stack1);
		while (*stack2)
			ft_sort("pa", &*stack1, &*stack2, 1);
	}
	else
		ft_sortthree(&*stack1);
}

void	ft_noobsort(t_intstk **stack1, t_intstk **stack2)
{
	if ((*stack1)->previous->index < 3)
	{
		if ((*stack1)->num > (*stack1)->next->num)
			ft_sort("sa", &*stack1, NULL, 1);
	}
	else
		ft_noobsortplus((*stack1)->previous->index, &*stack1, &*stack2);
}
