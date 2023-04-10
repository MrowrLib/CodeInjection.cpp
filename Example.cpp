#include <CodeInjection.h>

#include <iostream>

int main() {
    auto injection =
        CodeInjection::New("My Injection")
            .OnInstall([](Injection& _) {
                _.AllocateMemory("allocatedMemoryAddress", [](Injection& __) {
                    __.WriteAssembly([](Assembly::Code code) {
                        BeginAssembly;
                        code.mov(eax, 0x69);
                        code.ret();
                    });
                });
            })
            .OnUninstall([](Injection& _) { _.DeallocateMemory("allocatedMemoryAddress"); });

    injection.Install();

    auto allocatedMemoryAddress = injection.Var<uintptr_t>("allocatedMemoryAddress");
    std::cout << string_format("Allocated memory address: {:x}", allocatedMemoryAddress)
              << std::endl;

    // Pause and ask for any key to continue...
    std::cout << "Press any key to continue...";
    std::cin.get();

    injection.Uninstall();
}
