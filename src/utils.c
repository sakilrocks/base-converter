#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/utils.h"


// validation functions

bool isBinary(const char *str)
{
    if (*str == '\0')
        return false;

    while (*str)
    {
        if (*str != '0' && *str != '1')
            return false;
        str++;
    }

    return true;
}

bool isHex(const char *str)
{
    if (*str == '\0')
        return false;

    while (*str)
    {
        if (!isxdigit((unsigned char)*str))
            return false;

        str++;
    }

    return true;
}

bool isOctal(const char *str)
{
    if (*str == '\0')
        return false;

    while (*str)
    {
        if (*str < '0' || *str > '7')
            return false;

        str++;
    }

    return true;
}




// binary conversion helpers

void reverseString(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

void decimalToBinaryString(int decimal, char *binary)
{
    int i = 0;

    if (decimal == 0)
    {
        strcpy(binary, "0");
        return;
    }

    while (decimal > 0)
    {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    binary[i] = '\0';

    reverseString(binary);
}

int binaryStringToDecimal(const char *binary)
{
    int decimal = 0;

    while (*binary)
    {
        decimal = decimal * 2 + (*binary - '0');
        binary++;
    }

    return decimal;
}



// console helpers

void clearInputBuffer(void)
{
    while (getchar() != '\n');
}

void pauseScreen(void)
{
    printf("\npress enter to continue...");
    clearInputBuffer();
    getchar();
}