# CPP_06 - Type Casting in C++

In C++ programming, there are three primary casting operators for type conversion: `static_cast`, `dynamic_cast`, and `reinterpret_cast`. Here's a brief overview of each:

### ex_00 `static_cast`

- **Compile-Time Casting**: `static_cast` is a compile-time casting operator. It performs type conversions that are known at compile time and are considered safe by the compiler.

- **Used for Safe Conversions**: Typically used for conversions that don't involve polymorphism, such as converting between related types or numeric conversions.

- **Example**:

    ```cpp
    double d = 3.14;
    int i = static_cast<int>(d);
    ```

### `EX_01` `dynamic_cast`

- **Run-Time Casting (for Polymorphic Types)**: `dynamic_cast` is a run-time casting operator. It is primarily used with polymorphic types (types having at least one virtual function).

- **Used for Safe Downcasting**: Used for downcasting (casting from a base class pointer/reference to a derived class pointer/reference) when the object's type is not known until runtime. Checks the validity of the conversion at runtime.

- **Returns Nullptr for Invalid Conversions**: If the conversion is not valid, `dynamic_cast` returns `nullptr` for pointer types or throws an exception (`std::bad_cast`) for reference types.

- **Example**:

    ```cpp
    class Base {
        virtual void foo() {}
    };

    class Derived : public Base {};

    Base* basePtr = new Derived;
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        // Valid downcast
    } else {
        // Invalid downcast
    }
    ```

### ex_02 `reinterpret_cast`

- **Low-Level Bitwise Conversion**: `reinterpret_cast` is a low-level casting operator that performs a bitwise conversion between pointer types. It is not type-safe and should be used with caution.

- **Unrelated Types**: Typically used for converting between unrelated pointer types or between pointer and integer types.

- **No Checks for Validity**: `reinterpret_cast` does not perform any checks for validity. It's the programmer's responsibility to ensure that the conversion makes sense.

- **Example**:

    ```cpp
    int* intPtr = new int(42);
    double* doublePtr = reinterpret_cast<double*>(intPtr);
    ```

### General Advice

- Use `static_cast` when you have a well-defined and safe conversion.
- Use `dynamic_cast` when dealing with polymorphic types and you need runtime type information.
- Use `reinterpret_cast` with extreme caution and only when absolutely necessary, as it can lead to undefined behavior if misused.
