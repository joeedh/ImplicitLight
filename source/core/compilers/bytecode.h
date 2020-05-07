#ifndef _BYTECODE_H
#define _BYTECODE_H

#include <stdint.h>

namespace machine {
typedef struct ByteCode {
    short opcode;
    union {
        uint8_t data[10];
        uint8_t args[4];
        int16_t data16[4];
        int32_t data32[2];
        int64_t data;
    } data;
} ByteCode;

#define MAXREGS 32

typedef struct Machine {
    int stack, program;
    double regs[64];
    ByteCode *bytecode;
    int bytecode_len;
} Machine;

enum {
    BUILTIN_SIN,
    BUILTIN_COS,
    BUILTIN_ASIN,
    BUILTIN_ACOS,
    BUILTIN_TAN,
    BUILTIN_ATAN,
    BUILTIN_ATAN2,
    BUILTIN_EXP,
    BUILTIN_LOG,
    BUILTIN_LOG2,
    BUILTIN_POW,
    BUILTIN_SQRT,
    BUILTIN_FLOOR,
    BUILTIN_CEIL,
    BUILTIN_FRACT   
};

enum {
    OP_PUSH,
    OP_POP,    BUILTIN_NORMALIZE,
    OP_LOADREG_CONST,
    OP_LOADREG_IMMEDIATE,
    OP_LOADREG_STACK,
    OP_PUSHREG,
    OP_POPREG,
    OP_BUILTIN_CALL,

    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_EXP,
    OP_EQUALS,
    OP_NEQUALS,
    OP_LEQUALS,
    OP_GEQUALS,
    OP_LESS,
    OP_GREATER,
    OP_AND,
    OP_OR,
    OP_DV,
    OP_CALL,
    OP_BRANCH //if_branch_len else_branch_len
};

}

#endif /* _BYTECODE_H */
