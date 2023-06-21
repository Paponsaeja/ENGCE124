#include <stdio.h>

void transfer(int decimal) {
    int binary[100] , i = 0 ;

    do {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }while (decimal > 0);

    printf("binarynumber is : ");

    for (int j = i - 1; j >= 0; j--) {  // if i = 10 number then j = 9 -> 0
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("input decimalnumber : ");
    scanf("%d", &decimal);
    transfer(decimal);
    
    return 0;
}
