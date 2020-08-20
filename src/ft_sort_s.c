/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:40:27 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/20 06:45:32 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		ft_sort_s(char *line, t_intstk **stack1, t_intstk **stack2)
{
	if (line[1] == 'a' && *stack1)
		*stack1 = ft_sort_s_work(*stack1);
	else if (line[1] == 'b' && *stack2)
		*stack2 = ft_sort_s_work(*stack2);
	else if (line[1] == 's')
	{
		if (*stack1)
			*stack1 = ft_sort_s_work(*stack1);
		if (*stack2)
			*stack2 = ft_sort_s_work(*stack2);
	}
}

t_intstk	*ft_sort_s_work(t_intstk *stack)
{
	int		tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	return (stack);
}
