#include "Interpreter/Interpreter.h"
#include "API/API.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Interpreter* interpreter = new Interpreter();
    interpreter->run();
    delete interpreter;
    return 0;
}