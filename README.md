# 🧠 CPU Scheduling Algorithms Simulation

A simple and educational simulation of **CPU Scheduling Algorithms** written in **C**.  
This project helps visualize how different scheduling strategies work in operating systems.

---

## 🚀 Features

- Implements four major CPU scheduling algorithms:
  1. **FCFS (First-Come, First-Served)**
  2. **SJF (Shortest Job First)**
  3. **Priority Scheduling**(lower the number higher the priority)
  4. **Round Robin**
- Calculates:
  - **Average Waiting Time**
  - **Average Turnaround Time**
- Displays a **Gantt Chart** showing process execution order.
- Helps compare performance and fairness of different scheduling techniques.

---

## 🧩 Project Structure

<pre>
Cpu-Scheduling-Algorithms/
│
├── main.c               # Entry point of the program
├── scheduling.c         # Core algorithm implementations
├── scheduling.h         # Function declarations and structure definitions
├── round_robin.c        # Round Robin specific implementation (later was included in scheduling.c)
└── README.md            # Project documentation (this file)
</pre>

---

## ⚙️ Compilation and Execution

### Step 1: Clone the Repository
```bash
git clone https://github.com/Not-your-person/Cpu-Scheduling-Algorithms.git
cd Cpu-Scheduling-Algorithms
```
### Step 2: Compile the Program

Use GCC (or any C compiler):
```
gcc main.c scheduling.c round_robin.c -o cpu
```
### Step 3: Run the Program
```
./cpu
```
## 🧾 Input Format

When you run the program, it will ask for process details.
You need to provide:

Number of processes (n)

Arrival time of each process

Burst time (CPU time required)

Priority (for priority scheduling only)

Time Quantum (for Round Robin scheduling)

## Example Input
<pre> Enter the number of processes: 4 Enter details for each process: 
  Process 1 → Arrival Time: 0 Burst Time: 5 Priority: 2 
  Process 2 → Arrival Time: 1 Burst Time: 3 Priority: 1 
  Process 3 → Arrival Time: 2 Burst Time: 8 Priority: 4 
  Process 4 → Arrival Time: 3 Burst Time: 6 Priority: 3
  Enter time quantum (for Round Robin): 2 </pre>
## 🧮 Expected Output

The program will display:

Gantt Chart showing the order of process execution

Average Waiting Time

Average Turnaround Time

Example Output (Round Robin)
<pre> Gantt Chart: P1 | P2 | P3 | P4 | P1 | P3 | P4 | P3 (in bar graph) Average Waiting Time = 4.25 Average Turnaround Time = 8.00 </pre>
Example Output (SJF)
<pre> Gantt Chart: P2 | P1 | P4 | P3 (in bar graph) Average Waiting Time = 3.50 Average Turnaround Time = 7.25 </pre>
# 📊 Comparison Summary
| Algorithm       | Type             | Strengths                | Weaknesses              |
| --------------- | ---------------- | ------------------------ | ----------------------- |
| **FCFS**        | Non-preemptive   | Simple to implement      | Convoy effect (slow)    |
| **SJF**         | Non-preemptive   | Low average waiting time | Can cause starvation    |
| **Priority**    | Pre/Non-preempt. | Flexible, priority-based | Low priority starvation |
| **Round Robin** | Preemptive       | Fair, responsive         | Context switch overhead |

---
# Running the Code (For 🟧 emoji for gantt chart)
## On Windows

Windows consoles (like CMD or old PowerShell) use legacy encodings by default, so emojis may appear as gibberish (e.g., ðŸŸ§).

Fix:
```
Enable UTF-8 mode:

chcp 65001
```

Use a font that supports emojis (e.g., Cascadia Code, Segoe UI Emoji, or Noto Color Emoji).

Run the program in Windows Terminal (recommended).
```
gcc emoji.c -o emoji.exe
./emoji.exe
```
## On macOS

macOS terminals use UTF-8 by default, so it should work out of the box.

If emojis still display incorrectly:

Make sure your file is saved as UTF-8.

In VS Code → bottom-right corner → "UTF-8".

Force UTF-8 locale in the terminal:
```
export LANG=en_US.UTF-8
export LC_ALL=en_US.UTF-8
```

Run:
```
gcc emoji.c -o emoji
./emoji
```
## On Linux

Most modern Linux terminals already use UTF-8.
If needed:
```
export LANG=en_US.UTF-8
gcc emoji.c -o emoji
./emoji
```
