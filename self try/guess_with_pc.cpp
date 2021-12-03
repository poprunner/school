#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class player_guess
{
public:
    // constructor
    player_guess()
    {
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
    void trim(string guess_ans)
    {
        vector<string> tmp_anss;

        for (int A = 0; A <= 4; ++A)
            for (int B = 0; B + A <= 4; ++B)
            {
                auto tmp = anss;
                tmp.erase(remove_if(tmp.begin(), tmp.end(),
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
                          tmp.end());
                if (tmp.size() > tmp_anss.size())
                {
                    showA = A, showB = B;
                    tmp_anss = tmp;
                }
            }
        anss = tmp_anss;
    }

    void show_remain()
    {
        cout << "possible answer :\n";
        for (string &i : anss)
            cout << i << endl;
    }
    int size()
    {
        return anss.size();
    }

    int operator[](char c)
    {
        if (c == 'A')
            return showA;
        else if (c == 'B')
            return showB;
        else
            return -1;
    }

private:
    vector<string> anss;
    int showA, showB;
};

int main()
{
    player_guess pg;
    string your_ans;
    while (true)
    {
        cout << "Your guess >> ";
        cin >> your_ans;
        pg.trim(your_ans);
        cout << pg['A'] << "A" << pg['B'] << "B" << endl;
        if (pg['A'] == 4)
        {
            cout << "You got it !\n ";
            break;
        }
        if (pg.size() <= 10)
            pg.show_remain();
    }
}
