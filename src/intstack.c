/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:45:33 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 20:57:23 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void			ft_createintstack(t_intstk **stack1, int num)
{
	*stack1 = (t_intstk *)malloc(sizeof(t_intstk));
	(*stack1)->index = 1;
	(*stack1)->num = num;
	(*stack1)->next = *stack1;
	(*stack1)->previous = *stack1;
}

void			ft_fillintstack(t_intstk **stack1, int num)
{
	t_intstk	*tmp;

	if (!(*stack1))
		ft_createintstack(&*stack1, num);
	else if ((*stack1)->previous->index == 1)
	{
		(*stack1)->next = (t_intstk *)malloc(sizeof(t_intstk));
		(*stack1)->next->num = num;
		(*stack1)->next->index = 2;
		(*stack1)->next->next = (*stack1);
		(*stack1)->next->previous = (*stack1);
		(*stack1)->previous = (*stack1)->next;
	}
	else
	{
		tmp = (*stack1)->next;
		while (tmp->next->index != 1)
			tmp = tmp->next;
		tmp->next = (t_intstk *)malloc(sizeof(t_intstk));
		tmp->next->num = num;
		tmp->next->index = tmp->index + 1;
		tmp->next->next = *stack1;
		tmp->next->previous = tmp;
		(*stack1)->previous = tmp->next;
	}
}

void			ft_delintstack(t_intstk **stack)
{
	free(*stack);
	*stack = NULL;
}

t_intstk		*ft_delintstackelem(t_intstk *lst)
{
	t_intstk		*prev;
	t_intstk		*next;

	prev = lst->previous;
	next = lst->next;
	prev->next = lst->next;
	next->previous = lst->previous;
	free(lst);
	return (next);
}

int				ft_fulldelintstack(t_intstk **stack)
{
	t_intstk	*temp;
	t_intstk	*temp2;

	if (*stack)
	{
		temp = *stack;
		while (temp->index != temp->next->index)
		{
			temp2 = temp->next;
			ft_delintstackelem(temp);
			temp = temp2;
		}
		ft_delintstack(&temp);
		*stack = NULL;
	}
	return (0);
}
