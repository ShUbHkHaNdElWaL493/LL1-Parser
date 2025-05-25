/*
    Shubh Khandelwal
*/

#include <algorithm>
#include <iostream>
#include "parse.hpp"
#include <stack>

void LL1Parser::set_rules(std::ifstream& file)
{
    rules.clear();
    std::string rule;
    while (getline(file, rule))
    {
        rules.push_back(rule);
    }
}

void LL1Parser::set_symbols()
{
    for (std::string rule : rules)
    {
        for (char c : rule)
        {
            if ((c > 32) && (c != epsilon) && (c != '='))
            {
                if (c >= 'A' && c <= 'Z')
                {
                    non_terminals.emplace(c);
                } else
                {
                    terminals.emplace(c);
                }
            }
        }
        terminals.emplace('$');
    }
}

void LL1Parser::set_firsts()
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (NonTerminal non_terminal : non_terminals)
        {
            non_terminals.erase(non_terminals.find(non_terminal));
            size_t initial_size = non_terminal.first.size();
            for (std::string rule : rules)
            {
                if (non_terminal == rule[0])
                {
                    for (int i = 1; i < rule.size(); ++i)
                    {

                        if (rule[i] == epsilon)
                        {
                            non_terminal.add_terminal_in_first(Terminal(epsilon));
                            break;
                        }

                        std::set<Terminal>::iterator position_t = terminals.find(Terminal(rule[i]));
                        if (position_t != terminals.end())
                        {
                            non_terminal.add_terminal_in_first(*position_t);
                            break;
                        }

                        std::set<NonTerminal>::iterator position_nt = non_terminals.find(NonTerminal(rule[i]));
                        if (position_nt != non_terminals.end())
                        {
                            if (non_terminal.add_non_terminal_first_in_first(*position_nt))
                            {
                                if (i == rule.size() - 1)
                                {
                                    non_terminal.add_terminal_in_first(Terminal(epsilon));
                                    break;
                                }
                            } else
                            {
                                break;
                            }
                        }

                    }
                }
            }
            size_t final_size = non_terminal.first.size();
            non_terminals.insert(non_terminal);
            if (final_size != initial_size)
            {
                flag = true;
            }
        }
    }
}

void LL1Parser::set_follows()
{
    NonTerminal l = *non_terminals.find(NonTerminal(rules[0][0]));
    non_terminals.erase(non_terminals.find(NonTerminal(rules[0][0])));
    l.add_terminal_in_follow(*terminals.find(Terminal('$')));
    non_terminals.insert(l);
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (NonTerminal non_terminal : non_terminals)
        {
            non_terminals.erase(non_terminals.find(non_terminal));
            size_t initial_size = non_terminal.follow.size();
            for (std::string rule : rules)
            {
                for (int i = 1; rule[i] != '\0'; i++)
                {
                    if (non_terminal == rule[i])
                    {
                        while (i < rule.size())
                        {
                            if (i == rule.size() - 1)
                            {
                                std::set<NonTerminal>::iterator position_nt = non_terminals.find(NonTerminal(rule[0]));
                                non_terminal.add_non_terminal_follow_in_follow(*position_nt);
                            } else
                            {

                                std::set<Terminal>::iterator position_t = terminals.find(Terminal(rule[i + 1]));
                                if (position_t != terminals.end())
                                {
                                    non_terminal.add_terminal_in_follow(*position_t);
                                    break;
                                }

                                std::set<NonTerminal>::iterator position_nt = non_terminals.find(NonTerminal(rule[i + 1]));
                                if (position_nt != non_terminals.end())
                                {
                                    if (!non_terminal.add_non_terminal_first_in_follow(*position_nt))
                                    {
                                        break;
                                    }
                                }

                            }
                            i++;
                        }
                    }
                }
            }
            size_t final_size = non_terminal.follow.size();
            non_terminals.insert(non_terminal);
            if (final_size != initial_size)
            {
                flag = true;
            }
        }
    }
}

void LL1Parser::set_parse_table()
{

    for (int i = 0; i < non_terminals.size(); i++)
    {
        std::vector<int> row(terminals.size(), -1);
        parse_table.push_back(row);
    }

    for (int i = 0; i < rules.size(); i++)
    {
        int index_nt = 0;
        for (NonTerminal non_terminal : non_terminals)
        {
            if (non_terminal == rules[i][0])
            {
                break;
            }
            index_nt++;
        }
        for (int j = 1; j < rules[i].size(); j++)
        {

            if (rules[i][j] == epsilon)
            {
                std::set<NonTerminal>::iterator non_terminal = non_terminals.find(NonTerminal(rules[i][0]));
                for (Terminal t_follow : non_terminal->follow)
                {
                    int index_t = 0;
                    for (Terminal temp : terminals)
                    {
                        if (temp == t_follow.name)
                        {
                            break;
                        }
                        index_t++;
                    }
                    if (parse_table[index_nt][index_t] == -1)
                    {
                        parse_table[index_nt][index_t] = i;
                    } else
                    {
                        std::cerr << "Error: Parsing table can not be constructed for the set of rules." << std::endl;
                        std::exit(2);
                    }
                }
                break;
            }

            std::set<Terminal>::iterator position_t = terminals.find(Terminal(rules[i][j]));
            if (position_t != terminals.end())
            {
                int index_t = 0;
                for (Terminal terminal : terminals)
                {
                    if (terminal == position_t->name)
                    {
                        break;
                    }
                    index_t++;
                }
                if (parse_table[index_nt][index_t] == -1)
                {
                    parse_table[index_nt][index_t] = i;
                    break;
                } else
                {
                    std::cerr << "Error: Parsing table can not be constructed for the set of rules." << std::endl;
                    std::exit(2);
                }
            }

            std::set<NonTerminal>::iterator position_nt = non_terminals.find(NonTerminal(rules[i][j]));
            if (position_nt != non_terminals.end())
            {
                for (Terminal t_first : position_nt->first)
                {
                    if (t_first == epsilon)
                    {
                        for (Terminal t_follow : position_nt->follow)
                        {
                            int index_t = 0;
                            for (Terminal temp : terminals)
                            {
                                if (temp == t_follow.name)
                                {
                                    break;
                                }
                                index_t++;
                            }
                            if (parse_table[index_nt][index_t] == -1)
                            {
                                parse_table[index_nt][index_t] = i;
                            } else
                            {
                                std::cerr << "Error: Parsing table can not be constructed for the set of rules." << std::endl;
                                std::exit(2);
                            }
                        }
                    } else
                    {
                        int index_t = 0;
                        for (Terminal temp : terminals)
                        {
                            if (temp == t_first.name)
                            {
                                break;
                            }
                            index_t++;
                        }
                        if (parse_table[index_nt][index_t] == -1)
                        {
                            parse_table[index_nt][index_t] = i;
                        } else
                        {
                            std::cerr << "Error: Parsing table can not be constructed for the set of rules." << std::endl;
                            std::exit(2);
                        }
                    }
                }
                break;
            }

        }
    }

}

LL1Parser::LL1Parser(std::ifstream& file)
{
    set_rules(file);
    set_symbols();
    set_firsts();
    set_follows();
    set_parse_table();
}

void LL1Parser::get_parse_table()
{
    std::ofstream file("parse_table.csv");
    file << "_";
    for (Terminal terminal : terminals)
    {
        file << "," << terminal.name;
    }
    int index_nt = 0;
    for (NonTerminal non_terminal : non_terminals)
    {
        file << std::endl << non_terminal.name;
        for (int value : parse_table[index_nt])
        {
            file << "," << value + 1;
        }
        index_nt++;
    }
    file.close();
}

bool LL1Parser::parse(std::string line)
{
    line.append("$");
    std::stack<char> list;
    list.push('$');
    list.push(rules[0][0]);
    for (char c : line)
    {

        int index_t = 0;
        for (Terminal terminal : terminals)
        {
            if (terminal == c)
            {
                break;
            }
            index_t++;
        }
        if (index_t == terminals.size())
        {
            return false;
        }

        std::set<NonTerminal>::iterator position_nt = non_terminals.find(NonTerminal(list.top()));
        while (position_nt != non_terminals.end())
        {
            
            int index_nt = 0;
            for (NonTerminal non_terminal : non_terminals)
            {
                if (non_terminal == position_nt->name)
                {
                    break;
                }
                index_nt++;
            }
            if (parse_table[index_nt][index_t] == -1)
            {
                return false;
            }

            list.pop();
            for (int i = rules[parse_table[index_nt][index_t]].size() - 1; i > 0; i--)
            {
                if ((rules[parse_table[index_nt][index_t]][i] > 32) && (rules[parse_table[index_nt][index_t]][i] != epsilon) && (rules[parse_table[index_nt][index_t]][i] != '='))
                {
                    list.push(rules[parse_table[index_nt][index_t]][i]);
                }
            }

            position_nt = non_terminals.find(NonTerminal(list.top()));

        }

        if (list.top() == c)
        {
            list.pop();
        } else
        {
            return false;
        }

    }
    return true;
}