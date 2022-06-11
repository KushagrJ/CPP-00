// C++20 Standard
// This program doesn't include input validation.

#include <iostream>


int main()
{

    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    std::cout << "The sum of " << a << " and " << b << " is " << (a + b)
              << std::endl;

    return 0;

}





/* Output - 00.cpp

   Enter two integers: 2 5
   The sum of 2 and 5 is 7

 * End of Output */





/* Trivia - 00.cpp

 * The term 'object' has different meanings in C and C++.
   In C, an 'object' is a part of memory, whereas in C++, an 'object' is
   constructed over memory.
   In other words, in C, an object 'is' a region of storage, whereas in C++, an
   object 'occupies' a region of storage.
 * The term 'variable' (in relation with objects and identifiers) exists in C++,
   but not in C.
   C++ programmers tend to refer to variables as 'variables' or 'objects'
   interchangeably. Some programmers distinguish between named and unnamed
   objects, using the term variable to refer to named objects only.

 * C++ is nearly exactly a superset of C95.
   With very few exceptions, every valid C95 program is also a valid C++ program
   with the same meaning.
   [Annex C.5 of the C++20 Standard lists the differences between C++ and C]
 * This means that the majority of the concepts that are applicable for C are
   also applicable for C++.
 * So, many concepts which are directly applicable for C and C++ are skipped in
   these trivia/notes.
   Similarly, many terms which have the same definitions in C and C++ are not
   defined in these trivia/notes.


 * An 'algorithm' is a well-defined computational procedure that takes some
   value(s) as input and produces some value(s) as output in a finite amount of
   time.
   Alternatively, an 'algorithm' is a finite sequence of well-defined steps to
   be followed in order to accomplish a given task.
 * A 'data structure' is a way to store and organize data in order to facilitate
   access and modifications. Using the appropriate data structure(s) is an
   important part of algorithm design.


 * Every C++ program contains one or more functions, one of which must be named
   main, generally.
 * It is not possible to write a program without using the main() function,
   unless the program is being written in a freestanding environment.
 * There are two kinds of conforming implementations defined in the C++
   standard - 'hosted' and 'freestanding'.
   A freestanding implementation is one that is designed for programs that are
   executed without the benefit of an operating system. For eg., an OS kernel.
   A program using the facilities of an operating system would normally be in a
   hosted environment.
   [Also, one can make it seem like the main() function is not used in a program
    by using the #define preprocessor directive (#define kushagr main or
    #define kushagr m##a##i##n or some other trick), but after preprocessing,
    the code would still have the main() function]

 * A function definition has four elements: a return type, a function name,
   a (possibly empty) parameter list enclosed in parentheses, and a function
   body.
   In C, foo() means a function foo taking an unspecified number of arguments of
   unspecified type, whereas foo(void) means a function foo taking no arguments.
   In C++, both foo() and foo(void) mean the same thing, i.e. a function foo
   taking no arguments.

 * The main() function is required to have a return type of int.
   return is a statement that terminates a function and possibly sends a value
   back to the function's caller.
   When a return statement includes a value, the value returned must have a type
   that is compatible with the return type of the function.
   On most systems, the value returned from main() is a status indicator to the
   operating system. A return value of 0 indicates success. A nonzero return has
   a meaning that is defined by the system.
   On Unix systems, after executing a program, 'echo $?' can be used to check
   the value returned by main() to the operating system.
 * In C++, main() can only be entered and left once, whereas in C, re-entering
   main() is allowed, but should be avoided.

 * A 'type' defines both the contents of a data element and the operations that
   are possible on those data.
   When the type of a variable named 'v' is 'T', we often say that 'v' has type
   'T', or, interchangeably, that 'v' is a 'T'.


 * Just like C, the C++ language doesn't define any statements to do input or
   output (I/O).
   Instead, C and C++ include extensive standard libaries that provide I/O,
   and many other facilities.
   The C++ standard library is basically a collection of classes and functions.
   [STL (Standard Template Library) is a different term]
 * C++ includes two I/O libraries (an I/O library can be thought of as being a
   subset of the entire standard library): an object-oriented stream-based I/O
   library (called the 'iostream' library) and a C-style FILE-based I/O library
   (called the 'cstdio' library).
 * A 'stream' is a sequence of characters read from or written to an I/O device.
   The term stream is intended to suggest that the characters are generated, or
   consumed, sequentially over time.
 * Fundamental to the iostream library are two types named 'istream' and
   'ostream', which are related to the input and the output streams,
   respectively.
   The iostream library defines four I/O objects.
   To handle input, we use an object of type istream named 'cin'. This object is
   also referred to as the 'standard input'.
   To handle output, we use an object of type ostream named 'cout' This object
   is also referred to as the 'standard output'.
   For warning and error messages, we use an object of type ostream named
   'cerr'. This object is also referred to as the 'standard error'.
   For general information about the execution of the program, we use an object
   of type ostream called 'clog'.

 * The line #include <iostream> indicates that the iostream library is to be
   used in this program.
   The name inside the angle brackets, i.e. iostream in this case, is the name
   of a 'header file'.
   Header files typically contain class definitions, function prototypes,
   enumerations, etc.
   The preprocessor directive #include <iostream> makes that line get replaced
   by the contents of the header file named iostream.


 * An expression yields a result/value and is usually composed of one or more
   operands and operators.
   [For eg., x, 4, -6, 4 + 21, a * (b + c / d) / 20, q = 5 * 2, x = ++q % 3,
    q > 3, etc.]
   Here, the expression std::cout << "Enter two numbers: ", for eg., consists of
   the operands std::cout and "Enter two numbers: ", and the operator <<.
 * The left hand operand of the << operator must be an ostream object, and the
   right hand operand must be a value to write. The << operator writes the given
   value on the given ostream object. The value of this expression is the left
   hand operand.
 * The left hand operand of the >> operator must be an istream object, and the
   right hand operand must be an object in which the value read is to be stored.
   The value of this expression is again the left hand operand.
 * The associativity of the operators << and >> is left-to-right.
   Thus, for std::cout << "Hello" << "World";, the expresssion statement is
   equivalent to (std::cout << "Hello") << "World";.

 * A 'string literal' is a sequence of characters enclosed in double quotes.
   For eg., "kushagr" is a string literal consisting of the characters 'k', 'u',
   's', 'h', 'a', 'g', 'r' and '\0', and sizeof "kushagr" evaluates to 8.


 * std::endl (an example of a 'manipulator') can also be used instead of '\n' or
   "\n" to print a newline character.
   The difference between std::endl and '\n' or "\n" is that std::endl flushes
   the output buffer, whereas '\n' and "\n" don't. Thus, std::cout << std::endl;
   is equivalent to std::cout << '\n' << std::flush; or
   std::cout << "\n" << std::flush;.
   [The exact rules for automatic buffer flushing are dependent on the type of
    buffering used and are also implementation-defined.
    For eg., in most implementation of C/C++, stdout/cout is automatically
    flushed when there is impending input from stdin/cin.]
 * When debugging, programmers often add print statements. Such statements
   should always flush the output buffer. Otherwise, if the program crashes,
   output may be left in the buffer, leading to incorrect inferences about where
   the program crashed.
 * Stream buffering is done to aid performance. For eg., writing to a file, as
   opposed to writing to a screen, is a costly operation. Thus, it is often
   better to wait until the content to be written to a file reaches a particular
   size before writing to the file.
   So, using '\n' or "\n" when working with files is better than using std::endl
   frequently.
 * As another example, if a program is set to print messages after fixed
   intervals of time, it is better to flush the output buffer after every print
   operation in order to ensure that the messages appear on the screen after
   fixed intervals of time, instead of all the messages appearing on the screen
   at once when the output buffer is eventually flushed later.


 * The prefix 'std::' indicates that the names cout, cin and endl are defined
   inside the 'namespace' named 'std' (:: is the scope resolution operator).
   Namespaces allow us to avoid inadvertent collisions between the names we
   define and uses of those same names inside a library.
   All the names defined by the standard library are in the std namespace.
 * The scope resolution operator is basically used to tell the compiler what
   'namespace' or what 'class' something belongs to.

 * End of Trivia */
