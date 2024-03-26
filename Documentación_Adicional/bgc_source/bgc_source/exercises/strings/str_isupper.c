#include <stdio.h>
#include <ctype.h>

int str_isupper(char *s)
{
    while (*s != '\0')
        // cast to unsigned char to avoid undefined behavior
        if (!isupper((unsigned char)*s++))
            return 0;

    return 1;
}

int main(void)
{
    printf("%d\n", str_isupper("HELLO"));  // 1
    printf("%d\n", str_isupper("Hello"));  // 0
    printf("%d\n", str_isupper("hello"));  // 0
}
