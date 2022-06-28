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

        std::vector<long long> v(n);

        int no_of_positives = 0;
        int no_of_zeroes = 0;
        int no_of_negatives = 0;

        int positive, negative;

        for (int i = 0; i < n; i++)
        {
            std::cin >> v[i];

            if (v[i] > 0)
                ++(no_of_positives), (positive = v[i]);
            else if (v[i] == 0)
                ++(no_of_zeroes);
            else
                ++(no_of_negatives), (negative = v[i]);
        }

        if ((no_of_positives >= 3) || (no_of_negatives >= 3))
        {
            std::cout << "NO\n";
        }

        else if ((no_of_positives == 1) && (no_of_negatives == 1))
        {
            if (positive == -(negative))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }

        else if ((no_of_positives == 1) && (no_of_negatives == 2) &&
                    (no_of_zeroes > 0))
        {
            std::cout << "NO\n";
        }

        else if ((no_of_positives == 2) && (no_of_negatives == 1) &&
                    (no_of_zeroes > 0))
        {
            std::cout << "NO\n";
        }

        else if ((no_of_positives == 2) && (no_of_negatives == 2) &&
                    (no_of_zeroes > 0))
        {
            std::cout << "NO\n";
        }

        else
        {
            std::unordered_set<long long> s;
            for (int i = 0; i < n; i++)
                s.insert(v[i]);

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
    }

    return 0;

}
