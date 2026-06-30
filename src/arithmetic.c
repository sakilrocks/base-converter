#include <stdio.h>
#include "../include/arithmetic.h"

void binaryAddition() {
    int a, b;

    printf("enter first decimal number: ");
    scanf("%d", &a);

    printf("enter second decimal number: ");
    scanf("%d", &b);

    printf("result (decimal): %d\n", a + b);
}


void binarySubtraction() {
    int a, b;

    printf("enter first decimal number: ");
    scanf("%d", &a);

    printf("enter second decimal number: ");
    scanf("%d", &b);

    printf("result (decimal): %d\n", a - b);
}


void binaryMultiplication() {
    int a, b;

    printf("enter first decimal number: ");
    scanf("%d", &a);

    printf("enter second decimal number: ");
    scanf("%d", &b);

    printf("result (decimal): %d\n", a * b);
}