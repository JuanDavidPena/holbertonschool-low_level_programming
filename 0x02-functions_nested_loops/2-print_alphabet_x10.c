#include "holberton.h"

/**
 * print_alphabet_x10-prints alphabet in lc 10 times, followed by a new line.
 */
void print_alphabet_x10(void)
{
    char letter;
    int i;
    for (i = 0; i < 10; i++)
    {
        for (letter = 'a'; letter <= 'z'; letter++)
            _putchar(letter);

        _putchar('\n');
    }
}
