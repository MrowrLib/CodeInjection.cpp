#pragma once

#include <uint128_t.h>

#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#define __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(REG_NAME, REG_TYPE) \
    REG_TYPE REG_NAME() { return CurrentValues::REG_NAME; }                    \
    template <typename T>                                                      \
    T REG_NAME(uintptr_t offset) {                                             \
        return read_memory<T>(static_cast<uintptr_t>(REG_NAME()), {offset});   \
    }                                                                          \
    template <typename T>                                                      \
    T REG_NAME(std::vector<uintptr_t> offsets) {                               \
        return read_memory<T>(static_cast<uintptr_t>(REG_NAME()), offsets);    \
    }                                                                          \
    REG_TYPE REG_NAME(uintptr_t offset) { return REG_NAME<REG_TYPE>(offset); } \
    REG_TYPE REG_NAME(std::vector<uintptr_t> offsets) { return REG_NAME<REG_TYPE>(offsets); }

namespace CodeInjection {

    enum class Register {
        EAX,
        EBX,
        ECX,
        EDX,
        ESI,
        EDI,
        ESP,
        EBP,
        RAX,
        RBX,
        RCX,
        RDX,
        RSI,
        RDI,
        RSP,
        RBP,
        R8,
        R9,
        R10,
        R11,
        R12,
        R13,
        R14,
        R15,
        // R8D,
        // R9D,
        // R10D,
        // R11D,
        // R12D,
        // R13D,
        // R14D,
        // R15D,
        // R8W,
        // R9W,
        // R10W,
        // R11W,
        // R12W,
        // R13W,
        // R14W,
        // R15W,
        // R8B,
        // R9B,
        // R10B,
        // R11B,
        // R12B,
        // R13B,
        // R14B,
        // R15B,
        // XMM0,
        // XMM1,
        // XMM2,
        // XMM3,
        // XMM4,
        // XMM5,
        // XMM6,
        // XMM7,
        // XMM8,
        // XMM9,
        // XMM10,
        // XMM11,
        // XMM12,
        // XMM13,
        // XMM14,
        // XMM15,
        // XMM16,
        // XMM17,
        // XMM18,
        // XMM19,
        // XMM20,
        // XMM21,
        // XMM22,
        // XMM23,
        // XMM24,
        // XMM25,
        // XMM26,
        // XMM27,
        // XMM28,
        // XMM29,
        // XMM30,
        // XMM31,
        // YMM0,
        // YMM1,
        // YMM2,
        // YMM3,
        // YMM4,
        // YMM5,
        // YMM6,
        // YMM7,
        // YMM8,
        // YMM9,
        // YMM10,
        // YMM11,
        // YMM12,
        // YMM13,
        // YMM14,
        // YMM15,
        // YMM16,
        // YMM17,
        // YMM18,
        // YMM19,
        // YMM20,
        // YMM21,
        // YMM22,
        // YMM23,
        // YMM24
    };

    namespace Registers {

        namespace CurrentValues {
            uint32_t EAX = 0;
            uint32_t EBX = 0;
            uint32_t ECX = 0;
            uint32_t EDX = 0;
            uint32_t ESI = 0;
            uint32_t EDI = 0;
            uint32_t ESP = 0;
            uint32_t EBP = 0;
            uint64_t RAX = 0;
            uint64_t RBX = 0;
            uint64_t RCX = 0;
            uint64_t RDX = 0;
            uint64_t RSI = 0;
            uint64_t RDI = 0;
            uint64_t RSP = 0;
            uint64_t RBP = 0;
            uint64_t R8  = 0;
            uint64_t R9  = 0;
            uint64_t R10 = 0;
            uint64_t R11 = 0;
            uint64_t R12 = 0;
            uint64_t R13 = 0;
            uint64_t R14 = 0;
            uint64_t R15 = 0;
            // uint32_t  R8D   = 0;
            // uint32_t  R9D   = 0;
            // uint32_t  R10D  = 0;
            // uint32_t  R11D  = 0;
            // uint32_t  R12D  = 0;
            // uint32_t  R13D  = 0;
            // uint32_t  R14D  = 0;
            // uint32_t  R15D  = 0;
            // uint16_t  R8W   = 0;
            // uint16_t  R9W   = 0;
            // uint16_t  R10W  = 0;
            // uint16_t  R11W  = 0;
            // uint16_t  R12W  = 0;
            // uint16_t  R13W  = 0;
            // uint16_t  R14W  = 0;
            // uint16_t  R15W  = 0;
            // uint8_t   R8B   = 0;
            // uint8_t   R9B   = 0;
            // uint8_t   R10B  = 0;
            // uint8_t   R11B  = 0;
            // uint8_t   R12B  = 0;
            // uint8_t   R13B  = 0;
            // uint8_t   R14B  = 0;
            // uint8_t   R15B  = 0;
            // uint128_t XMM0  = 0;
            // uint128_t XMM1  = 0;
            // uint128_t XMM2  = 0;
            // uint128_t XMM3  = 0;
            // uint128_t XMM4  = 0;
            // uint128_t XMM5  = 0;
            // uint128_t XMM6  = 0;
            // uint128_t XMM7  = 0;
            // uint128_t XMM8  = 0;
            // uint128_t XMM9  = 0;
            // uint128_t XMM10 = 0;
            // uint128_t XMM11 = 0;
            // uint128_t XMM12 = 0;
            // uint128_t XMM13 = 0;
            // uint128_t XMM14 = 0;
            // uint128_t XMM15 = 0;
            // uint128_t XMM16 = 0;
            // uint128_t XMM17 = 0;
            // uint128_t XMM18 = 0;
            // uint128_t XMM19 = 0;
            // uint128_t XMM20 = 0;
            // uint128_t XMM21 = 0;
            // uint128_t XMM22 = 0;
            // uint128_t XMM23 = 0;
            // uint128_t XMM24 = 0;
            // uint128_t XMM25 = 0;
            // uint128_t XMM26 = 0;
            // uint128_t XMM27 = 0;
            // uint128_t XMM28 = 0;
            // uint128_t XMM29 = 0;
            // uint128_t XMM30 = 0;
            // uint128_t XMM31 = 0;
            // uint256_t YMM0  = 0;
            // uint256_t YMM1  = 0;
            // uint256_t YMM2  = 0;
            // uint256_t YMM3  = 0;
            // uint256_t YMM4  = 0;
            // uint256_t YMM5  = 0;
            // uint256_t YMM6  = 0;
            // uint256_t YMM7  = 0;
            // uint256_t YMM8  = 0;
            // uint256_t YMM9  = 0;
            // uint256_t YMM10 = 0;
            // uint256_t YMM11 = 0;
            // uint256_t YMM12 = 0;
            // uint256_t YMM13 = 0;
            // uint256_t YMM14 = 0;
            // uint256_t YMM15 = 0;
            // uint256_t YMM16 = 0;
            // uint256_t YMM17 = 0;
            // uint256_t YMM18 = 0;
            // uint256_t YMM19 = 0;
            // uint256_t YMM20 = 0;
            // uint256_t YMM21 = 0;
            // uint256_t YMM22 = 0;
            // uint256_t YMM23 = 0;
            // uint256_t YMM24 = 0;
        }

        std::unordered_set<Register> x86_GeneralPurposeRegisters = {
            Register::EAX, Register::EBX, Register::ECX, Register::EDX,
            Register::ESI, Register::EDI, Register::ESP, Register::EBP};

        std::unordered_set<Register> x64_GeneralPurposeRegisters = {
            Register::RAX, Register::RBX, Register::RCX, Register::RDX,
            Register::RSI, Register::RDI, Register::RSP, Register::RBP,
            Register::R8,  Register::R9,  Register::R10, Register::R11,
            Register::R12, Register::R13, Register::R14, Register::R15};

        std::unordered_set<Register> GetGeneralPurposeRegisters() {
            auto registers = x86_GeneralPurposeRegisters;
            if (sizeof(intptr_t) == 8)
                registers.insert(
                    x64_GeneralPurposeRegisters.begin(), x64_GeneralPurposeRegisters.end()
                );
            return registers;
        }

        class RegistersReader {
            template <typename T>
            T read_memory(uintptr_t base_address, std::vector<uintptr_t> offsets) {
                auto address = base_address;
                for (auto offset : offsets) {
                    address = *reinterpret_cast<uintptr_t*>(address + offset);
                }
                return (T)(address);
            }

        public:
            // 32-bit general purpose registers
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(EAX, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(EBX, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ECX, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(EDX, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ESI, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(EDI, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(EBP, uint32_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ESP, uint32_t)

            // 64-bit general purpose registers
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RAX, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RBX, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RCX, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RDX, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RSI, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RDI, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RBP, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(RSP, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R8, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R9, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R10, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R11, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R12, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R13, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R14, uint64_t)
            __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R15, uint64_t)

            // // 8-bit registers (R8B-R15B)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R8B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R9B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R10B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R11B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R12B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R13B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R14B, uint8_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R15B, uint8_t)

            // // 16-bit registers (R8W-R15W)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R8W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R9W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R10W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R11W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R12W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R13W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R14W, uint16_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R15W, uint16_t)

            // // 32-bit registers (R8D-R15D)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R8D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R9D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R10D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R11D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R12D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R13D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R14D, uint32_t)
            // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(R15D, uint32_t)

            // // // 64-bit MMX registers
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM0, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM1, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM2, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM3, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM4, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM5, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM6, __m64)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(MM7, __m64)

            // // // 128-bit SSE registers
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM0,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM1,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM2,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM3,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM4,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM5,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM6,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM7,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM8,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM9,  __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM10, __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM11, __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM12, __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM13, __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM14, __m128)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(XMM15, __m128)

            // // // 256-bit AVX registers
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM0,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM1,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM2,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM3,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM4,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM5,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM6,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM7,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM8,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM9,  __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM10, __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM11, __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM12, __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM13, __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM14, __m256)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(YMM15, __m256)

            // // // 512-bit AVX-512 registers
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM0,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM1,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM2,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM3,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM4,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM5,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM6,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM7,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM8,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM9,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM10, __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM11, __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM12, __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM13, __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM14, __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(ZMM15, __m512)

            // // // 512-bit AVX-512 registers
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K0,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K1,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K2,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K3,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K4,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K5,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K6,  __m512)
            // // __CODE_INJECTION__DEFINE_REGISTER_READER_FUNCTIONS(K7,  __m512)
        };

        namespace Instructions {
            namespace Store {
                std::vector<uint8_t> EAX   = {0xA3};
                std::vector<uint8_t> EBX   = {0x89, 0x1D};
                std::vector<uint8_t> ECX   = {0x89, 0x0D};
                std::vector<uint8_t> EDX   = {0x89, 0x15};
                std::vector<uint8_t> ESI   = {0x89, 0x35};
                std::vector<uint8_t> EDI   = {0x89, 0x3D};
                std::vector<uint8_t> EBP   = {0x89, 0x2D};
                std::vector<uint8_t> ESP   = {0x89, 0x25};
                std::vector<uint8_t> RAX   = {0x48, 0xA3};
                std::vector<uint8_t> RBX   = {0x48, 0x89, 0x1D};
                std::vector<uint8_t> RCX   = {0x48, 0x89, 0x0D};
                std::vector<uint8_t> RDX   = {0x48, 0x89, 0x15};
                std::vector<uint8_t> RSI   = {0x48, 0x89, 0x35};
                std::vector<uint8_t> RDI   = {0x48, 0x89, 0x3D};
                std::vector<uint8_t> RBP   = {0x48, 0x89, 0x2D};
                std::vector<uint8_t> RSP   = {0x48, 0x89, 0x25};
                std::vector<uint8_t> R8    = {0x4C, 0x89, 0x05};
                std::vector<uint8_t> R9    = {0x4C, 0x89, 0x0D};
                std::vector<uint8_t> R10   = {0x4C, 0x89, 0x15};
                std::vector<uint8_t> R11   = {0x4C, 0x89, 0x1D};
                std::vector<uint8_t> R12   = {0x4C, 0x89, 0x25};
                std::vector<uint8_t> R13   = {0x4C, 0x89, 0x2D};
                std::vector<uint8_t> R14   = {0x4C, 0x89, 0x35};
                std::vector<uint8_t> R15   = {0x4C, 0x89, 0x3D};
                std::vector<uint8_t> XMM0  = {0x0F, 0x11, 0x05};
                std::vector<uint8_t> XMM1  = {0x0F, 0x11, 0x0D};
                std::vector<uint8_t> XMM2  = {0x0F, 0x11, 0x15};
                std::vector<uint8_t> XMM3  = {0x0F, 0x11, 0x1D};
                std::vector<uint8_t> XMM4  = {0x0F, 0x11, 0x25};
                std::vector<uint8_t> XMM5  = {0x0F, 0x11, 0x2D};
                std::vector<uint8_t> XMM6  = {0x0F, 0x11, 0x35};
                std::vector<uint8_t> XMM7  = {0x0F, 0x11, 0x3D};
                std::vector<uint8_t> XMM8  = {0x0F, 0x11, 0x45};
                std::vector<uint8_t> XMM9  = {0x0F, 0x11, 0x4D};
                std::vector<uint8_t> XMM10 = {0x0F, 0x11, 0x55};
                std::vector<uint8_t> XMM11 = {0x0F, 0x11, 0x5D};
                std::vector<uint8_t> XMM12 = {0x0F, 0x11, 0x65};
                std::vector<uint8_t> XMM13 = {0x0F, 0x11, 0x6D};
                std::vector<uint8_t> XMM14 = {0x0F, 0x11, 0x75};
                std::vector<uint8_t> XMM15 = {0x0F, 0x11, 0x7D};
            }

            namespace Restore {
                std::vector<uint8_t> EAX   = {0x8B, 0x05};
                std::vector<uint8_t> EBX   = {0x8B, 0x1D};
                std::vector<uint8_t> ECX   = {0x8B, 0x0D};
                std::vector<uint8_t> EDX   = {0x8B, 0x15};
                std::vector<uint8_t> ESI   = {0x8B, 0x35};
                std::vector<uint8_t> EDI   = {0x8B, 0x3D};
                std::vector<uint8_t> EBP   = {0x8B, 0x2D};
                std::vector<uint8_t> ESP   = {0x8B, 0x25};
                std::vector<uint8_t> RAX   = {0x48, 0x8B, 0x05};
                std::vector<uint8_t> RBX   = {0x48, 0x8B, 0x1D};
                std::vector<uint8_t> RCX   = {0x48, 0x8B, 0x0D};
                std::vector<uint8_t> RDX   = {0x48, 0x8B, 0x15};
                std::vector<uint8_t> RSI   = {0x48, 0x8B, 0x35};
                std::vector<uint8_t> RDI   = {0x48, 0x8B, 0x3D};
                std::vector<uint8_t> RBP   = {0x48, 0x8B, 0x2D};
                std::vector<uint8_t> RSP   = {0x48, 0x8B, 0x25};
                std::vector<uint8_t> R8    = {0x4C, 0x8B, 0x05};
                std::vector<uint8_t> R9    = {0x4C, 0x8B, 0x0D};
                std::vector<uint8_t> R10   = {0x4C, 0x8B, 0x15};
                std::vector<uint8_t> R11   = {0x4C, 0x8B, 0x1D};
                std::vector<uint8_t> R12   = {0x4C, 0x8B, 0x25};
                std::vector<uint8_t> R13   = {0x4C, 0x8B, 0x2D};
                std::vector<uint8_t> R14   = {0x4C, 0x8B, 0x35};
                std::vector<uint8_t> R15   = {0x4C, 0x8B, 0x3D};
                std::vector<uint8_t> XMM0  = {0x0F, 0x10, 0x05};
                std::vector<uint8_t> XMM1  = {0x0F, 0x10, 0x0D};
                std::vector<uint8_t> XMM2  = {0x0F, 0x10, 0x15};
                std::vector<uint8_t> XMM3  = {0x0F, 0x10, 0x1D};
                std::vector<uint8_t> XMM4  = {0x0F, 0x10, 0x25};
                std::vector<uint8_t> XMM5  = {0x0F, 0x10, 0x2D};
                std::vector<uint8_t> XMM6  = {0x0F, 0x10, 0x35};
                std::vector<uint8_t> XMM7  = {0x0F, 0x10, 0x3D};
                std::vector<uint8_t> XMM8  = {0x0F, 0x10, 0x45};
                std::vector<uint8_t> XMM9  = {0x0F, 0x10, 0x4D};
                std::vector<uint8_t> XMM10 = {0x0F, 0x10, 0x55};
                std::vector<uint8_t> XMM11 = {0x0F, 0x10, 0x5D};
                std::vector<uint8_t> XMM12 = {0x0F, 0x10, 0x65};
                std::vector<uint8_t> XMM13 = {0x0F, 0x10, 0x6D};
                std::vector<uint8_t> XMM14 = {0x0F, 0x10, 0x75};
                std::vector<uint8_t> XMM15 = {0x0F, 0x10, 0x7D};
            }
        }
    }
}
