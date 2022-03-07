// C++20 Standard
// This program doesn't include input validation.

#include <iostream>


int main()
{

    int x;
    int sum = 0;

    std::cout << "Enter integers to be summed up (q to quit): ";

    while (std::cin >> x)
        sum += x;

    std::cout << "Their sum is " << sum << std::endl;

    return 0;

}





/* Output - 01.cpp

   Enter integers to be summed up (q to quit): 1 2 3 4 5 q
   Their sum is 15

 * End of Output */





/* Trivia - 01.cpp

 * Many concepts/terms common to C and C++ are not explained/defined here.


 * Statements normally execute sequentially. The first statement in a block is
   executed first, followed by the second, and so on.
   Programming languages also provide various flow-of-control statements that
   allow for more complicated execution paths. For eg., while, for & do while.


 * When an istream is used as a condition (or when an istream variable is cast
   to a bool), the effect is to test the state of the stream.
   If the stream is valid, i.e. if the stream hasn't encountered an error, then
   the test succeeds.
   If the stream is invalid, i.e. if end-of-file or invalid input has been
   encountered, then the test fails.
 * When we use the >> operator to get user input and put it into a variable,
   this is called an 'extraction'. The >> operator is accordingly called the
   extraction operator when used in this context.
 * When the user enters input in response to an extraction operation, the data
   is placed in a 'buffer' inside of the istream object named cin. A buffer is
   simply a piece of memory set aside for storing data temporarily while it's
   moved from one place to another. In this case, the buffer is used to hold
   user input while it's waiting to be extracted to variables.
 * When the extraction operator is used, the following procedure happens :-
   # If there is data already in the input buffer, that data is used for
     extraction.
   # If the input buffer contains no data, the user is asked to input data for
     extraction (this is the case most of the time).
     When the user hits ENTER, a '\n' character is placed in the input buffer.
   # The >> operator extracts as much data from the input buffer as it can into
     the variable (ignoring any leading whitespaces, and stopping at the first
     whitespace after non-whitespace characters).
   # Any data that can not be extracted is left in the input buffer for the next
     extraction.
 * Extraction succeeds if at least one character is extracted from the input
   buffer. For eg., if 5a is given as input to int x; std::cin >> x;, 5 will be
   extracted, converted to an integer and assigned to x. The characters 'a' and
   '\n' will be left in the input buffer for the next extraction. Thus, the
   next cin operation for an int variable will fail, as the next character to be
   read from the input buffer is 'a'.
 * Extraction fails if the input data does not match the type of the variable
   the data is being extracted to. For eg., if b is given as input to
   int x; std::cin >> x;, extraction would fail.
 * There are generally four types of input errors :-
   # Input extraction succeeds but the input is meaningless to the program. For
     eg., if 10 is given as input to a program requesting an integer between
     1 and 7.
   # Input extraction succeeds but the user enters additional input. For eg.,
     if 5a is given as input to a program requesting an integer.
   # Input extraction fails. For eg., if b is given as input to a program
     requesting an integer, or if EOF is triggered from the keyboard before any
     valid input is given.
   # Input extraction succeeds but the user overflows a numeric value.
 * When input extraction fails, two things happen: the input data is left in the
   input buffer (if any), and std::cin goes into 'failure' mode.
   Once in failure mode, future requests for input extraction silently fail.
   std::cin.fail() and !(std::cin) both return true if the previous extraction
   failed.
   std::cin.clear() puts std::cin back into 'normal' mode.
 * A failed extraction due to invalid input causes that variable for which the
   extraction failed to be set to 0, 0.0, "", or whatever value 0 converts to
   for that type.
   If another extraction is attempted using std::cin after failure has already
   occurred in a previous extraction attempt, the input data is again left in
   the input buffer (if any), but the variable isn't set to 0.
   For eg.,
   (1) int x = 100, y = 100, z = 100;
       std::cin >> x;
       std::cout << x << ' ';
       std::cin >> y;
       std::cout << y << ' ';
       getchar();
       std::cin >> z;
       std::cout << z << ' ';
       // If 1.2 is given as input to the above program, the output is 1 0 100.
   (2) int x = 100, y = 100, z = 100;
       scanf("%d", &x);
       std::cout << x << ' ';
       scanf("%d", &y);
       std::cout << y << ' ';
       getchar();
       scanf("%d", &z);
       std::cout << z << ' ';
       // If 1.2 is given as input to the above program, the output is 1 100 2.
 * Since an extraction may also fail due to incorrect input, and not due to EOF
   getting triggered, there is another flag related to std::cin which checks
   whether EOF was encountered.
   if (!(std::cin >> x))
   {
       if (std::cin.eof())
           std::cout << "Read failed due to EOF" << std::endl;
       else
           std::cout << "Read failed due to something other than EOF"
                     << std::endl;
   }


 * In C++, we define our own data structures by defining 'classes'.
 * A class defines a type along with a collection of operations that are related
   to that type.
 * A primary focus of the design of C++ is to make it possible to define class
   types that behave as naturally as the built-in types.
 * The author of a class needs to define all the actions that can be performed
   by objects of that class.
 * A 'member function' is a function that is defined as part of a class.
   Member functions are sometimes referred to as 'methods'.


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
   For eg., std::cout << '\113'; prints K
            std::cout << "\x32\115\xa"; prints 2M followed by a newline.

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

 * Identifiers (i.e. names given to objects/variables (as the terms 'object' and
   'variable' are used interchangeably), functions, etc.) are arbitrarily long
   sequences of letters, digits and the underscore character.
 * C++ imposes no limit on the length of an identifier.
 * Identifiers must begin with a either a letter or an underscore.
 * Identifiers are case-sensitive.
 * Reserved keywords can't be used as names of identifiers. For eg., alignas,
   alignof, asm, auto, bool, break, case, catch, char, char16_t, char32_t,
   class, const, constexpr, const_cast, continue, decltype, default, delete,
   do, double, dynamic_cast, else, enum, explicit, export, extern, false, float,
   for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept,
   nullptr, operator, private, protected, public, register, reinterpret_cast,
   return, short, signed, sizeof, static, static_assert, static_cast, struct,
   switch, template, this, thread_local, throw, true, try, typedef, typeid,
   typename, union, unsigned, using, virtual, void, volatile, wchar_t, while,
   and, and_eq, bitand, bitor, compl, not, not_eq, or, or_eq, xor and xor_eq.
 * The C++ standard also reserves a set of names for use in the standard
   library. The identifiers we define in our own programs must not contain two
   consecutive underscores, and they must not begin with an underscore followed
   immediately by an uppercase letter. In addition, identifiers defined outside
   a function must not begin with an underscore.
   Using such identifers invokes undefined behaviour. The compilers aren't
   required to issue warnings or errors for the usage of such identifiers.
 * For eg., an identifier designating / referring to an object / a varible is a
   convenient name given to that object/variable.
   Thus, the term 'name of an identifier' is meaningless, as an identifier is
   itself a name.

 * A 'scope' is a part of the program in which a name has a particular meaning.
   Most scopes in C++ are delimited by curly braces.
 * The same name can refer to different entities in different scopes.
   Names are visible from the point where they are declared until the end of the
   scope in which the declaration appears.
 * For eg.,
   #include <iostream>
   int main()
   {
       int sum = 0;
       for (int val = 1; val <= 10; (val)++)
           sum += val;
       std::cout << sum << std::endl;
       return 0;
   }
   The name 'main' is defined outside any curly braces, and thus has 'global'
   scope. Once declared, names at the global scope are accessible throughout
   the program.
   The name 'sum' is defined within the scope of the block that is the body of
   main(), and thus has 'block' scope. It is accessible from its point of
   declaration throughout the rest of the main() function, but not outside.
   The name 'val' is defined in the scope of the for statement, and thus also
   has 'block scope'. It can be used only inside that for statement, and not
   elsewhere in main() or outside main().
 * Scopes can contain other scopes. The nested scope is referred to as an
   'inner' scope and the containing scope is called the 'outer' scope.
   Once a name has been declared in a scope, that name can be used by any scopes
   nested inside that scope.
 * Names declared in the outer scope can also be redefined in an inner scope.
   For eg.,
   #include <iostream>
   int i = 42;
   int main()
   {
       std::cout << i << ' ';
       int i = 10;
       std::cout << i << ' ';
       std::cout << ::i << ' ';
       return 0;
   }
   This program prints 42 10 42.
   [The scope operator (::) can be used to override the default scoping rules.
    The global scope has no name. Hence, when the operator has an empty
    left-hand side, it is a request to fetch the name on the right-hand side
    from the global scope.]
 * It is almost always a bad idea to define an inner scope variable with the
   same name as an outer scope variable.
 * As always, using global variables is a bad idea, unless that variable is
   const-qualified.

 * Built-in types are also known as primitive/fundamental types.
 * A 'compound' type is a type that is defined in terms of another type
   (built-in or compound). For eg., arrays, functions (return type and types of
   parameters), pointers, references, classes, etc. are all compound types.
 * Any type that is not a built-in type is a compound type.

 * A 'declaration' is a base type (built-in or compound) followed by a list of
   'declarators'. Each declarator names a variable and gives the variable a type
   that is related to the base type.
   [Every definition is a declaration as well]
 * An 'lvalue reference', or simply 'reference', defines an alternative name
   for an object. A reference type 'refers to' another type. A reference must be
   initialized upon its declaration.
   For eg., int i = 42; int& ref_i = i;
 * Ordinarily, when we initialize a variable, the value of the initializer is
   copied into the object we are creating. When we define a reference, instead
   of copying the initializer's value, we 'bind' the reference to its
   initializer.
 * Once initialized, a reference remains bound to its initial object. There is
   no way to rebind a reference to refer to a different object.
 * After a reference is bound, all operations on that reference are actually
   operations on the object to which the reference is bound.
 * Because references are not objects, we can't define a reference to a
   reference.
 * Thus, in simple terms, a reference is just another name for an already
   existing object.
 * With two exceptions, the type of a reference and the object to which the
   reference refers must match exactly.
   Exception 1 - We can bind a reference-to-const to a non-const object,
                 a literal, or a more general expression that can be converted
                 to the original type.
                 For eg., int& r = 3.14 // error
                          const int& r = 3.14; // ok; a 'temporary object' will
                                                  be created to store 3
   [In such cases, because the underlying object might be non-const, it might be
    changed by other means]
   Exception 2 - We can bind a reference to a base-class type to an object of a
                 type derived from that base class.

 * A 'pointer' type is a compound type that 'points to' another type.
   [Same logic as C applies to C++ as well regarding pointers]
   [See https://stackoverflow.com/questions/57483 - What are the differences
    between a pointer variable and a reference variable in C++?]
 * With two exceptions, the type of a pointer and the object to which the
   pointer points must match exactly.
   Exception 1 - We can use a pointer-to-const to point to a non-const object.
   [In such cases, because the underlying object might be non-const, it might be
    changed by other means]
   Exception 2 - We can use a pointer to a base-class type to point to an object
                 of a type derived from that base class.
 * The value stored in a pointer variable can be in one of four states -
   (1) It can be the address of an object.
   (2) It can be the address of the location just immediately past the end of an
       object.
   (3) It can be a null pointer, indicating that it isn't the address of any
       object.
   (4) It can be invalid; values other than the preceding 3 are invalid.
   [The result of accessing an invalid pointer is that undefined behaviour gets
    invoked]
   [Although pointers in cases 2 and 3 are valid, we must not use them to access
    the (supposed) object to which the pointer points (undefined behaviour)]
 * There are several ways to obtain a null pointer -
   int* p1 = nullptr;
   int* p2 = 0;
   int* p3 = NULL; // must #include <cstdlib>
 * The type void* is a special pointer type that can hold the address of any
   object. Like any other pointer, a void* pointer holds an address, but the
   type of the object at that address is unknown.

 * We can make a variable unchangeable by defining the variable's type as
   'const'. Because we can't change the value of a const object after we create
   it, it must be initialized upon creation, just like references.
 * By default, const objects are local to a file. Thus, to share a const object
   among multiple files, we must define the const variable as extern.
 * A reference to a const cannot be used to change the object to which the
   reference is bound.
   There is no such thing as a const reference, as a reference is not an object.
 * A pointer to a const cannot be used to change the object to which the pointer
   points, but the pointer itself may be made to point elsewhere.
   A const pointer cannot be made to point elsewhere, but may be used to change
   the object to which the pointer points.
 * The term 'top-level const' is used to indicate that the pointer itself is
   const. When a pointer can point to a const object, we refer to that const as
   a 'low-level const'.
   [More generally, top-level const indicates that an object itself is const.
    Low-level const is applicable to types such as pointers and references.]

 * A constant expression is an expression whose value cannot change and that can
   be evaluated at compile time. A literal is a constant expression. A const
   object that is initialized from a constant expression is also a constant
   expression (as opposed to in C, where a const object is not a constant
   expression, even if it is initialized from a constant expression).
   For eg., int i = 10; // i is not a constant expression even though it is
                        // initialized from a constant expression, as the value
                        // of i may change during program execution
            const int j = get_size(); // j is again not a constant expression
                                      // even though it is const-qualified, as
                                      // the value of the initializer is not
                                      // known until run time
 * We can ask the compiler to verify whether a variable is a constant expression
   by declaring the variable in a 'constexpr' declaration.
   For eg., constexpr i = 20;
            constexpr j = i + 1;
            constexpr k = size(); // ok only if size() is a constexpr function
 * constexpr imposes a top-level const on the objects it is used with.
   Thus, in const int* p;, p is a pointer to const, whereas in
   constexpr int* q;, q is a constant pointer.

 * A 'type alias' is a name that is a synonym for another type.
   We can define a type alias by using 'typedef' or 'using'.
   For eg., typedef int* ptr_int;
            using ptr_int = int*;
 * typedef char* ptr_char;
   const ptr_char p;
   const ptr_char* q;
   Here, p is a constant pointer to char, and not a pointer to const char.
   It may seem like p should be a pointer to const char (as if we were to simply
   replace the alias like const char* p, p would be a pointer to const char),
   but it is not the case.
   Similarly, q is a non-constant pointer to a constant pointer to char.
   [These kinds of type aliases and declarations should generally not be used,
    in order to avoid confusion]

 * We can let the compiler figure out the type of a variable for us by using the
   'auto' type specifier.
   C++ doesn't allow the usage of 'auto' as a storage class specifier, unlike C.
 * A variable that uses auto as its type specifier must be initialized upon
   creation, just like const variables and references.
 * For eg., auto i = j + k; // the type of i will become whatever the resulting
                            // type of (j + k) is
 * When defining multiple variables using auto, the initializers for all the
   variables in the declaration must have types that are consistent with each
   other.
   For eg., auto i = 0, * p = &i; // ok
            auto j = 0, k = 3.14; // error
            auto l = 0, m = 'a'; // error, since auto i = 'a' makes the type of
                                 // i equal to char (not int)
 * When we use a reference as an initializer, the initializer is the
   corresponding object. Thus, for eg., int i = 0, & r = i; auto x = r; makes
   the type of x equal to int.
 * auto ordinarily ignores top-level consts, but keeps low-level consts.
   If we want the deduced type to have a top-level const, we must say so
   explicitly, like const auto i = j;
 * We can also specify that we want a reference to an auto deduced type (auto&).
   Top-level consts are not ingnored in this case.

 * The 'decltype' type specifier returns the type of its operand. The compiler
   analyzes the expression to determine its type, but does not evaluate the
   expression itself.
   For eg., decltype(f()) sum; // sum has whatever type f() returns
   Here, f() is not evaluated.
 * When we apply decltype to a simple variable, decltype returns the type of
   that variable, including top-level const and references.
   For eg., const int i = 0, & j = i;
            decltype(i) x = 0; // x has type const int
            decltype(j) y = x; // y has type const int& and is bound to x
   Thus, decltype is the only context in which a variable defined as a reference
   is not treated as a synonym for the object to which it refers.
 * When the expression to which we apply decltype is not simply a variable, we
   get the type that the expression yields.
   decltype returns a reference type (intead of the type itself) for expressions
   that yield objects that can stand on the left-hand side of assignment (=).
   For eg., int i = 42, * p = &i, & r = i;
            decltype(i) returns int
            decltype(r) returns int&
            decltype(r + 10) returns int since r + 10 doesn't yield an object
                             that can stand on the left-hand side of =
            decltype(p) returns int*
            decltype(*p) returns int& instead of int, since *p yields an
                         object that can stand on the left-hand side of =
 * When we apply decltype to a variable without any parentheses, we get the type
   of that variable. But, if we wrap the variable's name in one or more sets of
   parentheses, the compiler will treat it as an expression as not being simply
   a variable, and will consequently yield a reference.
   For eg., int i = 0, & j = i;
            decltype(i) returns int
            decltype((i)) returns int&
            decltype(j) returns int&
            decltype((j)) also returns int&, since (j) is treated as an
                          expression and (j) now corresponds to the bound object
                          whose type is int and can stand on the left-hand side
                          of =
            [j not being treated as a synonym for i is only applicable for
             decltype(j), and not for decltype((j))]

 * At the most basic level, a 'data structure' is a way to group together
   related data elements and a strategy for using those data.
 * As mentioned before, in C++, we define our own data types by defining
   classes. The libraries string, istream and ostream are all defined as
   classes.

 * In C++, structs and classes are pretty much the same. The only difference is
   that where access modifiers (for member variables, member functions
   (i.e. methods) and base classes) in classes default to private, access
   modifiers in structs default to public.
 * So, structs in C++ are simply referred to as classes.
 * However, in C, a struct is just an aggregate collection of (public) data, and
   has no other class-like features: no methods, no constructor, no base
   classes, etc.
 * Although C++ inherited the 'struct' keyword, it extended the semantics.
   Thus, since access modifiers in structs in C++ default to public, a C++
   struct written like a C struct behaves like one as well.

 * For eg., consider the following class :-

   struct Book_Data
   {
       std::string name;
       unsigned units_sold = 0;
       double revenue = 0.0;
   };
   Book_Data book1, book2;

   Here, as opposed to C structs, we don't need to write struct Book_Data book1,
   book2; and can simply write Book_Data book1, book2;.

   This class has only 'data members'. The data members of a class define the
   contents of the objects of that class type.
   Each object has its own copy of the class data members. Modifying the data
   members of one object does not change the data in any other object of a
   class.
   We define data members in the same way that we define normal variables.
   We can use an 'in-class initializer' for a data member, as used in this
   example. When we create objects, the in-class initializers will be used to
   initialize the data members. Members without an initializer are default
   initialized.
   Out of int x = 10;, int x = {10};, int x{10}; and int x(10);, in-class
   initialization cannot be done using int x(10);.
   [In C, such a feature is not available, i.e. there is no such thing as an
    'in-struct initializer' in C]
 * The dot operator (.) is used to access members of a class object.

 * Even though we can define a class inside a function, such classes have
   limited functionality. As a result, classes are ordinarily not defined inside
   functions.
 * When we define a class outside a function, there may be only one definition
   of that class in any given source file.
   In addition, if we use a class in several different files, the class'
   definition must be the same in each file.
   In order to ensure that the class definition is the same in each file,
   classes are usually defined in header files.
 * Because a header file that we use may also need to include other header
   files in it, the same header files might get included more than once in a
   source file, indirectly. So, we need to write our headers in a way that is
   safe even if the header is included multiple times, using #define, #ifdef,
   #endif, etc.
 * The preprocessor works in the same way in C++ as it does in C.

 * End of Trivia */
