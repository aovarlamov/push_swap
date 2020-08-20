/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:51:18 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/20 06:44:35 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_sort_r(char *line, t_intstk **stack1, t_intstk **stack2)
{
	if (line[1] == 'a' && *stack1)
		*stack1 = ft_sort_r_work(*stack1);
	else if (line[1] == 'b' && *stack2)
		*stack2 = ft_sort_r_work(*stack2);
	else if (line[1] == 'r')
	{
		if (*stack1)
			*stack1 = ft_sort_r_work(*stack1);
		if (*stack2)
			*stack2 = ft_sort_r_work(*stack2);
	}
}

t_intstk	*ft_sort_r_work(t_intstk *stack)
{
	int			tmp;
	int			i;
	t_intstk	*tmp_stk;
	t_intstk	*tmp_stk2;

	i = 1;
	tmp_stk = stack;
	tmp_stk2 = tmp_stk;
	while (i < tmp_stk->next->index)
	{
		i++;
		tmp = tmp_stk->num;
		tmp_stk->num = tmp_stk->next->num;
		tmp_stk->next->num = tmp;
		tmp_stk = tmp_stk->next;
	}
	return (tmp_stk2);
}
