/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:22:33 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/05 17:16:19 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_prosortend(t_intstk **stack1, t_intstk **stack2, int notsort)
{
	if (notsort == 1 && (*stack1)->next->num < (*stack1)->num)
	{
		ft_sort("ra", &*stack1, NULL, 1);
	}
	else if (notsort == 2)
	{
		if ((*stack1)->next->num < (*stack1)->num)
			ft_sort("sa", &*stack1, NULL, 1);
		ft_sort("ra", &*stack1, NULL, 1);
		ft_sort("ra", &*stack1, NULL, 1);
	}
}

void		ft_prosortnext(t_intstk **stack1, t_intstk **stack2,
			int *j, int *sort_mas)
{
	if ((*stack2) && (*stack2)->num == sort_mas[*j])
		ft_sort("pa", &*stack1, &*stack2, 1);
	else if ((*stack1)->next->num == sort_mas[*j] &&
	(*stack1)->num == sort_mas[*j + 1])
		ft_sort("sa", &*stack1, NULL, 1);
	else if ((*stack1)->num == sort_mas[*j])
	{
		ft_sort("ra", &*stack1, NULL, 1);
		*j = *j + 1;
	}
	else
		ft_sort("pb", &*stack1, &*stack2, 1);
}

void		ft_prosort(t_intstk **stack1, t_intstk **stack2,
			int *sort_mas, int *avrg_mas)
{
	int		i;
	int		j;
	int		half;

	i = 0;
	j = 0;
	half = (*stack1)->previous->index;
	while (half > 2)
	{
		half /= 2;
		while ((*stack1)->previous->index != half + j)
			ft_halfpb(&*stack1, &*stack2, avrg_mas, i);
		if (i != 0)
			while ((*stack1)->previous->num != avrg_mas[i - 1])
				ft_sort("rra", &*stack1, NULL, 1);
		while ((*stack1)->previous->num != avrg_mas[i])
		{
			ft_halfpa(&*stack1, &*stack2, sort_mas, &j);
			while ((*stack1)->num <= avrg_mas[i])
				ft_prosortnext(&*stack1, &*stack2, &j, sort_mas);
		}
		i++;
	}
	ft_prosortend(&*stack1, &*stack2, half);
}
