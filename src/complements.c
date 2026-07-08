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
    int number;
    unsigned char binary[8];

    printf("Enter a decimal number: ");
    scanf("%d", &number);

    int absNum = (number < 0) ? -number : number;

    /* Convert magnitude to binary */

    for (int i = 7; i >= 0; i--)
    {
        binary[i] = absNum % 2;
        absNum /= 2;
    }

    if (number < 0)
    {
        /* Invert all bits */
        for (int i = 0; i < 8; i++)
        {
            binary[i] = !binary[i];
        }
    }

    printf("1's Complement Representation: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", binary[i]);
    }

    printf("\n");

}


void twosComplementRepresentation(void)
{
    int number;
    unsigned char binary[8];

    printf("Enter a decimal number: ");
    scanf("%d", &number);

    int absNum = (number < 0) ? -number : number;

    /* Convert magnitude to binary */
    for (int i = 7; i >= 0; i--)
    {
        binary[i] = absNum % 2;
        absNum /= 2;
    }

    if (number < 0)
    {
        /* Invert bits */
        for (int i = 0; i < 8; i++)
        {
            binary[i] = !binary[i];
        }
        /* Add 1 */

        int carry = 1;
        for (int i = 7; i >= 0; i--)
        {
            int sum = binary[i] + carry;
            binary[i] = sum % 2;
            carry = sum / 2;
        }
    }
    printf("2's Complement Representation: ");

    for (int i = 0; i < 8; i++)
    {
        printf("%d", binary[i]);
    }

    printf("\n");

}


