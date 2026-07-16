#include <stdio.h>
#include <string.h>

#include "../include/graycode.h"
#include "../include/utils.h"

void binaryToGray(void)
{
    char binary[65];
    char gray[65];

    printf("enter a binary number: ");
    scanf("%64s", binary);

    if (!isBinary(binary))
    {
        printf("invalid binary number!\n");
        return;
    }

    gray[0] = binary[0];

    for (int i = 1; binary[i] != '\0'; i++)
    {
        gray[i] = (binary[i - 1] == binary[i]) ? '0' : '1';
    }

    gray[strlen(binary)] = '\0';

    printf("gray code: %s\n", gray);
}

void grayToBinary(void)
{
    char gray[65];
    char binary[65];

    printf("enter gray code: ");
    scanf("%64s", gray);

    if (!isBinary(gray))
    {
        printf("invalid gray code!\n");
        return;
    }

    binary[0] = gray[0];

    for (int i = 1; gray[i] != '\0'; i++)
    {
        if (gray[i] == '0')
            binary[i] = binary[i - 1];
        else
            binary[i] = (binary[i - 1] == '0') ? '1' : '0';
    }

    binary[strlen(gray)] = '\0';

    printf("binary: %s\n", binary);
}