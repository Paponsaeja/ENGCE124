#include <stdio.h>

int main() {
    int decimal;
    printf("input your decimal : ") ;
    scanf("%d", &decimal );
    char character = (char)decimal;

    printf("The character for decimal %d is '%c'\n", decimal, character);

    return 0;
}
