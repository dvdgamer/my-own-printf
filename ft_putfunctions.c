/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_putfunctions.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/09 12:48:00 by dponte       #+#    #+#                  */
/*   Updated: 2025/06/09 13:08:59 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	ft_putchar_and_count(int c, size_t *count)
{
	ft_putchar_fd(c, 1);
	*count += 1;
}

void	ft_putnbr_and_count(int n, size_t *count)
{
	ft_putnbr_fd(n, 1);
	*count += ft_count_digits(n);
}

void	ft_putstr_and_count(char *s, size_t *count)
{
	ft_putstr_fd(s, 1);
	*count += ft_strlen(s);
}
