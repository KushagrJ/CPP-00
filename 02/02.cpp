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


 * Built-in/fundamental/primitive types - int, char, float, etc.
   Compound types - array, pointer, reference, etc.
   Abstract data types - string, vector, linked list, stack, queue, etc.
 * Arrays are not built-in types.
   Arrays are compound types, and the term 'built-in' is an informal name for a
   fundamental type.

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


 * A 'string' is a variable-length sequence of characters. To use the string
   ADT (which is defined as a class), we must include the 'string' header.
   Because the string library is part of the standard library, the name 'string'
   is defined in the std namespace.
 * A library type is almost always more efficient to use than an equivalent
   user-defined type, because in addition to specifying the operations that the
   library types provide, the standard also imposes efbuffer

 * Common ways to initialize strings :-
   (1) string s1; // default initialization; s1 is the empty string ""
   (2) string s2 = s1; // s2 is a copy of s1
   (3) string s2(s1); // s2 is a copy of s1
   (4) string s3 = "hello"; // s3 is a copy of the string literal "hello",
                            // excluding the null character
   (5) string s3("hello"); // s3 is a copy of the string literal "hello",
                           // excluding the null character
   (6) string s4(5, 'c'); // s4 is "ccccc"
 * string s5 = string(5, 'c'); creates a temporary object (string) of the given
   size and character value and then copies that value into s5.

 * Common string operations :-
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
               // string s2
   (9) s1 == s2 // the strings s1 and s2 are equal if they are the same length
       s1 != s2 // and contain the same characters (equality is case-sensitive)
 * <, <=, > and >= comparisons are case sensitive and use dictionary ordering.

 * As explained before, is >> s is used to read input from the is stream,
   storing what is read in s, by discarding leading whitespaces and stopping at
   the first whitespace after non-whitespace characters.
   Thus, If Hello World! is given as input to an is >> s, only Hello would get
   stored in s with no extra whitespaces. The remaining part, that is one space
   character followed by World! would remain in the input buffer (or stream).
 * while (is >> s) (for eg., while (std::cin >> s)) can be used to read input
   till end-of-file.
 * The getline() function is used to read a line of input from an istream object
   into a string, consuming and excluding the terminating newline character.
   Like the extraction operator, getline() also returns its istream argument.
   So, while (getline(is, s)) (for eg., while (getline(std::cin, s))) can also
   be used to read input line by line till end-of-file.
 * A common problem with using getline() after an extraction is that when the
   extraction ends in most cases, the terminating newline character remains in
   the input buffer (or stream). The upcoming getline() sees the newline
   character, consumes it, discards it, and stores an empty string in its string
   argument.
   To resolve this issue, is.ignore() (for eg., std::cin.ignore()) can be called
   immediately before getline().

 * In std::string::size_type, the first scope operator is used because the name
   'string' is defined in the 'std' namespace, and the second scope operator
   is used because the name 'size_type' is defined in the 'string' class.
   Thus, the scope resolution operator is basically used to tell the compiler
   what 'namespace' or what 'class' something belongs to.
 * The size_type type is a companion type to the string class which makes it
   possible to use such types in a machine-independent manner. For eg., the
   size_t type in C.
   Thus, any variable used to store the result from the size() member function
   should be of type std::string::size_type.
   Using 'auto' or 'decltype' instead of writing the type of a variable would be
   easier in such situations.
 * Although the precise type of std::string::size_type varies between
   implementations, it is guaranteed that std::string:size_type is some unsigned
   integer type.

 * The string library lets us convert both character literals ('a') and string
   literals ("a") to strings. But, when we mix strings and character/string
   literals, at least one operand to each + operator must be of string type.
 * The type of a string literal is const char*, the type of a character literal
   is char and the type of a string is string.
 * For eg., string s1 = "hello", s2 = "world";
            string s3 = s1 + ", " + s2 + '\n'; // ok
            string s4 = s1 + ", "; // ok
            string s5 = "hello" + ", "; // error, no string type as an operand
                                        // to +
            string s6 = s1 + ", " + "world"; // ok, due to left to right
                                             // associativity of +
            string s7 = "hello" + ", " + s2 // error

 * End of Trivia */
