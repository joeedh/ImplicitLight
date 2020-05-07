#include "simd_x86.h"

using namespace machine;
using namespace std;

static int write_asm(char *buf, ByteCode *b) {
    buf[0] = 0;

    switch (b->opcode) {
        case OP_ADD:
            sprintf(buf, "add_ps_ps %i %i", b->data.data[0], b->data.data[1]);
            break;
    }
    
    return 0;
}

void SimdX86Compiler::compile(machine::Machine *machine) {
    int i;
    char _buf[512];
    char *buf = reinterpret_cast<char*>(_buf);
    
    ByteCode *b = machine->bytecode;

    for (i=0; i<machine->bytecode_len; i++, b++) {
        write_asm(buf, b);
        
        _asmout += buf;
        _asmout += "\n";
    }


}
