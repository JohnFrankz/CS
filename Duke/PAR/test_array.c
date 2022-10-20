#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double myMatrix[4][3] = { {1.0, 2.5, 3.2},    //elements of myMatrix[0]
                            {7.9, 1.2, 9.9},    //elements of myMatrix[1]
                            {8.8, 3.4, 0.0},    //elements of myMatrix[2]
                            {4.5, 9.2, 1.6} };  //elements of myMatrix[3]
                        
    printf("%p\n", myMatrix);
    printf("%p\n", *myMatrix);
    printf("_______________________\n");
    printf("%p\n", myMatrix[0]);
    printf("%p\n", &myMatrix[0]);
    printf("%p\n", &myMatrix[0][0]);
    printf("%p\n", &myMatrix[0][1]);
    printf("%p\n", &myMatrix[0][2]);
    printf("_______________________\n");
    printf("%p\n", myMatrix[1]);
    printf("%p\n", &myMatrix[1]);
    printf("%p\n", &myMatrix[1][0]);
    printf("%p\n", &myMatrix[1][1]);
    printf("%p\n", &myMatrix[1][2]);
    printf("_______________________\n");
    printf("%p\n", myMatrix[2]);
    printf("%p\n", &myMatrix[2]);
    printf("%p\n", &myMatrix[2][0]);
    printf("%p\n", &myMatrix[2][1]);
    printf("%p\n", &myMatrix[2][2]);
    printf("_______________________\n");
    printf("%p\n", myMatrix[3]);
    printf("%p\n", &myMatrix[3]);
    printf("%p\n", &myMatrix[3][0]);
    printf("%p\n", &myMatrix[3][1]);
    printf("%p\n", &myMatrix[3][2]);
    printf("_______________________\n");
    printf("%f\n", *(*(myMatrix + 0) + 0));
    printf("%f\n", *(*(myMatrix + 0) + 1));
    printf("%f\n", *(*(myMatrix + 0) + 2));
    printf("%f\n", *(*(myMatrix + 1) + 0));
    printf("%f\n", *(*(myMatrix + 1) + 1));
    printf("%f\n", *(*(myMatrix + 1) + 2));
    printf("%f\n", *(*(myMatrix + 2) + 0));
    printf("%f\n", *(*(myMatrix + 2) + 1));
    printf("%f\n", *(*(myMatrix + 2) + 2));
    printf("%f\n", **(myMatrix + 2));
    printf("%f\n", **(myMatrix + 3));
    
}
// output 
// 0x7ffe35939c30
// 0x7ffe35939c30
// _______________________
// 0x7ffe35939c30
// 0x7ffe35939c30
// 0x7ffe35939c30
// 0x7ffe35939c38
// 0x7ffe35939c40
// _______________________
// 0x7ffe35939c48
// 0x7ffe35939c48
// 0x7ffe35939c48
// 0x7ffe35939c50
// 0x7ffe35939c58
// _______________________
// 0x7ffe35939c60
// 0x7ffe35939c60
// 0x7ffe35939c60
// 0x7ffe35939c68
// 0x7ffe35939c70
// _______________________
// 0x7ffe35939c78
// 0x7ffe35939c78
// 0x7ffe35939c78
// 0x7ffe35939c80
// 0x7ffe35939c88
// _______________________
// 1.000000
// 2.500000
// 3.200000
// 7.900000
// 1.200000
// 9.900000
// 8.800000
// 3.400000
// 0.000000
// 8.800000
// 4.500000