🏰 Hanoi Tower Solver

📌 Overview

This project is a C++ console application that solves the classic Towers of Hanoi problem using both recursive and iterative approaches.
The user can select the number of disks and the solution method at runtime.
The program also compares the performance of recursive and iterative solutions.

🚀 Features

Recursive Solution

Uses a simple recursive algorithm.

Moves disks from source to destination using an auxiliary tower.

Iterative Solution

Uses a stack-based simulation instead of recursive calls.

Efficiently generates moves without recursion.

Visualization

Current state of towers printed step by step.

Shows each disk movement and updates the total step count.

Performance Testing

Calculates the number of moves and execution time.

Allows comparison between recursive vs iterative methods.

🧩 Main Functions

printTowers(...) → Displays the current state of the towers.

moveDisk(...) → Moves a single disk between towers and updates step count.

recursiveHanoi(...) → Solves Hanoi Towers using recursion.

iterativeHanoi(...) → Solves Hanoi Towers using a stack (non-recursive).

solveHanoi(...) → Chooses the solution method and measures performance.

🔮 Future Improvements

Graphical visualization (GUI) for tower movements.

Support for saving results to a file.

Performance chart comparing execution time for different disk sizes.

📜 License

This project is licensed under the MIT License – free to use, modify, and distribute.
