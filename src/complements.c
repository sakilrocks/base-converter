#include <stdio.h>
#include <string.h>

#include "../include/complements.h"

void onesComplement(void)
{
    char binary[65];

    printf("Enter binary number: ");
    scanf("%64s", binary);

    for (int i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] == '0')
            binary[i] = '1';
        else if (binary[i] == '1')
            binary[i] = '0';
    }

    printf("1's Complement: %s\n", binary);
}


void twosComplement(void)
{
    char binary[65];

    printf("Enter binary number: ");
    scanf("%64s", binary);

    int len = strlen(binary);

    for (int i = 0; i < len; i++)
    {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '0')
        {
            binary[i] = '1';
            break;
        }

        binary[i] = '0';
    }

    printf("2's Complement: %s\n", binary);
}


void signedMagnitude(void)
{
    int number;

    printf("Enter decimal number: ");
    scanf("%d", &number);

    if (number >= 0)
        printf("Sign bit = 0\n");
    else
        printf("Sign bit = 1\n");

    printf("Magnitude = %d\n", number >= 0 ? number : -number);
}


void onesComplementRepresentation(void)
{
    printf("------ 1's Complement Representation ------\n");
}


void twosComplementRepresentation(void)
{
    printf("------ 2's Complement Representation ------\n");
}


