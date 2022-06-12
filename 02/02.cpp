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


 * Arithmetic operators include + (unary plus), - (unary minus), *
   (multiplication), / (division), % (remainder, not modulo), + (addition) and
   - (subtraction).
 * The operands and results of these operators are rvalues.
 * The unary plus operator returns a (possibly promoted) copy of the value of
   its operand.
   For eg., if c is a char, then c returns a copy of the value of c with type
   char, whereas +c returns a copy of the value of c with type int.
 * The unary minus operator returns the result of negating a (possibly promoted)
   copy of the value of its operand.
   For eg., if b is true, then bool b2 = -b makes b2 true. This is because the
   value of b is promoted to the int value 1. That promoted value is negated,
   yielding -1. The value -1 is converted back to bool, which becomes true.

 * End of Trivia */
