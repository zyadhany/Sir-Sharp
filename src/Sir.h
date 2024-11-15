#ifndef SIR_H
#define SIR_H

#include <bits/stdc++.h>
using namespace std;



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

/** Interpting **/
void interpret(const string &line);

/** executing **/
void executeToken(vector<string> &tokens);

/** Variables **/
double GetVariable(string name);

/** opprations  **/
bool IsValidOperation(string expresion);
double MakeOperation(string expresion); 

/** Parsing **/
vector<string> parseCommandLine(const string &line);

#endif // SIR_H
