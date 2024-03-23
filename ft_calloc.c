/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:04:21 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:57:43 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if ((count * size) > 0)
	{
		if (size && count > SIZE_MAX / size)
			return (0);
		mem = malloc(count * size);
		if (mem)
			ft_bzero(mem, count * size);
		return (mem);
	}
	else
	{
		mem = malloc(1);
		if (mem)
			ft_bzero(mem, 1);
		return (mem);
	}
}
