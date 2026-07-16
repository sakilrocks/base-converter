#include <stdio.h>
#include "../include/conversions.h"
#include "../include/arithmetic.h"
#include "../include/bitwise.h"
#include "../include/complements.h"

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
        printf("7. addition\n");
        printf("8. subtraction\n");
        printf("9. multiplication\n");
        printf("10. bitwise AND\n");
        printf("11. bitwise OR\n");
        printf("12. bitwise XOR\n");
        printf("13. bitwise NOT\n");
        printf("14. left shift\n");
        printf("15. right shift\n");
        printf("16. 1's Complement\n");
        printf("17. 2's Complement\n");
        printf("18. signed magnitude representation\n");
        printf("19. one's complement representation\n");
        printf("20. two's complement representation\n");
        printf("21. binary -> gray code\n");
        printf("22. gray code -> binary\n");
        printf("23. decimal -> BCD\n");
        printf("24. BCD -> decimal\n");
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

            case 7:
                binaryAddition();
                break;

            case 8:
                binarySubtraction();
                break;

            case 9:
                binaryMultiplication();
                break;

            case 10:
                bitwiseAND();
                break;

            case 11:
                bitwiseOR();
                break;

            case 12:
                bitwiseXOR();
                break;

            case 13:
                bitwiseNOT();
                break;

            case 14:
                leftShift();
                break;

            case 15:
                rightShift();
                break;

            case 16:
                onesComplement();
                break;

            case 17:
                twosComplement();
                break;

            case 18:
                signedMagnitude();
                break;

            case 19:
                onesComplementRepresentation();
                break;

            case 20:
                twosComplementRepresentation();
                break;

            case 21:
                binaryToGray();
                break;
                
            case 22:
                grayToBinary();
                break;
                
            case 23:
                decimalToBCD();
                break;
                
            case 24:
                BCDToDecimal();
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