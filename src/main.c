#include <stdio.h>
#include "../include/conversions.h"

int main() {
    int choice;

    do {
        printf("\n");
        printf(" base conversion tool\n");
        printf("1. decimal -> binary\n");
        printf("2. binary -> decimal\n");
        printf("3. decimal -> hexadecimal\n");
        printf("4. hexadecimal -> decimal\n");
        printf("5. decimal -> octal\n");
        printf("6. octal -> decimal\n");
        printf("0. exit\n");
        printf("---------------------------------\n");
        printf("enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                decimalToBinary();
                break;

            case 2:
                binaryToDecimal();
                break;

            case 3:
                decimalToHex();
                break;

            case 4:
                hexToDecimal();
                break;

            case 5:
                decimalToOctal();
                break;

            case 6:
                octalToDecimal();
                break;

            case 0:
                printf("exiting...\n");
                break;

            default:
                printf("invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}