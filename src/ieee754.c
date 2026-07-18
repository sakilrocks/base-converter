#include <stdio.h>
#include <string.h>
#include <math.h>
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

void explainIEEE754(void)
{
    float number;

    printf("enter a decimal number: ");
    scanf("%f", &number);

    int sign = (number < 0);

    if (sign)
        number = -number;

    int integer = (int)number;
    float fraction = number - integer;

    printf("\nStep 1 : determine Sign\n");
    printf("-----------------------\n");
    printf("Sign Bit = %d\n", sign);

    // Integer to Binary 

    char intBinary[64];
    int index = 0;

    int temp = integer;

    if (temp == 0)
    {
        intBinary[index++] = '0';
    }
    else
    {
        while (temp > 0)
        {
            intBinary[index++] = (temp % 2) + '0';
            temp /= 2;
        }
    }

    intBinary[index] = '\0';

    for (int i = 0; i < index / 2; i++)
    {
        char t = intBinary[i];
        intBinary[i] = intBinary[index - i - 1];
        intBinary[index - i - 1] = t;
    }

    printf("\nStep 2 : Integer Part\n");
    printf("---------------------\n");

    printf("%d -> %s\n", integer, intBinary);

    /* Fraction */

    printf("\nStep 3 : Fraction Part\n");
    printf("----------------------\n");

    char fracBinary[64];
    int fracIndex = 0;

    float frac = fraction;

    while (frac > 0.0f && fracIndex < 23)
    {
        frac *= 2;

        if (frac >= 1.0f)
        {
            fracBinary[fracIndex++] = '1';
            printf("%.8f × 2 = %.8f -> 1\n", frac / 2, frac);
            frac -= 1.0f;
        }
        else
        {
            fracBinary[fracIndex++] = '0';
            printf("%.8f × 2 = %.8f -> 0\n", frac / 2, frac);
        }
    }

    fracBinary[fracIndex] = '\0';

    printf("\nBinary Representation\n");
    printf("---------------------\n");

    printf("%s.%s\n", intBinary, fracBinary);

    // Normalize 

    int exponent = strlen(intBinary) - 1;

    printf("\nStep 4 : Normalize\n");
    printf("------------------\n");

    printf("1.%s%s × 2^%d\n",
           intBinary + 1,
           fracBinary,
           exponent);

    int biased = exponent + 127;

    printf("\nStep 5 : Exponent\n");
    printf("-----------------\n");

    printf("Actual Exponent : %d\n", exponent);
    printf("Bias            : 127\n");
    printf("Stored          : %d\n", biased);

    char exponentBinary[9];

    for (int i = 7; i >= 0; i--)
    {
        exponentBinary[7 - i] = ((biased >> i) & 1) + '0';
    }

    exponentBinary[8] = '\0';

    printf("Exponent Bits   : %s\n", exponentBinary);

    char mantissa[24];

    strcpy(mantissa, intBinary + 1);
    strcat(mantissa, fracBinary);

    while (strlen(mantissa) < 23)
        strcat(mantissa, "0");

    mantissa[23] = '\0';

    printf("\nStep 6 : Mantissa\n");
    printf("-----------------\n");

    printf("%s\n", mantissa);

    printf("\nFinal IEEE 754\n");
    printf("-----------------\n");

    printf("%d %s %s\n",
           sign,
           exponentBinary,
           mantissa);
}