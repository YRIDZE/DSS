#include "main.h"
#include <regex>

std::map <std::string, bool> mem {};
std::string curr_var;
std::map <std::string, Node*> rule_nodes;
std::map <std::string, std::string> hyp;
std::map <std::string, std::string> que;
std::map <std::string, std::string> subvariable;
std::vector<std::string> var_stack;
std::string result;
int counter = 0;

Node::Node(std::string new_nd){
    oper = NEMA;
    rule_string = new_nd;
    parse();
}

void Node::parse(){

    std::string withoutbr;
    brackets(rule_string, withoutbr);
    size_t count_OR = std::count(withoutbr.begin(), withoutbr.end(), OR);
    if (count_OR > 0) {
        std::vector<std::string> child_v = split_str(withoutbr, OR);
        for(std::string new_nd: child_v){
            child_nodes.push_back( new Node(new_nd));
        }
        oper = OR;
        return;
    }

    size_t count_AND = std::count(withoutbr.begin(), withoutbr.end(), AND);

    if (count_AND > 0) {
        std::vector<std::string> child_v = split_str(withoutbr, AND);
        for(std::string new_nd: child_v){
            child_nodes.push_back( new Node(new_nd));
        }
        oper = AND;
        return;
    }

    size_t count_NOT = std::count(withoutbr.begin(), withoutbr.end(), NOT);
    if(count_NOT > 0){
        std::string child_v = split_str(withoutbr, NOT)[1];
        //чистим ноду вектора от пробелов
        child_nodes.push_back( new Node(child_v));
        oper = NOT;
        return;
    }
}

void Node::brackets(std::string fullrule, std::string &res){
    res = fullrule;
    int brack_left = count(fullrule.begin(), fullrule.end(), '(');
    int brack_right = count(fullrule.begin(), fullrule.end(), ')');
    int nesting_level = 0;

    if (brack_left > 0 && brack_right > 0){
        int start_left = -1;
        int start_right = -1;
        for (unsigned int i = 0; i < fullrule.size(); i++){
            if (fullrule[i] == '('){
                if (nesting_level == 0){
                    start_left = i;
                }
                nesting_level++;
            }
            else if(fullrule[i] == ')'){
                if(nesting_level == 1){
                    start_right = i;
                }
                nesting_level--;
            }
            if (start_left > -1 && start_right > -1 && start_right > start_left + 1){
                std::string substring = fullrule.substr(start_left, start_right+1);
                std::stringstream sbname;
                sbname << "substr" << counter;
                counter++;
                std::regex sub (substring);
                res = regex_replace(res, sub, sbname.str());
                rule_nodes[sbname.str()] = new Node(fullrule.substr(start_left+1, start_right));
                start_left = -1;
                start_right= -1;
            }
        }
    }
}

bool Node::operator()(){

    if (mem.find(rule_string) != mem.end()) { // value is in memes
        return mem[rule_string];
    }

    if (oper == OR){
        bool result = false;
        for (Node* n : child_nodes){
            if ((*n)()){
                result = true;
                break;
            }
        }
        mem[rule_string] = result;
        return result;
    }

    if (oper == AND){
        bool result = true;
        for (Node* n : child_nodes){
            if (!(*n)()){
                result = false;
                break;
            }
        }
        mem[rule_string] = result;
        return result;
    }
    if (oper == NOT){
        bool result = !(*child_nodes[0])();
        mem[rule_string] = result;
        return result;
    }

    var_stack.push_back(rule_string);

    if (rule_nodes.find(rule_string) != rule_nodes.end()) { // func is in rules
        bool rules_var_name = (*rule_nodes[rule_string])();
        mem[rule_string] = rules_var_name;
        if(var_stack[var_stack.size()-1] == rule_string){
            var_stack.pop_back();
        }
        return rules_var_name;
    }

    throw NotAskedException(rule_string);
}

std::set<std::string> Node::nodesques(){
    std::set<std::string> result;
    if(oper == NEMA){

        if(!que[rule_string].empty() && mem.find(rule_string) != mem.end()){
            result.insert(rule_string);
        }
        if(rule_nodes.find(rule_string) != rule_nodes.end()) {
            auto vec = rule_nodes[rule_string]->nodesques();
            result.insert(vec.begin(), vec.end());
        }

    }
    else{
        for(Node* n : child_nodes){
            if (!n)
                continue;

            auto vec = n->nodesques();
            result.insert(vec.begin(), vec.end());
        }
    }
    return result;
}


std::vector<std::string> split_str(std::string &rule, char delim){

    std::vector<std::string> out;
    std::stringstream ss(rule);
    std::string s;

    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out;
}


std::string remove_space(std::string rule){
    rule.erase(remove(rule.begin(), rule.end(), ' '), rule.end());
    return rule;
}



/*
bool rule(std::string var_name) {
    if (mem.find(var_name) != mem.end()) { // value is in memes
        return mem[var_name];
    }
    if (rules.find(var_name) != rules.end()) { // func is in rules
        bool rules_var_name = rules[var_name]();
        mem[var_name] = rules_var_name;
        return mem[var_name];
    }
    throw NotAskedException(var_name);

}*/

std::string f() {

    for (auto& [key, value]: hyp) {
        var_stack.clear();
        var_stack.push_back(key);

        if((*rule_nodes[key])()) {
           return key;
        }
    }
    return "";
}


void schitHYP(){
    hyp.clear();
    std::string line;
    std::ifstream file ((QString( QCoreApplication::applicationDirPath()  + "//txt//hypos.txt" )).toStdString());
    if (file.is_open()){
        while(getline(file, line)){
            if(!line.empty()){
            std::vector<std::string> ques = split_str(line, '=');
            hyp[ques[0]] = ques[1];
            }
        }
    }
    file.close();
}

void schitRULE(){
    rule_nodes.clear();
    std::string line;
    std::ifstream file ((QString( QCoreApplication::applicationDirPath()  + "//txt//rules.txt" )).toStdString());
    if (file.is_open()){
        while(getline(file, line)){
            if(!line.empty()){
            std::vector<std::string> rul = split_str(line, '=');
            rule_nodes[remove_space(rul[1])] = new Node(remove_space(rul[0]));
            }
        }
    }
    file.close();

}

void schitQUES(){
    que.clear();
    std::string line;
    std::ifstream file ((QString( QCoreApplication::applicationDirPath()  + "//txt//questions.txt" )).toStdString());
    if (file.is_open()){
        while(getline(file, line)){
            if(!line.empty()){
            std::vector<std::string> ques = split_str(line, '=');
            que[ques[0]] = ques[1];
            }
        }
    }
    file.close();

}

void schitSub(){
    subvariable.clear();
    std::string line;
    std::ifstream file ((QString( QCoreApplication::applicationDirPath()  + "//txt//sub.txt" )).toStdString());
    if (file.is_open()){
        while(getline(file, line)){
            if(!line.empty()){
            std::vector<std::string> ques = split_str(line, '=');
            subvariable[ques[0]] = ques[1];
            }
        }
    }
    file.close();

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
