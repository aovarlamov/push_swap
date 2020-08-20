/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:24:46 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 04:31:44 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int				main(int argc, char **argv)
{
	t_intstk	*stack1;
	t_intstk	*stack2;
	int			*sort_mas;
	int			*avrg_mas;

	stack1 = NULL;
	stack2 = NULL;
	if (!(ft_check_argv(argc, argv, &stack1)))
		return (0);
	if (ft_check_sort(stack1))
		return (ft_fulldelintstack(&stack1));
	sort_mas = ft_sort_mas(stack1);
	avrg_mas = ft_avrg_mas(sort_mas, stack1->previous->index);
	if (stack1->previous->index < 6)
		ft_noobsort(&stack1, &stack2);
	else
		ft_prosort(&stack1, &stack2, sort_mas, avrg_mas);
	return (ft_endprog(&avrg_mas, &sort_mas, &stack1));
}
