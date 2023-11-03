/* rv64-emu -- Simple 64-bit RISC-V simulator
 *
 *    inst-decoder.cc - RISC-V instruction decoder.
 *
 * Copyright (C) 2016,2019  Leiden University, The Netherlands.
 *
 */

#include "inst-decoder.h"
#include <iostream>

#include <map>

/*
 * Class InstructionDecoder -- helper class for getting specific
 * information from the decoded instruction.
 */

bool InstructionDecoder::checkGeldig()
{
  // 32 bits -> is altijd 32 bits dombo want uint32
  // opcode is je  
    // instructionWord 

  // if ()
  // {
    
  //   return true;
  // }
  // else 
  // {
  //   return false;
  // }

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
  uint8_t opc_8 = instructionWord & 0x8F;
  uint8_t opc_7 = instructionWord & 0x7F;
  uint8_t opc_6 = instructionWord & 0x6F;

  switch(opc_6)
  {
    case ADDI: // l.addi
    case NOP: // l.sub
      return opc_6;
      break;
    default:
      break;
  }

  switch(opc_8)
  {
    case 0x15:
      return opc_8;
    default:
      break;
  }

  return instructionWord & 0x7F;
}

bool InstructionDecoder::bepaalType()
{
  uint8_t opCode = getOpcode();

  

  if (opCode == ADDI){
    I_TYPE = true;
    return true;
  }else if (opCode == SUB){
    R_TYPE = true;
    return true;
  }

  return false;
  
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


// std::ostream &operator<<(std::ostream &os, const InstructionDecoder &decoder)
// {
//   uint8_t opcode = decoder.getOpcode();
//   uint32_t instructionWord = decoder.getInstructionWord(); // Get the instruction word

//   switch (opcode)
//   {
//     case ADDI:
//       {
//         uint8_t rd = static_cast<uint8_t>(decoder >> 20) & 0x1F; // destination reg, 25-21
//         uint8_t rs1 = static_cast<uint8_t>(decoder >> 15) & 0x1F; // first source reg, bits 20-16
//         uint16_t imm = static_cast<uint16_t> (decoder & 0xA); // immediate, bits 15 - 0
        
//         break;
//       }
//     case SUB:
//       {
//         uint8_t rd = static_cast<uint8_t>(decoder >> 20) & 0x1F; // destination reg, 25-21
//         uint8_t rs1 = static_cast<uint8_t>(decoder >> 15) & 0x1F; // first source reg, bits 20-16
//         uint8_t rs2 = static_cast<uint8_t>(decoder >> 10) & 0x1F; // second source reg, bits 15- 11

//         break;
//       }
//     case NOP:
//       { 
//         os << "l.nop 0x0";
//         break;
//       }
      

//       // Handle unknown or unsupported instructions HALLLLLOOOOOOOOOOoo ik kom zo call7
//       // oh isg ik zie nu passsssss

//   }

//   return os;
// }

std::ostream &operator<<(std::ostream &os, const InstructionDecoder &decoder)
{
  uint8_t opcode = decoder.getOpcode();
  uint32_t instructionWord = decoder.getInstructionWord();

  switch (opcode)
  {
    case ADDI:
      {
        uint8_t rd = static_cast<uint8_t>((instructionWord >> 7) & 0x1F); // destination reg, 11-7
        uint8_t rs1 = static_cast<uint8_t>((instructionWord >> 15) & 0x1F); // first source reg, bits 20-16
        int16_t imm = static_cast<int16_t>(instructionWord); // sign-extend to 32-bit

        os << "ADDI r" << static_cast<int>(rd) << ", r" << static_cast<int>(rs1) << ", " << imm;
        break;
      }
    case SUB:
      {
        uint8_t rd = static_cast<uint8_t>((instructionWord >> 7) & 0x1F); // destination reg, 11-7
        uint8_t rs1 = static_cast<uint8_t>((instructionWord >> 15) & 0x1F); // first source reg, bits 20-16
        uint8_t rs2 = static_cast<uint8_t>((instructionWord >> 20) & 0x1F); // second source reg, bits 25-21

        os << "SUB r" << static_cast<int>(rd) << ", r" << static_cast<int>(rs1) << ", r" << static_cast<int>(rs2);
        break;
      }
    case NOP:
      { 
        os << "l.nop 0x0";
        break;
      }
    default:
      os << "Unknown or unsupported instruction";
      break;
  }

  return os;
}
