#include <iostream>
#include <cstdio> // For FILE*
#include "Parser.hpp"

extern FILE* yyin; // Declare yyin for file input


/*int yyFlexLexer::yylex() {
    // this call should never happen, but flex/bison requires its implementation
    throw std::runtime_error("Bad call to yyFlexLexer::yylex()");
}*/


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

    int result = yyparse(); // Call parse
    //Parse parser{ &scanner};
    //parser.parse();
    fclose(yyin);

    return result;
    //return 0;
}
