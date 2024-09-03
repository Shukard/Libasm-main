#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"

int main () {
	const char *str = "Hello World!";
	const int nb = 42;
	const void *ptr = &str;
	ssize_t asm_ext_status = 0;
	ssize_t c_ext_status = 0;


	printf("Output of the ASM write with a str element : '%s'\n", str);
	asm_ext_status = ft_write(1, str, strlen(str));
	printf("\n\n");
	printf("Output of the C write with a str element : '%s'\n", str);
	c_ext_status = write(1, str, strlen(str));
	printf("\n\n");
	
	printf("Exit Status of the ASM write for a str element : '%zd'\n", asm_ext_status);
	printf("Exit Status of the C write for a str element : '%zd'\n", c_ext_status);

	printf("Output of the ASM write with an int element : '%d'\n", nb);
	asm_ext_status = ft_write(1, &nb, sizeof(int));
	printf("\n");
	printf("Output of the C write with an int element : '%d'\n", nb);
	c_ext_status = write(1, &nb, sizeof(int));

	printf("Exit Status of the ASM write for an int element : '%zd'\n", asm_ext_status);
	printf("Exit Status of the C write for an int element : '%zd'\n", c_ext_status);

	printf("Output of the ASM write with a void * element : '%p'\n", ptr);
	asm_ext_status = ft_write(1, ptr, sizeof(void *));
	printf("\n");
	printf("Output of the C write with a void * element : '%p'\n", ptr);
	c_ext_status = write(1, ptr, sizeof(void *));

	printf("Exit Status of the ASM write for a void * element : '%zd'\n", asm_ext_status);
	printf("Exit Status of the C write for a void * element : '%zd'\n", c_ext_status);

	return 0;
}
