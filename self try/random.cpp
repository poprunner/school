/*
#include <iostream>
#include <random>
using namespace std;
class GuessNumber
{
public:
    GuessNumber()
    {
        rnd = mt19937(random_device{}());
    }

private:
    mt19937 rnd;
};
int main()
{
}
*/

/*
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Random
{
public:
    Random()
    {
        mt = mt19937(random_device{}());
    }
    int uid(int begin, int end)
    {
        // uniform_int_distribution<> ret(begin, end);
        // return ret(mt);
        return uniform_int_distribution<>{begin, end}(mt);
    }
    double urd(double begin, double end)
    {
        // uniform_real_distribution<> ret(begin, end);
        // return ret(mt);
        return uniform_real_distribution<>{begin, end}(mt);
    }

private:
    mt19937 mt;
};
int main()
{
    Random rd{};
    vector<string> vs;
    for (int i = 0; i < 5; i++)
    {
        stringstream ss;
        ss << "int : " << rd.uid(0, 9) << endl
           << "dbl : " << rd.urd(0, 1);
        vs.push_back(ss.str());
    }
    for (auto &o : vs)
        cout << o << endl;
    cout << vs.size() << endl;
    vs.erase(remove_if(vs.begin(), vs.end(),
                       [](string &s)
                       {
                           if ((s[6] - '0') % 2 == 1)
                               return true;
                           else
                               return false;
                       }),
             vs.end());
    for (auto &o : vs)
        cout << o << endl;
    cout << vs.size() << endl;

    stringstream test;
    test << "This is a test.\n";
    cout << test.str();
}
*/

// random
/*
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

int main()
{
    // random_device rd;
    // mt19937 mt = mt19937(rd());

    // mt19937 mt = mt19937(random_device{}());
    mt19937 mt{random_device{}()};
    uniform_real_distribution<double> urd(0, 1);

    for (int i = 0; i < 10; i++)
        cout << fixed << setprecision(4) << urd(mt) << endl;
}
*/

// template
// lambda function []() -> type {...} type : type of return value
/*
#include <iostream>
#include <iomanip>

class TEST
{
public:
    TEST() {}

    template <typename T, typename F>
    T cal(T x, T y, F func)
    {
        return func(x, y);
    }
};
int main()
{
    TEST test1{};
    std::cout << test1.cal(2, 3,
                           [](int a, int b)
                           {
                               return a * b;
                           })
              << std::endl
              << std::fixed << std::setw(4)
              << test1.cal(2, 3,
                           [](int a, int b) -> int
                           {
                               return a - b;
                           })
              << std::endl;
}
*/
