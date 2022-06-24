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
   std::cin.fail() and !(std::cin) both return true if std::cin is in failure
   mode.
   std::cin.clear() puts std::cin back into 'normal' mode.
 * A failed extraction due to invalid input causes the input data to be left in
   the input buffer (if any) and the value of that variable for which the
   extraction failed to be set to 0, 0.0, "", or whatever value 0 converts to
   for that type.
   If another extraction is attempted using std::cin after failure has already
   occurred in an earlier extraction attempt and if std::cin is still in failure
   mode, then the input data is again left in the input buffer (if any), but the
   corresponding variable's value isn't set to 0.
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
 * Since an extraction may fail due to incorrect input, and not due to EOF
   getting encountered, there is another flag related to std::cin which checks
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

 * C++ defines a set of primitive/fundamental types that include the arithmetic
   types and a special type named 'void'.
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
   result is false if the value is 0 and true otherwise.
   For eg., bool b = 42;   // b is true
 * When a bool is assigned to one of the other arithmetic types, the resulting
   value is 1 if the bool is true and 0 if the bool is false.
   For eg., int i = b;   // i has value 1
 * When a floating-point value is assigned to an object of integral type, the
   value is truncated. The value that is stored is the part before the decimal
   point.
   For eg., i = 3.14;   // i has value 3
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
    such as char expressions being promoted to int ones when used, etc.]
 * For eg., short i = 1, j = 2; sizeof i returns the size of short, whereas
                                sizeof (i + j) returns the size of int.
            char i = 'a', j = 'b'; sizeof i returns the size of char, whereas
                                   sizeof (i + j) returns the size of int.
   Thus, i by itself isn't promoted to int, as it isn't 'used' in an expression
   in these cases. But, (i + j) makes i and j both typecast to int.
   [In C, however, sizeof i returns the size of int, i.e. in C, for eg., 'A' is
    considered to be of type int, whereas in C++, 'A' is of type char]

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
   int x{10}; // doesn't work in C
   int x(10); // doesn't work in C
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
   For eg., the std::string class (a compound type) says that if an initializer
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
   use that variable/function must declare (but not define) that
   variable/function.

 * Identifiers (i.e. names given to objects/variables (as the terms 'object' and
   'variable' are used interchangeably), functions, etc.) are arbitrarily long
   sequences of letters, digits and the underscore character.
 * C++ imposes no limit on the length of an identifier.
 * Identifiers must begin with either a letter or an underscore.
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
 * For eg., an identifier designating / referring to an object / a variable is a
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
 * As always, using global variables is a bad idea, unless those variables are
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
   For eg., int i = 42;
            int& ref_i = i;
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
   For eg., int i; int& ref_i_1 = i; int& ref_i_2 = ref_i_1;
            Here, in the third statement, ref_i_1 becomes a synonym for i,
            i.e. int& ref_i_2 = ref_i_1 is the same as int& ref_i_2 = i;
 * Thus, in simple terms, a reference is just another name for an already
   existing object.
 * With two exceptions, the type of a reference and the object to which the
   reference refers must match exactly.
   Exception 1 - We can bind a reference-to-const to a non-const object,
                 a literal, or a more general expression that can be converted
                 to the original type.
                 For eg., int& r = 3; // error
                          const int& r = 3; // ok; a 'temporary object' will be
                                            // created to store 3
                          int& r = 3.14; // error
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
   (1) It can be the starting address of an object.
   (2) It can be the address of the location just immediately past the end of an
       object.
   (3) It can be a null pointer, indicating that it isn't the address of any
       object.
   (4) It can be invalid - values other than the preceding 3 are invalid.
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
   For eg., constexpr int i = 20;
            constexpr int j = i + 1;
            constexpr int k = size(); // ok only if size() is a constexpr func
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
   [These kinds of type aliases and definitions should generally not be used,
    in order to avoid confusion]
   [In general, type aliases should not be used on pointer types]


 * We can let the compiler figure out the type of a variable for us by using the
   'auto' type specifier.
   C++ doesn't allow the usage of 'auto' as a storage class specifier, unlike C.
 * A variable that uses auto as its type specifier must be initialized upon
   creation, just like const variables and references.
 * For eg., auto i = j + k; // the type of i will become whatever the resulting
                            // type of (j + k) is
 * When defining multiple variables using auto, the initializers for all the
   variables in the definition must have base types that are consistent with
   each other.
   For eg., auto i = 0, * p = &i; // ok
            [This works similar to how int i = 0, * p = &i; works]
            auto j = 0, k = 3.14; // error
            auto l = 0, m = 'a'; // error, since auto i = 'a' makes the type of
                                 // i equal to char (not int)
            auto p = 0, q = 'a' + 'b'; // ok
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
   that yield lvalues (explained later).
   For eg., int i = 42, * p = &i, & r = i;
            decltype(i) returns int
            decltype(&i) returns int* since &i doesn't yield an lvalue
            decltype(r) returns int&
            decltype(r + 10) returns int since r + 10 doesn't yield an lvalue
            decltype(p) returns int*
            decltype(*p) returns int& instead of int, since *p yields an lvalue
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
                          whose type is int and is an lvalue
            [j not being treated as a synonym for i is only applicable for
             decltype(j), and not for decltype((j))]


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


 * Built-in/fundamental/primitive types - int, char, float, etc.
   Compound types - array, pointer, reference, class, etc.
 * Arrays are not built-in types.
   Arrays are compound types, and the term 'built-in' is an informal name for a
   fundamental type.

 * An abstract data type (ADT) is simply the description of a type. But, once
   that type has been implemented in a language, it no longer remains an ADT,
   and rather becomes concrete.
   So, the idea of an integer type is an ADT, but the type int is not an ADT and
   is rather a fundamental type.
   Similarly, the idea of a string/vector type is an ADT, but the type
   std::string/std::vector<int> is not an ADT and is rather a compound type,
   defined as a class / instantiated from a class template.
 * So, the definition of an ADT which says that an ADT is a type whose
   implementation details are hidden from the user is not fully correct.
 * Simply put, a formal abstract description of a type's properties and of the
   operations that can be performed on the type is called an ADT.
   This description shouldn't be tied to any particular implementation or
   programming language.
 * cppreference.com clearly indicates that there are only two kinds of types in
   C++, namely 'fundamental' and 'compound'. Thus, any ADT, when implemented,
   becomes either a fundamental type or a compound type.

 * The safest way to use names from a namespace without qualifying the names
   with namespace_name:: prefixes is by using 'using declarations'.
   For eg., using std::cin;.
 * Code inside header files should generally not include 'using declarations',
   because the contents of a header file are copied into the including program's
   text and if a header file has a 'using declaration', then every program that
   includes that header file gets that same 'using declaration'. As a result, a
   program that didn't intend to use the specified library name might encounter
   unexpected name conflicts.
 * Using 'using directives', such as using namespace std;, is generally
   considered bad practice, because 'using directives' make all the members of
   a namespace suddenly visible, paving the way for the global namespace
   pollution problem.


 * A 'string' in C++ is a variable-length sequence of characters. To use the
   std::string compound type (which is defined as a class), we must include the
   'string' header.
   Because the string library is part of the standard library, the name 'string'
   is defined in the std namespace.
 * A library type is almost always more efficient to use than an equivalent
   user-defined type, because in addition to specifying the operations that the
   library types provide, the standard also imposes efficiency requirements on
   implementors.

 * Common ways to initialize an std::string :-
   (1) std::string s1; // default initialization; s1 is the empty string ""
   (2) std::string s2 = s1; // s2 is a copy of s1
   (3) std::string s2(s1); // s2 is a copy of s1
   (4) std::string s3 = "hello"; // s3 is a copy of the string literal "hello",
                                 // excluding the null character
   (5) std::string s3("hello"); // s3 is a copy of the string literal "hello",
                                // excluding the null character
   (6) std::string s4(5, 'c'); // s4 is "ccccc"
 * std::string s5 = std::string(5, 'c'); creates a temporary std::string object
   of the given size and character value and then copies that value into s5.

 * Common std::string operations :-
   (1) os << s // writes the string s onto the ostream object os
   (2) is >> s // reads a string from the istream object is into the string s
   (3) getline(is, s) // reads a line of input from the istream object is into
                      // the string s, consuming and excluding the terminating
                      // newline character
   (4) s.empty() // returns true if the string s is empty, false otherwise;
                 // empty() is a member function of the string class
   (5) s.size() // returns the number of characters in the string s;
                // size() is a member function of the string class;
                // the value returned is of type std::string::size_type
   (6) s[n] // returns the char at the index n in the string s (technically a
            // reference to the char at the index n)
   (7) s1 + s2 // returns a string that is the concatenation of the strings
               // s1 and s2
   (8) s1 = s2 // replaces the characters in the string s1 with a copy of the
               // characters in the string s2
   (9) s1 == s2 // the strings s1 and s2 are equal if they are the same length
       s1 != s2 // and contain the same characters (equality is case-sensitive)
 * <, <=, > and >= comparisons are case sensitive and use dictionary ordering.

 * non-const std::string's are mutable, but string literals are not.

 * As explained before, is >> s is used to read input from the is stream,
   storing what is read in s, by discarding leading whitespaces and stopping at
   the first whitespace after non-whitespace characters.
   Thus, if Hello World! is given as input to an is >> s, only Hello would get
   stored in s with no extra whitespaces. The remaining part, that is one space
   character followed by World!\n would remain in the input buffer of is.
 * while (is >> s) (for eg., while (std::cin >> s)) can be used to read input
   till end-of-file.
 * The getline() function is used to read a line of input from an istream object
   into an std::string, consuming and discarding the terminating newline
   character.
   Like the extraction operator, getline() also returns its istream argument.
   So, while (getline(is, s)) (for eg., while (getline(std::cin, s))) can also
   be used to read input line by line till end-of-file.
 * A common problem with using getline() after an extraction is that when the
   extraction ends in most cases, the terminating newline character remains in
   the input buffer. The upcoming getline() sees the newline character, consumes
   it, discards it, and stores an empty string in its std::string argument.
   To resolve this issue, is.ignore() (for eg., std::cin.ignore()) can be called
   immediately before getline().

 * In std::string::size_type, the first scope operator is used because the name
   'string' is defined in the 'std' namespace, and the second scope operator
   is used because the name 'size_type' is defined in the 'std::string' class.
   Thus, the scope resolution operator is basically used to tell the compiler
   what 'namespace' or what 'class' something belongs to.
 * The size_type type is a companion type to the string class which makes it
   possible to use such types in a machine-independent manner. For eg., the
   size_t type in C.
   Thus, any variable used to store the result from the size() member function
   of an std::string object should be of type std::string::size_type.
   Using 'auto' or 'decltype' instead of writing the type of a variable would be
   easier in such situations.
 * Although the precise type of std::string::size_type varies between
   implementations, it is guaranteed that std::string:size_type is some unsigned
   integer type.

 * The string library lets us convert both character literals ('a') and string
   literals ("a") to std::string's. But, when we mix std::string's and
   character/string literals, at least one operand to each + operator must be of
   std::string type.
 * The type of a string literal is const char[], the type of a character literal
   is char and the type of an std::string is std::string.
 * For eg., std::string s1 = "hello", s2 = "world";
            std::string s3 = s1 + ", " + s2 + '\n'; // ok
            std::string s4 = s1 + ", "; // ok
            std::string s5 = "hello" + ", "; // error, no string type as an
                                             // operand to +
            std::string s6 = s1 + ", " + "world"; // ok, due to left to right
                                                  // associativity of +
            std::string s7 = "hello" + ", " + s2; // error
            std::string s8 = "hello" + s2; // ok
   ['a' + 'b' is integer arithmetic.
    "hello" + 'a' is pointer arithmetic, due to array ([]) to pointer (*) decay.
    "hello" + "world" is an error.]

 * The functions prototyped in the <cctype> header file can be used to process
   characters, such as isalnum(c), isalpha(c), iscntrl(c), isdigit(c),
   isgraph(), islower(c), isprint(c), ispunct(c), isspace(c), isupper(c),
   isxdigit(c), tolower(c) and toupper(c).

 * The range-based for statement can be used to process every character in an
   std::string.
   For eg., for (char c : s) // or for (auto c : s)
                std::cout << c << std::endl;
            In each iteration, the variable c is created and initialized with
            the value of the next element in s, even if c is changed in between
            by other means.
            For eg., for (char c : s)
                     {
                         std::cout << c << ' ';
                         c = 'a';
                         std::cout << c << ' ';
                     }
                     This will print h a e a l a l a o a, if s is hello.
 * For eg., for (char& c : s) // or for (auto& c : s)
                c = 'a';
            Here, in each iteration, the variable c is created and bound to the
            the next element in s.
   This works similar to how int& j = i; binds j to i, whereas int j = i; copies
   the value of i into j.

 * The subscript operator ([]) takes an std::string::size_type value (called the
   index/subscript) when used with std::string's. It denotes the index of the
   character we want to access and technically returns a reference to the
   character at the given index.
   For eg., char c = s[3]; copies the value of s[3] into c, whereas
   char& c = s[3]; binds c to s[3].
   [Here, 3 is implicitly converted from int to std::string::size_type]
   [Thus, generally, it can also be said that a variable returns a reference to
    that object. For eg., in the case of int j = i;, the reference returned by i
    is simply used to copy the contents of i into j, but in the case of
    int& j = i;, the reference returned by i is used to bind the name 'j' to
    the object designated by the name 'i'.]
 * std::string indices begin at 0 and go upto (s.size() - 1).
   The result of using an out of range index is that undefined behaviour gets
   invoked. By implication, subscripting an empty string invokes undefined
   behaviour.
   To avoid such issues, the range-based for statement is generally used to
   process characters in an std::string.


 * A 'vector' in C++ is a variable-length sequence of objects (references aren't
   objects), all of which have the same type. To use the std::vector<T> compound
   type (which is defined as a class instantiated from a class template), we
   must include the 'vector' header.
   Because the vector library is part of the standard library, the name 'vector'
   is defined in the std namespace.
 * A vector is an example of a 'container' because it contains other objects.
 * C++ has both 'class templates' and 'function templates'.
   Writing a template requires a fairly deep understanding of C++.
 * Templates are not themselves classes or functions. Instead, they can be
   thought of as instructions to the compiler for generating classes or
   functions. The process that the compiler uses to create classes or functions
   from templates is called 'instantiation'.
 * The term 'generic programming' indicates code that is not specific to a
   particular type, but which, once a type is specified, can be translated into
   code for that type.
 * C++ lets the user create generic algorithms in the form of templates that the
   compiler can then use to instantiate code automatically for a specified type.
 * When we use a template, we specify what kind of class or function we want the
   compiler to instantiate.
   For the class template vector, we supply the type of the object the vector
   will hold inside a pair of angle brackets following the template's name.
   For eg., std::vector<int> v;
            std::vector<std::vector<std::string>> v;
 * A container cannot hold array objects, as the type of the elements to be
   stored in a container must be both copy-able and assignable.
   Arrays are neither.
   So, unless the arrays are wrapped into structs, or unless std::array's are
   used, a vector of arrays cannot be created.

 * Common ways to initialize an std::vector :-
   (1) std::vector<T> v1; // default initialization; v1 is empty
   (2) std::vector<T> v2 = v1; // v2 has a copy of each element in v1
   (3) std::vector<T> v2(v1); // v2 has a copy of each element in v1
   (4) std::vector<T> v3 = {a, b, c, ...}; // v3 has as many elements as there
                                           // are initializers; elements are
                                           // initialized by corresponding
                                           // initializers
   (5) std::vector<T> v3{a, b, c, ...}; // v3 has as many elements as there are
       [a, b, c, ... are in             // initializers; elements are
        {}, and not in ()]              // initialized by corresponding
                                        // initializers
   (6) std::vector<T> v4(n, val); // v4 has n elements with value val
   (7) std::vector<T> v4(n); // v4 has n copies of a value-initialized object
 * A value-initialized object means that the library creates a
   value-initialized element initializer for us. The value of the element
   initializer depends on the type of of the elements stored in the vector.
   If the vector holds elements of a built-in type, such as int, then the
   element initializer has a value of 0. If the elements are of a class type,
   such as std::string, then the element initializer is default initialized.
   It should again be noted that some classes require that we always supply
   an explicit initializer.
 * vector<int> v1(10); // v1 has 10 integers, each with value 0
   vector<int> v2{10}; // v2 has 1 integer with value 10
   vector<int> v3(10, 1); // v3 has 10 integers, each with value 1
   vector<int> v4{10, 1}; // v4 has 2 integers with values 10 and 1

 * Common std::vector operations :-
   (1) v.empty() // returns true if the vector v is empty, false otherwise
                 // empty() is a member function of the vector<T> class
   (2) v.size() // returns the number of elements in the vector v
                // size() is a member function of the vector<T> class;
                // the value returned is of type std::vector<T>::size_type
   (3) v.push_back(t) // adds an element with the value t to the end of the
                      // vector v
   (4) v[n] // returns the element at the index n in the vector v (technically a
            // reference to the element at the index n)
   (5) v1 = v2 // replaces the elements in the vector v1 with a copy of the
               // elements in the vector v2
   (6) v1 = {a, b, c, ...} // replaces the elements in the vector v1 with a copy
                           // of the elements in the comma-separated list
   (7) v1 == v2 // the vectors v1 and v2 are equal if they are the same length
       v1 != v2 // and contain the same elements
 * <, <=, > and >= comparisons use dictionary ordering.
   [We can compare two vectors only if we can compare the elements in those
    vectors, i.e. if we use a vector of a user-defined class in which the
    comparison operations are not defined, then we cannot compare two such
    vectors]

 * The range-based for statement can be used to process every element in an
   std::vector as well.
 * The body of a range-based for must not change the size of the container
   (or std::string) over which it is iterating.
   For eg., the body of a range-based for must not add elements to an
   std::vector.

 * The subscript operator ([]) takes an std::vector<T>::size_type value (called
   the index/subscript) when used with std::vector's. It denotes the index of
   the element we want to access and technically returns a reference to the
   element at the given index.
   For eg., int i = v[3]; copies the value of v[3] into i, whereas
   int& i = v[3]; binds i to v[3].
   [Here, 3 is implicitly converted from int to std::vector<T>::size_type]
   [Thus, generally, it can also be said that a variable returns a reference to
    that object. For eg., in the case of int j = i;, the reference returned by i
    is simply used to copy the contents of i into j, but in the case of
    int& j = i;, the reference returned by i is used to bind the name 'j' to
    the object designated by the name 'i'.]
 * std::vector indices begin at 0 and go upto (v.size() - 1).
   The result of using an out of range index is that undefined behaviour gets
   invoked. By implication, subscripting an empty vector invokes undefined
   behaviour.
   To avoid such issues, the range-based for statement is generally used to
   process elements in a vector.


 * The elements of an std::vector (of type other than bool) are stored
   contiguously in memory (heap, generally). bool is an exception because
   std::vector<bool> uses only one bit per bool. Thus, although it does have
   contiguous memory, it can't be used as a bool* (this is widely considered to
   be a false optimization and a mistake on the part of C++ developers).
 * For eg., in the case of std::vector<int>, each int object is stored one after
   another in memory (heap, generally), as an int object has a fixed size.
 * If there is no contiguous memory available for a push_back() operation, an
   std::vector reallocates itself, just like realloc() in C. It should be noted
   that in such a case, all the previously saved pointers (and iterators,
   discussed below) will become invalidated.
 * For std::vector's such as std::vector<std::string>, the size of the string
   belonging to an std::string object is not fixed. Thus, 'contiguity' in this
   case doesn't mean that the first character of the second string is stored
   immediately after the last character of the first string, and so on, but
   instead it means that the std::vector of std::string's will store each
   std::string object contiguously in memory (heap, generally), where an
   std::string object consists of a char* to the actual string stored elsewhere
   in memory (heap, generally), alongwith some extra information like the size
   of the actual string, etc. The original std::vector object will be stored in
   stack (generally), consisting of various data members explained below.
   This is similar to how dynamic multidimensional arrays are created in C by
   using malloc, where, for eg., a 2-D array (sort of) can be dynamically
   created by allocating a malloced block of pointers to the starting addresses
   of the rows.
   For eg., int** p = malloc(3 * sizeof (int*));
            for (int i = 0; i < 3; i++)
                p[i] = malloc(10 * sizeof (int));
   Here, the object named 'p' is stored in stack, generally. This object p
   contains the address of the first element of a dynamic array stored in heap,
   generally, whose elements are objects storing the addresses of the first
   elements of dynamic arrays of int's stored in heap, generally.
 * Similar to the meaning of contiguity in the case of std::vector<std::string>,
   an std::vector of std::vectors also contains std::vector objects stored
   contiguously in the memory (heap, generally), where an std::vector object
   contains a pointer to the actual vector stored elsewhere in memory (heap,
   generally), alongwith some extra information. The original std::vector object
   is stored in stack, generally.

 * Thus, it should be noted that when an std::string object is created, such as
   std::string str;, 'str' becomes the name of a fixed-size std::string object
   stored in memory (stack, generally) with several data members. The first data
   member, p, is a pointer to the first character in a dynamically allocated
   array of characters in memory (heap, generally). The second data member,
   length, contains the length of the string. The third data member, capacity,
   contains the number of valid characters that may currently be stored in the
   array pointed to by p. When this capacity is exhausted and more is needed, it
   is automatically expanded by the object (reallocating its storage space).
   [One thing to note is that most modern std::string implementations save very
    small strings directly on the stack in a statically sized char array instead
    of using dynamic heap storage.
    For eg., on this system, if the length of a string is less than 16, then it
    is stored directly inside the string object (using a union).]
 * Similar logic is applicable for std::vector objects, i.e. when an std::vector
   object is created, such as std::vector<int> vec;, 'vec' becomes the name of a
   fixed-size std::vector object stored in memory (stack, generally) with
   several data members, such as a pointer to a dynamically allocated array of
   int's in memory (heap, generally), plus some extra variables to keep track of
   the size and capacity of the vector.


 * Additional std::string and std::vector operations will be discussed later.


 * Although we can use subscripts / pointers / range-based for statements to
   access the characters of an std::string or the elements of an std::vector,
   there is a more general mechanism, known as 'iterators', that we can use for
   the same purpose.
 * As stated above, subscripting an std::string/std::vector needs to be done
   carefully to avoid undefined behaviour. So, subscripting is the least
   preferable option to access the characters of an std::string or the elements
   of an std::vector. Moreover, in addition to std::vector, the standard library
   defines several other kinds of containers. All of the library containers have
   iterators, but only a few of them support subscripting.
   [The std::string class also supports iterators, even though std::string's
    aren't containers]
 * Moving on, we have the option of using pointers to iterate over std::string's
   and std::vector's.
   For eg., in arrays, we can use subscripting like this -
   for (int i = 0; i < size; i++)
       std::cout << arr[i];
   We can also use pointers like this -
   while (start < end)
   {
       std::cout << *(start);
       (start)++;
   }
   given that 'start' initially points to the first element of the array and
   'end' points to the location 'one past the end of the array', since it is
   guaranteed that the address one past the end element of an array is valid.
   [As always, the value at this address should not be accessed]
   This approach is again limited in some respects as this relies on the fact
   that the consecutive elements are stored contiguously in memory.
   Even though the elements of std::string's and std::vector's (except of type
   bool) are guaranteed to be stored contiguously in memory, the same cannot be
   said for the elements of other containers such as std::list, which is a
   linked list.
 * As another alternative, we have the option to use range-based for statements.
   When we have to process every element sequentially, using a range-based for
   statement is the preferred choice, as it leads to more legible code.
   But, in a few cases, we may need iterators, such as when we need to jump
   ahead and back while iterating. In such cases, a range-based for statement
   won't work.
 * So, iterators and range-based for statements are the only ways to iterate
   over most containers. Hence, many programmers use them even with
   std::string's and std::vector's (where other options are available) just to
   get themselves into the proper mindset.

 * Like pointers, iterators give us indirect access to objects.
   We can use an iterator to fetch an element and iterators have operations to
   move from one element to another.
   As with pointers, an iterator may be valid or invalid.
   A valid iterator either denotes an element or denotes a positon one past
   the last element in a container (or std::string).
   All other iterator values are invalid.
 * Unlike pointers, we do not use the address-of operator to obtain an iterator.
   Instead, types that support iterators have member functions that return
   iterators, such as begin() and end().
 * auto begin = v.begin(), end = v.end();
   Here, begin becomes an iterator that denotes the first element, if there is
   one, and end becomes an iterator that is positioned one past the last element
   of the container (or std::string).
   If the container (or std::string) is empty, then begin becomes the same
   iterator as end, i.e. the 'off-the-end iterator'.
 * In general, we do not know, or care about, the precise type that an iterator
   has. Hence, we generally use the auto type specifier for iterators.
   Like with size_type, the library types that support iterators define the
   iterator type like std::string::iterator, std::string::const_iterator,
   std::vector<int>::iterator, std::vector<int>::const_iterator, etc.
   Like with pointers, if an std::string or an std::vector is const, we can use
   only its const_iterator type, but if an std::string or an std::vector is
   non-const, we may use either iterator or const_iterator.
   If the object is const, begin() and end() return a const_iterator. If the
   object is non-const, begin() and end() return an iterator.
   To get the const_iterator even when the object is non-const, we may use
   the members cbegin() and cend().
 * Iterator operations :-
   (1) *(iter) - returns the element denoted by the iterator iter (technically a
                 reference to the element denoted by the iterator iter)
   (2) iter->mem - dereferences iter and fetches the member named mem from the
                   underlying element; equivalent to (*(iter)).mem
   (3) (iter)++ - increments iter to refer to the next element
   (4) (iter)-- - decrements iter to refer to the previous element
   (5) iter_1 == iter_2 - compares two iterators for equality/inequality;
       iter_1 != iter_2   (two iterators are equal if they denote the same
                           element or if they are both the off-the-end iterator)
 * Like with pointers, dereferencing an invalid iterator or an off-the-end
   iterator invokes undefined behaviour.
 * Since iterators for many containers don't support <, <=, > and >=, we use !=
   to check whether we have reached the end of a container (or string) when
   iterating using iterators, instead of <.
 * Additional iterator operations supported by std::string's/std::vector's :-
   (1) iter + n - yields an iterator n elements forward
   (2) iter - n - yields an iterator n elements backward
   (3) iter += n - equivalent to iter = (iter + n)
   (4) iter -+ n - equivalent to iter = (iter - n)
   (5) iter_1 - iter 2 - yields the number that when added to iter_2 yields
                         iter_1; iter_1 and iter_2 must denote elements in,
                         or one past the end of, the same container
                         (or std::string); the result is of type
                         std::string::difference_type or
                         std::vector<T>::difference_type, etc. (signed integer)
   (6) <, <=, > and >= - again, the iterators must denote elements in, or one
                         past the end of, the same container (or std::string)
 * For eg., to get the middle element of a container which supports these
   additional operations, or an std::string, using iterators, we may use
   auto mid = begin + ((end - begin) / 2);

 * When used by themselves in a statement, i++ and ++i have the same effect,
   i.e. the same effect as i = (i + 1);
   But, ++i is generally faster than i++, because, generally, the pre-increment
   form first increments the value and then returns it, while the
   post-increment form is generally implemented in terms of pre-increment with
   an extra copy, i.e. the post-increment form increments the result first but
   returns the value prior to incrementation (i.e. the incrementation happens as
   early as the compiler likes, as long as it is ensured that the value prior to
   incrementation is returned).
 * In some cases, for ++i, the incrementation doesn't always need to happen
   before the incremented value is returned, i.e. the compiler can store the
   return value of (i + 1) in a register and actually increment i later, but
   this isn't how ++i is implemented in most implementations.
 * For fundamental types, there is no significant extra cost for i++, but for
   things like iterators, it requires creating a temporary copy to hold the
   non-incremented iterator value, in order to be later returned.
   However, most compilers can optimize out the fact that this temporary copy
   isn't going to be used, and thus can eliminate the need to create this
   copy, making i++ the same as ++i when used by themselves in a statement.


 * Iteration using 'range-based for' must not change the size of the container
   (or std::string) being iterated over. This is because upon adding/removing
   elements, the value of a.end() might get invalidated, among other things.
   If this happens, undefined behaviour gets invoked.
 * A range-based for is basically equivalent to
   for (auto begin = a.begin(), end = a.end(); begin != end; (begin)++)

 * Although we may change the size of the container (or std::string) being
   iterated over when iterating using 'iterators', this should be done very
   carefully.
   This is because code that adds or removes elements to a sequence can
   invalidate iterators.
   Thus, we need to ensure that the iterators are repositioned, as appropriate,
   after each operation that changes the sequence.


 * C++ lets us define what operators mean when applied to objects of class type.
   This is known as 'operator overloading'.
   However, the number of operands and the precedence & the associativity of the
   operators cannot be changed.
 * For eg., the array subscripting operation arr[n] is equivalent to
   *(&(arr[0]) + n). But, when the subscript operator is applied to an
   std::string/std::vector<T> object, then the resulting operation isn't
   equivalent to *(&(a[0]) + n), as the name 'a' only designates the respective
   std::string/std::vector<T> object, and not the actual string/vector stored
   elsewhere in memory.
   Thus, in this case, the subscript operator [] has a different meaning, which
   is defined as part of the class definition.
 * Similarly, the bitwise shift operators >> and << when used with istream and
   ostream objects have a different meaning.

 * Operator overloading is used with iterators as well.
 * An iterator can be thought of as a metaphor of a pointer (that we can
   increment, dereference, etc.).
   For std::string and some containers such as std::vector, it may be possible
   that an implementation simply uses a pointer (or a class with a pointer as a
   data member) to implement an iterator.
   But, for other containers such as std::list, implementing an iterator is
   usually more involved than using pointers, as objects of an std::list aren't
   stored contiguously in memory.
 * In any case, the concept of iterators was introduced to get a uniform way of
   interacting with std::string's and containers such as std::vector and
   std::list without bothering about the exact implementation details of these
   data structures.


 * Array (static) is a compound type.
   Like std::vector's, static arrays are containers of unnamed objects of a
   single type that we access by position.
   Unlike std::vector's, static arrays have fixed size.
 * The number of elements in a static array is a part of the array's type, and
   as a result, the dimension must be known at compile time, which means that
   the dimension must be a constant expression. (VLA's aren't allowed in C++)
 * By default, elements in a static array are default initialized.
   For eg., a default-initialized static array of a built-in type that is
   defined inside a function has garbage/undefined values.
 * Like with std::vector's, when we define a static array, we must specify a
   type for the array. We cannot let auto to deduce the type of an std::vector
   or a static array from a list of initializers.
 * As with vectors, static arrays hold objects. Thus, there are no arrays of
   references.
 * int a[] = {0, 1, 2}; // dimension may be omitted
   int b[4] = {1, 2}; // b[2] and b[3] are value-initialized to 0
   string c[3] = {"hello", "world"}; // c[2] is the empty string
   double d[2] = {1.2, 3.4, 5.6}; // error - too many initializers
   char e[] = {'k', 'u', 's', 'h'};
 * When static char arrays are initialized using string literals, the
   terminating null character is copied into the array along with the characters
   in the literal.
 * We cannot initialize a static array as a copy of another array, not is it
   legal to assign one static array to another.
 * int* p[10]; // p is a 10-element array of pointers to int
   int& r[10]; // error, array of references cannot be created
   int (* p)[10]; // p can point to a 10-element array of int's
   int arr[10];
   int (& r)[10] = arr; // r refers to a 10-element array of int's
   [Note that arr doesn't decay to a pointer in this case]
 * A range-based for statement can be used to access the elements of a static
   array.
 * A variable/value that subscripts a static array should have type size_t,
   defined in the cstddef header. size_t is some unsigned integer type.
 * As with std::string's and std::vector's, subscripting static arrays should be
   done carefully to avoid undefined behaviours.

 * Strictly speaking, there is no such thing as a multidimensional static array
   in C/C++. Whay is commonly thought of as a multidimensional array is in fact
   an array of arrays, and so on.
   [Same logic as C applies to C++ as well regarding multidimensional arrays]

 * In C++, static arrays decay to pointers in most contexts, just like in C.
   In C, the exceptions to this decay are when the array expression appears as
   an operand of either the &, the sizeof or the alignof operators, or when it
   is a string literal being used as an initializer in a definition.
   In C++, a few more exceptions are applicable, such as when an array is passed
   by reference or assigned to a reference variable, used with decltype, used as
   an operand of typeid, etc.
 * For eg., int a[10]; auto b(a); makes the type of b int*, not int[10].
   But, decltype(a) b; makes the type of b int[10].

 * Pointers to static array elements support the same operations as iterators on
   std::string's and std::vector's.
   These operations have the same meaning when applied to pointers that point to
   elements in the same array as they do when applied to iterators.
   Using pointer arithemtic on pointers pointing to different objects causes
   undefined behaviour in most cases.
   For eg., int a, b; int* p = &a; int* q = &b; int c = p - q;
 * The result of subtracting two pointers pointing to the elements in the same
   array is a type named ptrdiff_t, defined in the cstddef header. Because
   subtraction might yield a negative value, ptrdiff_t is some signed integer
   type.
   [Same logic as C applies to C++ as well regarding pointers]
 * Two functions begin() and end() are defined for static arrays to get the
   first and off-the-end addresses of an array.
   For eg., int* begin = std::begin(arr); int* end = std::end(arr);
   [begin() and end() are examples of function templates, which is why passing
    the size of the array is not required]
 * begin() and end() also work with types that do have .begin() and .end()
   member functions.
   Thus, even though begin() and end() might seem like an overkill for static
   arrays (as we can simply use pointer arithmetic to get the first and the
   off-the-end addresses of an array), the same code can be used to traverse an
   std::vector or an std::list.
 * a[4] == *(a + 4), a[3][2] == *(*(a + 3) + 2), and so on.
 * Subscripts and pointer notation can both be used for pointers as well as
   static arrays.
   One distinction is that when the subscript operator is used with pointers,
   it can also take negative values.
   For eg., int a[10]; int* p = a; p += 4; p[-2] = 3;
   This is because once a static array is defined, the array name cannot be used
   to designate any other object. But, pointers can be made to point to other
   objects of the same type. So, when the subscript operator is used with
   pointers, the index can be a signed integer.

 * Although C++ supports C-style strings, they should not be used by C++
   programs, as they are a rich source of bugs and much harder to use than
   C++ library strings.
   In addition to being safer, C++ library strings are also much more efficient
   than C-style strings in most cases.
 * We can use a null-terminated char array (i.e. a C-style string) anywhere that
   we can use a string literal in C++, such as in initializing / assigning to
   a library string object, in concatenation, etc.
 * The std::string member function named c_str() returns a pointer to the
   beginning of a null-terminated char array that holds the same data as the
   characters in the string object.
   But, the array returned by c_str() isn't guaranteed to be valid indefinitely.
   Thus, is a program needs continued access to the contents of that array, then
   the program must copy the array returned by c_str().

 * We can use arrays to initialize vectors of the same type.
   For eg., vector<int> v(begin(arr), end(arr));
            vector<int> v(arr + 2, arr + 5);

 * Thus, arrays and pointers are error-prone, as they are used for low-level
   manipulations and it is easy to make book-keeping mistakes.
   Modern C++ programs should use std::vector's, iterators and std::string's,
   rather than arrays, pointers and C-style strings.

 * End of Trivia */
