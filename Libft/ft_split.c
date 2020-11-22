/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:37:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/11/22 18:34:54 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_remix(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_word_number(char const *s, char c)
{
	int i;
	int w;

	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

char		**ft_split(char const *s, char c)
{
	char	**dest;
	int		wnb;
	int		i;

	if (!s)
		return (NULL);
	wnb = ft_word_number(s, c);
	if (!(dest = malloc(sizeof(char *) * wnb)))
		return (NULL);
	i = -1;
	while (++i < wnb)
	{
		while (*s && *s == c)
			s++;
		if (!(dest[i] = ft_substr(s, 0, ft_strlen_remix(s, c))))
			return (NULL);
		s += ft_strlen_remix(s, c);
	}
	dest[i] = 0;
	return (dest);
}
