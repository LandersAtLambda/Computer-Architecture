#ifndef _CPU_H_
#define _CPU_H_

// PC: Program Counter, address of the currently executing instruction
// IR: Instruction Register, contains a copy of the currently executing instruction
// MAR: Memory Address Register, holds the memory address we're reading or writing
// MDR: Memory Data Register, holds the value to write or the value just read

// Holds all information about the CPU
struct cpu
{
  // TODO

  // PC
  int pc;

  // registers (array)
  unsigned char registers[8];

  // ram (array)
  unsigned char ram[256];
};

// ALU operations
enum alu_op
{
  ALU_MUL = 0b10100010,
  ALU_ADD = 0b10100000
  // Add more here
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI 0b10000010  // Set the value of a register to an integer.
#define PRN 0b01000111  // Print numeric value stored in the given register.
#define HLT 0b00000001  // Halt
#define MUL 0b10100010  // Multiply
#define PUSH 0b01000101 // Push
#define POP 0b01000110  // POP
#define CALL 0b01010000 // CALL
#define RET 0b00010001  // RET
#define ADD 0b10100000  // ADD

// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

extern void cpu_load(struct cpu *cpu, char *filename);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
