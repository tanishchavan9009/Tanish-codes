# TANISH CODES
### Comprehensive Computer Science, Software Engineering & Applied Mathematics Repository

---

## Executive Summary

**Tanish Codes** is a consolidated software development and computer science repository maintaining production implementations, algorithmic coursework, system utilities, and web applications. The repository bridges low-level systems programming in C and C++, full-stack web application development in Python and Flask, and computational modeling tools in JavaScript and HTML5.

Every module within this repository is designed following standard software engineering practices, clean code conventions, and modular architecture.

---

## Table of Contents

1. [Architectural Overview](#architectural-overview)
2. [Web Applications & Interactive Scientific Tools](#web-applications--interactive-scientific-tools)
   - [Farmer Market Crop Price Prediction](#1-farmer-market-crop-price-prediction)
   - [Smart Password Generator & Vault](#2-smart-password-generator--vault)
   - [Engineering Mathematics Suite (ErfSolve & Partial Derivatives)](#3-engineering-mathematics-suite)
3. [Object-Oriented Programming & Systems Architecture (C++)](#object-oriented-programming--systems-architecture-c)
4. [Data Structures, Algorithms & Foundational Computing (C)](#data-structures-algorithms--foundational-computing-c)
5. [Complete Repository Catalog](#complete-repository-catalog)
6. [Compilation, Build & Execution Manual](#compilation-build--execution-manual)
7. [Version Control Configuration (.gitignore)](#version-control-configuration-gitignore)
8. [Author & Maintenance](#author--maintenance)

---

## Architectural Overview

The repository is logically structured into specialized functional layers:

```text
Tanish codes/
├── crop_prediction/      # Intelligent agricultural decision-support web platform
├── website/              # Python/Flask password generator with SQLite persistence
├── errorfunction/        # Numerical computing engine for Gaussian error functions
├── partialderivative/    # Interactive multivariable differential calculus solver
├── cpp/                  # Modular C++ OOP systems (Stack ADT, text processing, Makefile)
├── C/                    # Core C numerical algorithms, series approximations & foundations
├── html/                 # Web documentation, C structures, and digital logic archives
├── .vscode/              # Algorithmic recursion, binary search, and IDE build tasks
└── [Root]                # Core C algorithms, sorting routines, and console utilities
```

---

## Web Applications & Interactive Scientific Tools

### 1. Farmer Market Crop Price Prediction
* **Directory:** `crop_prediction/`
* **Entry Point:** `crop_prediction/index.html`
* **Technology Stack:** HTML5, CSS3 (Modern Glassmorphic UI), JavaScript (ES6+), Chart.js

#### Overview
An agricultural predictive platform designed to assist farmers, suppliers, and agricultural economists in forecasting commodity market prices and optimizing selling schedules.

#### Key Features & Technical Details
* **Time-Series Market Visualization:** Leverages Chart.js to project 30-day commodity price trends, tracking gold, green, and white grain classifications.
* **Environmental & Soil Metrics:** Monitors ambient temperature, humidity, and soil moisture indicators to evaluate crop readiness and price sensitivity.
* **Commercial Decision Engine:** Computes optimal sales windows based on market volatility indicators and yield forecasting algorithms.
* **Responsive Architecture:** Fully responsive interface featuring high-contrast data cards, metric badges, and interactive control panels.

---

### 2. Smart Password Generator & Vault
* **Directory:** `website/`
* **Backend Application:** `website/app.py`
* **Persistence Layer:** SQLite (`website/passwords.db`)
* **Frontend Templates:** `website/templates/index.html`
* **Styling:** `website/static/style.css`
* **Technology Stack:** Python 3, Flask, SQLite3, HTML5, CSS3, JavaScript

#### Overview
A web-based cybersecurity utility that creates cryptographically strong, pseudo-random passwords conforming to configurable entropy criteria, while logging credential metadata for administrative auditing.

#### Key Features & Technical Details
* **Configurable Character Sets:** Granular toggle controls for alphanumeric lower/uppercase characters (`a-z`, `A-Z`), numeric digits (`0-9`), and high-entropy symbols (`!@#$%^&*()_+-=[]{}`).
* **Complexity Presets:** Tiered difficulty classifications (*Simple*, *Hard*, *Difficult*, *Very Difficult*) with customizable length constraints (4 to 30 characters).
* **Database Auditing:** Integrates with SQLite (`passwords.db`) to record password complexity, character length, generated string values, and execution timestamps via ISO 8601 strings.
* **Client-Side Clipboard API:** Implements JavaScript clipboard automation (`navigator.clipboard` / `document.execCommand`) with real-time user notification.

---

### 3. Engineering Mathematics Suite
Interactive analytical and numerical computing tools designed for higher engineering mathematics and scientific computation.

#### A. ErfSolve: Gaussian Error Function Engine
* **Directory:** `errorfunction/`
* **Files:** `errorfunction/index.html`, `errorfunction/script.js`, `errorfunction/style.css`
* **Mathematical Scope:** Special Functions, Probability Theory, Numerical Integration
* **Mathematical Formulation:**
  $$\text{erf}(x) = \frac{2}{\sqrt{\pi}} \int_0^x e^{-t^2} dt$$
* **Capabilities:**
  * **Numerical Quadrature:** Computes definite integrals using numeric approximation algorithms over continuous intervals.
  * **Taylor Series Approximations:** Computes power series expansions for localized evaluation.
  * **Dynamic Canvas Plotting:** Plots dynamic mathematical graphs on HTML5 Canvas with real-time coordinate transformations.
  * **LaTeX Rendering:** Integrates MathJax 3 for mathematical notation display.

#### B. Multivariable Partial Derivative Solver
* **Directory:** `partialderivative/`
* **Files:** `partialderivative/partial.html`
* **Technology Stack:** Math.js Computer Algebra System, Syne & Space Mono Typography
* **Capabilities:**
  * **Symbolic Differentiation:** Analyzes two-variable scalar fields $z = f(x, y)$ to compute first-order partial derivatives ($\frac{\partial z}{\partial x}$, $\frac{\partial z}{\partial y}$) and mixed second-order derivatives.
  * **Gradient Computation:** Evaluates the gradient vector $\nabla f(x, y) = \left\langle \frac{\partial f}{\partial x}, \frac{\partial f}{\partial y} \right\rangle$ at defined coordinates $(x_0, y_0)$.
  * **Step-by-Step Proofs:** Provides algorithmic step-by-step expansions for educational analysis.

---

## Object-Oriented Programming & Systems Architecture (C++)

The `cpp/` directory contains structured C++ software systems demonstrating modular design, object-oriented principles, memory management, and build automation.

### Key Components
1. **Modular Stack Abstract Data Type (ADT):**
   * **Header Interface:** `cpp/stack.h` &bull; Declares class specifications, stack bounds, and method signatures.
   * **Implementation File:** `cpp/stack.cpp` &bull; Encapsulates low-level array indexing, push/pop operations, and overflow/underflow handling.
   * **Driver Client:** `cpp/stack_main.cpp` &bull; Demonstrates client-side instantiation, exception testing, and execution workflow.
2. **Word Processing & Text Formatter System:**
   * **Header Interface:** `cpp/wp.h` &bull; Word processor class specifications.
   * **Implementation File:** `cpp/wp.cpp` &bull; Text manipulation, whitespace justification, token parsing, and formatting routines.
   * **Driver Client:** `cpp/wp_main.cpp` &bull; Execution driver for text formatting test suites.
3. **Build Automation (`cpp/Makefile`):**
   * Configures compiler flags (`-Wall -std=c++17`), separate compilation of translation units into object files (`.o`), and executable linking.
4. **Preprocessor & Macro Demonstrations (`cpp/macro_program.cpp`):**
   * Explores macro expansions, inline functional logic, and conditional compilation flags.
5. **Coursework Assignments:**
   * `cpp/ass0.cpp` & `cpp/ass1.cpp`: Formal programming assignments analyzing data abstraction, encapsulation, and control flow.

---

## Data Structures, Algorithms & Foundational Computing (C)

The repository root and `C/` directory house algorithmic implementations categorized as follows:

### 1. Sorting & Searching Algorithms
* **`bubblesort.c`:** Classical Bubble Sort algorithm with adjacent-element exchange logic ($O(n^2)$ time complexity).
* **`insertionsort.c`:** Insertion Sort implementing adaptive in-place array shifting ($O(n^2)$ worst-case, $O(n)$ best-case).
* **`selectionsorting.c`:** In-place Selection Sort finding minimum elements iteratively ($O(n^2)$ complexity).
* **`.vscode/binarysearch.c`:** Divide-and-conquer logarithmic search on sorted sequences ($O(\log n)$ complexity).

### 2. Linear Data Structures
* **`stack&queue.c`:** Array-based implementation of Stack (LIFO) and Queue (FIFO) abstract data structures with boundary overflow detection.

### 3. Numerical Algorithms & Mathematical Series
* **`gcd_1.c`:** Euclidean algorithm for computing the Greatest Common Divisor (GCD/HCF).
* **`febonacii_series.c`:** Generates Fibonacci numbers with iterative state accumulation.
* **`factorial.c`:** Computes large factorial sequences.
* **`prime_no.c`:** Primality testing using trial division.
* **`palindrome.c`:** Verification of symmetric numeric and alphanumeric sequences.
* **`C/sine.c` & `C/sin1.c`:** Taylor series approximation of trigonometric sine functions compared against standard IEEE 754 math libraries.

### 4. Real-World Business Logic & Simulation Utilities
* **`cafe.c`:** Interactive POS ordering system calculating inventory totals and customer bills.
* **`railwayclass.c`:** Passenger ticket pricing engine calculating tiered fare structures based on accommodation class.
* **`electricity_bill.c`:** Slab-based residential and commercial electrical consumption tariff calculator.
* **`cabtype.c`:** Vehicle category fare calculation based on travel distance and ride classification.
* **`html/structure_book.c`:** Relational record management using C `struct` representations for library cataloging.

---

## Complete Repository Catalog

| File / Path | Language | Category | Detailed Description |
| :--- | :--- | :--- | :--- |
| `area_circle.c` | C | Geometry | Calculates circle area given radius inputs using standard $\pi$ precision. |
| `area_rectangle.c` | C | Geometry | Calculates perimeter and area for arbitrary rectangular dimensions. |
| `arraymarks.c` | C | Array Processing | Calculates aggregates, averages, and pass/fail distributions of student grades. |
| `bubblesort.c` | C | Sorting Algorithms | Implements standard iterative bubble sort over integer arrays. |
| `cabtype.c` | C | System Logic | Calculates cab booking fares according to vehicle category and route length. |
| `cafe.c` | C | Console Application | Interactive point-of-sale restaurant billing utility with itemized receipts. |
| `compound_intrest.c` | C | Finance Math | Computes compound interest yields over principal, rate, and period terms. |
| `electricity_bill.c` | C | Commercial Logic | Computes electricity billing totals based on progressive kilowatt-hour slabs. |
| `factorial.c` | C | Mathematics | Iterative computation of factorial permutations ($n!$). |
| `febonacii_series.c` | C | Number Theory | Generates Fibonacci series sequences up to user-specified limits. |
| `gcd_1.c` | C | Number Theory | Euclidean algorithm for Greatest Common Divisor calculation. |
| `insertionsort.c` | C | Sorting Algorithms | Insertion sort algorithm maintaining sorted sub-arrays. |
| `num_comparison.c` | C | Logic | Evaluates conditional inequalities across multiple numeric inputs. |
| `num_oddeven.c` | C | Arithmetic | Determines integer parity via modulus arithmetic. |
| `odd_even.c` | C | Arithmetic | Alternative parity checker testing bitwise/arithmetic evaluation. |
| `palindrome.c` | C | String / Number | Determines whether numerical values are identical when reversed. |
| `pointers1.c` | C | Memory Management | Demonstrates pointer referencing, dereferencing, and pointer arithmetic. |
| `prime_no.c` | C | Number Theory | Primality detection algorithm. |
| `railwayclass.c` | C | Console Utility | Simulates railway reservation systems with ticket fare class matrices. |
| `selectionsorting.c` | C | Sorting Algorithms | Implements selection sort by tracking minimum element indices. |
| `stack&queue.c` | C | Data Structures | Array-backed implementations of Stack (LIFO) and Queue (FIFO). |
| `variousoperations.c` | C | Arithmetic | Demonstrates foundational C math and logical operators. |
| `C/ab.c` | C | Foundations | Fundamental conditional structures and variable assignment. |
| `C/abcd.c` | C | Foundations | Nested loop structures and iterative control flow. |
| `C/area.c` | C | Geometry | Mathematical area formulas for polygon shapes. |
| `C/basic.c` | C | Foundations | Standard I/O operations and format specifiers. |
| `C/elephant.c` | C | Data Analysis | Dataset averaging computation for biological sample weights. |
| `C/elephant1.c` | C | Data Analysis | Extended sample aggregation and statistical calculation. |
| `C/oop.cpp` | C++ | OOP Intro | Initial class declarations, access specifiers, and method bindings. |
| `C/poem.c` | C | String I/O | Console output and escape sequence demonstrations. |
| `C/PY.HTML` | HTML | Documentation | Reference notes and syntax outlines for Python programming. |
| `C/sin1.c` | C | Numerical Math | Taylor series polynomial approximation for $\sin(x)$. |
| `C/sine.c` | C | Trigonometry | Trigonometric sine calculation utilizing `<math.h>`. |
| `C/x.c` | C | Logic | Algorithmic logic exploration and conditional checks. |
| `cpp/ass0.cpp` | C++ | Coursework | Initial programming assignment covering foundational C++ semantics. |
| `cpp/ass1.cpp` | C++ | Coursework | Advanced OOP assignment covering class hierarchies and encapsulation. |
| `cpp/macro_program.cpp`| C++ | Preprocessor | Macro functions, token concatenation, and conditional compiler macros. |
| `cpp/Makefile` | Make | Build Engineering | Automated compilation rules for modular C++ translation units. |
| `cpp/output.txt` | Text | Build Logs | Historical program execution and verification logs. |
| `cpp/stack.h` | C++ | Modular Header | Specification and class declaration for Stack Abstract Data Type. |
| `cpp/stack.cpp` | C++ | Implementation | Method implementations for the Stack ADT class. |
| `cpp/stack_main.cpp` | C++ | Client Driver | Test harness and execution client for the Stack ADT. |
| `cpp/wp.h` | C++ | Modular Header | Specification and class definition for the Word Processor system. |
| `cpp/wp.cpp` | C++ | Implementation | Logic and text processing methods for the Word Processor system. |
| `cpp/wp_main.cpp` | C++ | Client Driver | Driver harness executing word processor operations. |
| `crop_prediction/index.html` | HTML/JS | Web Application | Farmer Market Crop Price Prediction platform with Chart.js. |
| `errorfunction/index.html` | HTML | Web Tool | UI structure for the Gaussian Error Function (ErfSolve) calculator. |
| `errorfunction/script.js` | JS | Numerical Math | Numerical integration and dynamic Canvas plotting engine for erf(x). |
| `errorfunction/style.css` | CSS | Styling | Responsive styling rules for the ErfSolve engineering interface. |
| `partialderivative/partial.html` | HTML/JS | Web Application | Interactive multivariable partial derivative calculator powered by Math.js. |
| `website/app.py` | Python | Web Backend | Flask web server with cryptographic generation and SQLite auditing. |
| `website/passwords.db` | SQLite | Persistence | SQLite database storing credential records and audit metadata. |
| `website/static/style.css` | CSS | Styling | Custom styles for the Password Generator application interface. |
| `website/templates/index.html`| Jinja2/HTML | Web Frontend | User interface template with client-side clipboard copy routines. |
| `html/cppsdeco.html` | HTML | Documentation | Web-based CS documentation and C++ lecture study guides. |
| `html/flip-flop code.zip` | Archive | Digital Logic | Source code and logic circuit files for digital flip-flop circuits. |
| `html/index.html` | HTML | Web Document | Introductory landing page document. |
| `html/structure_book.c` | C | Data Management | Relational inventory management using C structures. |
| `.vscode/binarysearch.c`| C | Search Algorithms | Binary search implementation on ordered integer arrays. |
| `.vscode/prndecresing.c`| C | Recursion | Recursive function execution demonstrating call-stack reduction. |
| `.vscode/tasks.json` | JSON | IDE Config | Automated VS Code build tasks for GCC/G++ compilation. |

---

## Compilation, Build & Execution Manual

### 1. Python Flask Web Application (`website/`)

#### Prerequisites
* Python 3.8+
* Flask (`pip install flask`)

#### Launch Server
```bash
cd website
python app.py
```
* **Default Host:** `127.0.0.1` (localhost)
* **Default Port:** `5000`
* **Access URL:** `http://127.0.0.1:5000/`

---

### 2. Client-Side Web Applications
These applications run entirely client-side without external server runtimes. Launch them directly in any modern Chromium, Firefox, or Safari browser:

```powershell
# Farmer Market Crop Price Prediction
Start-Process chrome.exe "crop_prediction\index.html"

# ErfSolve Engineering Calculator
Start-Process chrome.exe "errorfunction\index.html"

# Multivariable Partial Derivative Solver
Start-Process chrome.exe "partialderivative\partial.html"
```

---

### 3. C Programs (GCC Compiler)

Compile using the GNU Compiler Collection (GCC):

```bash
# Standard compilation
gcc bubblesort.c -o bubblesort
./bubblesort

# Programs requiring mathematical linkages (e.g., sine calculations)
gcc C/sine.c -lm -o sine
./sine

# Structure book management system
gcc html/structure_book.c -o structure_book
./structure_book
```

---

### 4. Modular C++ Programs (G++ Compiler & Make)

#### Using Make
```bash
cd cpp
make
```

#### Manual Modular Compilation
```bash
cd cpp

# Compile translation units into object files
g++ -c stack.cpp -o stack.o
g++ -c stack_main.cpp -o stack_main.o

# Link object binaries
g++ stack.o stack_main.o -o stack_app

# Execute binary
./stack_app
```

#### Single-File C++ Compilation
```bash
cd cpp
g++ ass1.cpp -o ass1
./ass1
```

---

## Version Control Configuration (.gitignore)

To maintain an unpolluted repository free of ephemeral build artifacts and binary executables, the following `.gitignore` specification is enforced:

```gitignore
# Compiled binary executables and translation units
*.exe
*.o
*.obj
*.out
*.dll

# IDE runner artifacts and build directories
tempCodeRunnerFile.*
build/
.vscode/

# Python interpreter bytecode and SQLite databases
__pycache__/
*.pyc
*.pyo
website/passwords.db
```

---

## Author & Maintenance
* **Maintainer:** Tanish
* **Primary Languages:** C, C++, Python, JavaScript, HTML5, CSS3
* **Repository Architecture:** Clean Architecture &bull; Modular ADTs &bull; Full-Stack Web Development

