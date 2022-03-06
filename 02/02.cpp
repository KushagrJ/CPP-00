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
   [Similar type conversion rules as that in C are applicable for C++ as well]

 * Resume from 2.1.3 Literals

 * End of Trivia */
