#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char icode[10][30], str[30], opr[10];
    int i = 0;

    printf("\nEnter the set of intermediate code (terminated by 'exit'):\n");
    while (1) {
        scanf("%s", icode[i]);
        if (strcmp(icode[i], "exit") == 0) break;
        i++;
    }

    printf("\nTarget code generation");
    printf("\n----------------------------------\n");

    for (int j = 0; j < i; j++) {
        strcpy(str, icode[j]);
        
        switch (str[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
            default:
                printf("\nInvalid operator in TAC: %s", str);
                continue;
        }

        printf("\tMov %c, R%d\n", str[2], j);
        printf("\t%s %c, R%d\n", opr, str[4], j);
        printf("\tMov R%d, %c\n", j, str[0]);
    }
}