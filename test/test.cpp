// C++20 Standard

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);
        std::unordered_set<int> s;

        for (int i = 0; i < n; i++)
        {
            std::cin >> v[i];

            if ((n >= 5) && (v[i] != 0))
            {
                std::cout << "NO\n";
                goto end_of_loop;
            }

            s.insert(v[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = (i + 1); j < n; j++)
            {
                for (int k = (j + 1); k < n; k++)
                {
                    if (s.find(v[i] + v[j] + v[k]) == s.end())
                    {
                        std::cout << "NO\n";
                        goto end_of_loop;
                    }
                }
            }
        }

        std::cout << "YES\n";

        end_of_loop: ;
    }

    return 0;

}
