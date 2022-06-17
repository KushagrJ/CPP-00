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


 * Every expression in C++ is either an 'lvalue' or an 'rvalue'.
 * An lvalue expression yields an object or a function. However, some lvalues,
   such as const objects, may not be the left-hand operand of an assignment.
   Moreover, some expressions yield objects but return them as rvalues.
 * Roughly speaking, when we use an object as an rvalue, we use the object's
   value (its contents), whereas when we use an object as an lvalue, we use the
   object's identity (its location in memory).
 * An lvalue can be used when an rvalue is required, but an rvalue cannot be
   used when an lvalue is required.
 * For eg., assignment requires a non-const lvalue as its left-hand operand and
   returns its left-hand operand as an lvalue, the address-of operator requires
   an lvalue operand and returns a pointer to its operand as an rvalue, the
   dereference and subscript operators (overloaded or otherwise) yield lvalues,
   and so on.

 * An expression with two or more operators is a 'compound' expression.
   Evaluating a compound expression involves grouping the operands to the
   operators.
   'Precedence' and 'associativity' determine how operands are grouped.
   These rules can be overridden by parenthesizing compound expressions to force
   a particular grouping.
 * For eg., 3 + 4 * 5 is grouped as (3 + (4 * 5))
            20 - 15 - 3 is grouped as ((20 - 15) - 3)
            6 + 3 * 4 / 2 + 2 is grouped as ((6 + ((3 * 4) / 2)) + 2)

 * The 'order of evaluation' of expressions is largely unspecified, like in C.
   For eg., i = f1() + f2() // it is only guaranteed that the calls to f1() and
                            // f2() will occur before the addition; however, it
                            // isn't guaranteed whether f1() will be called
                            // before f2(), or vice-versa
            1 + 2 + 3 * 4 // (1 + 2) may be evaluated before (3 * 4)

 * Like in C, std::cout << i << " " << i++ << std::endl; invokes undefined
   behaviour, among many other examples.

 * &&, ||, ? : and , guarantee a left-to-right order of evaluation for their
   operands, like in C.
   [&& and || use short-circuit evaluation, i.e. the right-hand operand is
    evaluated only if the left-hand operand evaluates to true (for &&) or
    false (for ||)]

 * The arithmetic operators include + (unary plus), - (unary minus), *
   (multiplication), / (division), % (remainder, not modulo), + (addition) and
   - (subtraction).
 * The operands and results of these operators are rvalues.
 * The unary plus operator returns a (possibly promoted) copy of the value of
   its operand.
   For eg., if c is a char, then c returns the value of c with type char,
   whereas +c returns a copy of the value of c with type int.
 * The unary minus operator returns the result of negating a (possibly promoted)
   copy of the value of its operand.
   For eg., if b is true, then bool b2 = -b makes b2 true. This is because the
   value of b is promoted to the int value 1. That promoted value is negated,
   yielding -1. The value -1 is converted back to bool, which becomes true.

 * The logical and relational operators include ! (logical NOT), < (less than),
   <= (less than or equal to), > (greater than), >= (greater than or equal to),
   == (equal to), != (not equal to), && (logical AND) and || (logical OR).
 * The operands and results (true/false) of these operators are rvalues.

 * The assignment operators include =, +=, -+, *=, /=, %=, <<=, >>=, &=, ^=
   and |=.
 * The left-hand operand of an assignment operator must be a modifiable lvalue.
 * The result of an assignment is its left-hand operand, which is an lvalue.
   The type of the result is the type of the left-hand operand.
   If the types of the left- and right-hand operands differ, then the right-hand
   operand is converted to the type of the left-hand operand.

 * The ++ (increment) and -- (decrement) operators require lvalue operands.
 * The prefix operators return the object itself as an lvalue.
   The postfix operators return a copy of the object's original value as an
   rvalue.
 * Thus, the prefix operators should generally be preferred over the postfix
   ones. However, as described before, when the copy of the object isn't going
   to be used (for eg., when i++ is used by itself in a statement), most
   compilers can optimize out this fact, and thus can eliminate the need to
   create a copy.

 * The . (dot) and -> (arrow) operators provide for member access.
   The dot operator fetches a member from an object of class type; the arrow
   operator is defined so that ptr->mem is a synonym for (*ptr).mem for an
   object of class type.
 * The dot operator yields an lvalue if the object from which the member is
   fetched is an lvalue. Otherwise, the result is an rvalue.
 * The arrow operator requires a pointer operand and yields an lvalue.

 * The ? : (conditional) operator lets us embed simple if-else logic inside an
   expression.
 * The result of the conditional operator is an lvalue if both expressions are
   lvalues or if they convert to a common lvalue type. Otherwise, the result is
   an rvalue.

 * The bitwise operators work on integer types and include ~ (bitwise NOT),
   << (left shift), >> (right shift), & (bitwise AND), ^ (bitwise XOR) and
   | (bitwise OR).
 * The way in which the 'sign bit' of signed types is handled is
   implementation-defined. Moreover, doing a left shift that changes the value
   of the sign bit is undefined.
   Thus, it is strongly recommended to use unsigned types with the bitwise
   operators.

 * The sizeof operator returns the size, in bytes, of an expression or a type
   name.

 * The comma operator takes two operands, which it evaluates from left to right.
 * The left-hand expression is evaluated and its result is discarded.
 * The result of a comma expression is the value of its right-hand expression.
   The result is an lvalue if the right-hand operand is an lvalue.


 * Implicit type conversions -

   The compiler automatically converts operands in the following circumstances:
   # In most expressions, values of integral types smaller than int are first
     promoted to an appropriate larger integral type.
   # In conditions, non-bool expressions are converted to bool.
   # In initializations, the initializer is converted to the type of the
     variable; in assignments, the right-hand operand is converted to the type
     of the left-hand operand.
   # In arithmetic and relational expressions with operands of mixed types, the
     types are converted to a common type.
   # Conversions also happen during function calls.

   (1) The arithmetic conversions -
       # The rules define a hierarchy of type conversions in which operands to
         an operator are converted to the widest type. For eg., if one operand
         is of type long double, then the other operand is converted to type
         long double regardless of what the second type is. More generally, in
         expressions that mix floating-point and integral values, the integral
         value is converted to an appropriate floating-point type.
       # The types bool, char, signed char, unsigned char, short and unsigned
         short are promoted (when used in expressions) to int if all possible
         values of that type fit in an int. Otherwise, the value is promoted to
         unsigned int.
         For eg., auto i = 'a'; makes i a char, whereas auto i = +'a'; makes i
         an int.
         The larger char types (wchar_t, char16_t and char32_t) are promoted to
         the smallest type of int, unsigned int, long, unsigned long, long long
         or unsigned long long in which all possible values of that character
         type fit.
       # If the operands of an operator have differing types, those operands are
         ordinarily converted to a common type. If any operand is an unsigned
         type, the type to which the operands are converted depends on the
         relative sizes of the integral types on the machine.
         As usual, integral promotions happen first. If the resulting type(s)
         match, no further conversion is needed. If both (possibly promoted)
         operands have the same signedness, then the operand with the smaller
         type is converted to the larger type.
         When the signedness differs and the type of the unsigned operand is the
         same as or larger than that of the signed operand, the signed operand
         is converted to unsigned.
         For eg., given an unsigned int and an int, the int is converted to
         unsigned int. If the int has a negative value, the result will be
         converted as described before (i.e the result will be the remaining
         part of the value modulo the number of values the target unsigned type
         can hold).
         The remaining case is when the signed operand has a larger type than
         the unsigned operand. In this case, the result is machine dependent. If
         all values in the unsigned type fit in the larger type, then the
         unsigned operand is converted to the signed type. If the values don’t
         fit, then the signed operand is converted to the unsigned type. For
         eg., if the operands are long and unsigned int, and int and long have
         the same size, the long will be converted to unsigned int. If the long
         type has more bits, then the unsigned int will be converted to long.

   (2) The array to pointer conversions (decays).
       [The exceptions to these have been discussed before]

   (3) Some other pointer conversions -
       # The integral value 0 and the literal nullptr can be converted to any
         pointer type.
       # A pointer to any non-const type can be converted to a void*.
       # A pointer to any type can be converted to a const void*.

   (4) The conversions to bool.

   (5) The conversions to const (for pointers and references).

   (6) The conversions defined by class types.


 * Explicit type conversions -

   A 'cast' is used to request an explicit type conversion.
   Although necessary at times, casts are inherently dangerous constructs.

   (1) static_cast<T> (expression) -
       Any well-defined type conversion, other than those involving low-level
       const, can be requested using a static_cast.
       A static_cast is often useful when a larger arithmetic type is assigned
       to a smaller type. The cast informs both the reader of the program and
       the compiler that we are aware of and are not concerned about the
       potential loss of precision.
       A static_cast is also useful to perform a conversion that the compiler
       will not generate automatically. For eg., converting void* to T*.
       [As always, we must be certain that the type to which we cast the pointer
        is the actual type of that pointer, as if the types don't match, then
        undefined behaviour gets invoked.
        This is an example of the violation of the 'strict aliasing rule'.
        For eg., if we have an int* pointing to some memory location containing
        an int and then we use a float* to that memory location and use it as a
        float, then undefined behaviour gets invoked.
        The exception to this rule is a char*, which is allowed to point to any
        type.]

   (2) dynamic_cast<T> (expression) -
       To be discussed later.

   (3) const_cast<T> (expression) -
       A const_cast changes only a low-level const in its operand.
       For eg., const char* pc = "hello";
                char* p = const_cast<char*> (pc);
                Here, writing through p invokes undefined behaviour.
       If the object was originally not a const, then using a const_cast to
       obtain write access is legal.
       But, using a const_cast in order to write to a const object, as in the
       example above, is illegal.
       A const_cast cannot be used to change the type of an expression.
       For eg., int x; float y = const_cast<float> (x); is an error.
       A const_cast is most useful in the context of overloaded functions, which
       are described later.

   (4) reinterpret_cast<T> (expression) -
       A reinterpret_cast generally performs a reinterpretation of the bit
       pattern of its operands.
       A reinterpret_cast is inherently machine-dependent.
       Safely using reinterpret_cast's requires completely understanding the
       types involved as well as the details of how the compiler implements the
       cast.

   (5) Old-style casts -
       type (expression) and (type) expression are examples of old-style casts.
       Depending on the types involved, an old-style cast has the same behaviour
       as a static_cast, a const_cast or a reinterpret_cast.


 * See https://en.cppreference.com/w/cpp/language/operator_precedence


 * 'Simple statements' end with a semicolon.
 * An expression becomes an 'expression statement' when it is followed by a
   semicolon. Expression statements cause the expression to be evaluated and its
   final result to be discarded.
   For eg., x + y; // useless expression statement; the value of x + y is
                   // discarded
            x = 5; // useful expression statement; 5 is first assigned to x as
                   // part of the evaluation of the expression, and the final
                   // result of the expression, i.e. 5, is now discarded
   Commonly, an expression statement contains an expression that has a 'side
   effect', such as assigning a value to a variable, or printing something.
 * A 'null statement' is a single semicolon.
   Such usage is most common when a loop's work can be done within its
   condition.
   For eg., while ((std::cin >> x) && (x != num))
                ;
   Alternatively, a 'continue' statement may also be used in such cases, i.e.
            while ((std::cin >> x) && (x != num))
                continue;
   In many cases, semicolons that might appear illegal are nothing more than
   null statements.
   For eg., v = v1 + v2;; // ok; the 2nd semicolon is a useless null statement

 * A 'compound statement', usually referred to as a 'block', is a (possibly
   empty) sequence of statements (simple, compound, etc.) and
   definitions/declarations surrounded by a pair of curly braces.
 * An empty block, i.e. a pair of curly braces with no statements, is equivalent
   to a null statement.
 * Compound statements don't end with a semicolon.
 * A block is a scope, and thus the names introduced inside a block are
   accessible only in that block, and in blocks nested inside that block.
   Names are visible from where they are introducesd until the end of the
   immediately enclosing block.
 * Compound statements are used when the language requires a single statement
   (simple, compound, etc.), for eg., if-else, while, for, etc., but the logic
   of the program needs multiple statements.

 * Variables can be defined inside the control structure of the if, if-else,
   switch, while and for statements.
   Variables defined in the control structure are visible only within that
   statement and are out of scope after the statement ends.
   For eg., if (int i = get_num())
                ...
            else
                ...
            switch (int i = get_num())
                ...
            while (int i = get_num())
                ...
            for (int i = get_num(); int j = get_num(); i++)
                ...

 * 'Conditional statements' include the if statement, the if-else statement, and
   the switch statement.
 * An if statement conditionally executes another statement based on whether a
   specified condition is true.
   The syntactic form of an if statement is
   if (condition)
       statement

 * End of Trivia */
