#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;
using State = vector<int>;
using Path = list<State>;
using Paths = set<Path>;

ostream &operator<<(ostream &os, State s)
{
    os << "(" << s[0] << "," << s[1] << ")";
    if (s[4] == 1)
        os << "V~~~";
    else
        os << "~~~V";
    os << "(" << s[2] << "," << s[3] << ")";
    return os;
}

class Crossing
{
private:
    State _npeople;
    set<State> _explored;
    Paths _paths;
    Paths _solutions;

    State go(State s, int m, int c)
    {
        s[0] -= m * s[4];
        s[1] -= c * s[4];
        s[2] += m * s[4];
        s[3] += c * s[4];
        s[4] = -s[4];
        return s;
    }

    set<State> extend(State s)
    {
        set<State> ss;
        for (int m = 0; m <= 2; ++m)
            for (int c = 0; c <= 2; ++c)
                if (m + c >= 1 && m + c <= 2)
                {
                    State state = go(s, m, c);
                    if (valid(state))
                        ss.insert(state);
                }
        return ss;
    }

    bool valid(State s)
    {
        if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0)
            return false;
        if (s[0] < s[1] && s[0] != 0)
            return false;
        if (s[2] < s[3] && s[2] != 0)
            return false;
        return true;
    }

    bool found(State s)
    {
        if (s[0] == 0 && s[1] == 0 && s[4] == -1)
            return true;
        return false;
    }

public:
    Crossing(State s) : _npeople{s}
    {
        _npeople.push_back(0);
        _npeople.push_back(0);
        _npeople.push_back(1);
    }

    void solve(int steps)
    {
        _paths.insert(Path{State{_npeople}});

        while (steps--)
        {
            Paths newpaths;
            for (auto p : _paths)
            {
                _explored.insert(p.back());
                auto ss = extend(p.back());
                for (auto s : ss)
                    if (_explored.find(s) == _explored.cend())
                    {
                        auto np = p;
                        np.push_back(s);
                        if (found(s))
                            _solutions.insert(np);
                        else
                            newpaths.insert(np);
                    }
            }
            _paths = newpaths;
        }
    }

    void show()
    {
        for (auto p : _solutions)
        {
            for (auto s : p)
                cout << s << endl;
            cout << "done\n";
        }
    }
};

int main()
{
    Crossing problem{State{3, 3}};
    problem.solve(15);
    problem.show();
}