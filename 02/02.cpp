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
   library types provide, the standard also imposes efficiency requirements on
   implementors.

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
               // characters in the string s2
   (9) s1 == s2 // the strings s1 and s2 are equal if they are the same length
       s1 != s2 // and contain the same characters (equality is case-sensitive)
 * <, <=, > and >= comparisons are case sensitive and use dictionary ordering.

 * non-const std::string's are mutable, but string literals are not.

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
   ['a' + 'b' is integer arithmetic.
    "hello" + 'a' is pointer arithmetic.
    "hello" + "world" is an error.]

 * The functions prototyped in the <cctype> header file can be used to process
   characters, such as isalnum(c), isalpha(c), iscntrl(c), isdigit(c),
   isgraph(), islower(c), isprint(c), ispunct(c), isspace(c), isupper(c),
   isxdigit(c), tolower(c) and toupper(c).

 * The range-based for statement can be used to process every character in a
   string.
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
   index/subscript) when used with strings. It denotes the index of the
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
 * String indices begin at 0 and go upto (s.size() - 1).
   The result of using an out of range index is that undefined behaviour gets
   invoked. By implication, subscripting an empty string invokes undefined
   behaviour.
   To avoid such issues, the range-based for statement is generally used to
   process characters in a string.


 * A 'vector' is a variable-length sequence of objects, all of which have the
   same type. To use the vector ADT (which is defined as a class template, and
   not simply a class), we must include the 'vector' header. Because the vector
   library is part of the standard library, the name 'vector' is defined in the
   std namespace.
 * A vector is also referred to as a 'container' because it contains other
   objects.
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
            std::vector<std::vector<string>> v;
 * A container cannot hold array objects, as the type of the elements to be
   stored in a container must be both copy-able and assignable.
   Arrays are neither.
   So, unless the arrays are wrapped into structs, or unless std::array's are
   used, a vector of arrays cannot be created.

 * Common ways to initialize vectors :-
   (1) vector<T> v1; // default initialization; s1 is empty
   (2) vector<T> v2 = v1; // v2 has a copy of each element in v1
   (3) vector<T> v2(v1); // v2 has a copy of each element in v1
   (4) vector<T> v3 = {a, b, c, ...}; // v3 has as many elements as there are
                                      // initializers; elements are initialized
                                      // by corresponding initializers
   (5) vector<T> v3{a, b, c, ...}; // v3 has as many elements as there are
       [a, b, c, ... are in        // initializers; elements are initialized
        {}, and not in ()]         // by corresponding initializers
   (6) vector<T> v4(n, val); // v4 has n elements with value val
   (7) vector<T> v4(n); // v4 has n copies of a value-initialized object
 * A value-initialized object means that the library creates a
   value-initialized element initializer for us. The value of the element
   initializer depends on the type of of the elements stored in the vector.
   If the vector holds elements of a built-in type, such as int, then the
   element initializer has a value of 0. If the elements are of a class type,
   such as string, then the element initializer is default initialized.
   It should again be noted that some classes require that we always supply
   an explicit initializer.
 * vector<int> v1(10); // v1 has 10 integers, each with value 0
   vector<int> v2{10}; // v2 has 1 integer with value 10
   vector<int> v3(10, 1); // v3 has 10 integers, each with value 1
   vector<int> v4{10, 1}; // v4 has 2 integers with values 10 and 1

 * Common vector operations :-
   (1) v.empty() // returns true if the vector v is empty, false otherwise
   (2) v.size() // returns the number of elements in the vector v
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

 * The range-based for statement can be used to process every element in a
   vector as well.
 * The body of a range-based for must not change the size of the sequence over
   which it is iterating.
   For eg., the body of a range-based for must not add elements to a vector.

 * The subscript operator ([]) takes an std::vector<T>::size_type value (called
   the index/subscript) when used with vectors. It denotes the index of the
   element we want to access and technically returns a reference to the
   element at the given index.
   For eg., int i = v[3]; copies the value of v[3] into i, whereas
   int& i = v[3]; binds i to v[3].
   [Here, 3 is implicitly converted from int to std::vector<T>::size_type]
   [Thus, generally, it can also be said that a variable returns a reference to
    that object. For eg., in the case of int j = i;, the reference returned by i
    is simply used to copy the contents of i into j, but in the case of
    int& j = i;, the reference returned by i is used to bind the name 'j' to
    the object designated by the name 'i'.]
 * Vector indices begin at 0 and go upto (v.size() - 1).
   The result of using an out of range index is that undefined behaviour gets
   invoked. By implication, subscripting an empty vector invokes undefined
   behaviour.
   To avoid such issues, the range-based for statement is generally used to
   process elements in a vector.


 * Resume from 3.4 Introducing Iterators

 * End of Trivia */
