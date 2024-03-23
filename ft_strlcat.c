/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:39:30 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/04 20:55:42 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	if (!dst && src && !size)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	i = 0;
	if (size <= d_len || size == 0)
		return (size + ft_strlen(src));
	while (src[i] && (i + d_len) < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + ft_strlen(src));
}
