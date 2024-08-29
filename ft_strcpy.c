#include <stdio.h>
#include <string.h>

extern char *ft_strcpy(char *, const char *);

#define MAX_SIZE 100

int main() {
    char src[MAX_SIZE] = "Hello, World!";
    char dst_asm[MAX_SIZE] = {0};
	char dst_c[MAX_SIZE] = {0};
    char expected[MAX_SIZE] = "Hello, World!";
	

    printf("Result of the ASM strcpy : %s\n", ft_strcpy(&dst_asm[0], &src[0]));
    printf("Result of the C strcpy : %s\n", strcpy(&dst_c[0], &src[0]));
	
	printf("Length of the copy of the ASM strcpy : %lu\n", strlen(dst_asm));
	printf("Length of the copy of the C strcpy : %lu\n", strlen(dst_c));

	
    if (strcmp(dst_asm, expected) == 0) {
        printf("The ASM strcpy works perfectly !\n");
    } else {
        printf("An error occured during the copy ...\n");
    }

    return 0;
}
