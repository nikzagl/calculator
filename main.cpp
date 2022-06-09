#include <iostream>
#include<string>
#include "processing.h"
#include <fstream>
int main() {
    std::ifstream in;
    int command;
    int N;
    std::string variable,value;
    std::string filename,expr;
    while (true) {
        std::cout<<"Input a command: 0 - exit, other - determine the value of the expression from file: ";
        std::cin>>command;
        if(!command)
            break;
        std::cout<<"Input a filename: ";
        std::cin>>filename;
        in.open(filename);
        if(in.is_open()) {
            in >> N;
            in >> expr;
            node *queue = make_polish_notation(expr);
            for(int i=0;i<N;i++)
            {
                in>>variable;
                in>>value;
                replace_tokens(queue,variable,value);
            }
            std::cout<<calculate(queue)<<"\n";

        }
        in.close();
    }
    return 0;
}