#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

int main() {
	const char *str = "Hello World!";
	const char *lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer eget nisi luctus, venenatis lorem a, consectetur purus. Morbi turpis tellus, sodales tincidunt velit sed, pretium tincidunt magna.";

	char *asm_result;
	char *c_result;

	printf("////////////////////////////// SHORT STR TEST //////////////////////////////\n\n");

	printf("Test of the ASM strdup with a short str : '%s'\n", str);
	asm_result = ft_strdup(str);
	printf("Value copied inside of the string with the ASM strdup : '%s'\n\n", asm_result);

	printf("Test of the c strdup with a short str : '%s'\n", str);
	c_result = strdup(str);
	printf("Value copied inside of the string with the c strdup : '%s'\n\n", c_result);

    	if (strcmp(asm_result, c_result) == 0) {
        	printf("The ASM strdup works perfectly !\n\n");
    	} else {
	        printf("An error occured during the copy ...\n\n");
    	}

	free(asm_result);
	free(c_result);

	printf("////////////////////////////// LONG STR TEST //////////////////////////////\n\n");

	printf("Test of the ASM strdup with a long str : '%s'\n", lorem);
	asm_result = ft_strdup(lorem);
	printf("Value copied inside of the string with the ASM strdup : '%s'\n\n", asm_result);

	printf("Test of the c strdup with a long str : '%s'\n", lorem);
	c_result = strdup(lorem);
	printf("Value copied inside of the string with the c strdup : '%s'\n\n", c_result);

   	 if (strcmp(asm_result, c_result) == 0) {
        	printf("The ASM strdup works perfectly !\n\n");
    	} else {
	        printf("An error occured during the copy ...\n\n");
    	}

	free(asm_result);
	free(c_result);

	printf("////////////////////////////// NULL TEST //////////////////////////////\n\n");

	char *others = NULL;
	printf("Test of the ASM strdup with a NULL pointer : '%s'\n", others);
	asm_result = ft_strdup(others);
	printf("Return of the ASM strdup : '%s'\n\n", asm_result);
	return 0;
}

