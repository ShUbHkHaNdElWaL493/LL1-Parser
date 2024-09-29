/*
    Shubh Khandelwal
*/

#ifndef DATATYPES_H
#define DATATYPES_H

#ifndef Epsilon
#define Epsilon 35
#endif

typedef struct
{
    char name;
    int ready;
    int first_num;
    char first[100];
    int follow_num;
    char follow[100];
} non_terminal;

extern int t_num;
extern int nt_num;
extern char terminals[100];
extern non_terminal non_terminals[100];

struct node
{
    char data;
    struct node *next;
};

struct node * push(struct node *top, char c);

struct node * pop(struct node *top);

int position_t(char c);

int position_nt(char c);

#endif