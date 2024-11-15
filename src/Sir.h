#ifndef SIR_H

#include <bits/stdc++.h>
using namespace std;


void interpret(const string &line);

struct BlockCode {
    vector<string> code;
};

struct IF_COND{
    string condtion;
    BlockCode block;
};

struct WHILE_LOOP{
    string condtion;
    BlockCode block;
};

struct FUNCTION{
    string name;
    vector<string> args;
    BlockCode block;
};

/** Variables **/
double GetVariable(string name);

/** opprations  **/
double MakeOperation(string expresion); 

#endif // SIR_H