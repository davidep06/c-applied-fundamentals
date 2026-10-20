# C Applied Fundamentals & Algorithms

A collection of C programming projects, data structures, and algorithms developed during my first year of Computer Science studies. The repository shows the progression from core programming fundamentals and memory manipulation to file persistence, state-space search (backtracking), and graph algorithms.

---

## Repository Structure

```text
c-applied-fundamentals/
├── c-foundations/                     # Semester 1: core C, matrices, bitwise operations, pointers
├── c-algorithms-and-techniques/       # Semester 2: algorithms and file organization
│   ├── inventory-project/             # Relative (direct-access) binary file management
│   ├── invoice-project/               # Binary persistence with nested arrays
│   ├── water-consumption-project/     # Multi-record binary updates and reporting
│   ├── indexed-database-project/      # Indexed file organization with binary search
│   ├── backtracking/                  # Combinatorial optimization and constraint satisfaction
│   └── graphs/                        # Graph traversals, shortest paths, tree validation
└── README.md
```

---

## Semester 1: C Foundations (`c-foundations/`)

Focuses on low-level memory manipulation, dynamic allocation, bitwise operations, and two-dimensional array processing.

| File | Description |
|------|-------------|
| `bitwise_matrix_filter.c` | Bitwise operations and masking applied to matrix elements. |
| `dynamic_array_min_max.c` | Dynamic memory allocation and pointer arithmetic to find the minimum and maximum. |
| `failing_students_matrix.c` | Filtering multi-dimensional data to identify failing students. |
| `magic_square_checker.c` | Checks whether a matrix is a magic square (equal row, column, and diagonal sums). |
| `matrix_multiplication.c` | Matrix multiplication with dimension validation. |
| `student_grades_statistics.c` | Statistical aggregation and reporting over student grade data. |

---

## Semester 2: Algorithms & Programming Techniques (`c-algorithms-and-techniques/`)

### 1. File Organization & Persistence

Projects demonstrating relative (direct-access, via `fseek`/`ftell`) and indexed binary file organization, plus export to formatted text.

* **Inventory Management (`inventory-project/`)**
  * `inventory_binary_writer.c` and `binary_to_text_exporter.c` – manage an inventory stored in a relative binary file (each record at a position derived from its key, so existing records are not overwritten) and export the active items to a formatted text table.
* **Invoice Processing (`invoice-project/`)**
  * `invoice_binary_writer.c` and `invoice_text_exporter.c` – handle `struct` records with embedded product arrays and format the exported rows dynamically.
* **Apartment Water Consumption (`water-consumption-project/`)**
  * `water_consumption_writer.c` and `water_consumption_updater.c` – track 12 months of hot and cold water readings using nested structures, with in-place record updates (`rb+` mode) and tabular reports.
* **Indexed Patient Database (`indexed-database-project/`)**
  * `indexed_patient_db.c` – separates the master data file (`pacient.dat`) from a sorted index file (`index.dat`). Supports logical deletion, in-place modification, and **O(log n) lookups using binary search** on the index file.

---

### 2. Backtracking & Combinatorial Optimization (`backtracking/`)

State-space search algorithms for optimization problems (several of them NP-hard) and constraint satisfaction puzzles.

* **`traveling_salesperson_tsp.c`** – solves the **Traveling Salesperson Problem (TSP)** by exploring Hamiltonian cycles in a weighted adjacency matrix to find the minimum-cost tour.
* **`knapsack_01_optimizer.c`** – solves the **0-1 Knapsack Problem**: selects the subset of items that maximizes profit without exceeding the weight capacity.
* **`aircraft_fleet_optimization.c`** – multi-constraint resource allocation that maximizes the average flight range under a budget limit and a minimum visibility requirement.
* **`n_queens_solver.c`** – **N-Queens** solver with column and diagonal attack checks, writing the chessboard solutions to text files.
* **`knights_round_table.c`** – generates circular permutations to find valid seating arrangements around a round table, given a conflict matrix and without counting rotations as distinct solutions.
* **`coin_change_combinations.c`** – bounded change-making: generates all combinations of banknotes (with limited quantities) that sum to a target value.

---

### 3. Graph Theory & Network Algorithms (`graphs/`)

Fundamental traversal, connectivity, and shortest-path algorithms on weighted and unweighted graphs.

* **`dijkstra_shortest_path.c`** – **Dijkstra's algorithm**: minimum-cost paths from a source vertex in a graph with non-negative edge weights, using edge relaxation.
* **`roy_floyd_all_pairs_shortest_path.c`** – **Roy-Floyd (Floyd-Warshall) algorithm**: all-pairs shortest paths using dynamic programming, O(V³).
* **`elementary_path_cycle_reducer.c`** – takes a user-defined walk, removes redundant cycles to obtain an elementary path, and computes its total cost.
* **`tree_property_validator_dfs.c`** – checks whether an undirected graph is a **tree**: it must have exactly V − 1 edges and be connected, which is verified with **Depth-First Search (DFS)**.
* **`breadth_first_search_bfs.c`** – **Breadth-First Search (BFS)** with an array-based queue, for level-order traversal and connectivity checking.

---

## Technologies & Concepts

* **Language:** C (standard C99/C11)
* **Core concepts:** pointers, dynamic memory allocation, bitwise manipulation, structs, two-dimensional arrays
* **File I/O:** binary direct access (`fopen`, `fseek`, `ftell`, `fread`, `fwrite`), indexed files, formatted text output
* **Algorithms:** binary search, backtracking, dynamic programming (Floyd-Warshall), shortest paths (Dijkstra), graph traversals (BFS, DFS)

---

## How to Compile and Run

Any source file can be compiled with `gcc` (Linux, or MinGW on Windows) or with Visual Studio (MSVC).

**Linux / macOS:**

```bash
gcc -std=c11 -Wall -Wextra path/to/file.c -o program
./program
```

**Windows (MinGW):**

```bash
gcc -std=c11 -Wall -Wextra path\to\file.c -o program.exe
program.exe
```
