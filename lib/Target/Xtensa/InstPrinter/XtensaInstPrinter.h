#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAINSTPRINTER_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Support/Compiler.h"

namespace llvm 
{
class MCOperand;

class XtensaInstPrinter : public MCInstPrinter 
{
public:
  XtensaInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                     const MCRegisterInfo &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

  // Automatically generated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  // Print an address with the given base, displacement and index.
  static void printAddress(unsigned Base, int64_t Disp,
                           raw_ostream &O);

  // Print the given operand.
  static void printOperand(const MCOperand &MO, raw_ostream &O);

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, unsigned RegNo) const override;
  void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot,
      const MCSubtargetInfo &STI) override;

private:
  // Print various types of operand.
  void printOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBranchTarget(const MCInst *MI, int OpNum, raw_ostream &O);
  void printJumpTarget(const MCInst *MI, int OpNum,raw_ostream &O);
  void printCallOperand(const MCInst *MI, int OpNum,raw_ostream &O);
  void printMemOperand(const MCInst *MI, int OpNUm, raw_ostream &O);
  void printMemRegOperand(const MCInst *MI, int OpNUm, raw_ostream &O);
  void printAccessRegOperand(const MCInst *MI, int OpNum, raw_ostream &O);

  void printImm8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm8_sh8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O); 
  void printImm7n_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm12_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImmn_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printShimm4_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printShimm5_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m16_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m32_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset4m32_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printEntry_Imm12_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printB4const_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printB4constu_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  
  // Print the mnemonic for a condition-code mask ("ne", "lh", etc.)
  // This forms part of the instruction name rather than the operand list.
  void printCond4Operand(const MCInst *MI, int OpNum, raw_ostream &O);
};
} // end namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSAINSTPRINTER_H */

