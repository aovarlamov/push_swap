/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:03:03 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 19:36:12 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int				main(int argc, char **argv)
{
	t_intstk	*stack1;
	t_intstk	*stack2;
	int			rt;
	char		*line;

	stack1 = NULL;
	stack2 = NULL;
	if (!(ft_check_argv(argc, argv, &stack1)))
		return (0);
	while ((rt = get_next_line(0, &line)))
	{
		if (!(chcker_writer(&line, &stack1, &stack2)))
			return (ft_fulldelintstack(&stack1) ||
			ft_fulldelintstack(&stack2) || ft_msgs(1));
	}
	if (ft_check_sort(stack1) && !stack2)
		return (ft_fulldelintstack(&stack1) || ft_msgs(2));
	else
		return (ft_fulldelintstack(&stack1) || ft_fulldelintstack(&stack2)\
		|| ft_msgs(3));
}
