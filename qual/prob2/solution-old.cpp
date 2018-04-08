#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename It>
void trouble_sort (It first, It last)
{
    bool done = false;
    while (!done)
    {
        done = true;
        for (It it = first; it != last - 2; ++it)
        {
            if (*it > *(it + 2))
            {
                done = false;
                swap(*it, *(it + 2));
            }
        }
    }
}

int main ()
{
    int num_cases;
    cin >> num_cases;

    for (int case_ndx = 0; case_ndx < num_cases; ++case_ndx)
    {
        int n;
        vector<int> list;

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            list.push_back(0);
            cin >> list.back();
        }

        trouble_sort(list.begin(), list.end());

        int ndx = 0;
        while (ndx < n-1 && list[ndx] <= list[ndx+1])
        {
            ++ndx;
        }

        cout << "Case #" << case_ndx+1 << ": ";
        if (ndx == n-1)
        {
            cout << "OK\n";
        }
        else
        {
            cout << ndx << "\n";
        }
    }
}
