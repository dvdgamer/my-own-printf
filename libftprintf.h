
#ifndef LIBFTPRINTF_H
# define  LIBFTPRINTF_H
# include <stddef.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_and_count(int c, size_t *count);
void	ft_putnbr_and_count(int n, size_t *count);
void	ft_putstr_and_count(char *s, size_t *count);

#endif
