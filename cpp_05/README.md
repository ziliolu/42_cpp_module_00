# CPP_05 - Exception Handling in C++

In C++, exception handling provides a mechanism to deal with runtime errors and abnormal program conditions. The key components of exception handling in C++ are `try`, `catch`, and `throw`. Here's an overview of each:

### `try`, `catch`, and `throw`

### `try` block

- The `try` block contains the code that might throw an exception. It is followed by one or more `catch` blocks.

- **Example**:

    ```cpp
    try {
        // Code that might throw an exception
    } catch (ExceptionType1& e1) {
        // Handle ExceptionType1
    } catch (ExceptionType2& e2) {
        // Handle ExceptionType2
    } catch (...) {
        // Handle any other exceptions
    }
    ```

### `catch` blocks

- `catch` blocks handle exceptions thrown in the corresponding `try` block. Each `catch` block specifies the type of exception it can handle.

- **Example**:

    ```cpp
    try {
        // Code that might throw an exception
    } catch (const std::exception& e) {
        // Handle standard C++ exceptions
    } catch (const MyCustomException& myException) {
        // Handle a custom exception
    } catch (...) {
        // Handle any other exceptions
    }
    ```

### `throw` statement

- The `throw` statement is used to throw an exception. It can throw various types, including built-in types, objects, or pointers.

- **Example**:

    ```cpp
    if (someCondition) {
        throw MyCustomException("Something went wrong!");
    }
    ```

## Exception Best Practices

- **Use Specific Exceptions**: Catch specific exceptions rather than catching all exceptions using `catch (...)`. This allows for more precise error handling.

- **Resource Management**: Use exception handling for proper resource cleanup. RAII (Resource Acquisition Is Initialization) can be particularly helpful.

- **Avoid Memory Leaks**: Ensure proper memory cleanup in case of exceptions to avoid memory leaks.

- **Don't Overuse Exceptions**: Exceptions are for exceptional conditions. Don't use them for normal control flow.

- **Handle Exceptions at the Right Level**: Handle exceptions at the appropriate level of your program, ensuring that each component is responsible for handling its own exceptions.

- **Standard Library Exceptions**: Familiarize yourself with the standard C++ exceptions provided by the `<stdexcept>` header, such as `std::runtime_error`, `std::logic_error`, etc.

## Example Code

```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        // Code that might throw an exception
        throw std::runtime_error("An error occurred!");
    } catch (const std::exception& e) {
        // Handle standard C++ exceptions
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (...) {
        // Handle any other exceptions
        std::cerr << "Unknown exception caught!" << std::endl;
    }

    return 0;
}
