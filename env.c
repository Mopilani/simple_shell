#include "main.h"

/**
 * _env -
 * Void input and output.
 */
void _env()
{
    extern char **environ;
    char **dx;

    for (dx = environ; *dx; dx++)
    {
        _print_string(*dx);
        _putchar('\n');
    }
}
