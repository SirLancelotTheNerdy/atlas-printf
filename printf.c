#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                count += _putchar(va_arg(args, int));
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    count += _putchar(*str);
                    str++;
                }
            }
            else if (format[i] == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}




/*
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list args;

	if(format == NULL)
		return -1;
	va_start(args, format);
	while(args)
{
		if(args != '%')
		{
			write(1, args, 1);
			char_print++;
		}
		else
		{
			args++;
			if(args == '\0')
			{
				return (chara_print);
			}
			else if(args == 'c')
			{
				char c = va_arg(*formant, int);
				write(1, &c, 1);
				chara_print++;
			}
			else if(args == 's')
			{
				char *str = va_arg(*formant, char*);
				int str_len = 0;
				if(str == NULL)
					str = "(null)";
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_print += str_len;
			}
			else if(args == '%')
				{
					if (args + 1) == '%')
					{
						return (0);
					}
					else
					{
						write(1, args, 1);
						chara_print++;
					}
				}
			else if (args == 'd' || args == 'i')
			{
			    
			chara_print += print_num(args);
			write(1, &chara_print, 4);
			}
		}
		args++;
	}
	va_end(args);
	va_end(*formant);
	return chara_print;
}*/