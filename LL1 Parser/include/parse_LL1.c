/*
    Shubh Khandelwal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "first_follow.h"
#include "parse_LL1.h"

int ** getParseTable(int n, char **rules)
{
    findFirsts(n, rules);
    findFollows(n, rules);
    int **table = (int **) malloc((nt_num) * sizeof(int *));
    for (int i = 0; i < nt_num; i++)
    {
        int *set = (int *) malloc((t_num) * sizeof(int));
        for (int j = 0; j < t_num; j++)
        {
            set[j] = -1;
        }
        table[i] = set;
    }
    for (int i = 0; i < n; i++)
    {
        int index_nt = position_nt(rules[i][0]);
        for (int j = 1; rules[i][j] != '\0'; j++)
        {
            if ((rules[i][j] == ',') || (rules[i][j] == '+') || (rules[i][j] == '-') || (rules[i][j] == '*') || (rules[i][j] == '/') || (rules[i][j] == '\'') || (rules[i][j] == '(')  || (rules[i][j] == ')') || ((rules[i][j] >= 'a') && (rules[i][j] <= 'z')))
            {
                int index_t = position_t(rules[i][j]);
                if (table[index_nt][index_t] == -1)
                {
                    table[index_nt][index_t] = i;
                } else
                {
                    printf("An LL1 parsing table can not be constructed for the above language.\n");
                    exit(0);
                }
                break;
            } else if ((rules[i][j] >= 'A') && (rules[i][j] <= 'Z'))
            {
                int index2 = position_nt(rules[i][j]);
                for (int k = 0; k < non_terminals[index2].first_num; k++)
                {
                    if (non_terminals[index2].first[k] == Epsilon)
                    {
                        for (int l = 0; l < non_terminals[index2].follow_num; l++)
                        {
                            int index_t = position_t(non_terminals[index2].follow[l]);
                            if (table[index_nt][index_t] == -1)
                            {
                                table[index_nt][index_t] = i;
                            } else
                            {
                                printf("An LL1 parsing table can not be constructed for the above language.\n");
                                exit(0);
                            }
                        }
                    } else
                    {
                        int index_t = position_t(non_terminals[index2].first[k]);
                        if (table[index_nt][index_t] == -1)
                        {
                            table[index_nt][index_t] = i;
                        } else
                        {
                            printf("An LL1 parsing table can not be constructed for the above language.\n");
                            exit(0);
                        }
                    }
                }
                break;
            } else if (rules[i][j] == Epsilon)
            {
                for (int k = 0; k < non_terminals[index_nt].follow_num; k++)
                {
                    int index_t = position_t(non_terminals[index_nt].follow[k]);
                    if (table[index_nt][index_t] == -1)
                    {
                        table[index_nt][index_t] = i;
                    } else
                    {
                        printf("An LL1 parsing table can not be constructed for the above language.\n");
                        exit(0);
                    }
                }
                break;
            }
        }
    }
    return table;
}

int parseString(char **rules, int **table, char *string)
{
    string[strlen(string)] = '$';
    struct node *top = NULL;
    top = push(top, '$');
    top = push(top, non_terminals[0].name);
    for (int i = 0; i < strlen(string); i++)
    {
        int index_t = position_t(string[i]);
        while ((top->data >= 'A') && (top->data <= 'Z'))
        {
            int index_nt = position_nt(top->data);
            if (table[index_nt][index_t] == -1)
            {
                return 0;
            } else
            {
                top = pop(top);
                int end = 0;
                while (rules[table[index_nt][index_t]][end] != '\0')
                {
                    end++;
                }
                end--;
                for (int j = end; j > 0; j--)
                {
                    if ((rules[table[index_nt][index_t]][j] == ',') || (rules[table[index_nt][index_t]][j] == '+') || (rules[table[index_nt][index_t]][j] == '-') || (rules[table[index_nt][index_t]][j] == '*') || (rules[table[index_nt][index_t]][j] == '/') || (rules[table[index_nt][index_t]][j] == '\'') || (rules[table[index_nt][index_t]][j] == '(')  || (rules[table[index_nt][index_t]][j] == ')') || ((rules[table[index_nt][index_t]][j] >= 'a') && (rules[table[index_nt][index_t]][j] <= 'z')) || ((rules[table[index_nt][index_t]][j] >= 'A') && (rules[table[index_nt][index_t]][j] <= 'Z')))
                    {
                        top = push(top, rules[table[index_nt][index_t]][j]);
                    }
                }
            }
        }
        if (top->data == string[i])
        {
            top = pop(top);
        } else
        {
            return 0;
        }
    }
    return 1;
}