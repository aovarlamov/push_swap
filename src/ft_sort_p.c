/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:12:17 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/20 06:44:59 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void			ft_sort_p(char *line, t_intstk **stack1, t_intstk **stack2)
{
	int			tmp_num;

	if (line[1] == 'b' && *stack1)
	{
		tmp_num = (*stack1)->num;
		if (!(tmp_num == (*stack1)->next->num))
			*stack1 = ft_sort_p_work_stk1(*stack1);
		else
			ft_delintstack(&*stack1);
		*stack2 = ft_sort_p_work_stk2(*stack2, tmp_num);
	}
	else if (line[1] == 'a' && *stack2)
	{
		tmp_num = (*stack2)->num;
		if (!(tmp_num == (*stack2)->next->num))
			*stack2 = ft_sort_p_work_stk1(*stack2);
		else
			ft_delintstack(&*stack2);
		*stack1 = ft_sort_p_work_stk2(*stack1, tmp_num);
	}
}

t_intstk		*ft_sort_p_work_stk1(t_intstk *stack1)
{
	t_intstk	*tmp_stk1;
	t_intstk	*temp;

	stack1 = ft_delintstackelem(stack1);
	while (stack1->index != 1)
	{
		stack1->index -= 1;
		stack1 = stack1->next;
	}
	return (stack1);
}

t_intstk		*ft_sort_p_work_stk2(t_intstk *stack2, int tmp_num)
{
	t_intstk	*tmp_stk;

	if (!stack2)
	{
		ft_createintstack(&stack2, tmp_num);
		return (stack2);
	}
	ft_createintstack(&tmp_stk, tmp_num);
	stack2->previous->next = tmp_stk;
	tmp_stk->previous = stack2->previous;
	stack2->previous = tmp_stk;
	tmp_stk->next = stack2;
	while (stack2->index != 1 || stack2->previous->index == 1)
	{
		stack2->index += 1;
		stack2 = stack2->next;
	}
	return (stack2);
}
