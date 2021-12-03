#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned int volume;
    while (cin >> volume)
    {
        int num = 0;
        unsigned int size;
        unsigned int sum = 0;
        while (cin >> size && size != 0)
            if (sum + size > volume)
            {
                ++num;
                sum = size;
            }
            else
                sum += size;
        if (sum > 0)
            ++num;
        cout << num << endl;
    }
}
