/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:18:34 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/10 18:58:09 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ins_sort(int *arr, int n)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

int		*ft_avrg_mas(int *sort_mas, int count)
{
	int		i;
	int		tmp;
	int		count_l;
	int		ind_a;
	int		*avrg_mas;

	i = 0;
	tmp = count;
	while ((tmp = tmp / 2) > 2)
		i++;
	avrg_mas = (int*)malloc(sizeof(int) * i + 6);
	count_l = 0;
	ind_a = 0;
	i = 0;
	while (count > 2)
	{
		if (count % 2 == 0)
			count_l = count / 2;
		else
			count_l = count / 2 + 1;
		ind_a = ind_a + count_l;
		avrg_mas[i++] = sort_mas[ind_a - 1];
		count -= count_l;
	}
	return (avrg_mas);
}

int		*ft_sort_mas(t_intstk *stack)
{
	int			*sort_mas;
	t_intstk	*tmp;
	int			i;

	i = 1;
	tmp = stack->next;
	sort_mas = (int*)malloc(sizeof(*sort_mas) * stack->previous->index);
	sort_mas[0] = stack->num;
	while (tmp->num != sort_mas[0])
	{
		sort_mas[i++] = tmp->num;
		tmp = tmp->next;
	}
	ft_ins_sort(sort_mas, stack->previous->index);
	return (sort_mas);
}
