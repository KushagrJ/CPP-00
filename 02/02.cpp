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


 * Variables can be defined inside the control structures of the if, if-else,
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

 * An if/if-else statement conditionally executes another statement based on
   whether a specified condition is true.

 * An if statement has the following syntactic form :-
   if (condition)
       statement // simple, compound, etc.
   [condition must be an initialized variable definition or an expression of a
    type convertible to bool.
    statement is executed if condition evaluates to true.]

 * An if-else statement has the following syntactic form :-
   if (condition)
       statement1 // simple, compound, etc.
   else
       statement2 // simple, compound, etc.
   [condition must be an initialized variable definition or an expression of a
    type convertible to bool.
    statement1 is executed if condition evaluates to true, whereas statement2 is
    executed if condition evaluates to false.]

 * The 'dangling else' ambiguity is resolved by matching each else with the
   closest preceding unmatched if within the same scope.
   For eg., 01. int x = 0, y = 0;
            02. if (x == 0)
            03.     if (y == 0)
            04.         std::cout << "0\n";
            05.     else
            06.         std::cout << "1\n";
            07. else
            08.     if (y == 0)
            09.         std::cout << "2\n";
            10.     else
            11.         std::cout << "3\n";
   Here, lines 03-06 form a single statement which is part of line 02's if,
   whereas lines 08-11 form a single statement which is part of line 07's else.
   It is generally advised to use braces in such cases in order to improve
   readability and to avoid ambiguity.
   For eg., 01. int x = 0, y = 0;
            02. if (x == 0)
            03.     if (y == 0)
            04.         std::cout << "0\n";
            05. else
            06.     if (y == 0)
            07.         std::cout << "2\n";
            08.     else
            09.         std::cout << "3\n";
   Here, line 05's else is matched with line 03's if, making the program
   logically erroneous, as the indendation suggests that the programmer intended
   for line 05's else to be matched with line 02's if.
   The corrected version is as follows :-
            01. int x = 0, y = 0;
            02.
            03. if (x == 0)
            04. {
            05.     if (y == 0)
            06.         std::cout << "0\n";
            07. }
            08.
            09. else
            10. {
            11.     if (y == 0)
            12.         std::cout << "2\n";
            13.     else
            14.         std::cout << "3\n";
            15. }
   Here, line 09's else is matched with line 03's if (as intended) because line
   05's if is not in the same scope as line 09's else.
   [Lines 04-07 form a compound statement consisting of a single if statement,
    and lines 10-15 form a compound statement consisting of a single if-else
    statement]

 * Thinking of 'else if' as a single keyword improves readability for
   programmers, even though there is no such thing as an 'else if' in C/C++,
   unlike the 'elif' keyword in Python.
   This means that
       if (condition1)
           statement1
       else if (condition2)
           statement2
       else if (condition3)
           statement3
       else if ...
           ...
       else
           statement
   is seen by the compiler as
       if (condition1)
           statement1
       else
           if (condition2)
               statement2
           else
               if (condition3)
                   statement3
               else
                   if ...
                       ...
                   else
                       statement

 * A switch statement has the following syntactic form :-
   switch (foo)
   {
       case label1:
           statement(s)
           break;
       case label2:
           statement(s)
           break;
       case label3:
           statement(s)
           break;
       ...
           ...
       default:
           statement(s)
   }
   [foo must be an initialized variable definition or an expression of a type
    convertible to integral type.
    foo is evaluated and the result is converted to integral type.
    Then, the result of foo is compared with the value associated with each case
    label.
    Each case label must be an integral constant expression (which, as opposed
    to in C, also includes const integral variables initialized using an
    integral constant expression).
    Also, it is an error for any two case labels to have the same value.
    For eg., switch (x) {case 65: foo; case 'A': bar;}.
    If the result of foo matches the value of a case label, then execution
    begins with the first statement following that case label.
    If no case label matches the the result of foo, then execution begins with
    the first statement following the default case label, if there is one.
   [Without break;, every statement starting with the first statement of the
    matched case label to the end of the switch statement would be executed.
    It should be noted that break; works with loops and switch, but continue;
    works only with loops. Thus, if continue; is used with a switch which is
    inside a loop, then that continue; would be part of the loop, i.e. it will
    cause the program to skip over the rest of the loop, including the other
    parts of the switch statement.]
   [Multiple labels can be used for the same case like this -
    case label1 :
    case label2 :
        statement(s)
        break;
    Here, due to the absence of break; in case label1, the program would
    process the statement(s) of case label2 if label1 is matched. In essence,
    both the labels would refer to the same statement(s).]
   [Since execution in a switch statement can jump across case labels, therefore
    when execution jumps to a particular case, any code that occurred inside the
    switch before that label is ignored.
    Thus, initializing variables inside switch needs to be done using compound
    statements.
    For eg., switch (c)
             {
                 case true:
                     int x; // ok, as x is not initialized, and only defined
                     int y = 1; // error, as other cases may use y, bypassing
                                // this initialization
                     break;
                 default:
                     x = 10; // ok
                     std::cout << y << '\n';
             }
    Not using the variable initialized in one case in another case doesn't make
    the code legal, i.e. in the above example, not using the value of y in
    default doesn't make the code legal.
    For eg., the following code is still erroneous :-
             switch (c)
             {
                 case true:
                     int y = 1;
                     std::cout << y << '\n';
                     break;
                 default:
                     std::cout << "hello\n";
             }
    In order to initialize a variable inside a switch statement, a compound
    statement needs to be used, in order to limit the scope of the initialized
    variable.
    For eg., switch (c)
             {
                 case true:
                     {
                         int y = 1;
                         std::cout << y << '\n';
                     }
                     break;
                 default:
                     std::cout << "hello\n";
             }
    Also see https://stackoverflow.com/a/19830820]


 * 'Iterative statements', commonly called loops, include the while statement,
   the for statement and the do-while statement.
   Iterative statements are used to repeatedly execute other statements, based
   on some criteria.

 * A while statement has the following syntactic form :-
   while (condition)
       statement // simple, compound, etc.
   [condition must be an initialized variable definition or an expression of a
    type convertible to bool.
    condition cannot be empty.
    statement is executed as long as condition evaluates to true.
    Variables defined in a while condition or body are created and destroyed on
    each iteration.]

 * A for statement has the following syntactic form :-
   for (init-statement condition; expression)
       statement // simple, compound, etc.
   [init-statement must be either a definition/declaration statement, an
    expression statement or a null statement. Each of these statements ends with
    a semicolon.
    condition must be an initialized variable definition or an expression of a
    type convertible to bool.
    condition can be empty, which translates to true.
    statement is executed as long as condition evaluates to true.
    Variables defined in a for condition or body are created and destroyed on
    each iteration.
    expression is evaluated immediately after statement is executed.
    When condition evaluates to false, statement is not executed and
    consequently, expression is not evaluated.
    expression can also be empty.]

 * A range-based for statement can be used to iterate over the elements of a
   sequence, and has the following syntactic form :-
   for (definition : expression)
       statement // simple, compound, etc.
   [definition defines a variable. It must be possible to convert each element
    of the sequence to the variable's type. The easiest way to ensure that the
    types match is to use the auto type specifier.
    expression must be a sequence, i.e. either be a braced initializer list, an
    array, or an object of a type such as std::vector or std::string that has
    begin and end member functions that return iterators.]
   [For eg., for (auto& r : v)
                 r *= 2;
    is equivalent to
             for (auto beg = v.begin(), end = v.end(); beg != end; ++(beg))
             {
                 auto& r = *(beg);
                 r *= 2;
             }
    Thus, the body of a range-based for must not change the size of the sequence
    over which it is iterating, since the value of end() is cached, and the
    value of the iterator end might get invalidated.]

 * A do-while statement has the following syntactic form :-
   do
       statement // simple, compound, etc.
   while (condition);
   [condition must be an expression of a type convertible to bool, and cannot be
    an initialized variable definition.
    condition cannot be empty.
    Regardless of the value of the condition, statement is executed at least
    once. Thereafter, statement is executed as long as condition evaluates to
    true.
    Variables defined in a do-while body are created and destroyed on each
    iteration.]


 * 'Jump statements' include the break statement, the continue statement, the
   goto statement and the return statement.

 * A break statement terminates the nearest enclosing while, do-while, for or
   switch statement.

 * A continue statement terminates the current iteration of the nearest
   enclosing loop and immediately begins the next iteration.
   In the case of a while or a do-while loop, execution continues by evaluating
   the condition. In a traditional for loop, execution continues at the
   expression inside the for header. In a range-based for loop, execution
   continues by initializing the control variable from the next element in the
   sequence.

 * A goto statement provides an unconditional jump from the goto to another
   statement in the same function and has the following syntactic form :-
   goto label;
   label: statement // simple, compound, etc.
   [label is an identifier that identifies a statement.
    Label identifiers are independent of the other identifiers. Hence, a label
    may have the same identifier as another entity in the program without
    interfering with the other uses of that identifier.
    As with a switch statement, a goto statement cannot transfer control from a
    point where an initialized variable is out of scope to a point where that
    variable is in scope.]
 * In almost all cases, using goto statements is considered to be bad practice,
   as they make programs hard to understand and hard to modify.
   But, in some very specific cases, using a goto statement can make the code
   simpler, such as when we want to get out of deeply nested loops quickly.
   Without a goto statement, getting out of deeply nested loops requires the
   usage of boolean flags in every loop and multiple break statements.


 * Add stuff from 5.6 try Blocks and Exception Handling later.

 * End of Trivia */
