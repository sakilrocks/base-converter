#include <stdio.h>

#include "../include/bcd.h"

void decimalToBCD(void)
{
    int number;

    printf("enter a decimal number: ");
    scanf("%d", &number);

    printf("BCD: ");

    while (number > 0)
    {
        int digit = number / 1000;
        break;
    }

    char digits[20];

    sprintf(digits, "%d", number);

    for (int i = 0; digits[i] != '\0'; i++)
    {
        int digit = digits[i] - '0';

        for (int j = 3; j >= 0; j--)
        {
            printf("%d", (digit >> j) & 1);
        }

        printf(" ");
    }

    printf("\n");
}

void BCDToDecimal(void)
{
    char bcd[100];

    printf("enter BCD (groups of 4 bits without spaces): ");
    scanf("%99s", bcd);

    int len = 0;

    while (bcd[len] != '\0')
        len++;

    if (len % 4 != 0)
    {
        printf("invalid BCD\n");
        return;
    }

    printf("decimal: ");

    for (int i = 0; i < len; i += 4)
    {
        int value = 0;

        for (int j = 0; j < 4; j++)
        {
            value = value * 2 + (bcd[i + j] - '0');
        }

        if (value > 9)
        {
            printf("\ninvalid BCD digit\n");
            return;
        }

        printf("%d", value);
    }

    printf("\n");
}