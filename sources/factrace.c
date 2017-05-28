/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 01:43:25 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/28 04:42:31 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static void			del_t_factrace(t_factrace *f)
{
	t_factrace		*tmp;

	while (f)
	{
		tmp = f;
		f = f->next;
		mpz_clear(tmp->big);
		mpz_clear(tmp->factor1);
		mpz_clear(tmp->factor2);
		free(tmp);
	}
}

static t_factrace	*init_t_factrace(t_factrace *f)
{
	t_factrace		*start;
	char			*stdin;

	start = f;
	if (!(stdin = (char*)malloc(sizeof(char) * 10000000))
		|| read(1, stdin, 10000000) == -1)
		return (NULL);
	while ()//parsing every line
	{
		if (!(f = (t_factrace*)malloc(sizeof(t_factrace))))
			return (NULL);
		mpz_init(f->big);
		//evaluate big with the line value
		mpz_init(f->factor1);
		mpz_init(f->factor2);
		f = f->next;
	}
	free(stdin);
	return (start);
}

int					main(void)
{
	t_factrace		*f;
	t_factrace		*start;

	start = f;
	if (!(f = init_t_factrace(f)))
		return (-1);
	while (f)
	{
		//f = factrace_search_solution(f);
		//f = factrace_write_output(f);
		f = f->next;
	}
	del_t_factrace(start);
	return (0);
}
