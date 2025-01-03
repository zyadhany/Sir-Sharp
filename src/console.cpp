#include "Sir.h"

vector<string> COMMAND_LINES;


/**
 * @brief Run the Sir# interpreter console.
 * 
 * @return void
 */
void runConsole() {
    int lineCount = 0;
    string line;

    cout << "Welcome to Sir# Interpreter! Type 'exit' to quit.\n";
    while (true) {
        cout << "sir#[" << lineCount++ << "]> ";
        
        if (!getline(cin, line)) {
            cout << "Goodbye!\n";
            break;
        }

        if (line == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        try {
            interpret(line);
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
            // cerr << "Error[Line " << lineCount << "]: " << e.what() << endl;
        }
    }
}

int main(int argc, char *argv[]) {

    if(argc > 1) {
        COMMAND_LINES = readfile(argv[1]);
        Command command("block", "scope", "");
        command.scope = Scope(0, COMMAND_LINES.size());

        command.runCommand();
    }
    else runConsole();
    return 0;
}
