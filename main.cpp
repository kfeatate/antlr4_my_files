#include <iostream>
#include "antlr4-runtime.h"
#include "arithmeticUserVisitor.h"
#include "arithmeticParser.h"
#include "arithmeticLexer.h"


int main() {
    antlr4::ANTLRInputStream input("6*(2+3)");
    arithmeticLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    arithmeticParser parser(&tokens);
    std::cout << parser.expr()->toStringTree() << std::endl;
    return 0;
}