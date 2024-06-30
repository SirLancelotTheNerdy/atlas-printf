#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);
    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {   
            char c = (char) va_arg(args, int);
            write(1, &c, 1);
            count++;
        }
        else if (*ptr == 's')
        {
            char *s = va_arg(args, char*);
            while (*s)
            {
                write(1, s++, 1);
                count++;
            }
        }
        else if (*ptr == '%') 
        {
            char c = '%';
            write(1, &c, 1);
            count++;
        }
        else 
        {
            write(1, ptr - 1, 1);
            write(1, ptr, 1);
            count += 2;
        }
        else 
        {
            write(1, ptr, 1);
            count++;
        }
    }
    va_end(args);

    return (count);
}