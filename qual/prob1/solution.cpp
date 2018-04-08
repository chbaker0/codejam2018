#include <iostream>
#include <string>
#include <utility>
#include <cstdint>

using namespace std;

int64_t compute_damage (const string& prog)
{
    int64_t total = 0;
    int64_t cur_strength = 1;

    for (char c : prog)
    {
        switch (c)
        {
        case 'C':
            cur_strength *= 2;
            break;
        case 'S':
            total += cur_strength;
            break;
        default:
            break;
        }
    }

    return total;
}

int main ()
{
    int num_cases;
    cin >> num_cases;

    for (int case_ndx = 0; case_ndx < num_cases; ++case_ndx)
    {
        int64_t max_damage;
        string program;

        cin >> max_damage >> program;

        int num_hacks = 0;
        int64_t cur_damage = compute_damage(program);
        while (cur_damage > max_damage)
        {
            int ndx = program.size() - 2;
            while (ndx >= 0 && !(program[ndx] == 'C' && program[ndx+1] == 'S'))
            {
                --ndx;
            }

            if (ndx < 0)
            {
                // No hacks
                break;
            }
            else
            {
                ++num_hacks;
                swap(program[ndx], program[ndx+1]);
            }

            cur_damage = compute_damage(program);
        }

        cout << "Case #" << case_ndx+1 << ": ";
        if (cur_damage <= max_damage)
        {
            cout << num_hacks << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}
