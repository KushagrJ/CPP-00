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
 * The type of a string literal is const char[], the type of a character literal
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
    "hello" + 'a' is pointer arithmetic, due to array ([]) to pointer (*) decay.
    "hello" + "world" is an error.]

 * In C++, arrays decay to pointers in most contexts, just like in C.
   In C, the exceptions to this decay are when the array expression appears as
   an operand of either the &, the sizeof or the alignof operators, or when it
   is a string literal being used as an initializer in a declaration.
   In C++, a few more exceptions are applicable, such as when an array is passed
   by reference.

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


 * A 'vector' is a variable-length sequence of objects (references aren't
   objects), all of which have the same type. To use the vector ADT (which is
   defined as a class template, and not simply a class), we must include the
   'vector' header. Because the vector library is part of the standard library,
   the name 'vector' is defined in the std namespace.
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

 * The elements of a vector (of type other than bool) are stored contiguously in
   memory. bool is an exception because std::vector<bool> uses only one bit per
   bool. Thus, although it does have contiguous memory, it can't be used as a
   bool* (this is widely considered to be a false optimization and a mistake on
   the part of C++ developers).
 * For eg., in std::vector<int>, each int object is stored one after another
   in memory, as an int object has a fixed size.
 * If there is no contiguous memory available for a push_back() operation, a
   vector reallocates itself, just like realloc() in C. It should be noted that
   in such a case, all the previously saved pointers (and iterators, discussed
   below) will become invalidated.
 * For vectors such as std::vector<string>, the size of each string is not
   known. Thus, 'contiguity' in this case doesn't mean that the first character
   of the second string is stored immediately after the last character of the
   first string, and so on, but instead it means that the vector of strings will
   store each string object contiguously, where a string object contains a char*
   to the actual string stored elsewhere in memory, alongwith some extra
   information like the size of the actual string, etc.
   This is similar to how dynamic multidimensional arrays are created in C by
   using malloc, where, for eg., a 2-D array (sort of) can be dynamically
   created by allocating a malloced block of pointers to the starting addresses
   of the rows.
 * Similar to the meaning of 'contiguity' in the case of std::vector<string>,
   a vector of vectors also contains vector objects stored contiguously in the
   memory, where a vector object contains a pointer to the actual vector stored
   elsewhere in memory, alongwith some extra information.

 * Thus, it should be noted that when a string object is created, such as
   std::string str;, 'str' becomes the name of a string object with several data
   members. The first data member, p, is a pointer to the first character in a
   dynamically allocated array of characters. The second data member, length,
   contains the length of the string. The third data member, capacity, contains
   the number of valid characters that may currently be stored in the array
   pointed to by p.
 * Similar logic is applicable for vector objects, i.e. when a vector object is
   created, such as std::vector<int> vec;, 'vec' becomes the name of a vector
   object with several data members, such as a pointer to a dynamically
   allocated buffer, plus some extra variables to keep track of the size and
   capacity of the vector.


 * Although we can use subscripts / pointers / range-based for statements to
   access the characters of a string or the elements of a vector, there is a
   more general mechanism, known as 'iterators', that we can use for the same
   purpose.
 * As stated above, subscripting a string/vector needs to be done carefully to
   avoid undefined behaviour. So, subscripting is the least preferable option
   to access the characters of a string or the elements of a vector.
   Moreover, in addition to vector, the standard library defines several other
   kinds of containers. All of the library containers have iterators, but only a
   few of them support subscripting.
   [The string class also supports iterators, even though strings aren't
    containers]
 * Moving on, we have the option of using pointers to iterate over strings and
   vectors.
   For eg., in arrays, we can use subscripting like this -
   for (int i = 0; i < size; i++)
       std::cout << arr[i];
   We can also use pointers like this -
   while (start < end)
   {
       std::cout << *(start);
       (start)++;
   }
   Given that 'start' initially points to the first element of the array and
   'end' points to the location 'one past the end of the array', since it is
   guaranteed that the address one past the end element of an array is valid.
   [As always, the value at this address should not be accessed]
   This approach is again limited in some respects as this relies on the fact
   that the consecutive elements are stored contiguously in memory.
   Even though the elements of strings and vectors (except of type bool) are
   guaranteed to be stored contiguously in memory, the same cannot be said for
   the elements of other containers such as std::list, which is a linked list.
 * As another alternative, we have the option to use range-based for statements.
   When we have to process every element sequentially, using a range-based for
   statement is the preferred choice, as it leads to more legible code.
   But, in a few cases, we may need iterators, such as when we need to jump
   ahead and back while iterating. In such cases, a range-based for statement
   won't work.
 * So, iterators and range-based for statements are the only way to iterate over
   most containers. Hence, many programmers use them even with strings and
   vectors (where other options are available) just to get themselves into the
   proper mindset.

 * Like pointers, iterators give us indirect access to objects.
   We can use an iterator to fetch an element and iterators have operations to
   move from one element to another.
   As with pointers, an iterator may be valid or invalid.
   A valid iterator either denotes an element or denotes a positon one past
   the last element in a container (or string).
   All other iterator values are invalid.
 * Unlike pointers, we do not use the address-of operator to obtain an iterator.
   Instead, types that support iterators have member functions that return
   iterators, such as begin() and end().
 * auto begin = v.begin(), end = v.end();
   Here, begin becomes an iterator that denotes the first element, if there is
   one, and end becomes an iterator that is positioned one past the end of the
   associated container (or string).
   If the container (or string) is empty, then begin becomes the same iterator
   as end, i.e. the 'off-the-end iterator'.
 * In general, we do not know, or care about, the precise type that an iterator
   has. Hence, we generally use the auto type specifier for iterators.
   Like with size_type, the library types that support iterators define the
   iterator type like std::string::iterator, std::string::const_iterator,
   std::vector<int>::iterator, std::vector<int>::const_iterator, etc.
   Like with pointers, if a string or a vector is const, we can use only its
   const_iterator type, but if a string or a vector is non-const, we may use
   either iterator or const_iterator.
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
 * Additional iterator operations supported by strings and vectors :-
   (1) iter + n - yields an iterator n elements forward
   (2) iter - n - yields an iterator n elements backward
   (3) iter += n - equivalent to iter = (iter + n)
   (4) iter -+ n - equivalent to iter = (iter - n)
   (5) iter_1 - iter 2 - yields number that when added to the iter_2 yields
                         iter_1; iter_1 and iter_2 must denote elements in,
                         or one past the end of, the same container (or string);
                         the result is of type std::string::difference_type or
                         std::vector<T>::difference_type, etc. (signed integer)
   (6) <, <=, > and >= - again, the iterators must denote elements in, or one
                         past the end of, the same container (or string)
 * For eg., to get the middle element of a container which supports these
   additional operations, or a string, using iterators, we may use
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


 * Iteration using 'range-based for' must not change the size of the sequence
   being iterated over. This is because upon adding/removing elements, the value
   of a.end() might get invalidated, among other things.
   If this happens, undefined behaviour gets invoked.
 * A range-based for is basically equivalent to
   for (auto begin = a.begin(), end = a.end(); begin != end; (begin)++)

 * Although we may change the size of the sequence being iterated over when
   iterating using 'iterators', this should be done very carefully.
   This is because code that adds or removes elements to a sequence can
   invalidate iterators.
   Thus, we need to ensure that the iterators are repositioned, as appropriate,
   after each operation that changes the sequence.


 * Resume from 3.5 Arrays

 * End of Trivia */
