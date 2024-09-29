/*
    Shubh Khandelwal
*/

#include <stdlib.h>
#include "datatypes.h"

int t_num = 0;
int nt_num = 0;
char terminals[100];
non_terminal non_terminals[100];

struct node * push(struct node *top, char c)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = c;
    temp->next = top;
    top = temp;
    return top;
}

struct node * pop(struct node *top)
{
    struct node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int position_t(char c)
{
    for (int i = 0; i < t_num; i++)
    {
        if (c == terminals[i])
        {
            return i;
        }
    }
    terminals[t_num] = c;
    t_num++;
    return (t_num - 1);
}

int position_nt(char c)
{
    for (int i = 0; i < nt_num; i++)
    {
        if (c == non_terminals[i].name)
        {
            return i;
        }
    }
    non_terminals[nt_num].name = c;
    non_terminals[nt_num].ready = 0;
    non_terminals[nt_num].first_num = 0;
    non_terminals[nt_num].follow_num = 0;
    nt_num++;
    return (nt_num - 1);
}