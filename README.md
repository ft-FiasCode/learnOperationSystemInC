# 📚 learnOperationSystemInC
<div align="center">
<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=24&pause=1000&center=true&vCenter=true&width=750&lines=Learn+Operating+Systems+In+C+From+Scratch;Beginner+Friendly+Kernel+Programming+Repository;Understand+Core+OS+Concepts;Build+Strong+Systems+Programming+Foundations" alt="Typing Animation" />
<br><br>

![Language](https://img.shields.io/badge/Language-C-brightgreen?style=for-the-badge&logo=c)
![Topic](https://img.shields.io/badge/Topic-Operating%20Systems-purple?style=for-the-badge&logo=linux)
![Beginner Friendly](https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge)
![Practice](https://img.shields.io/badge/Practice-OS%20Implementations-orange?style=for-the-badge)
![Hands-on](https://img.shields.io/badge/Hands-on-Labs-blue?style=for-the-badge)
![Kernel](https://img.shields.io/badge/Type-Kernel%20Coding-red?style=for-the-badge)
![Open Source](https://img.shields.io/badge/Open%20Source-Yes-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)
![Coverage](https://img.shields.io/badge/Coverage-Process%2C+Memory%2C+I%2FO-yellow?style=for-the-badge)

<br><br>

[![GitHub stars](https://img.shields.io/github/stars/ft-FiasCode/learnOperationSystemInC?style=for-the-badge&logo=github)](https://github.com/ft-FiasCode/learnOperationSystemInC/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/ft-FiasCode/learnOperationSystemInC?style=for-the-badge&logo=github)](https://github.com/ft-FiasCode/learnOperationSystemInC/network)
[![GitHub issues](https://img.shields.io/github/issues/ft-FiasCode/learnOperationSystemInC?style=for-the-badge&logo=github)](https://github.com/ft-FiasCode/learnOperationSystemInC/issues)
[![GitHub PRs](https://img.shields.io/github/issues-pr/ft-FiasCode/learnOperationSystemInC?style=for-the-badge&logo=github)](https://github.com/ft-FiasCode/learnOperationSystemInC/pulls)
[![GitHub license](https://img.shields.io/github/license/ft-FiasCode/learnOperationSystemInC?style=for-the-badge)](LICENSE)
[![GitHub Language](https://img.shields.io/github/languages/top/ft-FiasCode/learnOperationSystemInC?style=for-the-badge)](https://github.com/ft-FiasCode/learnOperationSystemInC)

<br><br>

**A structured journey through Operating System fundamentals, implemented from scratch in C.**

</div>


## 📖 Overview

This repository provides a hands-on, practical approach to understanding core Operating System concepts by implementing them in C. Designed for students, educators, and anyone looking to deepen their knowledge of how operating systems work under the hood, this collection of C programs offers clear, concise examples covering essential topics like process management, inter-process communication, CPU scheduling, and memory management.

Each C file serves as a standalone demonstration of a specific OS principle, allowing users to compile, run, and experiment directly with the code to observe its behavior and grasp the underlying mechanics.

## ✨ Key Learning Areas

The repository is organized around fundamental Operating System topics, with each C program demonstrating a specific concept:

### ⚙️ Process Management
Explore how processes are created, managed, and interact within an operating system.
-   `childzombie.c`: Demonstrates the creation of zombie processes.
-   `forkinfork.c`: Illustrates multiple `fork()` calls creating complex process trees.
-   `forkinforloop.c`: Shows process creation using `fork()` within a loop.
-   `forksleppwait.c`: Explores the `fork()`, `sleep()`, and `wait()` system calls for process synchronization.
-   `multipefork.c`: Provides further examples of creating multiple child processes with `fork()`.
-   `osphanprocess.c`: Illustrates the creation of orphan processes.
-   `preventzombiewait.c`: Demonstrates methods to prevent zombie processes using `wait()`.
-   `processcreation.c`: Basic demonstration of process creation using `fork()` and `exec()`.

### 📩 Inter-Process Communication (IPC)
Understand various mechanisms for processes to communicate and synchronize their actions.
-   `interprocesscommunication.c`: Demonstrates unidirectional IPC using pipes.
-   `interprocesscommunicationbidirectonal.c`: Illustrates bidirectional IPC using two pipes.
-   `semaphores.c`: Implements process synchronization using semaphores to solve critical section problems.

### ⏱️ CPU Scheduling Algorithms
Implement and analyze different algorithms that an OS uses to manage process execution on the CPU.
-   `FCFS.c`: First-Come, First-Served (FCFS) scheduling algorithm simulation.
-   `longestjob.c`: Basic implementation of Longest Job First (LJF) scheduling.
-   `roundrobin.c`: Round Robin (RR) scheduling algorithm simulation.
-   `rr.c`: Another implementation/variation of the Round Robin scheduling algorithm.
-   `shortestjob.c`: Basic implementation of Shortest Job First (SJF) scheduling.
-   `sjf.c`: A more comprehensive simulation of the Shortest Job First (SJF) scheduling algorithm.

### 🧠 Memory Management & Page Replacement
Dive into memory organization and strategies for managing virtual memory and page faults.
-   `memorymanagement.c`: General concepts of memory allocation and deallocation.
-   `pageFIFO.c`: First-In, First-Out (FIFO) page replacement algorithm simulation.
-   `pageLFU.c`: Least Frequently Used (LFU) page replacement algorithm simulation.
-   `pageLRU.c`: Least Recently Used (LRU) page replacement algorithm simulation.
-   `pageMRU.c`: Most Recently Used (MRU) page replacement algorithm simulation.
-   `pageOPTIMAL.c`: Optimal page replacement algorithm simulation (used for comparison).
-   `pageclock.c`: Clock page replacement algorithm simulation.

### 📂 File System Operations
Basic demonstrations of how an operating system interacts with files.
-   `fileinputoutput.c`: Examples of fundamental file input and output operations.



### 📂 Lab Index
🔹 Lab 01: OS Administration – Installation of Linux Distribution (Ubuntu)

Objective: Install and configure Ubuntu Linux.

System requirements

Downloading Ubuntu ISO

Disk space allocation

Creating a bootable USB

Step-by-step Ubuntu installation

🔹 Lab 02: OS Administration – Exploring the Linux Environment

Objective: Understand Linux file systems and directory structure.

Linux file systems

File system layout

Root directory and subdirectories

Directory navigation commands

🔹 Lab 03: OS Administration – Essential Linux Commands

Objective: Learn core Linux commands and user management.

Adding and deleting users

Basic Linux commands

Process-related commands

File manipulation

Command grouping & filters

🔹 Lab 04: Process States in Operating Systems

Objective: Understand process states.

Windows Task Manager

Linux process states

🔹 Lab 05: Process Management – Process Creation

Objective: Learn how processes are created and identified.

Process creation

Process identification

System calls: fork(), getpid(), getppid()

🔹 Lab 06: Process Management – Process Exit & Wait

Objective: Understand process termination and synchronization.

exit() system call

wait() system call

🔹 Lab 07: Process Management – Multiple & Orphan Processes

Objective: Manage multiple processes.

Multiple fork() calls

Orphan processes

🔹 Lab 08: Process Scheduling – First Come First Serve (FCFS)

Objective: Study FCFS scheduling.

Multiprogramming

Scheduling algorithms

FCFS scheduling

Disadvantages

🔹 Lab 09: Process Scheduling – Shortest Job First (SJF)

Objective: Understand SJF scheduling.

SJF algorithm

Advantages & disadvantages

🔹 Lab 10: Process Scheduling – Round Robin (RR)

Objective: Analyze Round Robin scheduling.

RR scheduling

Advantages & disadvantages

Performance evaluation

🔹 Lab 11: Mutual Exclusion Using Semaphores

Objective: Implement synchronization using semaphores.

Semaphore concept

Advantages & disadvantages

🔹 Lab 12: File I/O – Reading & Writing Files

Objective: Perform file operations.

File reading

File writing

🔹 Lab 13: Inter-Process Communication Using Pipes

Objective: Understand IPC mechanisms.

Pipes

Communication between processes

🔹 Lab 14: Memory Management

Objective: Learn memory management concepts.

Memory allocation

Memory management techniques

🔹 Lab 15: Page Fault

Objective: Learn page Fault concepts.

Apply different Algo on page fault

### 🎯 Learning Outcomes

By completing this lab manual, students will be able to:

Install and configure Linux OS

Use essential Linux commands

Understand process creation & scheduling

Implement synchronization techniques

Perform IPC and file I/O operations

## 🛠️ Tech Stack

-   **Language:** C
-   **Compiler:** GCC (GNU Compiler Collection) or Clang
-   **Environment:** POSIX-compliant operating system (Linux, macOS, WSL)

## 🚀 Getting Started

To compile and run the examples in this repository, you will need a C compiler installed on your system.

### Prerequisites

-   **C Compiler:** Ensure you have `gcc` (or `clang`) installed.
    -   On Debian/Ubuntu: `sudo apt-get install build-essential`
    -   On Fedora: `sudo dnf install gcc`
    -   On macOS: Install Xcode Command Line Tools (`xcode-select --install`)
-   **Operating System:** A Unix-like environment (Linux, macOS, or Windows Subsystem for Linux (WSL)).

### Installation

1.  **Clone the repository**
    ```bash
    git clone https://github.com/ft-FiasCode/learnOperationSystemInC.git
    cd learnOperationSystemInC
    ```

### Running Examples

Each `.c` file in this repository is a standalone program. You can compile and run them individually.

1.  **Compile a C file:**
    Use `gcc` (or `clang`) to compile the source code into an executable. Replace `<source_file.c>` with the name of the C file you want to run (e.g., `FCFS.c`) and `<output_name>` with your desired executable name (e.g., `fcfs`).

    ```bash
    gcc -o <output_name> <source_file.c>
    # Example:
    gcc -o fcfs FCFS.c
    ```

2.  **Execute the compiled program:**
    Run the executable generated in the previous step.

    ```bash
    ./<output_name>
    # Example:
    ./fcfs
    ```

### Example Usage (FCFS Scheduling)

```bash

# Clone the repository (if not already done)
git clone https://github.com/ft-FiasCode/learnOperationSystemInC.git
cd learnOperationSystemInC

# Compile the FCFS scheduling example
gcc -o fcfs FCFS.c

# Run the FCFS scheduling simulation
./fcfs
```
This will output the results of the FCFS scheduling algorithm based on the hardcoded processes in `FCFS.c`. You can modify the process details within the source file to experiment with different scenarios.

## 📁 Project Structure

The repository maintains a flat structure, with each C file serving as an independent example.

```
learnOperationSystemInC/
├── FCFS.c                      # First-Come, First-Served CPU scheduling
├── LICENSE                     # Project license file
├── README.md                   # This README file
├── childzombie.c               # Demonstrates zombie processes
├── fileinputoutput.c           # Basic file I/O operations
├── forkinfork.c                # Multiple fork() calls
├── forkinforloop.c             # fork() in a loop
├── forksleppwait.c             # fork(), sleep(), wait() system calls
├── interprocesscommunication.c # Unidirectional IPC using pipes
├── interprocesscommunicationbidirectonal.c # Bidirectional IPC using pipes
├── longestjob.c                # Longest Job First (LJF) scheduling
├── memorymanagement.c          # General memory management concepts
├── multipefork.c               # Multiple process creation
├── osphanprocess.c             # Demonstrates orphan processes
├── pageFIFO.c                  # FIFO page replacement algorithm
├── pageLFU.c                   # LFU page replacement algorithm
├── pageLRU.c                   # LRU page replacement algorithm
├── pageMRU.c                   # MRU page replacement algorithm
├── pageOPTIMAL.c               # Optimal page replacement algorithm
├── pageclock.c                 # Clock page replacement algorithm
├── preventzombiewait.c         # Preventing zombie processes
├── processcreation.c           # Basic process creation
├── roundrobin.c                # Round Robin (RR) scheduling
├── rr.c                        # Another Round Robin (RR) implementation
├── semaphores.c                # Process synchronization with semaphores
├── shortestjob.c               # Shortest Job First (SJF) scheduling
└── sjf.c                       # Detailed Shortest Job First (SJF) implementation
```

## 🤝 Contributing

Contributions are welcome! If you have additional OS concepts implemented in C, improvements to existing examples, or bug fixes, please feel free to open a pull request.

1.  Fork the repository.
2.  Create your feature branch (`git checkout -b feature/AmazingFeature`).
3.  Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4.  Push to the branch (`git push origin feature/AmazingFeature`).
5.  Open a Pull Request.

Please ensure your code adheres to a consistent style and includes comments where necessary to explain complex logic.



## 🙏 Acknowledgments

-   This repository is maintained by [ft-FiasCode](https://github.com/ft-FiasCode).
-   Inspired by numerous Operating Systems courses and textbooks worldwide, aiming to provide practical coding examples for theoretical concepts.

## 📞 Support & Contact

-   🐛 Issues: [GitHub Issues](https://github.com/ft-FiasCode/learnOperationSystemInC/issues)

---

<div align="center">

# 📜 License

[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

This project is open-source and free to use, modify, and distribute.

---

⭐ If you found this project useful, consider **starring the repository**!

![Author](https://img.shields.io/badge/Author-ft--FiasCode-blue?style=flat&logo=github)


Made with ❤️ by [ft-FiasCode](https://github.com/ft-FiasCode)
```
