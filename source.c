/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:01:33 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 14:58:56 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	find_brackets(char *s, char br)
{
	long	it;
	long	tmp;

	it = -1;
	while (s[++it] && s[it] != br)
	{
		if (!br && (s[it] == ')' || s[it] == ']' || s[it] == '}'))
			return (-1);
		else if (s[it] == '(' && (tmp = find_brackets(&s[it + 1], ')')) == -1)
			return (-1);
		else if (s[it] == '{' && (tmp = find_brackets(&s[it + 1], '}')) == -1)
			return (-1);
		else if (s[it] == '[' && (tmp = find_brackets(&s[it + 1], ']')) == -1)
			return (-1);
		if (s[it] == '(' || s[it] == '[' || s[it] == '{')
			it += tmp;
	}
	return (s[it] == br ? it + 1 : -1);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (write(1, "\n", 1));
	while (--ac && ++av)
		if (find_brackets(*av, 0) == -1)
			write(1, "Error\n", 6);
		else
			write(1, "OK\n", 3);
	return (0);
}
