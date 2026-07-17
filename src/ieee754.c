#include <stdio.h>
#include <string.h>
#include "../include/ieee754.h"
#include "../include/utils.h"

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

void IEEE754ToDecimal(void)
{
    char binary[33];

    printf("enter the 32-bit IEEE 754 binary: ");
    scanf("%32s", binary);

    if (strlen(binary) != 32)
    {
        printf("<error> input must contain exactly 32 bits.\n");
        return;
    }

    if (!isBinary(binary))
    {
        printf("<error> input contains invalid characters.\n");
        return;
    }

    IEEE754 number;
    number.bits = 0;

    for (int i = 0; i < 32; i++)
    {
        number.bits <<= 1;
        number.bits |= (binary[i] - '0');
    }

    printf("\nIEEE 754 Breakdown\n\n");

    printf("sign Bit : %c\n", binary[0]);

    printf("exponent : ");
    for (int i = 1; i <= 8; i++)
        printf("%c", binary[i]);

    printf("\n");

    printf("mantissa : ");
    for (int i = 9; i < 32; i++)
        printf("%c", binary[i]);

    printf("\n\n");

    printf("decimal: %f\n", number.value);
}