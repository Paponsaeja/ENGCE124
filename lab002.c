#include <math.h>
#include <stdio.h>

void transfer( long int bin) {
    int dec = 0, i = 0, remainder;

    do {
        remainder = bin % 10;
        bin /= 10;
        dec += remainder * pow(2, i);  // pow from math meaning 2^i
        ++i;
    }while (bin != 0) ;
    
    printf("Decimal number is: %d\n", dec);
}

int main() {
    long int bin;
    printf("Enter a binary number: ");
    scanf("%ld", &bin);
    transfer(bin) ;

    return 0;
}

