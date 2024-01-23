/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:54:51 by locharve          #+#    #+#             */
/*   Updated: 2023/12/16 18:57:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (i > 0 && ft_isspace(str[i]) && !ft_isspace(str[i - 1]))
			count++;
		i++;
	}
	if (i > 0 && !ft_isspace(str[i - 1]))
		count++;
	return (count);
}

static char	*str_piece_cpy(const char *s, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((end - start + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start < end)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*from_str_to_strs(const char *s, int *i)
{
	char	*dst;
	int		j;

	while (s[*i] && ft_isspace(s[*i]))
		*i += 1;
	j = *i;
	while (s[j] && !ft_isspace(s[j]))
		j++;
	dst = str_piece_cpy(s, *i, j);
	*i = j;
	return (dst);
}

void	free_all(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
	return ;
}

char	**ft_split(const char *s)
{
	char	**split;
	int		nbr_str;
	int		i;
	int		index;

	if (s == NULL)
		return (NULL);
	nbr_str = count_words(s);
	split = (char **)malloc((nbr_str + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (i < nbr_str)
	{
		split[i] = from_str_to_strs(s, &index);
		if (!split[i])
		{
			free_all(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
