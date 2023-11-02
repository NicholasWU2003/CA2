/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.cc - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 *
 */

#include "inst-decoder.h"

#include <map>

/*
 * Class InstructionDecoder -- helper class for getting specific
 * information from the decoded instruction.
 */

bool InstructionDecoder::checkGeldig()
{
  // 32 bits -> is altijd 32 bits dombo want uint32
  // opcode is je  
    instructionWord 

  if ()
  {
    
    return true;
  }
  else 
  {
    return false;
  }

}

void
InstructionDecoder::setInstructionWord(const uint32_t instructionWord)
{
  bool geldig = checkGeldig(); // wanneer is een instruction geldig??



  if (geldig)
  {
    this->instructionWord = instructionWord;
  }
  else 
  { // illegal instruction hoe??


  }
}

uint32_t
InstructionDecoder::getInstructionWord() const
{
  return instructionWord;
}

uint8_t InstructionDecoder::getOpcode() const
{// get first 7 bits
  uint8_t opc_8;
  uint8_t opc_6;

  
    return instructionWord & 0x7F;
}

bool InstructionDecoder::bepaalType()
{
  uint8_t opCode = getOpcode();
  if (opCode == 0x33 || opCode == 0x23 || opCode == 0x63)
  {
    return rs2 = true;
  }
}


RegNumber
InstructionDecoder::getA() const
{// register rs1
  uint8_t opc = getOpcode();
  RegNumber regA = 0x0;

  switch (opc)
  {
  case 0x27:
    

    break;
  
  default:
    break;
  }
  return (instructionWord >> 15) & 0x1F; //bits from 19 to 14

}

RegNumber
InstructionDecoder::getB() const
{// register rs2 field only for R S B type instructions


  if (rs2)
  {
    return (instructionWord >> 20) & 0x1F;
  } 
  else
  {
    return 0; 
  }


}

RegNumber
InstructionDecoder::getD() const
{//register rd field 
  return (instructionWord >> 7) & 0x1F; // Bits 11 to 7 for rd
}


