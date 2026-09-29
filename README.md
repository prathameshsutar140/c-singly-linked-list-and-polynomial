# Singly Linked List & Polynomial Addition in C/C++

A collection of basic C/C++ programs demonstrating the dynamic creation, traversal, and application of **singly linked lists**.

## Programs Included

### 1. Singly Linked List Creation & Traversal (`LINKED_L.CPP`)
* Creates a basic singly linked list by taking integer inputs dynamically from the user[cite: 16].
* Traverses and displays all elements in sequential order[cite: 16].

### 2. Polynomial Addition using Linked List (`poly.c`)
* Represents polynomial expressions as linked lists where each node stores a coefficient (`coeff`) and an exponent power (`pow`)[cite: 17].
* Implements functions to dynamically insert polynomial terms (`insertTerm()`)[cite: 17], add two polynomials by combining like terms (`addPolynomials()`)[cite: 17], and display the resulting algebraic polynomial (`displayPolynomial()`)[cite: 17].

---

## Technical Note
These programs use legacy Turbo C / MS-DOS headers (`<conio.h>`, `clrscr()`, `getch()`)[cite: 16, 17]. If compiling with modern compilers like **GCC / Clang**:
* Replace `void main()` with `int main()`[cite: 16, 17]
* Remove `clrscr()` and `getch()`[cite: 16, 17]
