#include <vector>
#include "../bytecode.h"
#include <string>

using namespace std;

class SimdX86Compiler {
private:
    std::vector<machine::ByteCode> _bytecode;
    machine::Machine _machine;
    std::string _asmout;
    std::vector<int> _branchstack;
public:
    void compile(machine::Machine *machine);
};

