/*
    Shubh Khandelwal
*/

#ifndef PARSE_H
#define PARSE_H

int ** getParseTable(int n, char **rules);

int parseString(char **rules, int **table, char *string);

#endif