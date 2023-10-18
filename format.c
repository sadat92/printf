#include <stdio.h>
#include <stdarg.h>

/*
 * @int _printf - returns number of strings printed
 *
 */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  

    while (*format) {
        if (*format == '%') {
            format++; 

            if (*format == '\0') 
                break;

            if (*format == 'c') {
                int c = va_arg(args, int); 
                putchar(c);
                count++;
            } else if (*format == 's') {
                char *str = va_arg(args, char *); 
                while (*str) {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++; 
    }

    va_end(args);
    return count;
}

int main() {
    char ch = 'S';
    char *str = "Sadati, Okeyo!";
    int result;

    result = _printf("Character: %c, String: %s, Percentage: %%\n", ch, str);
    printf("\nTotal characters printed: %d\n", result);

    return 0;
}

