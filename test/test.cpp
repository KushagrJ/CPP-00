// C++20 Standard

#include <iostream>
#include <cstdio>
#include <string>


int main()
{

    std::string a = "hello";

    char i = a[0];
    i = 'k';
    std::cout << a << std::endl;

    char& j = a[0];
    j = 'k';
    std::cout << a << std::endl;

    int p = 0;
    int q = p;
    int& ref_p = p;

    return 0;

}
