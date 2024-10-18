#include <stdio.h>
#include <string.h>
#include "libasm.h"

int main() {
	const char *str_test = "Hello World!";
	const char *same_str = "Hello World!";
	const char *diff_str = "Not the same!";

	printf("Comparison between same string with the ASM strcmp ( first param : %s | second param : %s ) == %d\n", str_test, same_str, ft_strcmp(str_test, same_str));
	printf("Comparison between same string with the C strcmp ( first param : %s | second param : %s ) == %d\n", str_test, same_str, strcmp(str_test, same_str));

	printf("Comparison between different string with the ASM strcmp ( first param : %s | second param : %s ) == %d\n", str_test, diff_str, ft_strcmp(str_test, diff_str));
	printf("Comparison between different string with the C strcmp ( first param : %s | second param : %s ) == %d\n", str_test, diff_str, strcmp(str_test, diff_str));

	char *one = NULL;
	char *two = NULL;
	printf("Test with null arguments on the ASM strcmp ( first param : %s | second param : %s ) == %d\n", one, two, ft_strcmp(one, two));

	return 0;
}
