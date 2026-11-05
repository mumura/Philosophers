/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucho <ucho@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 04:09:13 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/18 19:20:24 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
	}
	return (cnt);
}

static void	free_split(char **arr, size_t n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

static char	*dup_word(char const *start, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static char	*next_word(char const **s, char c)
{
	char const	*end_ptr;
	char		*word;
	size_t		len;

	while (**s && **s == c)
		(*s)++;
	end_ptr = ft_strchr(*s, c);
	if (end_ptr)
	{
		len = end_ptr - *s;
	}
	else
	{
		len = ft_strlen(*s);
	}
	if (len == 0)
		return (NULL);
	word = dup_word(*s, len);
	if (!word)
		return (NULL);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	out = ft_calloc(words + 1, sizeof(*out));
	if (!out)
		return (NULL);
	i = 0;
	while (i < words)
	{
		out[i] = next_word(&s, c);
		if (!out[i])
		{
			free_split(out, i);
			return (NULL);
		}
		i++;
	}
	return (out);
}
