# OS

- Real time OS
    - A real-time operating system (RTOS) is a special kind of operating system designed to handle tasks that need to be completed quickly and on time. Unlike general-purpose operating systems (GPOS), which are good at multitasking and user interaction, RTOS focuses on doing things in real time.
- OS is a software that manages system hardware.
- Some important features of OS
    1) Resouce management
    2) Process management
    3) Storage management (File management on disk)
    4) Memory management
    5) Security management
- Two basic components of OS
    1) Shell
        - A program which provides a communication platform for users to use hardware.
    2) Kernel
        - Kernel is the core component of OS, which is responsible for handling various features such as: process managmenet, memory managmenet, disk managment, IPC etc.
        - The kernel is a computer program at the core of a computer's operating system and generally has complete control over everything in the system. The kernel is also responsible for preventing and mitigating conflicts between different processes. It is the portion of the operating system code that is always resident in memory and facilitates interactions between hardware and software components.
        - A kernel loads first into memory when an operating system is loaded and remains in memory until the operating system is shut down again. 
        - The rest of the components in OS depends on kernel for the supply of the important services that are provided by OS.
        - Types of kernel
            1) Monolithic kernel
                - A monolithic kernel is a single large process running entirely in a single address space, containing all core services like process management, memory management, file systems, and device drivers.
                - Examples: linux, windows earlier versions
            2) Micro kernel
                - A microkernel is a minimalistic kernel that includes only essential functions such as inter-process communication and basic memory management, with other services running in user space.
            3) Hybrid kernel
                - A hybrid kernel combines aspects of both monolithic and microkernels, running some services in kernel space and others in user space, to balance performance and modularity.
                - Examples: Windows (newer versions), 
- OS vs kernel
    - OS = Kernel + User-level components
        - User-level components:
            - The OS includes various components that operate in user space—outside the kernel. These provide higher-level functionality for the user and applications:
                1) System libraries: These are collections of utilities that provide standard functionalities like file handling, string manipulation, etc. (e.g., libc on Unix systems). They act as intermediaries between applications and the kernel.
                2) User interface (shell): The command-line interface (CLI) or graphical user interface (GUI) that users interact with. Common shells include:
                    - Bash, Zsh (CLI)
                    - GNOME, KDE (GUI)

- **Popular OS**
    - Linux based OS:
        - Strictly speaking linux is not a OS. Linux is a kernel.
        - However, when people say "Linux," they often refer to Linux-based operating systems, also known as distributions or distros, which bundle the Linux kernel with other software to create a complete OS.
        - Some examples of linux distributions that use the linux kernel but package it with additional software, user interfaces, and applications to form a complete OS are:
            - Ubuntu
            - Debian
            - Fedora
            - CentOS
            - Kali linux
            - Linux mint
        - sudo stands for "superuser do." It allows a permitted user to execute a command as the superuser (root) or another user.
        - GNOME
            - GNOME is a popular desktop environment for Linux and other Unix-like operating systems. It provides a user-friendly graphical interface with a focus on usability, customization, and accessibility.
            - Think of it as the "face" of your computer, providing the visual elements and tools you interact with.
        - SSH (secure shell)
            - A protocol used to securely connect to remote servers via the command line. The ssh command initiates an encrypted connection between a client and server.
            - SSH replaced telnet: SSH (Secure Shell) encrypts data during transmission, providing a secure channel over an unsecured network, while Telnet transmits data in plain text, making it vulnerable to eavesdropping and attacks.
        - grep:
            - A command used to search for specific patterns or text within files or output.
            - grep commands:
                - grep "keyword" file_name
                    - searches for "keyword" in file whose name is file_name.
                - grep -i "keyword" file_name
                    - ignores case when searching
                - grep -n "keyword" file_name
                    - Displays line numbers along with matching lines.
                - grep -c "keyword" file_name
                    - Counts the number of lines which has "keyword".
                - grep -r "pattern" directory/
                    - Searches for "pattern" in all files within a directory and its subdirectories.
                - grep -E "regular_expressions" file_name
                    - grep -E "a.b" filename
                        - Matches lines containing "a" followed by "b".
                    - grep -E "a+b+" filename
                        - This matches lines which has pattern one or more "a"s followed by one or more "b"s.
                    - grep -E "ab*" filename
                        - This matches line which has pattern one 'a' followed by one (or) more 'b's
        - man
            - The command to display documentation about other Linux commands. For example, man ls shows the manual for the ls command.
        - script
            - A file containing a series of commands that can be executed as a program. Typically, shell scripts end with .sh and can be run using bash script.sh.
            - echo 
                - Built in command in shell scripting.
                - echo "Hello, World!" will print "Hello, World!" to the terminal.
        - Tar files
            - A tar file is an archive file format used to combine multiple files and directories into a single file for easier storage and transfer. The term "tar" stands for "tape archive," as it was originally developed for storing files on magnetic tape.
            - File Extension: Tar files typically have the .tar extension. Compressed tar files often have extensions like .tar.gz or .tar.bz2.
            - Why tar files are use:
                1) Compiling multiple files and directories into one file, simplifying file organisation, management and transfer.
                2) Commonly used for data backup and long-term storage(archiving) as it preserves the original structure.
                3) Compression: When combined with compression algorithms (like gzip or bzip2), tar files can significantly reduce file sizes.
            - Commands:
                - tar -cvf archive.tar /path/to/directory
                    - create a tar file
                - tar -xvf archive.tar
                    - extract a tar file
                - tar -czvf archive.tar.gz /path/to/directory
                    - create a compressed tar file
                - tar -xzvf archive.tar.gz
                    - extract a compressed tar file
        - Listing:
            - commands
                - ls
                    - list all files and directories in current directory.
                - ls directory_path
                    - list all files and directoreis in directory with the correspoding path.
                - ls -a
                    - lists all hidden files (those starting with dot)
                - ls -l
                    - display detailed info about files
                - ls -R
                    - lists all file and directories recursively
                - ls -i 
                    - lists the inode indices of all files and directories in current directory
                    - stat file_name
                        - to get more details in inode entry of the file.
        - Remove
            - rm
                - rm file_name
                    - Removes file with name file_name in current 
                - rm -r dir
                    - Removes directory recursively
        - copy
            - cp orginal_file copied_file
                - copy the contents of file
        - mkdir
            - mdir dir
                - create directory dir in current directory.
        - cd
            - cd ..
                - go to parent directory of current direcotry.





- Types of OS
    1) Batch OS (Batch processing systems)
        - A Batch Operating System is an early type of operating system where tasks (jobs) are collected (batched) and processed together without any user interaction. Programs or jobs are submitted to the system in batches, and the operating system processes them sequentially, one after the other.
        - No direct interaction with the user: Once the job is submitted, the user doesn't interact with it until the entire job is processed.
        - Job Scheduling: Jobs are scheduled in batches, often using First-Come, First-Served (FCFS) or priority-based scheduling.
        - Reduced idle time: Since jobs are processed in batches, it reduces CPU idle time by efficiently handling the execution of multiple jobs.
        - I/O Bound Operations: Input/output operations were often slower than CPU execution, so the batch system was used to queue up jobs, allowing the CPU to stay busy while waiting for I/O.
    2) Multi-programming OS
        - Multi programming is pseduo parallelsim
    3) Multi-processing OS
        - A multiprocessing operating system is defined as a type of operating system that makes use of more than one CPU to improve performance. Multiple processors work parallelly in multi-processing operating systems to perform the given task. 
        - Multi processing is true parallelsim.
- Must read article for comparision among multi-programming, multi-procesing, multi-tasking and multi-threading: [GFG article](https://www.geeksforgeeks.org/difference-between-multitasking-multithreading-and-multiprocessing/)
- [Spooling](https://www.geeksforgeeks.org/what-exactly-spooling-is-all-about/)
- A bus is a communication system that transfers data between components of a computer, like the CPU, memory, and peripherals.
- An address bus is a type of bus that carries memory addresses from the CPU to other components, such as RAM, to specify where data should be read or written. It determines the addressing capacity of the system.


# Definitions
- UI and UX
    - UI:
        - UI is about what the user sees and touches.
        - A website with a clean, intuitive layout and clear navigation is a good UI.
        - UI include compoents like: Buttons, icons, typography, color schemes, layouts, and more.
    - UX:
        - UX is about how the user feels while using the product.
        - A website that is easy to use, meets the user's needs, and provides a satisfying experience is a good UX.
        - UI is a subset of UX.
        - UI focuses on aesthetics and usability, while UX focuses on the entire user journey.


## CPU scheduling algorithms
- Non-Preemptive Scheduling Algorithm
    - In non-preemptive scheduling, once a process is given the CPU, it runs to completion or until it voluntarily releases the CPU (e.g., by completing execution or waiting for I/O).
    - The running task has full control of the CPU until it finishes or yields.
- Preemptive Scheduling Algorithm
    - In preemptive scheduling, the CPU can be taken away from a process if a higher-priority process arrives or after a certain time interval (time quantum in case of round-robin scheduling). The running process is interrupted and moved back to the ready queue.
    - The OS has control over the CPU and can stop a running task before it completes, switching to another task.
- In general:
    - Preemptive Scheduling algorithm: In the preemptive scheduling algorithm if more than one process wants to enter into the critical section then it will be allowed and it can enter into the critical section without any interruption only if no other progress is in the critical section.
    - Non-Preemptive scheduling algorithm: If a process gets a critical section then it will not leave the critical section until or unless it works gets done.

## Booting the computer
- Important question: What happens when we turn on a computer? 
- Must read article:  [Boot block in OS](https://www.geeksforgeeks.org/boot-block-in-operating-system/)
**Booting** is the process of starting or restarting a computer by loading the operating system (OS) into the computer’s memory (RAM) from a storage device (like a hard drive, SSD, or CD). This process prepares the system for user interaction by initializing hardware components and launching the OS.

There are two types of booting:
1. **Cold Booting (Hard Booting):** When the computer is turned on from a completely powered-off state.
2. **Warm Booting (Soft Booting):** When the system is restarted without fully turning off the power (e.g., using the "Restart" option in an operating system).

### Steps in the Booting Process:

1. **Power On Self-Test (POST):**
   - When the computer is powered on, the Basic Input/Output System (BIOS) or Unified Extensible Firmware Interface (UEFI) performs a POST, which tests the hardware components like RAM, CPU, storage devices, and other peripherals to ensure they are functioning properly.
   - If any hardware issues are detected, the boot process halts, and an error is displayed (or a beep code sounds).

2. **BIOS/UEFI Initialization:**
   - The BIOS/UEFI initializes the hardware and checks for attached bootable devices (like hard drives, USB drives, or CDs). It determines the boot sequence (which device to boot from first).
   - BIOS/UEFI then locates the **bootloader** on the boot device and hands over control.

3. **Bootloader Execution:**
   - The bootloader, often called **GRUB** (for Linux systems) or **Windows Boot Manager** (for Windows), is a small program that loads the operating system into memory.
   - It locates the OS kernel (the core part of the OS) and starts the process of loading the OS.

4. **Operating System Loading:**
   - Once the kernel is loaded, the operating system takes control of the system.
   - The OS initializes the rest of the hardware components (like the graphical user interface, device drivers, and user processes) and prepares the system for user interaction.

5. **Login and User Interface:**
   - After the OS has been fully loaded, the system displays the login screen or desktop environment, allowing the user to interact with the computer.

### Booting Sequence Overview:
1. Power on → 
2. POST (Power On Self-Test) → 
3. BIOS/UEFI initializes hardware → 
4. Bootloader loads the OS kernel → (BOOTSTRAP)
5. OS initializes the system → 
6. User login/interface

### Types of Bootloaders:
- **GRUB (GRand Unified Bootloader):** Used in Linux-based systems to manage multiple operating systems or kernels.
- **Windows Boot Manager (BOOTMGR):** Used in Microsoft Windows systems to start the Windows OS.

### Cold Boot vs. Warm Boot:
- **Cold Boot:** Starting the computer from a powered-off state.
- **Warm Boot:** Restarting the system without turning off the power (like pressing the restart button or using software commands).

Booting is crucial as it sets up the system environment for running the OS, allowing the user to access and use the computer.

# Inter process communication
**Inter-Process Communication (IPC)** allows processes to communicate and synchronize their actions in a multitasking environment. Here’s a brief overview:

### Key IPC Mechanisms

1. **Pipes**: 
   - **Anonymous Pipes**: Unidirectional communication between parent and child processes.
   - **Named Pipes (FIFOs)**: Bidirectional communication between any two processes using a named channel.

2. **Message Queues**: 
   - Asynchronous communication where messages are sent to a queue and read in FIFO order.

3. **Shared Memory**: 
   - A common memory segment accessed by multiple processes for fast communication, requiring synchronization (e.g., with semaphores).

4. **Semaphores**: 
   - Synchronization tools to control access to shared resources, preventing race conditions.

5. **Sockets**: 
   - Communication over a network, suitable for processes on the same or different machines, supporting TCP (stream-oriented) and UDP (datagram-oriented).

6. **Signals**: 
   - Notifications sent to processes for events (e.g., termination requests), but limited in data transfer.

### Choosing IPC Mechanisms
- **Data Size**: Shared memory for large data; pipes and message queues for smaller messages.
- **Directionality**: Pipes for unidirectional; sockets or message queues for bidirectional.
- **Performance vs. Complexity**: Shared memory is fastest but complex; sockets are flexible for network communication.

### Challenges
- **Synchronization Issues**: Can lead to race conditions and deadlocks.
- **Performance Overheads**: Introduced by context switching and system calls.
- **Security**: Preventing unauthorized access to shared resources is critical.

# Memory
- An **Address Bus** is a crucial component in a computer system that carries the memory addresses from the processor (CPU) to other components, such as RAM or I/O devices. It is used by the CPU to specify the location of data or instructions that need to be read from or written to in memory.
- Types of memory
    1) RAM 
        - volatile
        - faster
        - expensive
        i) DRAM
        ii) SRAM
    2) ROM
        - non volatile
        - slower
        - cheaper
        i) PROM
        ii) EPROM
        iii) EEPROM
- A **page fault** occurs when a process attempts to access data or code that is in its address space but is not currently located in the system RAM. This triggers a sequence of events where the operating system must manage the fault by loading the required data from secondary storage into RAM.
    - Page replacement becomes necessary when a page fault occurs and no free page frames are in memory.
    - Paging
-------
## Detection of page fault
A page fault is detected by the operating system (OS) when a process tries to access a page of memory that is not currently mapped in its address space. Here's how the detection process typically works:

### Steps in Page Fault Detection:

1. **Accessing Memory**:
   - When a program accesses memory (e.g., reading from or writing to a variable), the CPU generates a memory address.

2. **Translation Lookaside Buffer (TLB)**:
   - The CPU first checks the **TLB**, a cache that stores recently used virtual-to-physical address mappings. If the translation is found in the TLB, the corresponding physical address is used, and the access continues without any issue.

3. **Page Table Lookup**:
   - If the TLB does not have the mapping (a TLB miss), the CPU then accesses the **page table** for the process. The page table contains the mapping of virtual addresses to physical addresses.

4. **Page Table Entry (PTE) Status**:
   - Each entry in the page table (Page Table Entry, PTE) has a status bit indicating whether the page is in physical memory or not:
     - **Present Bit**: If this bit is set, it means the page is currently loaded in physical memory.
     - **Not Present Bit**: If this bit is not set, it indicates that the page is not in physical memory.

5. **Page Fault Trigger**:
   - If the access results in a PTE with the **not present** bit (indicating the page is not currently in RAM), a **page fault** is triggered.

6. **Page Fault Handler**:
   - The operating system's page fault handler is invoked to handle the page fault. The handler typically:
     - Determines the cause of the page fault (e.g., whether it was a valid access or an invalid access).
     - If it's a valid access, the handler will find the needed page (from disk or other storage) and load it into memory.
     - Updates the page table with the new mapping.
     - Restarts the instruction that caused the page fault.

### Summary:
Page faults are detected when a process tries to access a page not currently in physical memory. The detection process involves checking the TLB and the page table, leading to the invocation of a page fault handler if the page is not present in memory.
-----------
- [Page replacement algo](https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/)
    - FIFO
    - Optimal page replacement
    - LRU
        - LRU is also used as cache replacement algorithm
        - [Question](https://leetcode.com/problems/lru-cache/submissions/1404037372/)
        - [LRU_without_dummies.cpp](LRU_without_dummies.cpp) is complex as no dummies are used.
            - Time: O(1) per operation
            - Auxillary space: capacity * 2 
        - [LRU_simple.cpp](LRU_simple.cpp) is simplified by using dummies
            - Time: O(1) per operation
            - Auxillary space: capacity * 2 
    - MRU
- Demand paging

- Virtual memory is a combination of RAM and disk space that running processes can use. Swap space is the portion of virtual memory that is on the hard disk, used when RAM is full. 

- Two main types of virtual memory managment
    1) paging
    2) Segmentation
        - Segmentation is a memory management technique that divides a program into segments, improving performance and reducing internal fragmentation.
        - Segments are not of equal size and are loaded into memory at runtime
- Virtual memeory
    - Virtual memory is a memory management technique that creates an "abstraction" of the physical memory available in a system. It allows a computer to use hard disk space as if it were additional RAM, enabling larger applications to run on systems with limited physical memory.
- Physical memory refers to the actual RAM (Random Access Memory) installed in a computer system. It is the hardware that stores data and instructions currently in use.
- Page table 
    - A data sturcture used to get the physical address of logical address. 
    - Page tables are typically stored in main memory (RAM). Each process has its own page table that keeps track of the mapping for its virtual address space.
    - Pointer in PCB: The Process Control Block (PCB) of each process contains a pointer (base address) to the page table of that process, allowing the operating system to quickly access the page table during context switches.
    - During context switching, the OS updates the page table base register PTBR (in the CPU) with the address of the new process's page table from its PCB.

- PTE:
    - A Page Table Entry (PTE) is an entry in the Page Table that stores information about a particular page of memory. Each PTE contains information such as the physical address of the page in memory, whether the page is present in memory or not, whether it is writable or not, and other access permissions.
- TLB
    - Translation Lookaside buffer
    - Is a fast cache used to store page table entries.



-----

Fragmentation is a phenomenon that occurs in computer memory management where free memory space becomes divided into small, non-contiguous blocks, making it difficult to allocate larger contiguous blocks of memory. There are two main types of fragmentation: **external fragmentation** and **internal fragmentation**. Let's delve into both, especially in the context of paging:

**1. External Fragmentation**
- **Definition**: External fragmentation happens when there is enough total free memory available to satisfy a memory request, but the available memory is not contiguous. This results in many small gaps in memory that cannot be used effectively.
- **Example**: If you have free memory blocks of sizes 10 KB, 5 KB, and 15 KB, and you need a 20 KB block, you cannot allocate the memory, even though the total free memory (30 KB) is sufficient.

**2. Internal Fragmentation**
- **Definition**: Internal fragmentation occurs when a fixed-size memory block is allocated to a process, but the process does not use the entire block. The unused space within the block becomes wasted.
- **Example**: If a process requests 18 KB of memory and the system allocates a 20 KB block (the smallest block available), there will be 2 KB of internal fragmentation because that space is not utilized.

### How Paging Reduces Fragmentation
Paging is a memory management technique that helps mitigate fragmentation issues in the following ways:

- **Fixed-Size Pages**: In paging, memory is divided into fixed-size pages (usually between 4 KB and 64 KB). When a process is loaded into memory, its pages are mapped to available physical memory frames, which can be non-contiguous. This means that processes can be allocated memory in a more flexible manner, helping to reduce external fragmentation.

- **Avoiding Large Contiguous Allocations**: Since the pages can be scattered throughout physical memory, the operating system does not require large contiguous blocks of memory, which helps alleviate the issue of external fragmentation. 

- **Minimizing Internal Fragmentation**: Although internal fragmentation can still occur with paging (for instance, if a page is not completely filled), it is often minimized since the page size is chosen to balance between overhead and efficient usage of memory. The overall effect is that paging can result in less wasted memory than other methods, like segmentation, which uses variable-sized memory blocks.

- **Paging** effectively reduces external fragmentation by allowing non-contiguous allocation of pages and minimizes internal fragmentation through the use of fixed-size pages.
- By using paging, operating systems can optimize memory usage, reduce fragmentation issues, and improve overall system performance.

    
### **SRAM (Static RAM)**:
- **Definition**: A type of memory that uses flip-flops to store data, retaining information as long as power is supplied.
- **Speed**: Faster.
- **Cost**: Expensive.
- **Power Consumption**: Low power when idle, but consumes more during access.
- **Usage**: Used in CPU cache (L1, L2, L3).
- **Refreshing**: No need for refreshing.

### **DRAM (Dynamic RAM)**:
- **Definition**: A type of memory that stores data in capacitors, requiring periodic refreshing to retain information.
- **Speed**: Slower.
- **Cost**: Cheaper.
- **Power Consumption**: Consumes more power due to constant refreshing.
- **Usage**: Used in main memory (RAM) of computers.
- **Refreshing**: Requires constant refreshing to hold data.

### ROM types
1. PROM (Programmable read-only memory): It can be programmed by the user. Once programmed, the data and instructions in it cannot be changed. 

2. EPROM (Erasable Programmable read-only memory): It can be reprogrammed. To erase data from it, expose it to ultraviolet light. To reprogram it, erase all the previous data. 

3. EEPROM (Electrically erasable programmable read-only memory): The data can be erased by applying an electric field, with no need for ultraviolet light. We can erase only portions of the chip.

# Process and threads

- [Source](https://www.geeksforgeeks.org/process-table-and-process-control-block-pcb/). A process control block (PCB) stores various  information about a process so that the operating system can manage it properly. Like:
    1) Process ID (PID)
    2) Process Status
    3) CPU Registers
    4) Memory Management Information
    5) I/O Information
    6) stack pointer
    7) Program counter
    8) frame pointer:
        - Points to the base of the stack frame: The frame pointer contains the memory address of the base of the current stack frame, which is used as a reference point for accessing local variables and parameters.

- Process table is an array of PCB's of all process.
- Context Switching: The process of switching from one process to another is called context switching. The PCB plays a crucial role in context switching by saving the state of the current process and restoring the state of the next process.
- Process: Program under execution. Thread: Part of a process.
    - The process is isolated. Threads share memory.
- Zombie vs Orphan vs Daemon process
    - Zombie process
        - A process which has been terminated but still has an entry in the process table is called Zombie process
        - A zombie process occurs when a child process has completed its execution, but its parent process has not yet called wait() to read its exit status. This leaves an entry in the process table for the terminated child process, thus it becomes a "zombie."
        - The child process becomes a zombie when it exits, and the parent hasn't yet "reaped" it by calling wait() or waitpid(). The process remains in the zombie state until the parent reads the exit status, at which point it is removed from the process table.
    - Orphan process
        - A process continues to run, whose parent has terminated is called Orphan process.
    - Daemon process
        - A daemon process is a background process which starts with system boot and runs until shutdown.
- The init process is the parent of all processes in Linux, identified by the process ID (PID) of 1. It is the first process that starts when a computer boots up and continues to run until the system shuts down. The term init stands for “initialization,” and its primary role is to create and manage processes based on instructions from configuration scripts, specifically those stored in the ‘/etc/inittab‘ file. 
    - When a process's parent terminates before the process itself, init adopts these orphaned processes and ensures their proper termination.
    - The init process launches and manages system services (like daemons) needed to run the OS. This includes starting services like network management, logging, and scheduling.
- PID 0 refers to the kernel’s swapper/idle process, which handles CPU idle time and was originally tasked with swapping memory in early Unix systems.
- Thread 
    - Threads run in parallel improving the application performance. Each such thread has its own CPU state and stack, but they share the address space of the process and the environment. 
    - Threads can share common data so they do not need to use inter-process communication. Like the processes, threads also have states like ready, executing, blocked, etc. 
    - The multiple threads of a given process may be executed concurrently (via multithreading capabilities), sharing resources such as memory, while different processes do not share these resources. In particular, the threads of a process share its executable code and the values of its dynamically allocated variables and non-thread-local global variables at any given time.
    - Benifits of multi threading
        - Concurrent execution.
        - Less costly can creating a brand new process.
    - Each thread has its own Thread Control Block (TCB). Like the process, a context switch occurs for the thread, and register contents are saved in (TCB). As threads share the same address space and resources, synchronization is also required for the various activities of the thread.
    - Types of threads:
        - User level thread
            - User-level threads are managed by user-space libraries rather than the operating system's kernel. The OS is unaware of the existence of these threads and sees them as a single process.
            - In case of a page fault, the whole process can be blocked.
        - Kernel level thread
            - Kernel-level threads are managed directly by the operating system’s kernel. The kernel is fully aware of each thread and is responsible for scheduling and managing them.<br/>
        - | **Feature**             | **User-Level Threads (ULT)**                             | **Kernel-Level Threads (KLT)**                       |
        |:-------------------------|:---------------------------------------------------------|:------------------------------------------------------|
        | **Managed by**           | User-space libraries                                    | Operating system kernel                              |
| **Context Switching**    | Faster (handled in user space)                          | Slower (requires system calls)                       |
| **Parallelism**          | No true parallelism (one CPU/core at a time)            | True parallelism on multi-core systems               |
| **Blocking Calls**       | Entire process blocks if a thread blocks                | Only the blocking thread is affected                 |
| **Thread Management**    | More efficient, no kernel overhead                      | Higher overhead due to kernel involvement            |
| **Scheduling**           | Application-level (more control but less optimized)     | Kernel-level (better resource utilization)           |
| **Portability**          | High, as threading is managed in user space             | Less portable due to kernel-specific implementations |

- Jacketing technique
    - The jacketing technique is used to convert a blocking system call into a non-blocking system call. In a traditional system call, the calling thread is blocked until the I/O operation is completed. Jacketing introduces an intermediate layer, known as a jacket routine, which checks if the I/O device is busy before making the system call. If the device is busy, the jacket routine queues the request and returns control to the calling thread, allowing it to continue executing other tasks. When the I/O device becomes available, the jacket routine resumes the original system call.

## Process synchronization:
- Models of parallel computing under the PRAM model, which defines how multiple processors in a parallel system interact with shared memory. (essentially how a memory is accessed)
    - EREW (Exclusive Read Exclusive Write)
    - CREW (Concurrent Read Exculsive Write)
    - CRCW (Concurrent Read Concurrent Write)
- The main objective of process synchronization is to ensure that multiple processes access shared resources without interfering with each other and to prevent the possibility of inconsistent data due to concurrent access.
#### Race conditions
A **race condition** occurs when two or more threads or processes try to access and modify shared data simultaneously, leading to unpredictable or incorrect results depending on the timing of their execution.

##### How to Prevent Race Conditions:
1. **Locks/Mutexes**: Ensure that only one thread can access critical sections at a time.
2. **Atomic Operations**: Operations that complete without being interrupted.
3. **Volatile Keyword**: For variables to be directly accessed from main memory.
4. **Thread Synchronization**: Using mechanisms like semaphores, barriers, or condition variables.

##### Example:
In a bank application, if two threads try to update a shared balance (say $100):
1. Thread A reads balance = 100.
2. Thread B reads balance = 100.
3. Thread A adds $50 (100 + 50 = 150) and writes.
4. Thread B adds $20 (100 + 20 = 120) and writes.

Final balance = $120 instead of $170.

Using **locks**, we ensure one thread completes before the other starts.

-------
- In multi-threaded computer programming, a function is **thread-safe** when it can be invoked or accessed concurrently by multiple threads without causing unexpected behavior, race conditions, or data corruption.
    - For example: If two threads are only reading shared data without modifying it, the execution order does not matter, and there's no race condition. Similarly, if the order of operations on shared data leads to the equivalent result regardless of execution timing, it's also safe. 

# Some code on system calls using C
- file descriptor: A unique id to identify a open file.
    - 0: for stdin
    - 1: for stdout
    - 2: for stderr
- system calls
    - open()
    - write()
    - execvp()
    - close()
    - exit()
    - wait()
    - sleep() which internally calls system calls

1) Program to create a file and write number from 1 to 100 in it.
    - [os_code1.c](os_code1.c)
    - Running:
        - gcc os_code1.c
        - ./a.out
    - Ouput:
        - Upon successful execution a file named 100_numbers.txt is created which contains numbers from 1 to 100.
2) Write a program which will execute another child process which will print all even numbers from 1 to 20 if command argument is even else it prints odd numbers from 1 to 20.
    - [os_code2_parent.c](os_code2_parent.c)
    - [os_code2_child.c](os_code2_child.c)
    - Running:
        - gcc os_code2_parent.c -o os_code2_parent.out
        - gcc os_code2_child.c -o os_code2_child.out
        - ./os_ocde2_parent.out even
    - Ouptut:
        - Upon successful execution 
3) Read input from a file and write the same input to another file
    - [os_code3.c](os_code3.c)
    - Running:
        - gcc os_code3.c -o os_code3.out
        - ./os_code3.out input.txt output.txt
    - Output:
        - Upon successful creation the contents from input.txt are copied to output.txt
4) Program to read from a file and then execute another process which will write the contents read from the file.
 

# CPU scheduling 
- Arrival Time: Time at which the process arrives in the ready queue.
- Completion Time: Time at which process completes its execution.
- Burst Time: Time required by a process for CPU execution.
- Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time  –  Arrival Time
- Waiting Time(W.T): Time Difference between turn around time and burst time. Waiting Time = Turn Around Time  –  Burst Time
- Response time: Response Time is the duration it takes for a system to react to a request or an action by a user or process. In computing, it is typically measured from the moment a user initiates a request (e.g., clicking a button, entering a command) until the system provides feedback or completes the requested operation.
- Sceduling algorithms:
    - First come first serve
    - Shortest job first (SJF)
        - One of the demerit SJF has is starvation. Many times it becomes complicated to predict the length of the upcoming CPU request.
    - Longest job first (LJF)
    - Priority scheduling
    - Round robin
        - Round Robin is a CPU scheduling algorithm where each process is cyclically assigned a fixed time slot. It is the preemptive version of First come First Serve CPU Scheduling algorithm.
    - Shortest Remaining Time First(SRTF)
        - Shortest remaining time first is the preemptive version of the Shortest job first which we have discussed earlier where the processor is allocated to the job closest to completion.
    - Longest Remaining Time First(LRTF)
        - The longest remaining time first is a preemptive version of the longest job first scheduling algorithm. 
    -  Highest Response Ratio Next(HRRN)
        - Highest Response Ratio Next is a non-preemptive CPU Scheduling algorithm and it is considered as one of the most optimal scheduling algorithms. The name itself states that we need to find the response ratio of all available processes and select the one with the highest Response Ratio. A process once selected will run till completion. 
        -  Response Ratio = (W + S)/S
            - Here, W is the waiting time of the process so far and S is the Burst time of the process.
        - HRRN is considered as the modification of the Shortest Job First to reduce the problem of starvation.
        - The on ground implementation of HRRN scheduling is not possible as it is not possible know the burst time of every job in advance.

    
## File system management:
- The inode table is a critical data structure in a Unix/Linux filesystem that holds all the inodes for a particular filesystem.
    - The inode table is essentially a collection of inodes, each corresponding to a file or directory within the filesystem. It provides a mapping between file names and their associated metadata.
    - Effect of fragmentation on inode table:
        - As the inode table fills up and some inodes become free, the remaining inodes may be spread throughout the table instead of being grouped together.
        - This can lead to a scenario where the system needs to search through non-contiguous locations in the inode table to find a free inode for a new file, which takes longer and can slow down file access and creation.
    - [inode_structure.png](inode_structure.png)
- Key information stored in inode index:
    - Inode index is the unique id of a file.
    - File type: Whether it's a regular file, directory, symbolic link, etc.
    - Permissions: Who can access the file (owner, group, others) and what they can do (read, write, execute).
    - Ownership: The user and group that own the file.
    - Time stamps: Creation time, modification time, and last access time.
    - Size: The file size in bytes.
    - Location: Pointers to the data blocks that make up the file.
- A file can be well understood by juxtaposing with disk block.
    - A file is a collection of related data stored in a computer system. File is a basic unit of data organisation and storage.
        - Disk blocks are the physical units of storage on a disk drive. They are the smallest addressable unit of data on a disk. A disk is divided into a large number of disk blocks, each of which can store a fixed amount of data.
        - Logical vs. physical: Files are logical entities that represent a collection of data, while disk blocks are physical units of storage.
    - Size: Files can vary in size, while disk blocks have a fixed size.
    - Organization: Files are organized into directories or folders, while disk blocks are organized sequentially on the disk.
    - Access: Files are accessed by their name, while disk blocks are accessed by their physical location on the disk.
    - Files are typically stored across multiple blocks.
    - The operating system manages the allocation and deallocation of disk blocks for files.
        - The inode (or similar data structure) of a file stores pointers to the disk blocks that contain the file's data.
    - Files can contain various types of information, such as text, images, audio, video, programs, or documents.
        - Data in disk blocks is in binary format.
        - While data is stored in binary format on a disk, it needs to be converted into a format that humans can understand, such as audio or video.  
            - Encoding: When an audio or video file is created, it's converted from its original form (e.g., sound waves, images) into binary data. This process is called encoding. 
            - Storage: The encoded binary data is then stored on a disk.
            - Decoding: When you want to play an audio or video file, a playback device (like your computer, phone, or TV) reads the binary data from the disk. It then uses a decoder to convert the binary data back into its original form. This process is called decoding. The decoder uses the same encoding method that was used to create the file.
    - Due to fragmentation the disk blocks allocated to a file may not be contiguous.
        - Defragmentation is the process of reorganizing the data on a disk so that files are stored in contiguous blocks.
        - The default file system for linux: ext4 (and many other file systems) are designed to minimize fragmentation.
- Way to handle system crashes:
    - Journaling
    - Source: [Wiki](https://en.wikipedia.org/wiki/Journaling_file_system)
