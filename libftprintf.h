
#ifndef LIBFTPRINTF_H
# define  LIBFTPRINTF_H
# include <stddef.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_and_count(int c, int *count);
void	ft_putnbr_and_count(int n, int *count);
void	ft_putstr_and_count(char *s, int *count);
void	ft_putunsigned_and_count(unsigned int n, int *count);

#endif
