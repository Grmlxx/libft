/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:49:51 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:51:18 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
/*void X(unsigned int i, char *c)
{
	(void) (i);
    *c -= 32;
}
int main()
{
	char s[] = "lwejdi";
	ft_striteri(s, X);
    printf ("%s\n", s);
}*/