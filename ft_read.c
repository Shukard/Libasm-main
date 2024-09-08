#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libasm.h"

#define MAX_SIZE 100

int main(int ac, char **av) {

	if (ac != 2)
			return -1;

	int fd_asm = open(av[1], O_RDONLY);
	int fd_c = open(av[1], O_RDONLY);
	if (fd_c <= -1 || fd_asm <= -1)
		return -1;


	char buffer_asm[MAX_SIZE] = {0};
	char buffer_c[MAX_SIZE] = {0};
	ssize_t asm_exit_status = 0;
	ssize_t c_exit_status = 0;

	printf("Test of the ASM read with a valid fd\n");
	asm_exit_status = ft_read(fd_asm, buffer_asm, 13);
	printf("Value written inside of the buffer with the ASM read : '%s'\n", buffer_asm);
	printf("Exit Status of the ASM read : '%zd'\n\n", asm_exit_status);

	printf("Test of the C read with a valid fd\n");
	c_exit_status = read(fd_c, buffer_c, 13);
	printf("Value written inside of the buffer with the C read : '%s'\n", buffer_c);
	printf("Exit Status of the C read : '%zd'\n\n", c_exit_status);

	printf("Second use of the ASM read with the same fd\n");
	asm_exit_status = ft_read(fd_asm, buffer_asm, 13);
	printf("Value written inside of the buffer with the ASM read : '%s'\n", buffer_asm);
	printf("Exit Status of the ASM read : '%zd'\n", asm_exit_status);
	printf("Buffer is still the same cause we read everything in the file, we reach the end of file (EOF)\n\n");

	printf("Second use of the C read with the same fd\n");
	c_exit_status = read(fd_c, buffer_c, 13);
	printf("Value written inside of the buffer with the C read : '%s'\n", buffer_c);
	printf("Exit Status of the C read : '%zd'\n", c_exit_status);
	printf("Buffer is still the same cause we read everything in the file, we reach the end of file (EOF)\n\n");

	printf("Now, were gonna test the errno return of the read functions : \n\n");
	
	printf("Test of errno in the ASM read with an invalid fd\n");
	asm_exit_status = ft_read(42, buffer_asm, 42);
	printf("Exit Status of the ASM read for errno : '%zd'\n", asm_exit_status);
	printf("Errno error of this issue : '%s'\n", strerror(errno));
	printf("\nTest of errno in the C read with an invalid fd\n");
	c_exit_status = read(42, buffer_c, 42);
	printf("Exit Status of the C read for errno : '%zd'\n", c_exit_status);
	printf("Errno error of this issue : '%s'\n", strerror(errno));

	return 0;
}
