#include <iostream>
#include <sstream>
using namespace std;

string rle(string str)
{
    stringstream ss;
    char prev = '\0';
    int cnt = 0;
    for (auto c : str)
    {
        if (c != prev)
        {
            if (cnt != 0)
                ss << cnt << prev;
            prev = c;
            cnt = 1;
        }
        else
            ++cnt;
    }
    ss << cnt << prev;
    return ss.str();
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        int k;
        cin >> str >> k;
        while (k--)
            str = rle(str);
        cout << str << endl;
    }
}
