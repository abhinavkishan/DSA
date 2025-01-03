# C++ Features
- Portable
- Mid-level

> compiler -> assembler -> linker -> executable
> compiler creates object files

> integer is platform dependent (size of integer is variable)

## goto:

- goto label;
- used to come out of loops
- example: timeout

# Malloc:
- malloc returns void * as we dont need type cast 

# auto:
this is default storage class for all the variables declared inside a function or a block.

# extern:
Extern storage class simply tells us that variable is defined elsewhere

# static:
their scope is local to function to which they were defined.

# register:
storage class declares register variable that the compiler tries to store in register of microprocessor

# volatile:
it tells compiler that the value variable may change at any time
```c
int i, *ptr;
ptr = &i;
volatile int iv;
iv = *ptr;
iv = *ptr; // volatile tells compiler not to remove this
```

# Pointers to Function:
```c
function_return_type(*Pointer_name)(list of arguments)
```

# Command line arguments
```c
int main(int argc, char **argv) {
    // argv[0] -> name of the file
}
```

# Environment Variables
```c
int main(int argc, char **argv, char**envp)
extern char **environ;
```

# Variable number of arguments:
int func(int, ...) {
    <!--  -->
}

# CPP Features:
- Multithreading
    - C++11 has std::thread

- Smart Pointers
smart pointer is a wrapper class over a pointer with an operator *, ->

- array container
    - has begin and end

- Move Semantics
- Lambda Functions
- Auto

# Startup Code:
- flag to see assembly code: -S
- startup code is written in assembly

# Standard I/O Library:
- cout and cin are objects of ostream and istream classes
```c++
cout << "My name" << " Ankush " ; 
```
- cascading, output of each operation is cout
- result of  << is left hand operand

## Endl:
- manipulator
- flushes buffer
- flushing the buffer ensures that all the output the program has generated so far is actually written to output stream.

## Namespace
- in c we can use static to localise the scope

# Object Oriented Concepts
## Class
- template / blueprint for entities called objects
- Dont occupy space
## Object
- instance of a class
- occupy space
## Encapsulation
## Polymorphism
## Inheritance
## Abstraction
## Composition
- individual entities do not make sense

## Ignore:
```c++
cin.ignore(1000, '\n')
```

# Defining Class
- by default private
```c++
class ClassName 
{
    Access Specifier; // private, public or protected
    Data members;
    Memmder functions;
}
```

> Headers should not include using declaration

# Namespace:
- to access global variables within namespaces use ```::variable``` -> global namespace

# Literals:
- values stored in constant variables
```c++
cout << hex << number;
cout << oct << number;
```

> wchar_t -> 2 bytes

# Lvalue and Rvalues
# Static values
- static variables are initialized only once
- static variables are initialized before any other variable
- static variables are initialized to 0 if not initialized explicitly
- static variables are stored in data segment
- static variables are destroyed when program terminates

# Function Overloading
- functions with same name but different parameters
    - Different number of arguments
    - Different type of arguments
    - Different sequence of arguments

- this is called static polymorphism (compile time polymorphism)
> functions with different return types are not overloaded

# Inline Functions:
- macros are expanded by preprocessor
- inline functions are expanded by compiler
- to avoid function call overhead

# new vs malloc
- new calls constructor
- malloc does not call constructor
- new returns exact data type
- malloc returns void pointer
- new does not require size
> new (nothrow) int[5] -> returns null if memory is not available instead of throwing exception

# Dangling Pointer
- pointer pointing to a memory location that has been deleted
ways to create dangling pointer:
- freeing allocated memory
- returning pointer to local variable from a function
- returning reference to a variable outside scope of function