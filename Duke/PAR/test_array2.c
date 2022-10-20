#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double row0[3] = {1.0, 2.5, 3.2};
    double row1[3] = {7.9, 1.2, 9.9};
    double row2[3] = {8.8, 3.4, 0.0};
    double row3[3] = {4.5, 9.2, 1.6};
    double * myMatrix[4] = {row0, row1, row2, row3};

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
// 0x7ffc7e9fe1e0
// 0x7ffc7e9fe160
// _______________________
// 0x7ffc7e9fe160
// 0x7ffc7e9fe1e0
// 0x7ffc7e9fe160
// 0x7ffc7e9fe168
// 0x7ffc7e9fe170
// _______________________
// 0x7ffc7e9fe180
// 0x7ffc7e9fe1e8
// 0x7ffc7e9fe180
// 0x7ffc7e9fe188
// 0x7ffc7e9fe190
// _______________________
// 0x7ffc7e9fe1a0
// 0x7ffc7e9fe1f0
// 0x7ffc7e9fe1a0
// 0x7ffc7e9fe1a8
// 0x7ffc7e9fe1b0
// _______________________
// 0x7ffc7e9fe1c0
// 0x7ffc7e9fe1f8
// 0x7ffc7e9fe1c0
// 0x7ffc7e9fe1c8
// 0x7ffc7e9fe1d0
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