/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:13 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:50:33 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*void del(void *d)
{
	free(d);
}

int main ()
{
	t_list *p = ft_lstnew(ft_strdup("1"));
	t_list *p1 = ft_lstnew(ft_strdup("2"));
	t_list *p2 = ft_lstnew(ft_strdup("3"));
	p->next = p1;
	p1->next = p2;
	ft_lstdelone(p1, del);
	p->next = p2; 
	while (p)
	{
		printf("%s\n", (char *)p -> content);
		p = p->next;
	}
}*/