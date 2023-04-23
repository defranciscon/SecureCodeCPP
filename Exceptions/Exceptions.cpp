// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

// Create a custom exception class
// Derived from https://cplusplus.com/doc/tutorial/exceptions/
class MyException: public std::exception
{
public:
    // what() function specified as public for accessibility purposes
    virtual const char* what() const throw() {
        return "My custom exception.";
    }
};

bool do_even_more_custom_application_logic()
{
    // Throws standard exception
    throw std::bad_exception();

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    // Exception handler wrapper
    try {
        if (do_even_more_custom_application_logic()) {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // Exception handler catches std::exception, displays message and exception.what()
    catch (const std::exception& e) {
        std::cerr << "Exception Occurred: " << e.what() << std::endl;
    }

    // Throws custom exception
    throw MyException();

    std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
    // Throws exception to deal with divide by zero errors
    if (den == 0) {
        throw std::runtime_error("Exception Occurred: Division by Zero");
    }
    return (num / den);
}

// Implements exception specifier noexcept: function does not throw exception
void do_division() noexcept
{
    // Exception handler catches ONLY the exception thrown by divide function.
    float numerator = 10.0f;
    float denominator = 0;

    try 
    {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    // Handles exception from divide() function
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    // Exception handler wrapper
    try {
        std::cout << "Exceptions Tests!" << std::endl;
        do_division();
        do_custom_application_logic();
    }
    // Handler catches custom exception
    catch (const MyException& e) {
        std::cerr << "Exception Occurred: " << e.what() << std::endl;
    }
    // Handler catches std::exception
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // Catch-all handler catches all unhandled exceptions
    catch (...) {
        std::cout << "Uncaught Exception." << std::endl;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
