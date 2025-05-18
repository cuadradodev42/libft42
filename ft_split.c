/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:23:00 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/18 22:28:19 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_word_count(char const *s, char const c)
{
	unsigned int	i;
	unsigned int	word_count;
	int				flag;

	i = 0;
	word_count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			word_count++;
			flag = 1;
		}
		i++;
	}
	return (word_count);
}

static unsigned int	ft_start_word(char const *s, char const c,
		unsigned int n_word)
{
	unsigned int	i;
	unsigned int	word_count;
	int				flag;

	i = 0;
	word_count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			if (word_count == n_word)
				return (i);
			word_count++;
			flag = 1;
		}
		i++;
	}
	return (i);
}

char	*ft_fill_str(char const *s, unsigned int start, char c)
{
	size_t			s_len;
	unsigned int	i;
	char			*str;

	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
	{
		return (NULL);
	}
	while (s[i + start] != '\0' && s[i + start] != c)
		i++;
	str = ft_substr(s, start, i);
	return (str);
}

char	**ft_split(char const *s, char const c)
{
	unsigned int	word_count;
	unsigned int	i_str;
	unsigned int	start_word;
	char			**str_split;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	str_split = malloc((word_count + 1) * sizeof(char *));
	if (!str_split)
		return (NULL);
	i_str = 0;
	start_word = 0;
	while (i_str < word_count)
	{
		start_word = ft_start_word(s, c, i_str);
		str_split[i_str] = ft_fill_str(s, start_word, c);
		i_str++;
	}
	str_split[i_str] = NULL;
	return (str_split);
}
/*
int main (void)
{
	char	**str_split;
	char	*s;
	char	c;

	s = "   hello world  ! SDAJFAKLÑ";
	c = ' ';
	str_split = ft_split(s, c);
	for (int i = 0; str_split[i] != NULL; i++)
	{
		printf("%s\n", str_split[i]);
		free(str_split[i]);
	}
	free(str_split);
	return (0);
}
*/