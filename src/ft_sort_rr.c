/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:07:13 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/20 06:45:20 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_sort_rr(char *line, t_intstk **stack1, t_intstk **stack2)
{
	if (line[2] == 'a' && *stack1)
		*stack1 = ft_sort_rr_work(*stack1);
	else if (line[2] == 'b' && *stack2)
		*stack2 = ft_sort_rr_work(*stack2);
	else if (line[2] == 'r')
	{
		if (*stack1)
			*stack1 = ft_sort_rr_work(*stack1);
		if (*stack2)
			*stack2 = ft_sort_rr_work(*stack2);
	}
}

t_intstk	*ft_sort_rr_work(t_intstk *stack)
{
	int			tmp;
	int			i;
	t_intstk	*tmp_stk;

	tmp_stk = stack->previous;
	i = tmp_stk->index;
	while (i > tmp_stk->previous->index)
	{
		i--;
		tmp = tmp_stk->num;
		tmp_stk->num = tmp_stk->previous->num;
		tmp_stk->previous->num = tmp;
		tmp_stk = tmp_stk->previous;
	}
	return (tmp_stk);
}
