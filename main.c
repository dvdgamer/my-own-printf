#include <stdio.h>
#include "libft/libft.h"
#include <stddef.h>
#include <limits.h>
#include "libftprintf.h"

int main(void)
{
    int len1;
    int len2;
    int x;
    void *ptr;
    len1 = ft_printf("Char: %c, String: %s\n", 'A', "%");
    len2 = printf("Char: %c, String: %s\n", 'A', "%");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Char: %c, String: %s\n", 'A', "Hello% World%");
    len2 = printf("Char: %c, String: %s\n", 'A', "Hello% World%");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%c\n", 0);
    len2 = printf ("%c\n", 0);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%c\n", -1);
    len2 = printf ("%c\n", -1);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%s\n", (char *)NULL);
    len2 = printf ("%s\n", (char *)NULL);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%s\n", "");
    len2 = printf ("%s\n", "");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%s\n", "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    len2 = printf ("%s\n", "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%s\n", "qqq\0qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    len2 = printf ("%s\n", "qqq\0qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%s\n", "qqq%qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    len2 = printf ("%s\n", "qqq%qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Char: %c, String: %s\n", 'A', "Hello World");
    len2 = printf("Char: %c, String: %s\n", 'A', "Hello World");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Int pos: %d, Int neg: %d\n", 12345, -12345);
    len2 = printf("Int pos: %d, Int neg: %d\n", 12345, -12345);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    len2 = printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Ints: %d %d %d %d %d\n", 0, 1, -1, 1000, -1000);
    len2 = printf("Ints: %d %d %d %d %d\n", 0, 1, -1, 1000, -1000);
    printf("Ints → ft: %d | std: %d\n\n", len1, len2);
    len1 = ft_printf("Zero pointer: %p, zero int: %d, zero unsigned: %u\n", NULL, 0, 0u);
    len2 = printf("Zero pointer: %p, zero int: %d, zero unsigned: %u\n", NULL, 0, 0u);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Unsigned max: %u\n", UINT_MAX);
    len2 = printf("Unsigned max: %u\n", UINT_MAX);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%u\n", 0);
    len2 = printf ("%u\n", 0);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%u\n", -1);
    len2 = printf ("%u\n", -1);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf ("%u\n", (unsigned int)4294967295);
    len2 = printf ("%u\n", (unsigned int)4294967295);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    x = 42;
    len1 = ft_printf("Pointer: %p\n", &x);
    len2 = printf("Pointer: %p\n", &x);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Null pointer: %p\n", (void *)0);
    len2 = printf("Null pointer: %p\n", (void *)0);
    printf("Null pointer → ft: %d | std: %d\n\n", len1, len2);
    ptr = 0;
    len1 = ft_printf("Pointer: %p\n", ptr);
    len2 = printf("Pointer: %p\n", ptr);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Hex lower: %x, Hex upper: %X\n", 305441741, 305441741);
    len2 = printf("Hex lower: %x, Hex upper: %X\n", 305441741, 305441741);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("%X, %x\n", 0, 0);
    len2 = printf("%X, %x\n", 0, 0);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("%X, %x\n", -1, -1);
    len2 = printf("%X, %x\n", -1, -1);
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    // -1 gets implicitly cast to unsigned int, which results in 0xFFFFFFFF on 32-bit systems.
    len1 = ft_printf("ULONG_MAX as uint: %u\n", (unsigned int)ULONG_MAX);
    len2 = printf("ULONG_MAX as uint: %u\n", (unsigned int)ULONG_MAX);
    printf("Overflow → ft: %d | std: %d\n\n", len1, len2);
    {
        char s[] = "Hello\0World";
        len1 = ft_printf("Embedded null: %sEND\n", s);
        len2 = printf("Embedded null: %sEND\n", s);
        printf("Embedded null → ft: %d | std: %d\n\n", len1, len2);
    }
    len1 = ft_printf("Result: %d\n", ft_printf("%d", 42));
    len2 = printf("Result: %d\n", printf("%d", 42));
    printf("Nested simple → ft: %d | std: %d\n\n", len1, len2);
    len1 = ft_printf("A[%s]B\n",
    ft_printf("X=%d", 5) > 0 ? "ok" : "err");
    len2 = printf("A[%s]B\n", printf("X=%d", 5) > 0 ? "ok" : "err");
    printf("Nested → ft: %d | std: %d\n\n", len1, len2);
    len1 = ft_printf("no specifiers\n");
    len2 = printf("no specifiers\n");
    printf("Plain text → ft: %d | std: %d\n\n", len1, len2);
    /* len1 = ft_printf(NULL); */
    len2 = printf(NULL);
    /* printf("ft_printf len: %d, printf len: %d\n\n", len1, len2); */
    printf("printf len: %d\n\n", len2);
    len1 = ft_printf("%\n");
    len2 = printf("%\n");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Percent sign: %%\n");
    len2 = printf("Percent sign: %%\n");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Percent sign: %%%\n");
    len2 = printf("Percent sign: %%%\n");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    len1 = ft_printf("Percent sign: %%%c\n");
    len2 = printf("Percent sign: %%%c\n");
    printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
    return (0);
}
