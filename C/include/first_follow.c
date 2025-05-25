/*
    Shubh Khandelwal
*/

#include "first_follow.h"

void addTerminalInFirst(non_terminal *A, char c)
{
    for (int i = 0; i < A->first_num; i++)
    {
        if (A->first[i] == c)
        {
            return;
        }
    }
    A->first[A->first_num] = c;
    A->first_num++;
}

int addNonTerminalInFirst(non_terminal *A, non_terminal B)
{
    int epsilon = 0;
    for (int i = 0; i < B.first_num; i++)
    {
        if (B.first[i] == Epsilon)
        {
            epsilon = 1;
            continue;
        }
        addTerminalInFirst(A, B.first[i]);
    }
    return epsilon;
}

void addTerminalInFollow(non_terminal *A, char c)
{
    for (int i = 0; i < A->follow_num; i++)
    {
        if (A->follow[i] == c)
        {
            return;
        }
    }
    A->follow[A->follow_num] = c;
    A->follow_num++;
}

int addNonTerminalFirstInFollow(non_terminal *A, non_terminal B)
{
    int epsilon = 0;
    for (int i = 0; i < B.first_num; i++)
    {
        if (B.first[i] == Epsilon)
        {
            epsilon = 1;
            continue;
        }
        addTerminalInFollow(A, B.first[i]);
    }
    return epsilon;
}

int addNonTerminalFollowInFollow(non_terminal *A, non_terminal B)
{
    int dollar = 0;
    for (int i = 0; i < B.follow_num; i++)
    {
        if (B.follow[i] == '$')
        {
            dollar = 1;
            continue;
        }
        addTerminalInFollow(A, B.follow[i]);
    }
    return dollar;
}

void findFirsts(int n, char **rules)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; rules[i][j] != '\0'; j++)
        {
            if ((rules[i][j] == ',') || (rules[i][j] == '+') || (rules[i][j] == '-') || (rules[i][j] == '*') || (rules[i][j] == '/') || (rules[i][j] == '\'') || (rules[i][j] == '(')  || (rules[i][j] == ')') || ((rules[i][j] >= 'a') && (rules[i][j] <= 'z')))
            {
                position_t(rules[i][j]);
            }
        }
    }
    position_t('$');
    for (int i = 0; i < n; i++)
    {
        position_nt(rules[i][0]);
    }
    int ready = 0;
    while (ready != nt_num)
    {
        ready = 0;
        for (int i = 0; i < nt_num; i++)
        {
            if (non_terminals[i].ready == 1)
            {
                continue;
            }
            non_terminals[i].ready = 1;
            for (int j = 0; j < n; j++)
            {
                if (rules[j][0] == non_terminals[i].name)
                {
                    for (int k = 1; rules[j][k] != '\0' && rules[j][k] != non_terminals[i].name; k++)
                    {
                        if ((rules[j][k] == ',') || (rules[j][k] == '+') || (rules[j][k] == '-') || (rules[j][k] == '*') || (rules[j][k] == '/') || (rules[j][k] == '\'') || (rules[j][k] == '(') || (rules[j][k] == ')') || (rules[j][k] == Epsilon) || ((rules[j][k] >= 'a') && (rules[j][k] <= 'z')))
                        {
                            addTerminalInFirst(&non_terminals[i], rules[j][k]);
                            break;
                        } else if (((rules[j][k] >= 'A') && (rules[j][k] <= 'Z')))
                        {
                            int index = position_nt(rules[j][k]);
                            if (non_terminals[index].ready == 0)
                            {
                                non_terminals[i].ready = 0;
                            } else
                            {
                                if (addNonTerminalInFirst(&non_terminals[i], non_terminals[index]))
                                {
                                    if (rules[j][k + 1] == '\0')
                                    {
                                        addTerminalInFirst(&non_terminals[i], Epsilon);
                                    } else
                                    {
                                        continue;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < nt_num; i++)
        {
            ready += non_terminals[i].ready;
        }
    }
}

void findFollows(int n, char **rules)
{
    for (int i = 0; i < nt_num; i++)
    {
        non_terminals[i].ready = 0;
    }
    addTerminalInFollow(&non_terminals[0], '$');
    int ready = 0;
    while (ready != nt_num)
    {
        ready = 0;
        for (int i = 0; i < nt_num; i++)
        {
            if (non_terminals[i].ready == 1)
            {
                continue;
            }
            non_terminals[i].ready = 1;
            for (int j = 0; j < n; j++)
            {
                for (int k = 1; rules[j][k] != '\0'; k++)
                {
                    if (rules[j][k] == non_terminals[i].name)
                    {
                        while (rules[j][k] != '\0')
                        {
                            if (rules[j][k + 1] == '\0')
                            {
                                int index = position_nt(rules[j][0]);
                                if (non_terminals[index].ready)
                                {
                                    if (addNonTerminalFollowInFollow(&non_terminals[i], non_terminals[index]))
                                    {
                                        addTerminalInFollow(&non_terminals[i], '$');
                                    }
                                } else
                                {
                                    non_terminals[i].ready = 0;
                                }
                            } else if ((rules[j][k + 1] == ',') || (rules[j][k + 1] == '+') || (rules[j][k + 1] == '-') || (rules[j][k + 1] == '*') || (rules[j][k + 1] == '/') || (rules[j][k + 1] == '\'') || (rules[j][k + 1] == '(') || (rules[j][k + 1] == ')') || (rules[j][k + 1] == Epsilon) || ((rules[j][k + 1] >= 'a') && (rules[j][k + 1] <= 'z')))
                            {
                                addTerminalInFollow(&non_terminals[i], rules[j][k + 1]);
                                break;
                            } else if (((rules[j][k + 1] >= 'A') && (rules[j][k + 1] <= 'Z')))
                            {
                                int index = position_nt(rules[j][k + 1]);
                                if (addNonTerminalFirstInFollow(&non_terminals[i], non_terminals[index]))
                                {
                                    if (rules[j][k + 2] == '\0')
                                    {
                                        addTerminalInFollow(&non_terminals[i], '$');
                                        break;
                                    }
                                } else
                                {
                                    break;
                                }
                            }
                            k++;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < nt_num; i++)
        {
            ready += non_terminals[i].ready;
        }
    }
}