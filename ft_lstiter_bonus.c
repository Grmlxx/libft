/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:52:10 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:50:47 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}
/*void	my_f(void *i)
{
	char *str = (char *)i;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
int main()
{
	t_list	*p = ft_lstnew(ft_strdup("wa"));
	t_list	*p1 = ft_lstnew(ft_strdup("trisawi"));
	p->next = p1;
	ft_lstiter(p, my_f);
	while (p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
}*/