/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:54:47 by alepinto          #+#    #+#             */
/*   Updated: 2023/07/19 10:54:49 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "libft.h"

int	ft_segcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
				count++;
		i++;
	}
	return (count);
}