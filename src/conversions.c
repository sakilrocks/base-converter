#include <stdio.h>
#include <stdlib.h>
#include "../include/conversions.h"

void decimalToBinary() {
    int num;

    printf("enter a  decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("binary: 0\n");
        return;
    }

    int binary[32];
    int i = 0;

    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    printf("binary: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");
}

void binaryToDecimal() {
    long long binary;
    int decimal = 0;
    int base = 1;
    int remainder;

    printf("enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }

    printf("decimal: %d\n", decimal);
}

void decimalToHex() {
    int num;

    printf("enter a decimal number: ");
    scanf("%d", &num);

    printf("hexadecimal: %X\n", num);
}

void hexToDecimal() {
    char hex[20];

    printf("enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal;

    sscanf(hex, "%x", &decimal);

    printf("decimal: %d\n", decimal);
}

void decimalToOctal() {
    int num;

    printf("enter a decimal number: ");
    scanf("%d", &num);

    printf("octal: %o\n", num);
}

void octalToDecimal() {
    int octal;

    printf("enter an octal number: ");
    scanf("%o", &octal);

    printf("decimal: %d\n", octal);
}