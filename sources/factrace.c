/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 01:43:25 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/28 17:54:36 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static t_factrace	*factrace_search_solution(t_factrace *f)
{
	if (mpz_cmp_ui(f->big, 4) < 0)
		return (NULL);
	while (!mpz_divisible_p(f->big, f->factor1))
		mpz_add_ui(f->factor1, f->factor1, 1);
	mpz_divexact(f->factor2, f->big, f->factor1);
	if (!mpz_cmp_ui(f->factor2, 1))
		return (NULL);
	return (f);
}

static void			del_t_factrace(t_factrace *f)
{
	mpz_clear(f->big);
	mpz_clear(f->factor1);
	mpz_clear(f->factor2);
	free(f);
}

static t_factrace	*init_t_factrace(t_factrace *f)
{
	char			*stdin;
	int				i;

	i = 0;
	if (!(stdin = (char*)malloc(sizeof(char) * 10000000)))
		return (NULL);
	while (read(0, &stdin[i], 1) > 0 && stdin[i] != '\n')
		++i;
	if (!i)
	{
		free(stdin);
		return (NULL);
	}
	if (!(f = (t_factrace*)malloc(sizeof(t_factrace))))
		return (NULL);
	mpz_init(f->big);
	mpz_set_str(f->big, stdin, 10);
	mpz_init(f->factor1);
	mpz_set_ui(f->factor1, 2);
	mpz_init(f->factor2);
	mpz_set_ui(f->factor2, 2);
	free(stdin);
	return (f);
}

int					main(int argc, char **argv)
{
	t_factrace		*f;

	f = NULL;
	if (argc != 2)
		return (-1);
	(void)argv;
	while (1)
	{
		if (!(f = init_t_factrace(f)))
			return (0);
		if (!(f = factrace_search_solution(f)))
			return (-1);
		gmp_printf("%Zd=%Zd*%Zd\n", f->big, f->factor1, f->factor2);
		del_t_factrace(f);
	}
}
