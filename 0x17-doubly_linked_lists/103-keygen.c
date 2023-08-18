#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generates a key on the basis of a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments vector
 *
 * Return: 0 it it succeeds, 1 if failure
 */
int main(int argc, char *argv[])
{
	unsigned int k, b;
	size_t length, sumation;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Application: ./keygen5 username\n");
		return (1);
	}
	length = strlen(argv[1]);
	p[0] = l[(length ^ 59) & 63];
	for (k = 0, sumation = 0; k < length; k++)
		sumation += argv[1][k];
	p[1] = l[(sumation ^ 79) & 63];
	for (k = 0, b = 1; k < length; k++)
		b *= argv[1][k];
	p[2] = l[(b ^ 85) & 63];
	for (b = argv[1][0], k = 0; k < length; k++)
		if ((char)b <= argv[1][k])
			b = argv[1][k];
	srand(b ^ 14);
	p[3] = l[rand() & 63];
	for (b = 0, k = 0; k < length; k++)
		b += argv[1][k] * argv[1][k];
	p[4] = l[(b ^ 239) & 63];
	for (b = 0, k = 0; (char)k < argv[1][0]; k++)
		b = rand();
	p[5] = l[(b ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
