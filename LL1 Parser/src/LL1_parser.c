/*
    Shubh Khandelwal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_LL1.h"

int main()
{
    int n;
    char string[1024] = {0};
    printf("Enter the number of production rules.\n");
    scanf("%d", &n);
    char **rules = (char **) malloc(n * sizeof(char *));
    printf("\nEnter the production rules.\n");
    for (int i = 0; i < n; i++)
    {
        char *string = (char *) malloc(1000 * sizeof(char));
        scanf("%s", string);
        rules[i] = string;
    }
    printf("\n");
    int **table = getParseTable(n, rules);
    printf("Enter the string you want to check.\n");
    scanf("%s", string);
    if (parseString(rules, table, string))
    {
        printf("The string can be parsed by this language.\n");
    } else
    {
        printf("The string can not be parsed by this language.\n");
    }
    return 0;
}