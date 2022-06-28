// C17 Standard

#include <iostream>
#include <vector>


int main(void)
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> v(n);
        for (int i = 0; i < n; i++)
            std::cin >> v[i];

        int x = v[0];
        for (int i = 1; i < (n - 1); i++)
            x ^= v[i];

        for (int i = (n - 1); i >= 0; i++)
        {
            if (x == v[i])
            {
                std::cout << v[i] << '\n';
                break;
            }

            x ^= v[i-1];
            x ^= v[i];
        }
    }

    return 0;

}
