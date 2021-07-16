#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 **string_nconcat - a function that concatenates two strings.
 *@s1 : pointer to string
 *@s2 : pointer to string
 *@n : integer
 *Return: pointer to string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int k, l, i, j;
	char *s;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (k = 0; s1[k] != '\0'; k++)
	;

	for (l = 0; s2[l] != '\0'; l++)
	;

	if (n >= l)
		n = l;

	s = malloc(sizeof(char) * (k + n + 1));
	if (s == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		s[i] = s1[i];

	for (j = k; j < k + n; j++)
		s[j] = s2[j - k];

	s[j] = '\0';
	return (s);
}
