# Compiler
1) Preprocessing: gcc -E source.c -o source.i
2) Compiling: gcc -S source.i -o source.s
3) Assembling: gcc -c source.s -o source.o
4) Linking: gcc source.o -o executable
5) Loading/Running: ./executable

- Interpreter
- Java compilers (hybrid)
    - source code is translated to an intermediate representation known as bytecode. Bytecode is not the machine code for any particular computer, and may be portable among computer architectures. The bytecode may then be interpreted by, or run on a virtual machine. 
    - JIT (Just In Time compilers)
        - The JIT compiler reads the bytecodes in many sections (or in full, rarely) and compiles them dynamically into machine code so the program can run faster. This can be done per-file, per-function or even on any arbitrary code fragment; the code can be compiled when it is about to be executed (hence the name "just-in-time"), and then cached and reused later without needing to be recompiled
    - Statically-compiled code or native code is compiled prior to deployment. A dynamic compilation environment is one in which the compiler can be used during execution. A common goal of using JIT techniques is to reach or surpass the performance of static compilation, while maintaining the advantages of bytecode interpretation: Much of the "heavy lifting" of parsing the original source code and performing basic optimization is often handled at compile time, prior to deployment: compilation from bytecode to machine code is much faster than compiling from source. The deployed bytecode is portable, unlike native code. Since the runtime has control over the compilation, like interpreted bytecode, it can run in a secure sandbox. Compilers from bytecode to machine code are easier to write, because the portable bytecode compiler has already done much of the work.


- A sandbox is a controlled environment used to run programs or execute code with restricted permissions to prevent it from affecting the host system. It provides isolation between the executing code and the system, allowing the code to be tested, executed, or analyzed without risk of security breaches, crashes, or other harmful side effects.

## Dynamic compilation vs static compilation
- **Static compilation** and **dynamic compilation** are two approaches to compiling and executing programs. The key difference lies in when and how the code is compiled and executed.

### Static Compilation (Ahead-of-Time Compilation - AOT):
- **Definition**: In static compilation, the entire source code is compiled into machine code (or an intermediate form) before the program is executed. This compiled code is then executed directly by the system.
- **Process**: Compilation happens **once** at build time, and the resulting binary can be executed multiple times without recompilation.
- **Characteristics**:
  - Faster execution at runtime, since the code is precompiled.
  - No need for a compiler during execution.
  - Requires recompilation for any code changes.
  - Platform-dependent: The compiled binary is typically specific to the system it was compiled on.
  
- **Example**: Languages like C, C++, and Fortran use static compilation. The `gcc` or `clang` compiler generates executable files that are ready to run on the target platform.

### Dynamic Compilation (Just-in-Time Compilation - JIT):
- **Definition**: Dynamic compilation compiles parts of the source code or intermediate code during the execution of the program. It occurs "just-in-time" when the code is needed.
- **Process**: Source code or intermediate code is partially compiled at runtime, optimizing code paths based on execution conditions.
- **Characteristics**:
  - Slower startup time since compilation happens during execution.
  - Can optimize code based on runtime information (e.g., hot code paths).
  - Requires a runtime environment or a virtual machine (VM) for execution (e.g., JVM for Java).
  - Platform-independent at the source level: the same code can run on different platforms by compiling dynamically during execution.
  
- **Example**: Java, Python, and C# use dynamic compilation (JIT). The Java Virtual Machine (JVM) compiles Java bytecode into machine code as it runs.

---

### Comparison:

| Feature                     | Static Compilation (AOT)                | Dynamic Compilation (JIT)                |
|-----------------------------|-----------------------------------------|------------------------------------------|
| **Timing of Compilation**    | At compile time (before execution)      | At runtime (during execution)            |
| **Execution Speed**          | Faster execution (no compilation overhead) | Slower startup, but can optimize during runtime |
| **Optimization**             | Compile-time optimizations only         | Can optimize based on runtime conditions |
| **Portability**              | Platform-specific binaries              | Platform-independent (needs runtime)     |
| **Code Changes**             | Requires recompilation                  | Can adapt without recompiling            |
| **Examples**                 | C, C++, Fortran                         | Java, Python (with JIT)              |

---

### Use Cases:
- **Static Compilation**: Used when performance is critical and the target platform is known (e.g., system software, embedded systems, game engines).
- **Dynamic Compilation**: Used when flexibility and portability are needed, or when runtime optimizations are important (e.g., web browsers, Java applications, managed languages).

### Symbol Table 

The **symbol table** is a data structure used by the compiler during semantic analysis to store information about identifiers (variables, functions, etc.) in the source code. It helps the compiler manage names, types, and memory allocation efficiently.

### Key Information Stored in the Symbol Table:

1. **Name**: The identifier's name (e.g., variable or function name).
2. **Type**: Data type (e.g., `int`, `float`, function signature).
3. **Scope**: Visibility (local, global, etc.).
4. **Memory Location**: Relative offset or address where the symbol will be stored.
5. **Value**: Initial or constant value (if applicable).
6. **Function Info**: Return type, parameter types, and count for functions.
7. **Array Info**: Size and type for arrays.
8. **Class/Struct Info**: Member details and access specifiers.
9. **Modifiers**: Attributes like `const`, `static`, or `extern`.

The symbol table ensures correct usage and efficient management of symbols during compilation.