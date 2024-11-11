#include <stdio.h>
#include <string.h>

int k = 0, i = 0, j = 0, c = 0;
char a[16], stk[15], act[10] = "SHIFT->";
void check();

int main() {
    printf("GRAMMAR is:\nE -> E+E\nE -> E*E\nE -> (E)\nE -> id\n");
    printf("Enter input string: ");
    scanf("%s", a);
    c = strlen(a);

    printf("stack\tinput\taction\n");
    for (k = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            strncpy(&stk[i], "id", 2);
            stk[i + 2] = '\0';
            a[j] = a[j + 1] = ' ';
            printf("$%s\t%s$\t%sid\n", stk, a, act);
            check();
            j++; 
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("$%s\t%s$\t%ssymbol\n", stk, a, act);
            check();
        }
    }
    return 0;
}

void check() {
    const char *reduceMsg = "REDUCE TO E";
    int z;

    for (z = 0; z < c; z++) {
        if (strncmp(&stk[z], "id", 2) == 0) {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("$%s\t%s$\t%s\n", stk, a, reduceMsg);
            break;
        }
    }

    for (z = 0; z < c - 2; z++) {
        if ((stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') ||
            (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')) {
            stk[z] = 'E';
            stk[z + 1] = stk[z + 2] = '\0';
            printf("$%s\t%s$\t%s\n", stk, a, reduceMsg);
            i -= 2;
            break;
        }
    }

    for (z = 0; z < c - 2; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = stk[z + 2] = '\0';
            printf("$%s\t%s$\t%s\n", stk, a, reduceMsg);
            i -= 2;
            break;
        }
    }
}
