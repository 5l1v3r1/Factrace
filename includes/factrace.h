/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 01:41:43 by mapandel          #+#    #+#             */
/*   Updated: 2017/05/28 18:49:10 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRACE_H
# define FACTRACE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "gmp.h"

typedef struct		s_factrace
{
	mpz_t			big;
	mpz_t			factor1;
	mpz_t			factor2;
}					t_factrace;

#endif
