/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string>
#include <sstream>

#include "pyELF.hpp"

#include "LIEF/ELF/hash.hpp"
#include "LIEF/ELF/NoteDetails/core/CorePrStatus.hpp"

#include "LIEF/ELF/EnumToString.hpp"

#include "enums_wrapper.hpp"

#define PY_ENUM(x) LIEF::ELF::to_string(x), x

namespace LIEF {
namespace ELF {

template<class T>
using getter_t = T (CorePrStatus::*)(void) const;

template<class T>
using setter_t = void (CorePrStatus::*)(T);

template<>
void create<CorePrStatus>(py::module& m) {

  py::class_<CorePrStatus, NoteDetails> cls(m, "CorePrStatus");

  cls
    .def_property("siginfo",
        static_cast<getter_t<const Elf_siginfo&>>(&CorePrStatus::siginfo),
        static_cast<setter_t<const Elf_siginfo&>>(&CorePrStatus::siginfo),
        "")

    .def_property("current_sig",
        static_cast<getter_t<uint16_t>>(&CorePrStatus::current_sig),
        static_cast<setter_t<uint16_t>>(&CorePrStatus::current_sig),
        "")

    .def_property("sigpend",
        static_cast<getter_t<uint64_t>>(&CorePrStatus::sigpend),
        static_cast<setter_t<uint64_t>>(&CorePrStatus::sigpend),
        "")

    .def_property("sighold",
        static_cast<getter_t<uint64_t>>(&CorePrStatus::sighold),
        static_cast<setter_t<uint64_t>>(&CorePrStatus::sighold),
        "")

    .def_property("pid",
        static_cast<getter_t<int32_t>>(&CorePrStatus::pid),
        static_cast<setter_t<int32_t>>(&CorePrStatus::pid),
        "")

    .def_property("pgrp",
        static_cast<getter_t<int32_t>>(&CorePrStatus::pgrp),
        static_cast<setter_t<int32_t>>(&CorePrStatus::pgrp),
        "")

    .def_property("sid",
        static_cast<getter_t<int32_t>>(&CorePrStatus::sid),
        static_cast<setter_t<int32_t>>(&CorePrStatus::sid),
        "")

    .def_property("utime",
        static_cast<getter_t<Elf64_timeval>>(&CorePrStatus::utime),
        static_cast<setter_t<Elf64_timeval>>(&CorePrStatus::utime),
        "")

    .def_property("utime",
        static_cast<getter_t<Elf64_timeval>>(&CorePrStatus::utime),
        static_cast<setter_t<Elf64_timeval>>(&CorePrStatus::utime),
        "")

    .def_property("stime",
        static_cast<getter_t<Elf64_timeval>>(&CorePrStatus::stime),
        static_cast<setter_t<Elf64_timeval>>(&CorePrStatus::stime),
        "")

    .def_property("cutime",
        static_cast<getter_t<Elf64_timeval>>(&CorePrStatus::cutime),
        static_cast<setter_t<Elf64_timeval>>(&CorePrStatus::cutime),
        "")

    .def_property("cstime",
        static_cast<getter_t<Elf64_timeval>>(&CorePrStatus::cstime),
        static_cast<setter_t<Elf64_timeval>>(&CorePrStatus::cstime),
        "")

    .def("__eq__", &CorePrStatus::operator==)
    .def("__ne__", &CorePrStatus::operator!=)
    .def("__hash__",
        [] (const CorePrStatus& note) {
          return Hash::hash(note);
        })

    .def("__str__",
        [] (const CorePrStatus& note)
        {
          std::ostringstream stream;
          stream << note;
          std::string str = stream.str();
          return str;
        });


  LIEF::enum_<CorePrStatus::REGISTERS>(cls, "REGISTERS")
    .value(PY_ENUM(CorePrStatus::REGISTERS::UNKNOWN))

    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EBX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_ECX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EDX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_ESI))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EDI))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EBP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EAX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_DS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_ES))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_FS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_GS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86__))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EIP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_CS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_EFLAGS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_ESP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_SS))

    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R15))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R14))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R13))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R12))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RBP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RBX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R11))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R10))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R9))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_R8))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RAX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RCX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RDX))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RSI))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RDI))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64__))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RIP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_CS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_EFLAGS))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_RSP))
    .value(PY_ENUM(CorePrStatus::REGISTERS::X86_64_SS))

    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R0))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R1))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R2))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R3))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R4))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R5))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R6))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R7))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R8))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R9))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R10))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R11))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R12))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R13))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R14))
    .value(PY_ENUM(CorePrStatus::REGISTERS::ARM_R15))

    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X0))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X1))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X2))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X3))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X4))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X5))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X6))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X7))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X8))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X9))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X10))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X11))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X12))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X13))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X14))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X15))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X16))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X17))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X18))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X19))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X20))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X21))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X22))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X23))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X24))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X25))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X26))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X27))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X28))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X29))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X30))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_X31))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64_PC))
    .value(PY_ENUM(CorePrStatus::REGISTERS::AARCH64__));

}
} // namespace ELF
} // namespace LIEF
