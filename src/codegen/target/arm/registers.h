/* Copyright (c) 2008-2014, Avian Contributors

   Permission to use, copy, modify, and/or distribute this software
   for any purpose with or without fee is hereby granted, provided
   that the above copyright notice and this permission notice appear
   in all copies.

   There is NO WARRANTY for this software.  See license.txt for
   details. */

#ifndef AVIAN_CODEGEN_ASSEMBLER_ARM_REGISTERS_H
#define AVIAN_CODEGEN_ASSEMBLER_ARM_REGISTERS_H

#include <avian/codegen/lir.h>
#include <avian/codegen/assembler.h>

namespace avian {
namespace codegen {
namespace arm {

const uint64_t MASK_LO32 = 0xffffffff;
const unsigned MASK_LO8 = 0xff;

const int N_GPRS = 16;
const int N_FPRS = 16;
const RegisterMask GPR_MASK = 0xffff;
const RegisterMask FPR_MASK = 0xffff0000;

inline bool isFpr(lir::RegisterPair* reg)
{
  return (int8_t)reg->low >= N_GPRS;
}

inline int fpr64(Register reg)
{
  return (int8_t)reg - N_GPRS;
}
inline int fpr64(lir::RegisterPair* reg)
{
  return fpr64(reg->low);
}
inline int fpr32(Register reg)
{
  return fpr64(reg) << 1;
}
inline int fpr32(lir::RegisterPair* reg)
{
  return fpr64(reg) << 1;
}

#ifdef ARCH_arm64
const int ThreadRegister = 19;
const int StackRegister = 31;
const int LinkRegister = 30;
const int ProgramCounter = 0xFF; // i.e. unaddressable
#else
const int ThreadRegister = 8;
const int StackRegister = 13;
const int LinkRegister = 14;
const int ProgramCounter = 15;
#endif

}  // namespace arm
}  // namespace codegen
}  // namespace avian

#endif  // AVIAN_CODEGEN_ASSEMBLER_ARM_REGISTERS_H
