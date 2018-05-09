/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:01:33 by exam              #+#    #+#             */
/*   Updated: 2018/05/09 19:57:52 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*find_brackets(char *s, char br)
{
	--s;
	while (*++s && *s != br)
		if (!br && (*s == ')' || *s == ']' || *s == '}'))
			return (0);
		else if (*s == '(' && (s = find_brackets(s + 1, ')')) == 0)
			return (0);
		else if (*s == '{' && (s = find_brackets(s + 1, '}')) == 0)
			return (0);
		else if (*s == '[' && (s = find_brackets(s + 1, ']')) == 0)
			return (0);
	return (*s == br ? s : 0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (write(1, "\n", 1));
	while (--ac && ++av)
		if (find_brackets(*av, 0) == 0)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
	return (0);
}
