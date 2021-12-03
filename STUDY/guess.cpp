#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class guess
{
public:
    // constructor
    guess()
    {
        mt = mt19937{random_device{}()};
        for (int i = 0; i <= 9999; ++i)
        {
            stringstream ss;
            ss << setfill('0') << setw(4) << i;
            anss.push_back(ss.str());
        }
        anss.erase(remove_if(anss.begin(), anss.end(),
                             [](string s) -> bool
                             {
                                 for (int i = 0; i < 4; ++i)
                                     for (int j = 0; j < i; j++)
                                         if (s[i] == s[j])
                                             return true;
                                 return false;
                             }),
                   anss.end());
    }

    // function
    void trim(int A, int B)
    {
        anss.erase(remove_if(anss.begin(), anss.end(),
                             [=](string s) -> bool
                             {
                                 int a = 0, b = 0;
                                 for (int i = 0; i < 4; ++i)
                                     for (int j = 0; j < 4; j++)
                                         if (s[i] == guess_ans[j])
                                             if (i == j)
                                                 ++a;
                                             else
                                                 ++b;
                                 if (a == A && b == B)
                                     return false;
                                 else
                                     return true;
                             }),
                   anss.end());
    }
    string guess_and_show()
    {
        uniform_int_distribution<int> uid(0, anss.size() - 1);
        return guess_ans = anss[uid(mt)];
    }
    int size()
    {
        return anss.size();
    }

private:
    mt19937 mt;
    vector<string> anss;
    string guess_ans;
};

int main()
{
    int A, B;
    guess gs;
    while (1)
    {
        cout << "Is " << gs.guess_and_show() << "?" << endl
             << "?A?B" << endl
             << ">> ";
        cin >> A >> B;
        gs.trim(A, B);
        if (A == 4)
        {
            cout << "I got it!\n";
            break;
        }
        if (gs.size() == 0)
        {
            cout << "You are a liar, NO WAY!\n";
            break;
        }
    }
}