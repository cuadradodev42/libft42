/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:43:31 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/19 00:12:07 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_number_lengt(int n)
{
	unsigned int	lengt;

	lengt = 0;
	while (n / 10 > 1)
	{
		n = n / 10;
		lengt++;
	}
	return (lengt);
}

static unsigned int	ft_possitive_number(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	return (n);
}

static void	ft_converter(char *ascii, int n, unsigned int lengt)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		ascii[0] = '-';
		i++;
		lengt++;
	}
	ascii[i] = '\0';
	while (i <= lengt)
	{
		ascii[lengt] = (n % 10) + 48;
		n = n / 10;
		lengt--;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	n_possitive;
	unsigned int	lengt;
	char			*ascii;

	if (!n)
		return (NULL);
	n_possitive = ft_possitive_number(n);
	lengt = ft_number_lengt(n_possitive);
	ascii = malloc(sizeof(char) * (lengt + 1));
	if (!ascii)
		return (NULL);
	ft_converter(ascii, n_possitive, lengt);
	return (ascii);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", ft_itoa(ft_atoi(argv[1])));
	}
	else
		printf("error");
	return (0);
}
