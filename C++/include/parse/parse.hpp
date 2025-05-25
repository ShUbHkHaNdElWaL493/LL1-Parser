/*
    Shubh Khandelwal
*/

#ifndef PARSE_HPP
#define PARSE_HPP

#include <datatypes/datatypes.hpp>
#include <fstream>
#include <string>
#include <vector>

class LL1Parser
{

    private:

    std::vector<std::string> rules;
    std::set<Terminal> terminals;
    std::set<NonTerminal> non_terminals;
    std::vector<std::vector<int>> parse_table;

    void set_rules(std::ifstream&);
    void set_symbols();
    void set_firsts();
    void set_follows();
    void set_parse_table();

    public:

    LL1Parser(std::ifstream&);
    void get_parse_table();
    bool parse(std::string);

};

#endif