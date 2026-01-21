#include <stdio.h>
#include <math.h>

void printMenu();

int main() {
    int n1, n2, op;

    do {
        printMenu();
        scanf("%d", &op);

        if (op == 7) {
            printf("\033[1;31mExiting the calculator... Goodbye!\033[0m\n");
            break;
        }

        printf("\033[1;36m\nEnter First Number: \033[0m");
        scanf("%d", &n1);
        printf("\033[1;36mEnter Second Number: \033[0m");
        scanf("%d", &n2);

        printf("\033[1;33m--------------------------------------\033[0m\n");
        switch (op) {
            case 1: printf("\033[1;32mResult: %d + %d = %d\033[0m\n", n1, n2, n1 + n2); break;
            case 2: printf("\033[1;32mResult: %d - %d = %d\033[0m\n", n1, n2, n1 - n2); break;
            case 3: printf("\033[1;32mResult: %d * %d = %d\033[0m\n", n1, n2, n1 * n2); break;
            case 4: 
                if (n2 == 0)
                    printf("\033[1;31mError: Division by zero!\033[0m\n");
                else
                    printf("\033[1;32mResult: %d / %d = %.2f\033[0m\n", n1, n2, (float)n1 / n2);
                break;
            case 5: printf("\033[1;32mResult: %d %% %d = %d\033[0m\n", n1, n2, n1 % n2); break;
            case 6: printf("\033[1;32mResult: %d ^ %d = %.2f\033[0m\n", n1, n2, pow(n1, n2)); break;
            default: printf("\033[1;31mInvalid option! Please try again.\033[0m\n");
        }
        printf("\033[1;33m--------------------------------------\033[0m\n");

    } while (op != 7);

    return 0;
}

void printMenu() {
    printf("\n\033[1;34m      Welcome to Simple Calculator!!! 🌟\033[0m\n");
    printf("\033[1;33m-----------------------------------------------\033[0m\n");
    printf("\033[1;36mChoose one of the following options:\033[0m\n");
    printf("\033[1;32m1. Addition (+)\033[0m\n");
    printf("\033[1;32m2. Subtraction (-)\033[0m\n");
    printf("\033[1;32m3. Multiplication (*)\033[0m\n");
    printf("\033[1;32m4. Division (/)\033[0m\n");
    printf("\033[1;32m5. Modulus (%%)\033[0m\n");
    printf("\033[1;32m6. Power (^)\033[0m\n");
    printf("\033[1;31m7. Exit (Q)\033[0m\n");
    printf("\033[1;35mEnter your option: \033[0m");
}
