#include <iostream>
#include <cstdio> // For FILE*
#include "parser.hpp"

extern FILE* yyin; // Declare yyin for file input

void yyerror(const char* msg) {
    std::cerr << "Error: " << msg << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    int result = yyparse(); // Call yyparse
    fclose(yyin);

    return result;
}