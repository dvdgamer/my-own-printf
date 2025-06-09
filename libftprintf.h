/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   libftprintf.h                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: dponte <dponte@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/09 16:44:36 by dponte       #+#    #+#                  */
/*   Updated: 2025/06/09 16:44:49 by dponte       ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stddef.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_and_count(int c, int *count);
void	ft_putnbr_and_count(int n, int *count);
void	ft_putstr_and_count(char *s, int *count);
void	ft_putunsigned_and_count(unsigned int n, int *count);

#endif
