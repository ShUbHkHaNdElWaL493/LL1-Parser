/*
    Shubh Khandelwal
*/

#ifndef DATATYPES_HPP
#define DATATYPES_HPP

// epsilon: #
#ifndef epsilon
#define epsilon 35
#endif

#include <set>

class Terminal
{
    
    public:

    char name;

    Terminal(char);
    bool operator<(const Terminal &) const;
    bool operator==(const char &) const;

};

class NonTerminal
{

    public:

    char name;
    std::set<Terminal> first, follow;
    
    NonTerminal(char);
    bool operator<(const NonTerminal &) const;
    bool operator==(const char &) const;
    void add_terminal_in_first(Terminal);
    void add_terminal_in_follow(Terminal);
    bool add_non_terminal_first_in_first(NonTerminal);
    bool add_non_terminal_first_in_follow(NonTerminal);
    void add_non_terminal_follow_in_follow(NonTerminal);

};

#endif