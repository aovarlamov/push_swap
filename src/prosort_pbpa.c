/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prosort_pbpa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:06:47 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 18:50:55 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_halfpb(t_intstk **stack1, t_intstk **stack2, int *mid, int i)
{
	t_intstk	*tmp;
	int			l_mid;
	int			find;

	tmp = *stack1;
	if (i == 0)
		l_mid = -2147483648;
	else
		l_mid = mid[i - 1];
	if (!(tmp->num <= mid[i]) && tmp->num > l_mid)
	{
		tmp = tmp->next;
		while (tmp->index != 1)
		{
			if (tmp->num <= mid[i] && tmp->num > l_mid)
			{
				find = tmp->num;
				while ((*stack1)->num != find)
					ft_sort("ra", &*stack1, NULL, 1);
				break ;
			}
			tmp = tmp->next;
		}
	}
	ft_sort("pb", &*stack1, &*stack2, 1);
}

void		ft_halfpa_cksh(t_intstk **stack1, t_intstk **stack2,
			int *sort_hmas, int *mid_i)
{
	if ((*stack2)->num == sort_hmas[*mid_i])
	{
		ft_sort("pa", &*stack1, &*stack2, 1);
		*mid_i = *mid_i - 1;
	}
	else if ((*stack2)->num >= sort_hmas[*mid_i])
		ft_sort("pa", &*stack1, &*stack2, 1);
}

void		ft_halfpa(t_intstk **stack1, t_intstk **stack2,
			int *sort_mas, int *j)
{
	int		*sort_hmas;
	int		mid_i;

	sort_hmas = ft_sort_mas(*stack2);
	mid_i = (*stack2)->previous->index / 2;
	while (*stack2)
	{
		if ((*stack2)->num == sort_mas[*j])
		{
			ft_sort("pa", &*stack1, &*stack2, 1);
			if (*stack2 && ((*stack2)->num == sort_mas[*j + 1] ||
			(*stack2)->num >= sort_hmas[mid_i]))
				ft_sort("ra", &*stack1, NULL, 1);
			else
				ft_sort("rr", &*stack1, &*stack2, 1);
			*j = *j + 1;
		}
		else if ((*stack2)->num == sort_hmas[mid_i] || (*stack2)->num >=
		sort_hmas[mid_i])
			ft_halfpa_cksh(&*stack1, &*stack2, sort_hmas, &mid_i);
		else
			ft_sort("rb", NULL, &*stack2, 1);
	}
	free(sort_hmas);
}
