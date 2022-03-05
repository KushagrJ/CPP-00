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

 * Some concepts/terms common to C and C++ may not be explained/defined here.


 * Statements normally execute sequentially. The first statement in a block is
   executed first, followed by the second, and so on.
   Programming languages also provide various flow-of-control statements that
   allow for more complicated execution paths. For eg., while, for & do while.

 * Like C, all non-zero values are considered to be true in C++.


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
   std::cin.fail() and !(std::cin) return true if the previous extraction
   failed.
   std::cin.clear() puts std::cin back into 'normal' mode.
 * A failed extraction due to invalid input causes the variable to be set to
   0, 0.0, "", or whatever value 0 converts to for that type.
 * Since an extraction may fail due to incorrect input, and not due to EOF
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

 * End of Trivia */
