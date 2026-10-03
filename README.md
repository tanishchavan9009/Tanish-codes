# Tanish Codes

<p align="center">
  <img src="assets/images/repo_banner.jpg" alt="Tanish Codes Hero Banner" width="100%" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black" alt="C" />
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" alt="Python" />
  <img src="https://img.shields.io/badge/Flask-000000?style=for-the-badge&logo=flask&logoColor=white" alt="Flask" />
  <img src="https://img.shields.io/badge/SQLite-07405E?style=for-the-badge&logo=sqlite&logoColor=white" alt="SQLite" />
  <img src="https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black" alt="JavaScript" />
  <img src="https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white" alt="HTML5" />
  <img src="https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white" alt="CSS3" />
</p>

---

A structured portfolio repository encompassing **Data Structures & Algorithms (DSA)** in C/C++, **Object-Oriented Programming (OOP)**, **Python/Flask Web Applications**, and **Interactive Mathematical & Agricultural Web Tools**.

---

## 🚀 Featured Web Applications & Projects

### 🌾 1. Farmer Market Crop Price Prediction
> **Location:** [`crop_prediction/`](crop_prediction/)

<p align="center">
  <img src="assets/images/crop_prediction_preview.jpg" alt="Farmer Market Crop Price Prediction Preview" width="95%" />
</p>

An intelligent agricultural decision-support web application tailored for farmers and agricultural traders to forecast market valuations and optimize selling strategies.

- **📈 Trend Forecasting:** Visualizes price patterns and 30-day forecast curves powered by `Chart.js`.
- **🌦 Weather & Soil Support:** Integrates temperature, humidity, and moisture metrics for harvest decisions.
- **💡 Smart Profit Advice:** Suggests optimal holding/selling windows to maximize revenue.
- **📱 Responsive Glassmorphic UI:** Clean, responsive interface optimized for desktop and mobile displays.

---

### 🔐 2. Smart Password Generator & Vault
> **Location:** [`website/`](website/)

<p align="center">
  <img src="assets/images/password_generator_preview.jpg" alt="Smart Password Generator Preview" width="95%" />
</p>

A secure Python Flask web application designed to generate high-entropy, customizable passwords and maintain an encrypted generation history.

- **🎛️ Custom Parameters:** Fine-grained control over length (4–30 chars), uppercase/lowercase letters, digits, and special characters.
- **🛡️ Multi-Level Complexity:** Selectable presets ranging from *Simple* to *Very Difficult*.
- **📋 One-Click Copy:** Integrated JavaScript clipboard API with instant confirmation feedback.
- **🗄️ SQLite Database:** Automatically logs generated credentials with difficulty rating, length, and timestamp into `passwords.db`.

---

### 📐 3. Engineering Mathematics & Interactive Solvers
> **Locations:** [`errorfunction/`](errorfunction/) & [`partialderivative/`](partialderivative/)

<p align="center">
  <img src="assets/images/math_calculators_preview.jpg" alt="Engineering Math Calculators Preview" width="95%" />
</p>

Interactive computing environments for engineering mathematics, calculus, and numerical computation:

- **ErfSolve (`errorfunction/`)**:
  - Computes the Gaussian Error Function $\text{erf}(x) = \frac{2}{\sqrt{\pi}} \int_0^x e^{-t^2} dt$.
  - Features real-time Canvas plotting, Taylor series expansions, and numerical quadrature algorithms.
  - Formatted mathematical rendering using **MathJax 3**.
- **Partial Derivative Solver (`partialderivative/`)**:
  - Multivariable differential calculus engine powered by `Math.js`.
  - Calculates first-order and second-order partial derivatives ($\frac{\partial z}{\partial x}$, $\frac{\partial z}{\partial y}$, $\nabla f$) with detailed step-by-step breakdown.
  - Cyberpunk dark-mode design with glowing gradient aesthetics and Space Mono typography.

---

## 📁 Complete Repository Directory Index

```text
Tanish codes/
├── 🖼️ assets/
│   └── images/
│       ├── repo_banner.jpg               # Developer portfolio hero banner
│       ├── crop_prediction_preview.jpg   # Smart agriculture analytics preview
│       ├── password_generator_preview.jpg# Cyber-security vault preview
│       └── math_calculators_preview.jpg  # Multivariable calculus & erf solver preview
│
├── 🌾 crop_prediction/
│   └── index.html                        # Farmer Market Crop Price Prediction portal
│
├── 🔐 website/ (Flask Password Manager Web App)
│   ├── app.py                            # Flask server with SQLite persistence
│   ├── passwords.db                      # Local SQLite credentials store
│   ├── static/
│   │   └── style.css                     # Modern UI styling
│   └── templates/
│       └── index.html                    # Jinja2 frontend template with clipboard copy
│
├── 📐 errorfunction/ (ErfSolve Engineering Math Tool)
│   ├── index.html                        # UI layout with MathJax integration
│   ├── script.js                         # Numerical integration & canvas curve renderer
│   └── style.css                         # Clean mathematical dashboard styles
│
├── ⚡ partialderivative/
│   └── partial.html                      # Interactive multivariable calculus solver (Math.js)
│
├── 🌐 html/
│   ├── cppsdeco.html                     # Web-based study material on C++
│   ├── flip-flop code.zip                # Digital electronics flip-flop circuits archive
│   ├── index.html                        # General landing page
│   └── structure_book.c                  # Library book inventory using C structures
│
├── ⚙️ C Programming & DSA (Root)
│   ├── area_circle.c                     # Calculates area of a circle
│   ├── area_rectangle.c                  # Calculates area of a rectangle
│   ├── arraymarks.c                      # Student marks array manipulation
│   ├── bubblesort.c                      # Bubble Sort algorithm
│   ├── cabtype.c                         # Cab reservation & fare calculation
│   ├── cafe.c                            # Cafe ordering and billing management
│   ├── compound_intrest.c                # Compound interest calculator
│   ├── electricity_bill.c                # Tiered electricity billing logic
│   ├── factorial.c                       # Factorial calculation
│   ├── febonacii_series.c                # Fibonacci sequence generator
│   ├── gcd_1.c                           # Greatest Common Divisor (GCD)
│   ├── insertionsort.c                   # Insertion Sort algorithm
│   ├── num_comparison.c                  # Numeric comparison (max/min)
│   ├── num_oddeven.c                     # Odd or even number determination
│   ├── odd_even.c                        # Parity check utility
│   ├── palindrome.c                      # Palindrome checker
│   ├── pointers1.c                       # Pointer manipulation and memory basics
│   ├── prime_no.c                        # Prime number detection algorithm
│   ├── railwayclass.c                    # Railway passenger ticket reservation
│   ├── selectionsorting.c                # Selection Sort algorithm
│   ├── stack&queue.c                     # Array-based Stack and Queue implementation
│   └── variousoperations.c               # Arithmetic operations demo
│
├── 📘 C/ (Core C & Mathematical Practice)
│   ├── ab.c                              # Basic C syntax practice
│   ├── abcd.c                            # Conditional logic & loops
│   ├── area.c                            # Geometric area calculations
│   ├── basic.c                           # Introductory concepts & I/O
│   ├── elephant.c                        # Average weight calculation program
│   ├── elephant1.c                       # Extended dataset computation
│   ├── oop.cpp                           # Intro to OOP concepts in C++
│   ├── poem.c                            # Formatted string output
│   ├── PY.HTML                           # Python reference notes
│   ├── sin1.c                            # Taylor series approximation of sine
│   ├── sine.c                            # Trigonometric sine calculation
│   └── x.c                               # Algorithmic logic exploration
│
├── 💻 cpp/ (Object-Oriented Programming & DSA in C++)
│   ├── ass0.cpp                          # Assignment 0: Core C++ practice
│   ├── ass1.cpp                          # Assignment 1: OOP classes and objects
│   ├── macro_program.cpp                 # C++ preprocessor macros & inline logic
│   ├── Makefile                          # Build automation for modular C++
│   ├── output.txt                        # Program output log
│   ├── stack.h                           # Stack abstract data type header
│   ├── stack.cpp                         # Stack class implementation
│   ├── stack_main.cpp                    # Driver program for Stack ADT
│   ├── wp.h                              # Word processor / text formatter header
│   ├── wp.cpp                            # Word processor class implementation
│   └── wp_main.cpp                       # Driver program for Word Processor
│
└── 🛠️ .vscode/
    ├── binarysearch.c                    # Binary Search implementation
    ├── prndecresing.c                   # Recursive sequence print
    └── tasks.json                        # VS Code build automation tasks
```

---

## 🛠️ How to Compile & Run

### 1. Python Flask Web App (`website/`)
```bash
cd website
pip install flask
python app.py
```
Visit `http://127.0.0.1:5000/` in your browser.

### 2. Interactive Web Applications
Directly open the HTML files in your browser:
```bash
# Crop Price Prediction
Start-Process chrome.exe crop_prediction/index.html

# ErfSolve Calculator
Start-Process chrome.exe errorfunction/index.html

# Partial Derivative Solver
Start-Process chrome.exe partialderivative/partial.html
```

### 3. C & C++ Programs
```bash
# Compile and run C programs
gcc bubblesort.c -o bubblesort
./bubblesort

# Compile and run modular C++ Stack project
cd cpp
g++ -c stack.cpp stack_main.cpp
g++ stack.o stack_main.o -o stack_app
./stack_app
```

---

## 📌 Git Configuration (`.gitignore`)

To ensure clean commits, binary build artifacts and local cache files are omitted:

```gitignore
*.exe
*.o
*.obj
*.out
tempCodeRunnerFile.*
build/
__pycache__/
website/passwords.db
```

---

## 👤 Author
- **Tanish**

