#include <stdio.h>
#include <string.h>
#include "libasm.h"

int main() {
    const char *str = "Hello, World!";
    printf("Length of '%s' with the ASM strlen : %lu\n", str, ft_strlen(str));
    printf("Length of '%s' with the C strlen : %lu\n", str, strlen(str));
    return 0;
}
