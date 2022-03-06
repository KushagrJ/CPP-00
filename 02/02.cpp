// C++20 Standard
// This program doesn't include input validation.

#include <iostream>


int main()
{

    return 0;

}





/* Output - 02.cpp



 * End of Output */





/* Trivia - 02.cpp

 * Many concepts/terms common to C and C++ are not explained/defined here.


 * Every widely used programming language provides a common set of features,
   which differ in detail from one language to another. Understanding the
   details of how a language provides these features is the first step toward
   understanding the language.
   Among the most fundamental of these common features are :-
   (1) Built-in types such as integers, characters, etc.
   (2) Variables, which let us give names to the objects we use.
   (3) Expressions and statements to manipulate values of these types.
   (4) Control structures such as if and while.
   (5) Functions that let us define callable units of computation.

 * Some languages such as Python check types at run time. In contrast, C and C++
   are statically typed, i.e. type checking is done at compile time. As a
   consequence, the compiler must know the type of every name used in the
   program.
   Static type checking can help find bugs easily, as if the programmer tries to
   do things that the type does not support, the compiler generates error
   messages and does not produce an executable file.

 * C lets programmers define types (using structures) that specify only what
   data make up the type.
   C++ allows programmers to define types (using classes) that include
   operations as well as data.
 * Object orientation means that instead of being organised around functions
   that operate on the data (like in C), programs are organised around the data
   itself (like in C++).

 * C++ defines a set of primitive types that include the arithmetic types and a
   special type named 'void'.
   The arithmetic types represent characters, integers, boolean values and
   floating-point numbers.
   The void type has no associated values and can be used in only a few
   circumstances, most commonly as the return type for functions that do not
   return a value.

 * Type          Minimum Size

   bool          N/A
   char          8 bits
   wchar_t       16 bits
   char16_t      16 bits
   char32_t      32 bits
   short         16 bits
   int           16 bits
   long          32 bits
   long long     64 bits
   float         6 significant digits
   double        10 significant digits
   long double   10 significant digits

   [size(short) <= size(int) <= size(long) <= size(long long)]

 * Deciding which type to use :-
   # Unsigned types should be used when it is known that the values cannot be
     negative.
   # int's should be used for integer arithmetic. short is usually too small
     and, in practice, long often has the same size as int. If the data values
     are larger than the minimum guaranteed size of an int, then long long
     should be used.
   # Plain char or bool should not be used in arithmetic expressions. They
     should be used only to hold characters or truth values. Computations using
     char are especially problematic because char is signed on some machines and
     unsigned on others.
     If a tiny integer is needed, it should be explicitly specified whether the
     type is signed char or unsigned char.
   # double should be used for floating-point computations. float usually does
     not have enough precision, and the cost of double-precision calculations
     versus single-precision is negligible. In fact, on some machines,
     double-precision operations are faster than single. The precision offered
     by long double usually is unnecessary and often entails considerable
     run-time cost.

 * When one of the non-bool arithmetic types is assigned to a bool object, the
   result is false if the value if 0 and true otherwise.
   For eg., bool b = 42;   // b is true
 * When a bool is assigned to one of the other arithmetic types, the resulting
   value is 1 if the bool is true and 0 if the bool is false.
   For eg., int i = b;   // i has value 1
 * When a floating-point value is assigned to an object of integral type, the
   value is truncated. The value that is stored is the part before the decimal
   point.
   For eg., i = 3.14;   // i has value
 * When an integral value is assigned to an object of floating-point type, the
   fractional part is zero. Precision may be lost if the integer has more bits
   than the floating-point object can accomodate.
   For eg., double pi = i;   // pi has value 3.0
 * If an out-of-range value is assigned to an object of unsigned type, the
   result is the remaining part of the value modulo the number of values the
   target type can hold.
   For eg., unsigned char c1 = -1;   // assuming 8-bit chars, c1 has value 255
 * If an out-of-range value if assigned to an object of signed type, the result
   is undefined behaviour.
   For eg., signed char c2 = 256;   // assuming 8-bit chars, undefined behaviour
                                    // gets invoked

 * Undefined and implementation-defined behaviours should be avoided.

 * The compiler applies these same type conversions when a value of one
   arithmetic type is used where a value of another arithmetic type is expected.
   For eg., when a non-bool value is used as a condition, the arithmetic value
   is converted to bool in the same way that it would be converted had that
   arithmetic value been assigned to a bool variable.
   [Similar type conversion rules as that in C are applicable for C++ as well,
    such as char expressions being promoted to int ones, etc.]

 * A constant expression such as 41, 012, 0x23, 5.7, 'A', true, false, nullptr,
   etc. is known as a literal.
   [An expression has a type and evaluates to a value. Expressions, values and
    objects all have types.]
 * By default, decimal literals are signed, whereas octal and hexadecimal
   literals can be either signed or unsigned.
   A decimal literal has the smallest type of int, long or long long.
   An octal/hexadecimal literal has the smallest type of int, unsigned int,
   long, unsigned long, long long or unsigned long long.
 * By default, floating-point literals have type double.
 * The prefixes u, U, L and u8 can be used for char16_t, char32_t, wchar_t and
   char string literals, respectively.
 * The suffixes u/U, l/L, ll/LL, f/F and l/L can be used for unsigned, long,
   long long, float and long double literals, respectively.
   For eg., an integer literal with a U suffix has the smallest type of unsigned
   int, unsigned long and unsigned long long in which the literal's value fits.
 * The value of a literal is never negative. For eg., in -42, the minus sign is
   not part of the literal. The minus sign is an operator that negates the value
   of its operand.

 * A character enclosed within single quotes is a literal of type char.
   The type of a char literal/expression is promoted to int when used.
 * Zero or more characters enclosed in double quotation marks is a string
   literal. The type of a string literal is array of constant chars. The
   compiler appends a null character ('\0') to every string literal. Thus, the
   actual size of a string literal is one more than its apparent size.

 * Other than the escape sequences \n, \v, \\, \r, \t, \b, \?, \\f, \a, \" and
   \', we can also use our own generalized escape sequences.
   This can be done by writing \ followed by one, two or three octal digits, or
   \x followed by one or more hexadecimal digits.
   For eg., '\12' is the same as '\n', '\x4d' is the same as 'M', and so on.
   [When a character, including escape sequences, is part of a string of
    characters enclosed in double quotes, it should not be enclosed in single
    quotes]
   [If a \ is followed by more than 3 octal digits, only the first three are
    associated with the \.
    In contrast, \x uses up all the hex digits following it.]

 * It is possible to initialize a variable to the value of one defined earlier
   in the same definition. For eg., int i = 1, j = (i * 2);
 * Initialization is not assignment. Initialization happens when a variable is
   given a value when it is created. Assignment obliterates an object's current
   value and replaces that value with a new one.
 * For eg., any of the following four different ways can be used to define an
   int variable named x and initialize it to 10:
   int x = 10;
   int x = {10};
   int x{10};
   int x(10);
   [The generalized form of curly braces for initialization is referred to as
    'list initialization']
 * When used with variables of built-in types, list initialization has one
   important property: the compiler will not let the user initialize variables
   of built-in types if the initializer might lead to the loss of information.
   For eg., long double ld = 3.14;
            int a{ld}, b = {ld}; // error
            int c(ld), d = ld; // ok, but value will be truncated
 * When a variable is defined without an initializer, the variable is 'default
   initialized'. Such variables are given the default value. What that default
   value is depends on the type of the variable and may also depend on where the
   variable is defined.
 * Variables of built-in types defined outside of any function body are
   initialized to zero.
   Static variables of built-in types defined inside a function are also
   initialized to zero.
   Automatic variables of built-in types defined inside a function are
   uninitialized. The value of an uninitialized variable is undefined. Undefined
   behaviour gets invoked when the value of an uninitialized variable is
   accessed.
 * Each class controls how objects of that class type can be initialized. In
   particular, it is up to the class whether objects of that type can be
   defined without an initializer. If they can, the class determines what value
   the resulting object will have.
   For eg., the string class (not a built-in type) says that if an initializer
   is not supplied, the resulting string is the empty string.
 * Some classes require that every object be explicitly initialized. The
   compiler will complain if an object is tried to be created of such a class
   with no initializer.

 * When a program is split into multiple files, a way is needed to share code
   across those files. For eg., code defined in one file may need to use a
   variable defined in another file. As a concrete example, std::cout and
   std::cin are objects defined somewhere in the standard library, yet the
   programs can use these objects.
 * To support such separate compilation, C++ distinguishes between declarations
   and definitions of variables, functions, etc., much like C.
   A 'declaration' makes a name known to a program. A file that wants to use a
   name defined elsewhere includes a declaration for that name.
   A 'definition' creates the associated entity.
 * A variable declaration specifies the type and name of the variable.
   A variable definition, in addition to specifying the type and name of the
   variable, allocates storage and may provide the variable with an initial
   value.
   For eg., extern int i; // declares, but doesn't define i
            int j; // declares and defines j
            int k = 1; // declares and defines k
            extern int l = 1; // declares and defines l (extern gets overriden)
   [It is an error to provide an initializer on an extern inside a function]
 * Variables and functions must be defined exactly once, but can be declared
   many times.
   To use the same variable/function across files in a multi-file program, that
   variable/function must be defined in one and only one file. Other files that
   use that variable/function must declare (but not define) that variable.

 * Resume from 2.2.3 Identifiers

 * End of Trivia */
