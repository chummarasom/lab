#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main()
{
    char ch, token[100][50];
    int i = 0, j = 0, k;
    FILE *f1, *f2;
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    if (f1 == NULL)
    {
        printf("Cannot open the input file.\n");
        exit(0);
    }
    ch = getc(f1);
    while (ch != EOF)
    {
        if (isalnum(ch))
        {
            if (isdigit(ch))
            {
                while (isdigit(ch) && ch != EOF)
                {
                    token[i][j++] = ch;
                    ch = getc(f1);
                }
            }
            else
            {
                while (isalnum(ch) && ch != EOF)
                {
                    token[i][j++] = ch;
                    ch = getc(f1);
                }
            }
            token[i][j] = '\0';
            i++;
            j = 0;
        }
        else if (!isspace(ch))
        {
            token[i][j++] = ch;
            token[i][j] = '\0';
            i++;
            j = 0;
            ch = getc(f1);
        }
        else if (isspace(ch))
        {
            while (isspace(ch) && ch != EOF)
            {
                ch = getc(f1);
            }
        }
    }
    for (k = 0; k < i; k++)
    {
        printf("%s", token[k]);
        if (strcmp(token[k], "int") == 0 || strcmp(token[k], "main") == 0 || strcmp(token[k], "void") == 0)
        {
            printf("\tKeyword\n");
            fprintf(f2, "%s\tKeyword\n", token[k]);
        }
        else if (strcmp(token[k], "+") == 0 || strcmp(token[k], "=") == 0)
        {
            printf("\tOperator\n");
            fprintf(f2, "%s\tOperator\n", token[k]);
        }
        else if (strcmp(token[k], ";") == 0 || strcmp(token[k], "(") == 0 || strcmp(token[k], ")") == 0 ||
                 strcmp(token[k], "{") == 0 || strcmp(token[k], "}") == 0)
        {
            printf("\tSpecial character\n");
            fprintf(f2, "%s\tSpecial character\n", token[k]);
        }
        else if (isdigit(token[k][0]))
        {
            printf("\tNumber\n");
            fprintf(f2, "%s\tNumber\n", token[k]);
        }
        else if (isalpha(token[k][0]))
        {
            printf("\tIdentifier\n");
            fprintf(f2, "%s\tIdentifier\n", token[k]);
        }
        else if (strcmp(token[k], "/") == 0)
        {
            if (strcmp(token[k + 1], "/") == 0)
            {
                printf("\n");
            }
            else
            {
                printf("\tOperator\n");
                fprintf(f2, "%s\tOperator\n", token[k]);
            }
        }
        else
        {
            printf("\tIdentifier\n");
            fprintf(f2, "%s\tIdentifier\n", token[k]);
        }
    }
    fclose(f1);
    fclose(f2);
}