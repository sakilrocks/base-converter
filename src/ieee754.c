#include <stdio.h>
#include "../include/ieee754.h"

typedef union
{
    float value;
    unsigned int bits;
} IEEE754;

void decimalToIEEE754(void)
{
    IEEE754 number;

    printf("enter a decimal number: ");
    scanf("%f", &number.value);

    printf("\nIEEE 754 (32-bit)\n\n");

    printf("Binary : ");

    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (number.bits >> i) & 1);

        if (i == 31 || i == 23)
            printf(" ");
    }

    printf("\n");

    unsigned int sign = (number.bits >> 31) & 1;
    unsigned int exponent = (number.bits >> 23) & 0xFF;
    unsigned int mantissa = number.bits & 0x7FFFFF;

    printf("\nSign Bit  : %u\n", sign);

    printf("exponent : ");

    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (exponent >> i) & 1);
    }

    printf(" (%u)\n", exponent);

    printf("mantissa : ");

    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (mantissa >> i) & 1);
    }

    printf("\n");
}