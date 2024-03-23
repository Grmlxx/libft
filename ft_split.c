/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:50:55 by alamaoui          #+#    #+#             */
/*   Updated: 2023/12/05 16:51:09 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*end;
	char		*wd;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	end = *s;
	wd = ft_substr(start, 0, end - start);
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		res[i] = get_next_word(&s, c);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
/*int    main(void)
{
    int        i;
    char    **result = ft_split("......Hello......1337......Pandora",'.');
    i = 0;
    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
}*/