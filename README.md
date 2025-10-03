# 🔢 Big Numbers (Numere Mari)

## 📖 Description
This project implements **classes for handling very large numbers** (up to 10,000 digits) in C++.
It supports different categories of numbers:
- Natural numbers
- Integers
- Real numbers
- Complex numbers

Each class allows operations such as:
- `+=` (AddToMe)
- `-=` (SubtractFromMe)
- `*=` (MultiplyMeWith)
- `Modulus` (absolute value of the number)

Numbers can be created either from small values or from strings that represent large numbers.

## 🗂️ Project Structure
- `main.cpp` – entry point for testing.
- `numeremari.cpp` – implementation of big number classes.
- `numeremari.h` – header file with class declarations.
- `date4.in` – example input file.

## ⚙️ Features
- Read integers as `"-342342"`.
- Read reals as `"-123.4891"`.
- Read complex numbers as `"-233.23 - 12.5i"`.
- Reuse of code between classes for efficiency.
- Display functionality for all big numbers.

## 🛠️ Technologies Used
- **C++** (OOP concepts, operator overloading, file input).

## 🚀 How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Axinte8543/NumereMari.git
   ```
2. Compile the project (for example, with g++):
   ```bash
   g++ main.cpp numeremari.cpp -o BigNumbers
   ```
3. Run the program:
   ```bash
   ./BigNumbers
   ```

## 🔮 Future Improvements
- Implement additional operations (division, power, comparison).
- Optimize performance for extremely large inputs.
- Extend input/output support (e.g., JSON or file-based configs).

## 👤 Author
Project created by **Axinte**.
