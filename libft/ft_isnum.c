#include "libft.h"

int ft_isnum(char *s)
{
    while (*s)
    {
        if (!ft_isdigit(*s))
            return (0);
        s++;
    }
    return (1);
}