//
//  main.c
//  lab5.1
//
//  Created by Papon Saeja on 20/7/2566 BE.
//

#include <stdio.h>

int M = 2 ;

int power(int M, int N) {
    if ( N == 0) {   // power M^0 = 1
        return 1 ;
    } else if ( N == 1) {  // m^1 = M
        return M ;
    } else {
        return M * power( M, N-1 ) ;   // M * M * M ... วนจำนวน M ตาม N จนกระทั่งจะ N == 1
    }
}

int main(void) {
    int N = 2 ;
    int result = power( M, N ) ;
    printf("result = %d\n", result ) ;
    
}
