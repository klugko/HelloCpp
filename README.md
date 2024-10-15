# HelloCpp

# Polynomial Operations in C++

This project implements two classes, `Monome` and `Polynome`, to handle basic polynomial operations such as derivation, addition, and subtraction using object-oriented programming (OOP) principles in C++.

## Classes

### 1. **Monome**

The `Monome` class represents a single term (monomial) in a polynomial, characterized by a coefficient and a degree (exponent). 

#### Methods:
- **Constructor**: 
  - `Monome(double coef = 0, int deg = 0)`
  - Creates a monomial with a given coefficient and degree.
  
- **getCoefficient()**:
  - Returns the coefficient of the monomial.
  
- **getDegre()**:
  - Returns the degree of the monomial.

- **derive()**:
  - Derives the monomial and returns a new `Monome`. If the degree is 0, the result will be a monomial with a coefficient of 0.

- **operator+**:
  - Adds two monomials of the same degree. If the degrees are different, it outputs an error message.
  
- **operator-**:
  - Subtracts two monomials of the same degree. If the degrees are different, it outputs an error message.

#### Example:
```cpp
Monome m1(3, 2);  // Represents 3X^2
Monome m2(5, 2);  // Represents 5X^2

Monome sum = m1 + m2;  // Result: 8X^2
```

### 2. **Polynome**

The `Polynome` class represents a polynomial, which is essentially a collection of `Monome` objects.

#### Methods:
- **addMonome(const Monome& m)**:
  - Adds a monomial to the polynomial. If a monomial with the same degree already exists, their coefficients are combined.

- **derive()**:
  - Derives the entire polynomial by applying the derivative to each monomial and returns a new `Polynome`.

- **operator+**:
  - Adds two polynomials by adding corresponding monomials.

- **operator-**:
  - Subtracts two polynomials by subtracting corresponding monomials.

- **printPolynome()**:
  - Prints the polynomial in standard mathematical form.

#### Example:
```cpp
Monome m1(3, 2);  // 3X^2
Monome m2(5, 1);  // 5X^1
Monome m3(2, 0);  // 2

Polynome p;
p.addMonome(m1);
p.addMonome(m2);
p.addMonome(m3);

p.printPolynome();  // Outputs: 3X^2 + 5X^1 + 2X^0

Polynome derived = p.derive();
derived.printPolynome();  // Outputs: 6X^1 + 5X^0
```

### 3. **DateHeure**
- to manipulate Date 
