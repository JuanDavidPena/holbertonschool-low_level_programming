#ifndef _FUNCTION_FILE_H_
#define _FUNCTION_FILE_H_
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void print_name(char *name, void (*f)(char *));

#endif