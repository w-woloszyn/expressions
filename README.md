# Expression evaluator written in C++17 using std::visitor function in the interface std::variant

The project demonstrates the use of C++17's std::visitor function in the interface std::variant to implement the visitor pattern in the field of classical design patterns, by the example of an expression evaluator.

## Description

* An Expression, here, is an inductively defined object using the atomic Expressions of type int, bool, or std::monostate, together with operators inherited from these types. More technically, an Expression is a self-recursive variant with 1-ary and 2-ary operators defined on it.
* Each Expression is either valid or invalid. An Expression is valid just in case it represents a well-formed formula or mathematical expression (no atomic subExpression is of type std::monostate).
* Visitor method typeCheck() checks whether an Expression is well-formed.
* Visitor method evaluate() evaluates the expression or formula.
* Each method defined on the Expression follows the visitor pattern, including the operators +,-, and so on.

## Prerequisites

You will need CMake and a compiler that can handle C++17. The very least I recommend is gcc 7.4.0 and CMake 3.2; tested on gcc 7.4.0 and CMake 3.10.2


## Building the project

Clone the repository.

```
git clone https://github.com/wwoloszyn/expressions.git
```

Enter the cloned project.

```
cd expressions
```

Create a build folder and enter this folder.

```
mkdir build && cd build
```

Call cmake.

```
cmake ..
```

Run make.

```
make
```

## Running the tests

Run the unit tests by executing the binary file.

```
./expressions
```
