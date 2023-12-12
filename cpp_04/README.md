# CPP_04 - Subtype Polymorphism, Abstract Classes, and Interfaces in C++

In C++, subtype polymorphism is achieved through the use of abstract classes and interfaces. These concepts are essential for building flexible and extensible software with polymorphic behavior. Here's an overview:

## Abstract Classes

### Definition

- An abstract class is a class that cannot be instantiated on its own. It serves as a blueprint for other classes, often containing one or more pure virtual functions.

- **Example**:

    ```cpp
    class AbstractClass {
    public:
        virtual void pureVirtualFunction() const = 0; // Pure virtual function
        virtual void commonFunction() const {
            // Implementation shared by subclasses
        }

        virtual ~AbstractClass() = default;
    };
    ```

### Key Points

- Abstract classes can have both pure virtual functions (forcing subclasses to provide an implementation) and regular virtual functions.

- Objects of abstract classes cannot be created. They are meant to be used as base classes for other classes.

## Interfaces

### Definition

- An interface is a collection of pure virtual functions. It defines a contract that concrete classes must adhere to by providing implementations for all the functions in the interface.

- **Example**:

    ```cpp
    class Interface {
    public:
        virtual void method1() const = 0;
        virtual void method2() const = 0;

        virtual ~Interface() = default;
    };
    ```

### Key Points

- Interfaces are used to define a set of functions that must be implemented by any class that claims to implement the interface.

- C++ doesn't have a dedicated `interface` keyword like some other languages. Instead, an interface is created using a class with pure virtual functions.

## Subtype Polymorphism

- Subtype polymorphism allows objects of different derived classes to be treated as objects of the base class.

- It is achieved through virtual functions and dynamic dispatch, allowing the correct function implementation to be called at runtime based on the actual type of the object.

- **Example**:

    ```cpp
    void performOperations(const AbstractClass& obj) {
        obj.pureVirtualFunction(); // Dynamic dispatch based on the actual type
        obj.commonFunction();
    }
    ```

## Example Code

```cpp
#include <iostream>

class AbstractClass {
public:
    virtual void pureVirtualFunction() const = 0;
    virtual void commonFunction() const {
        std::cout << "Common function in AbstractClass" << std::endl;
    }

    virtual ~AbstractClass() = default;
};

class ConcreteClass : public AbstractClass {
public:
    void pureVirtualFunction() const override {
        std::cout << "Implementation in ConcreteClass" << std::endl;
    }
};

int main() {
    ConcreteClass concreteObj;
    performOperations(concreteObj);

    return 0;
}
