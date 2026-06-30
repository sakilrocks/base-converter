#include <stdio.h>
#include "../include/bitwise.h"

void bitwiseAND() {
    int a, b;

    printf("enter first number: ");
    scanf("%d", &a);

    printf("enter second number: ");
    scanf("%d", &b);

    printf("result: %d\n", a & b);
}

void bitwiseOR() {
    int a, b;

    printf("enter first number: ");
    scanf("%d", &a);

    printf("enter second number: ");
    scanf("%d", &b);

    printf("result: %d\n", a | b);
}

void bitwiseXOR() {
    int a, b;

    printf("enter first number: ");
    scanf("%d", &a);

    printf("enter second number: ");
    scanf("%d", &b);

    printf("result: %d\n", a ^ b);
}

void bitwiseNOT() {
    int a;

    printf("enter number: ");
    scanf("%d", &a);

    printf("result: %d\n", ~a);
}

void leftShift() {
    int a, shift;

    printf("enter number: ");
    scanf("%d", &a);

    printf("shift by: ");
    scanf("%d", &shift);

    printf("result: %d\n", a << shift);
}

void rightShift() {
    int a, shift;

    printf("enter number: ");
    scanf("%d", &a);

    printf("shift by: ");
    scanf("%d", &shift);

    printf("result: %d\n", a >> shift);
}