/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:07:05 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/23 20:07:08 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		f(cur);
		cur = cur->next;
	}
}
