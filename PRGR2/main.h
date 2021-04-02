#ifndef MAIN_H
#define MAIN_H
#include "mainwindow.h"
#include <iostream>
#include <vector>
#include <QApplication>
#include <QLabel>
#include <fstream>
#include <sstream>
#include <set>

constexpr char AND = '&';
constexpr char OR = '|';
constexpr char NOT = '!';
constexpr char NEMA = '0';

std::string remove_space(std::string rule);
std::vector<std::string> split_str(std::string &rule, char delim);
std::vector<std::string> nodesques();
void schitHYP();
void schitRULE();
void schitQUES();
void schitSub();

class Node{
private:
    std::string rule_string;
    std::vector<Node*> child_nodes;
    char oper;

public:

    Node(std::string new_nd);

    void parse();

    bool operator()();

    std::set<std::string> nodesques();

    void brackets(std::string fullrule, std::string &res);

};


class NotAskedException : public std::exception {
    private:
        std::string e_question;

    public :
        NotAskedException(std::string question)
            : e_question(question)
        {

        }
        const char * what () const throw () {
              return e_question.c_str();
           }

};



extern std::map <std::string, bool> mem;
extern std::string curr_var;

extern std::map <std::string, Node*> rule_nodes;
extern std::map <std::string, std::string> hyp;
extern std::map <std::string, std::string> que;
extern std::map <std::string, std::string> subvariable;

extern std::vector<std::string> var_stack;
extern std::string result;

#endif // MAIN_H
