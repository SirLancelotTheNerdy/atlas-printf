#include "main.h" 

/* this is where we loop through the protatypes fro the main printf.c */

int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list list_of_args;

	if(format == NULL)
		return -1;
	va_start(list_of_args, format);
	while(*format)