/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_putfunctions.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/09 12:48:00 by dponte       #+#    #+#                  */
/*   Updated: 2025/06/09 17:10:19 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putchar_and_count(int c, int *count)
{
	ft_putchar_fd(c, 1);
	*count += 1;
}

void	ft_putnbr_and_count(int n, int *count)
{
	ft_putnbr_fd(n, 1);
	*count += ft_count_digits(n);
}

void	ft_putstr_and_count(char *s, int *count)
{
	ft_putstr_fd(s, 1);
	*count += ft_strlen(s);
}

void	ft_putunsigned_and_count(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putunsigned_and_count(n / 10, count);
	ft_putchar_and_count((n % 10) + '0', count);
}
