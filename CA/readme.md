# Computer Architecture

- Embedded systems vs Standalone (or) general purpose systems:
    - Embedded systems:
        - A computer system designed to perform a specific task within a larger system. It's often small, low-power, and has limited functionality.
        - Examples:
            1) Home appliances (microwave ovens, washing machines)
            2) automotive systems (anti-lock braking systems, engine control units)
            3) medical devices (pacemakers)
            4) consumer electronics (smart TVs, cameras)
        - Embedded systems are specialized computing systems designed to perform dedicated functions or tasks within a larger system. Unlike general-purpose computers, which can run a variety of applications, embedded systems are typically optimized for specific applications and have constraints on resources such as power, memory, and processing speed.
        - an embedded system typically controls physical operations of the machine that it is embedded within. [wiki](https://en.wikipedia.org/wiki/Embedded_system)
        - Embedded systems range from those low in complexity, with a single microcontroller chip, to very high with multiple units, peripherals and networks, which may reside in equipment racks or across large geographical areas connected via long-distance communications lines.
    - Standalone (or) general purpose systems:
        -  A computer that operates independently and can be used for various tasks.
        - Examples:
            1) PC (laptops (or) desktops)
            2) Servers
- Integrated Circuit (IC):
    - A circuit in which all or some of the circuit elements are inseparably associated and electrically interconnected so that it is considered to be indivisible for the purposes of construction and commerce.
    - An integrated circuit (IC), also known as a microchip or simply chip, is a small electronic device made up of multiple interconnected electronic components such as transistors, resistors, and capacitors. These components are etched onto a small piece of semiconductor material, usually silicon.
    - At its core, an IC is designed to process, store, or transmit information by combining multiple electronic components (transistors, resistors, capacitors, etc.) into a small, compact chip.
- Microprocessor and processor
    - A microprocessor is a type of processor that is implemented on a single integrated circuit (IC). It serves as the central processing unit (CPU) of a computer or embedded system.
        - Contains an arithmetic logic unit (ALU), control unit, and registers on a single chip.
        - Specialized for general-purpose computing tasks.
        - Typically used in personal computers, laptops, and embedded systems.
        - Examples: Intel 8086, Intel Core i7, AMD Ryzen.
    - A processor is a broader term that refers to any electronic unit capable of performing computational tasks, including processing data and executing instructions.
        - Can refer to a microprocessor, graphics processor (GPU), digital signal processor (DSP), or even specialized processors like AI accelerators.
        - Not necessarily confined to a single IC; it can be composed of multiple chips or modules (e.g., a CPU and a separate memory module).
        - Examples:
            - Microprocessors: Intel Core, AMD Ryzen.
            - Graphics Processors (GPUs): NVIDIA GeForce, AMD Radeon.
            - AI Processors: Google TPU, Apple Neural Engine.
        - All microprocessors are processors, but not all processors are microprocessors.
- Microcontroller vs controller
    - Definition: A microcontroller is a compact computing system-on-a-chip (SoC) that includes a processor (CPU), memory (RAM and flash), and input/output peripherals.
        - Contains everything needed for standalone operation.
        - Microcontrollers are designed for embedded applications, in contrast to the microprocessors used in personal computers or other general-purpose applications consisting of various discrete chips.
        - A microcontroller (MC, UC, or μC) or microcontroller unit (MCU) is a small computer on a single integrated circuit. A microcontroller contains one or more CPUs (processor cores) along with memory and programmable input/output peripherals.
        - In modern terminology, a microcontroller is similar to, but less sophisticated than, a system on a chip (SoC). A SoC may include a microcontroller as one of its components but usually integrates it with advanced peripherals like a graphics processing unit (GPU), a Wi-Fi module, or one or more coprocessors.
        - Examples: Arduino
    - Definition: A controller is a broad term referring to any electronic or mechanical component that manages or regulates the operation of a system or device.
        - Can refer to simple systems like a thermostat or complex ones like a GPU controller.
        - Examples:
            - Disk controller (manages data transfer between a computer and storage).
            - Motor controller (manages speed and direction of motors)
            - Network controller (manages network communications).
- System on Chip (SoC):
    - An SoC integrates a microcontroller, microprocessor or perhaps several processor cores with peripherals like a GPU, Wi-Fi and cellular network radio modems or one or more coprocessors. Similar to how a microcontroller integrates a microprocessor with peripheral circuits and memory, an SoC can be seen as integrating a microcontroller with even more advanced peripherals.
    - SoCs are very common in the mobile computing (as in smart devices such as smartphones and tablet computers) and edge computing markets.
    - Examples:
        - **Snapdragon** 8 Gen 2: Found in flagship Android devices, integrates CPU, GPU (Adreno), AI, and modem.
        - NVIDIA Jetson Series:
            - Jetson AGX Orin: Designed for AI robotics and edge computing.
        - Google TPU (Tensor Processing Unit):
            - Custom SoC for AI and ML applications in data centers.

- Processor:
    - processors are made of ICs. A processor is essentially a highly complex IC optimized for computational tasks, forming the brain of a computer or device.
    - processors are made of integrated circuits (ICs). In fact, a processor is a highly sophisticated type of IC specifically designed to perform computational tasks. A processor, such as a Central Processing Unit (CPU) or a Graphics Processing Unit (GPU), is an advanced IC made up of billions of transistors and other electronic components like resistors and capacitors.

- There is something called scratchpad memory: [wiki](https://en.wikipedia.org/wiki/Scratchpad_memory)
    - Scratchpad memory (SPM), also known as scratchpad, scratchpad RAM or local store in computer terminology, is an internal memory, usually high-speed, used for temporary storage of calculations, data, and other work in progress. In reference to a microprocessor (or CPU), scratchpad refers to a special high-speed memory used to hold small items of data for rapid retrieval.
    - Difference between using scratchpad memory and L1 cache
        - In some systems[a] it can be considered similar to the L1 cache in that it is the next closest memory to the ALU after the processor registers, with explicit instructions to move data to and from main memory, often using DMA-based data transfer.[1] 
        - In contrast to a system that uses caches, a system with scratchpads is a system with non-uniform memory access (NUMA) latencies, because the memory access latencies to the different scratchpads and the main memory vary.  Another difference from a system that employs caches is that a scratchpad commonly does not contain a copy of data that is also stored in the main memory.

## Different architectures
There are several different **processor architectures**, each designed to optimize performance, power efficiency, or specific use cases. Architectures define how a processor interprets and executes instructions. 

### **1. ARM (Advanced RISC Machines)**
- **Type**: **RISC (Reduced Instruction Set Computing)**
- **Key Features**:
  - Simpler, smaller instruction set.
  - Optimized for power efficiency, making it ideal for mobile and embedded systems.
  - Uses a load/store architecture (separates memory access and computation instructions).
- **Applications**:
  - Smartphones, tablets, IoT devices, microcontrollers, and some laptops.
- **Popular Examples**:
  - ARM Cortex series (Cortex-A, Cortex-M, Cortex-R).
  - Apple's M-series chips (based on ARM architecture).

### **2. x86 (Intel and AMD)**
- **Type**: **CISC (Complex Instruction Set Computing)**
- **Key Features**:
  - Large, complex instruction set designed for high performance.
  - Backward compatibility with earlier x86 processors.
  - Higher power consumption compared to ARM.
- **Applications**:
  - Desktops, laptops, servers, and workstations.
- **Popular Examples**:
  - Intel Core series, AMD Ryzen.

### **3. RISC-V**
- **Type**: **RISC (Reduced Instruction Set Computing)**
- **Key Features**:
  - Open-source and customizable instruction set.
  - Enables innovation and flexibility for developers and manufacturers.
  - Similar simplicity to ARM but without licensing costs.
- **Applications**:
  - Emerging in IoT, embedded systems, and academia.
- **Popular Examples**:
  - SiFive processors, Andes Technology cores.

### **4. MIPS (Microprocessor without Interlocked Pipeline Stages)**
- **Type**: **RISC**
- **Key Features**:
  - Simple and efficient instruction set.
  - Focus on embedded systems and low-power devices.
- **Applications**:
  - Routers, IoT, and automotive systems.
- **Popular Examples**:
  - Earlier PlayStation consoles, networking equipment.

### **5. GPU Architectures (e.g., NVIDIA, AMD, Intel)**
- **Type**: Highly parallel architecture optimized for compute-heavy tasks.
- **Key Features**:
  - Specialized for tasks like graphics rendering, AI, and high-performance computing.
  - Includes thousands of cores for parallel processing.
- **Applications**:
  - Graphics processing, machine learning, and simulations.
- **Popular Examples**:
  - NVIDIA CUDA, AMD RDNA.
    - RDNA (Radeon DNA) is a graphics processing unit (GPU) microarchitecture and accompanying instruction set architecture developed by AMD. 
    - NVIDIA GPU Microarchitectures:
        - In NVIDIA's ecosystem, their GPU microarchitecture is called Turing, Ampere, Ada Lovelace, etc., depending on the generation, and they use their proprietary instruction set and platform technologies.

---

### How Architectures Differ:
1. **Instruction Set**: Determines the commands the CPU can execute.
2. **Power Efficiency**: ARM excels in low-power environments, while x86 prioritizes performance.
3. **Design Philosophy**:
   - **RISC**: Simplified instructions, better efficiency.
   - **CISC**: Complex instructions, often requiring fewer lines of code.

------
## Cache

- In computing, a cache is a hardware or software component that stores data so that future requests for that data can be served faster; the data stored in a cache might be the result of an earlier computation or a copy of data stored elsewhere.
- A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot.
- Locality of reference (or) principle of locality
    - In computer science, locality of reference, also known as the principle of locality, is the tendency of a processor to access the same set of memory locations repetitively over a short period of time.
    - There are two basic types of reference locality: temporal and spatial locality. Temporal locality refers to the reuse of specific data and/or resources within a relatively small time duration. Spatial locality (also termed data locality) refers to the use of data elements within relatively close storage locations. Sequential locality, a special case of spatial locality, occurs when data elements are arranged and accessed linearly, such as traversing the elements in a one-dimensional array.
    - Locality is a type of predictable behavior that occurs in computer systems. Systems that exhibit strong locality of reference are great candidates for performance optimization through the use of techniques such as the caching, prefetching for memory and advanced branch predictors of a processor core.
- Cache pollution: [wiki](https://en.wikipedia.org/wiki/Cache_pollution)
    - Cache pollution describes situations where an executing computer program loads data into CPU cache unnecessarily, thus causing other useful data to be evicted from the cache into lower levels of the memory hierarchy, degrading performance. For example, in a multi-core processor, one core may replace the blocks fetched by other cores into shared cache, or prefetched blocks may replace demand-fetched blocks from the cache.
- Cache control instruction:
    - In computing, a cache control instruction is a hint embedded in the instruction stream of a processor intended to improve the performance of hardware caches, using foreknowledge of the memory access pattern supplied by the programmer or compiler.
    - PREFETCH:
        - Cache prefetching is a technique used by computer processors to boost execution performance by fetching instructions or data from their original storage in slower memory to a faster local memory before it is actually needed (hence the term 'prefetch').
        - Most modern computer processors have fast and local cache memory in which prefetched data is held until it is required. The source for the prefetch operation is usually main memory. Because of their design, accessing cache memories is typically much faster than accessing main memory, so prefetching data and then accessing it from caches is usually many orders of magnitude faster than accessing it directly from main memory. Prefetching can be done with non-blocking cache control instructions.
- Types of caches:
    - CPU Cache
        - A CPU cache is a hardware cache used by the central processing unit (CPU) of a computer to reduce the average cost (time or energy) to access data from the main memory.
        - Most CPUs have a hierarchy of multiple cache levels (L1, L2, often L3, and rarely even L4), with different instruction-specific and data-specific caches at level 1.
        - Every core of a multi-core processor has a dedicated L1 cache and is usually not shared between the cores. The L2 cache, and higher-level caches, may be shared between the cores. L4 cache is currently uncommon, and is generally dynamic random-access memory (DRAM) on a separate die or chip, rather than static random-access memory (SRAM).
    - GPU Cache
    - Disk Cache
    - Web Cache
    - Memory Cache
        - Optimizes access to main memory in systems with non-uniform memory access (NUMA).
    - Database Cache
        - Caching results of frequently asked queries.

- Cache placement policies:
    - Cache placement policies are policies that determine where a particular memory block can be placed when it goes into a CPU cache. A block of memory cannot necessarily be placed at an arbitrary location in the cache; it may be restricted to a particular cache line or a set of cache lines by the cache's placement policy.
    - There are three different policies available for placement of a memory block in the cache: direct-mapped, fully associative, and set-associative. Originally this space of cache organizations was described using the term "congruence mapping".
    - [Wiki](https://en.wikipedia.org/wiki/Cache_placement_policies)
    - Two way set associative cache placemenet policy.

- Non uniform memory acces:
    - Non-uniform memory access (NUMA) is a computer memory design used in multiprocessing, where the memory access time depends on the memory location relative to the processor. Under NUMA, a processor can access its own local memory faster than non-local memory (memory local to another processor or memory shared between processors). NUMA is beneficial for workloads with high memory locality of reference and low lock contention, because a processor may operate on a subset of memory mostly or entirely within its own cache node, reducing traffic on the memory bus.

- CPU Stalls
    - The time taken to fetch one cache line from memory (read latency due to a cache miss) matters because the CPU will run out of work while waiting for the cache line. When a CPU reaches this state, it is called a stall. As CPUs become faster compared to main memory, stalls due to cache misses displace more potential computation; modern CPUs can execute hundreds of instructions in the time taken to fetch a single cache line from main memory.
    - Various techniques have been employed to keep the CPU busy during this time, including out-of-order execution in which the CPU attempts to execute independent instructions after the instruction that is waiting for the cache miss data. Another technology, used by many processors, is simultaneous multithreading (SMT), which allows an alternate thread to use the CPU core while the first thread waits for required CPU resources to become available.

### Cache reaplacement policies:
- [Wiki](https://en.wikipedia.org/wiki/Cache_replacement_policies)
- During a cache miss, some other previously existing cache entry is typically removed in order to make room for the newly retrieved data. The heuristic used to select the entry to replace is known as the replacement policy.
- The average memory reference time = m * Tm + Th + E
- Policies:
    1) Bélády's optimal algorithm (Optimal replacment policies)
        - Not feasible, because we do not know the access sequence
    2) FIFO
    3) LIFO
    4) Least Recently Used (LRU)
    5) Most Recently Used (MRU)
    6) Least frequently used (LFU)

### Cache Write policies
- If data is written to the cache, at some point it must also be written to main memory; the timing of this write is known as the write policy.
- Two types:
    1) Write through
        -  In a write-through cache, every write to the cache causes a write to main memory. 
    2) Write back
        - Alternatively, in a write-back or copy-back cache, writes are not immediately mirrored to the main memory, and the cache instead tracks which locations have been written over, marking them as dirty. The data in these locations is written back to the main memory only when that data is evicted from the cache. For this reason, a read miss in a write-back cache may sometimes require two memory accesses to service: one to first write the dirty location to main memory, and then another to read the new location from memory. Also, a write to a main memory location that is not yet mapped in a write-back cache may evict an already dirty location, thereby freeing that cache space for the new memory location.

### Cache coherence
- In computer architecture, cache coherence is the uniformity of shared resource data that is stored in multiple local caches. In a cache coherent system, if multiple clients have a cached copy of the same region of a shared memory resource, all copies are the same. Without cache coherence, a change made to the region by one client may not be seen by others, and errors can result when the data used by different clients is mismatched.
- cache coherency protocols:
    - [wiki](https://en.wikipedia.org/wiki/Cache_coherency_protocols_(examples))
    - Snoopy coherency protocol (Bus snooping), [Wiki](https://en.wikipedia.org/wiki/Bus_snooping)
        - Bus snooping or bus sniffing is a scheme by which a coherency controller (snooper) in a cache (a snoopy cache) monitors or snoops the bus transactions, and its goal is to maintain a cache coherency in distributed shared memory systems. 
        - There are two kinds of snooping protocols depending on the way to manage a local copy of a write operation:
            - Write-invalidate
                - When a processor writes on a shared cache block, all the shared copies in the other caches are invalidated through bus snooping. This method ensures that only one copy of a datum can be exclusively read and written by a processor. All the other copies in other caches are invalidated. This is the most commonly used snooping protocol. MSI, MESI, MOSI, MOESI, and MESIF protocols belong to this category.
            - Write-update
                - When a processor writes on a shared cache block, all the shared copies of the other caches are updated through bus snooping. This method broadcasts a write data to all caches throughout a bus. It incurs larger bus traffic than write-invalidate protocol. That is why this method is uncommon. Dragon and firefly protocols belong to this category.
- Cache invalidation is a process in a computer system whereby entries in a cache are replaced or removed.

------------

## Architectures
- von Neumann architecture
    - The term "von Neumann architecture" has evolved to refer to any stored-program computer in which an instruction fetch and a data operation cannot occur at the same time (since they share a common bus). This is referred to as the von Neumann bottleneck, which often limits the performance of the corresponding system.
    - [Architecture](https://en.wikipedia.org/wiki/File:Von_Neumann_Architecture.svg)
- Harvard architecture
    - The Harvard architecture is a computer architecture with separate storage and signal pathways for instructions and data. It is often contrasted with the von Neumann architecture, where program instructions and data share the same memory and pathways. This architecture is often used in real-time processing or low-power applications.
    - [Harward architecture](https://en.wikipedia.org/wiki/File:Harvard_architecture.svg)

----
# How is Ardunio different from FPGA

## 🧠 Core Difference:

### ✅ **Arduino** = Microcontroller-based development platform  
(Usually runs on an **AVR** microcontroller like ATmega328)

### 🛠️ **FPGA** = Programmable hardware platform  
(You design hardware logic from scratch)

## 🔍 Side-by-Side Comparison:

| Feature               | **Arduino**                         | **FPGA**                             |
|-----------------------|--------------------------------------|--------------------------------------|
| **Type**              | Microcontroller (Software-based)     | Reconfigurable Hardware (Logic gates)|
| **Programming**       | C/C++ (Arduino IDE)                  | Verilog / VHDL                       |
| **Execution**         | Sequential                           | Parallel                             |
| **Hardware Control**  | Fixed hardware (timers, UART, etc.)  | You design hardware blocks yourself  |
| **Speed**             | Lower (~16 MHz typical)              | Much higher (100s of MHz, parallel)  |
| **Learning Curve**    | Easy for beginners                   | Steeper, more complex                |
| **Example Use**       | Controlling LEDs, sensors, motors    | Custom CPU design, signal processing |
| **Real-Time Performance** | Limited                        | Excellent for hard real-time tasks   |


## 🧪 Example:

### Arduino:
You write:
```cpp
digitalWrite(LED_PIN, HIGH);
```
👉 It runs on the built-in CPU and turns on an LED.



### FPGA:
You define logic like:
```verilog
assign LED = button_input;
```
👉 No CPU here — just direct logic gates. The LED turns on *because* the hardware is wired that way.



## ⚠️ Summary:

- **Use Arduino** for rapid prototyping, DIY electronics, and simple automation.
- **Use FPGA** when you need **custom hardware**, super-fast parallel processing, or to simulate chips.


If you're just starting out in embedded systems, Arduino is perfect.  
If you're diving into hardware design, digital logic, or high-performance embedded systems, then FPGA is your playground. 

----
