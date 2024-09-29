/*
    Shubh Khandelwal
*/

#include "datatypes.h"

#ifndef FIRST_FOLLOW_H
#define FIRST_FOLLOW_H

void addTerminalInFirst(non_terminal *A, char c);

int addNonTerminalInFirst(non_terminal *A, non_terminal B);

void addTerminalInFollow(non_terminal *A, char c);

int addNonTerminalFirstInFollow(non_terminal *A, non_terminal B);

int addNonTerminalFollowInFollow(non_terminal *A, non_terminal B);

void findFirsts(int n, char **rules);

void findFollows(int n, char **rules);

#endif