/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:52:42 by mehtel            #+#    #+#             */
/*   Updated: 2020/11/14 23:55:10 by mehtel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	int		arr_len;
	char	**arr;
	char	*word;
	int		i;

	end = -1;
	start = 0;
	arr_len = 0;
	while (s[++end])
		(s[end] != c && (s[end + 1] == c || !s[end + 1])) ? \
				   arr_len++ : 1;
	if (!(arr = (char**)malloc(sizeof(char**) * (arr_len + 1))))
		return (0);
	end = 0;
	i = 0;
	arr[arr_len] = 0;
	while (i < arr_len)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (!(s[end] == c) && s[end])
			end++;
		if ((end - start) && (word = \
					(char*)malloc(sizeof(char) * (end - start + 1))))
		{
			word[end - start] = '\0';

			while (start != end--)
				word[end - start] = s[end];
			start += ft_strlen(word) + 1 ;
		}
		arr[i++] = word;
	}
	return (arr);
}
