#include "command.h"

Command::Command(const string &line) {
    type = "null";
    name = "";
    expression = "";
    vector<string> BlockNames = {"if", "while", "function"};

    if (line.size() == 0) return;
    if (line[0] == '#') return;

    size_t pos = 0;
    size_t end = 0;


    if (line.find(" ") != string::npos) {
        pos = line.find(" ");
        name = line.substr(0, pos);
        expression = line.substr(pos + 1);
    } else {
        name = line;
    }

    if (name == "if" || name == "while" || name == "function") {
        type = "block";
    } else if (internal_functions.find(name) != internal_functions.end()) {
        type = "built-in";
    } else {
        type = "expression";
        expression = line;
        name = "";
    }
}


Variable Command::runCommand() {
    if (type == "expression") return runExpression();
    if (type == "built-in") return runBuiltIn();
    if (type == "block") return runBlock();

    throw runtime_error("Invalid command type: " + type);
}


Variable Command::runBuiltIn() {
    auto it = internal_functions.find(name);
    if (it == internal_functions.end()) {
        throw runtime_error("Invalid built-in function: " + name);
    }

    return it->second(*this);
}

Variable Command::runExpression() {
    return Variable(expression);
    throw runtime_error("Not implemented");
}


Variable Command::runBlock() {
    auto it = BLOCK_FUNCTIONS.find(name);
    if (it == BLOCK_FUNCTIONS.end()) {
        throw runtime_error("Invalid block function: " + name);
    }
    return it->second(*this);
}
