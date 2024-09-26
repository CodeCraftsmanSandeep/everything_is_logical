# OS


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
        - Kernel is the core component of OS, which is responsible for handling various features such as: process managmenet, memory managmenet, etc.
        - A kernel loads first into memory when an operating system is loaded and remains in memory until the operating system is shut down again. 
        - The rest of the components in OS depends on kernel for the supply of the important services that are provided by OS.
        - Types of kernel
            1) Monolithic kernel
            2) Micro kernel
            3) Hybrid kernel
- Types of OS
    1) Batch OS
    2) Multi-programming OS
        - Multi programming is pseduo parallelsim
    3) Multi-processing OS
        - A multiprocessing operating system is defined as a type of operating system that makes use of more than one CPU to improve performance. Multiple processors work parallelly in multi-processing operating systems to perform the given task. 
        - Multi processing is true parallelsim.
## CPU scheduling algorithms
- Non-Preemptive Scheduling Algorithm
    - In non-preemptive scheduling, once a process is given the CPU, it runs to completion or until it voluntarily releases the CPU (e.g., by completing execution or waiting for I/O).
- Preemptive Scheduling Algorithm
    - In preemptive scheduling, the CPU can be taken away from a process if a higher-priority process arrives or after a certain time interval (time quantum in case of round-robin scheduling). The running process is interrupted and moved back to the ready queue.
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


# Memory
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

- [Source](https://www.geeksforgeeks.org/process-table-and-process-control-block-pcb/). A process control board (PCB) stores various  information about a process so that the operating system can manage it properly. Like:
    1) Process ID (PID)
    2) Process Status
    3) CPU Registers
    4) Memory Management Information
    5) I/O Information
    6) stack pointer
    7) Program counter
- Process table is an array of PCB's of all process.
- Context Switching: The process of switching from one process to another is called context switching. The PCB plays a crucial role in context switching by saving the state of the current process and restoring the state of the next process.
- Process: Program under execution. Thread: Part of a process.
    - The process is isolated. Threads share memory.
- Zombie vs Orphan vs Daemon process
    - Zombie process
        - A process which has been terminated but still has an entry in the process table is called Zombie process
    - Orphan process
        - A process continues to run, whose parent has terminated is called Orphan process.
    - Daemon process
        - A daemon process is a background process which starts with system boot and runs until shutdown.
# Some code on system calls using C
- file descriptor: A unique id to identify a open file.
    - 0: for stdin
    - 1: for stdout
    - 2: for stderr
- system calls
    - write()
    - read()

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
3) Program to read from a file and then execute another process which will write the contents read from the file.
    