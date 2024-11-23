#include "ft_printf.h"

int main()
{
    // ft_printf(" ow8ey p 9a0hu\n");
    // ft_printf("y 8gu%\n");
    // ft_printf("%%\n");
    // ft_printf("%d\n", 69);
    // ft_printf("%i\n", -123467890);
    // ft_printf("%u\n", -2147447);
    // ft_printf("%c\n", 'N');
    // ft_printf("%s\n", "NIGGER");
    // ft_printf("fuck %s %d\n", "jews", 2905345);
    // ft_printf("%x\n", 123);
    // ft_printf("%X\n", 123);

    int x = 10;
    int i;

    i = printf("%p\n", (void*)&x);
    printf("%d", i);
    ft_printf("%p\n", (void*)&x);
    printf("%d\n", ft_puthex((unsigned long)&x, 1, 0));

    return 0;
}