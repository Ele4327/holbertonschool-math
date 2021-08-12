#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - Function that concatenates strings
 * @s1: String 1
 * @s2: String 2
 * @n: Size of n bytes to print from s2 in s1
 * Return: Pointer type char
 */

char *string_nconcat(char *s1, char *s2, unsigned int n);

/**
 * _strlen - Function that calculate lenght of string
 * @s2: String 2
 * Return: Type Int
 */

int _strlen(char *s2)
{
	int count;

	for (count = 0; s2[count] != '\0'; count++)
		; /*for vacio*/
	return (count);
}

/**
 * storestring - Function that storage strings
 * @memorry_allocate: New space in memory
 * @string: String to print
 * @n: Size of n bytes to print from s2 in s1
 * Return: Type int
 */

int storestring(char *memorry_allocate, char *string, int n)
{
	int countstring = 0;

	while (countstring < n)
	{

		memorry_allocate[countstring] = string[countstring];

		countstring++;
	}

	return (countstring);
}

/**
* string_nconcat - Function that concat
* @s1: String 1
* @s2: String 2
* @n: Size of n bytes to concatenate from s2 in s1
* Return: Type char
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{

	int lens2 = 0;

	if (s2 != NULL)
	{
		lens2 = _strlen(s2);
	}

	if (s1 == NULL && s2 == NULL)
	{
		char *emptystring = NULL;

		emptystring = (char *)malloc(sizeof(char));

		if (emptystring == NULL)
		{

			return (NULL);
		}

		*emptystring = ('\0');

		return (emptystring);
	}
	else if (n >= (lens2) && s1 != NULL && s2 != NULL)
	{
		int lens1 = _strlen(s1);
		int add = lens1 + lens2;
		int len = 0;
		char *s1s2 = (char *)malloc(sizeof(char) * (add + 1));

		if (s1s2 == NULL)
		{

			return (NULL);
		}

		len = storestring(s1s2, s1, lens1);
		storestring(s1s2 + len, s2, lens2);
		s1s2[add] = '\0';

		return (s1s2);
	}
	else
	{

		char *s1s2 = NULL;
		int lens1 = _strlen(s1);
		int add = lens1 + n;
		int len = 0;

		s1s2 = (char *)malloc(sizeof(char) * (add + 1));

		if (s1s2 == NULL)
		{
			return (NULL);
		}

		len = storestring(s1s2, s1, lens1);
		storestring(s1s2 + len, s2, n);
		s1s2[add] = '\0';

		return (s1s2);
	}
}
