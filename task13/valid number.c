#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isNumber(char *s)
{
    int num = 0;
    int exp = 0;
    int sign = 0;
    int dec = 0;

    while (*s != '\0')
    {
        if (*s >= '0' && *s <= '9')
        {
            num = 1; 
        }
        else if (*s == 'e' || *s == 'E')
        {
            if (exp || !num)
                return false; 
            exp = 1;          
            sign = 0;         
            num = 0;          
            dec = 0;
        }
        else if (*s == '+' || *s == '-')
        {
            if (sign || num || dec)
                return false; 
            sign = 1;         
        else if (*s == '.')
        {
            if (dec || exp)
                return false; 
            dec = 1;         l
        }
        else
        {
            return false;
        }

        s++; 
    }
    }


    return num; 
}

int main()
{
    printf("%d", isNumber("+6e-1"));
    return 0;
}
