#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * vprintk - print formatted data from variable args
 *
 * state:
 *  0: regular
 *  1: escape
 */
void vprintk(const char *fmt, va_list args)
{
  int state = 0;

  while (*fmt)
  {
    if (state == 0)
    {
      if (*fmt == '%')
      {
        state = 1;
      }
      else
      {
        putchar(*fmt);
      }
    }
    else if (state == 1)
    {
      switch (*fmt)
      {
      case 'c':
      {
        char ch = va_arg(args, int);
        putchar(ch);
        break;
      }
      case 's':
      {
        const char *s = va_arg(args, const char *);
        while (*s)
        {
          putchar(*s++);
        }
        break;
      }
      }

      state = 0;
    }

    fmt++;
  }
}
int _printf(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  vprintk(fmt, args);

  va_end(args);

  return (0);
}

