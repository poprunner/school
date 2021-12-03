/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int digits;
        cin >> digits;
        string str1, str2;
        cin >> str1 >> str2;
        int tmp, carry = 0;
        string ans;
        for (int i = digits - 1; i >= 0; --i)
        {
            tmp = str1[i] - '0' + str2[i] - '0' + carry;
            carry = tmp / 2;
            ans.push_back(tmp % 2 + '0');
        }
        for (auto i = ans.rbegin(); i != ans.rend(); ++i) // 往rend方向為增加
            cout << *i;
        cout << endl;
    }
}
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int digits;
        cin >> digits;
        string one, two;
        cin >> one >> two;
        int tmp, carry = 0;
        string ans;
        for (int i = digits - 1; i >= 0; --i)
        {
            tmp = one[i] + two[i] + carry - '0' - '0';
            carry = tmp / 2;
            ans.push_back(tmp % 2 + '0');
        }
        for (auto i = ans.rbegin(); i != ans.rend(); ++i)
            cout << *i;
        cout << endl;
    }
}
