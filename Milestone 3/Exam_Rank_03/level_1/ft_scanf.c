#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	char c = fgetc(f);

	if (c == 'EOF')
		return (-1);
    	while(isSpace(c))
		c = fgetc(f);
	ungetc(c, f);
    	return (1);
}

int match_char(FILE *f, char c)
{
        char x = fgetc(f);

	if (x == 'EOF')
		return (-1);
	if (x == c)
		return (1);
	ungetc(x,f);
	return (0);
}

int scan_char(FILE *f, va_list ap)
{
        char c = fgetc(f); //lo que acaba de leer del stdin

	char *y = va_arg(ap, char *); //extrae el siguiente argumento de la lista variádica, si el usuario pone ft_scanf("%c", &c);, devuelve &c, 'y' ahora apunta a la variable donde hay que guardar el carácter leído (c)
	if (c == 'EOF')
		return (-1);
	*y = c; //guarda el carácter leído en y
	unget(c, f);

    	return (1);
}

int scan_int(FILE *f, va_list ap)
{
        // You may insert code here
    	return (0);
}

int scan_string(FILE *f, va_list ap)
{
        // You may insert code here
    	return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;

	va_start(format, ap);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(format, ap);
	return ret;
}

