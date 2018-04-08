#include <iomanip>
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846264338328

using namespace std;

int main ()
{
    int num_cases;
    cin >> num_cases;

    for (int case_ndx = 0; case_ndx < num_cases; ++case_ndx)
    {
        double area;
        cin >> area;

        double theta = asin(area / sqrt(2)) - PI / 4.0;

        cout << std::setprecision(10);
        cout << "Case #" << case_ndx+1 << ":\n";
        cout << 0.5 * cos(theta) << " " << 0.5 * sin(theta) << " 0\n";
        cout << -0.5 * sin(theta) << " " << 0.5 * cos(theta) << " 0\n";
        cout << "0 0 0.5\n";
    }
}
