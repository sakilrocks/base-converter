#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

// validation 
bool isBinary(const char *str);
bool isHex(const char *str);
bool isOctal(const char *str);


// binary conversion helpers 
void decimalToBinaryString(int decimal, char *binary);
int binaryStringToDecimal(const char *binary);


// string helpers 
void reverseString(char *str);


// console helpers
void clearInputBuffer(void);
void pauseScreen(void);

#endif