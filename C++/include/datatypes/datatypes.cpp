/*
    Shubh Khandelwal
*/

#include "datatypes.hpp"
#include <stdlib.h>

Terminal::Terminal(char name) : name(name)
{}

bool Terminal::operator<(const Terminal &temp) const
{
    return name < temp.name;
}

bool Terminal::operator==(const char &c) const
{
    return name == c;
}

NonTerminal::NonTerminal(char name) : name(name)
{}

bool NonTerminal::operator<(const NonTerminal &temp) const
{
    return name < temp.name;
}

bool NonTerminal::operator==(const char &c) const
{
    return name == c;
}

void NonTerminal::add_terminal_in_first(Terminal temp)
{
    this->first.insert(temp);
}

void NonTerminal::add_terminal_in_follow(Terminal temp)
{
    this->follow.insert(temp);
}

bool NonTerminal::add_non_terminal_first_in_first(NonTerminal temp)
{
    bool present = false;
    for (auto terminal : temp.first)
    {
        if (terminal == epsilon)
        {
            present = true;
            continue;
        }
        this->add_terminal_in_first(terminal);
    }
    return present;
}

bool NonTerminal::add_non_terminal_first_in_follow(NonTerminal temp)
{
    bool present = false;
    for (auto terminal : temp.first)
    {
        if (terminal == epsilon)
        {
            present = true;
            continue;
        }
        this->add_terminal_in_follow(terminal);
    }
    return present;
}

void NonTerminal::add_non_terminal_follow_in_follow(NonTerminal temp)
{
    for (auto terminal : temp.follow)
    {
        this->add_terminal_in_follow(terminal);
    }
}