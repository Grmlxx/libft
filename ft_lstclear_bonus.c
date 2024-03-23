/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:51:07 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:50:26 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	head = *lst;
	while (head)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = head;
	}
}
/*void del(void *d)
{
	free(d);
	printf("tsuprimat\n");
}
int main ()
{
	t_list *p = ft_lstnew(ft_strdup("1"));
	t_list *p1 = ft_lstnew(ft_strdup("2"));
	t_list *p2 = ft_lstnew(ft_strdup("3"));
	p->next = p1;
	p1->next = p2;	
	ft_lstclear(&p,&del);
	while (p)
	{
		printf("%s\n", (char *)p -> content);
		p = p -> next;
	}		
}*/