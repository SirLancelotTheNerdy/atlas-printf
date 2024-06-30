#include "main.h" 

/* this is where we loop through the protatypes fro the main printf.c */

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
				return (char_print);
			}
			else if(args == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				char_print++;
			}
			else if(args == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;
				if(str == NULL)
					str = "(null)";
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				char_print += str_len;
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
						char_print++;
					}
				}
			else if (args == 'd' || args == 'i')
			{
			    
			char_print += print_num(args);
			write(1, &char_print, 4);
			}
		}
		args++;
	}
	va_end(args);
	return char_print;