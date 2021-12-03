/*
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
using State = vector<int>;
using Path = list<State>;
using Paths = set<Path>;

ostream &operator<<(ostream &os, State s)
{
    os << '(';
    for (auto i : s)
        os << i << ',';
    os << ')';
    return os;
}

class Pouring
{
private:
    State _capacities;
    set<State> _explored;
    Paths _paths;
    Paths _solutions;

public:
    Pouring(State s) : _capacities(s) {}

    State Fill(State s, int idx)
    {
        s[idx] = _capacities[idx];
        return s;
    }
    State Empty(State s, int idx)
    {
        s[idx] = 0;
        return s;
    }
    State Pour(State s, int from, int to)
    {
        int remain = _capacities[to] - s[to];
        if (remain < s[from])
        {
            s[from] -= remain;
            s[to] += remain;
        }
        else
        {
            s[to] += s[from];
            s[from] = 0;
        }
        return s;
    }

    set<State> extend(State s)
    {
        set<State> ss;
        for (int i = 0; i < _capacities.size(); ++i)
        {
            ss.insert(Fill(s, i));
            ss.insert(Empty(s, i));
            for (int j = 0; j < _capacities.size(); ++j)
                if (i != j)
                    ss.insert(Pour(s, i, j));
        }
        return ss;
    }

    bool found(State s, int target)
    {
        for (auto i : s)
            if (i == target)
                return true;
        return false;
    }

    void solve(int target, int steps)
    {
        State ini;
        for (int i = 0; i < _capacities.size(); ++i)
            ini.push_back(0);

        Path path;
        path.push_back(ini);

        _paths.insert(path);

        while (steps--)
        {
            Paths newpaths, oldpaths;

            for (auto p : _paths)
            {
                auto cur_s = p.back();
                _explored.insert(cur_s);
                auto ss = extend(cur_s);
                for (auto s : ss)
                {
                    if (_explored.find(s) == _explored.cend()) // newstate
                    {
                        auto np = p;
                        np.push_back(s);
                        if (found(s, target))
                            _solutions.insert(np);
                        else
                            newpaths.insert(np);
                    }
                }
                oldpaths.insert(p);
            }

            for (auto p : oldpaths)
                _paths.erase(p);
            for (auto p : newpaths)
                _paths.insert(p);
        }
    }

    void show()
    {
        for (auto &i : _solutions)
        {
            for (auto &j : i)
                cout << j << "-->";
            cout << endl;
        }
    }
};

int main()
{
    Pouring problem{State{7, 5, 3}};
    problem.solve(1, 4);
    problem.show();
}
*/

////

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
    os << "(";
    for (int i = 0; i < s.size() - 1; ++i)
        os << s[i] << ",";
    os << s[s.size() - 1];
    os << ")";
    return os;
}

class Pouring
{
private:
    State _capacities;
    set<State> _explored;
    Paths _paths;
    Paths _solutions;

    State Fill(int idx, State s)
    {
        s[idx] = _capacities[idx];
        return s;
    }
    State Empty(int idx, State s)
    {
        s[idx] = 0;
        return s;
    }
    State Pour(int from, int to, State s)
    {
        int diff = _capacities[to] - s[to];
        if (s[from] > diff)
        {
            s[from] -= diff;
            s[to] = _capacities[to];
        }
        else
        {
            s[to] += s[from];
            s[from] = 0;
        }
        return s;
    }

    set<State> extend(State s)
    {
        set<State> ss;
        for (int i = 0; i < _capacities.size(); ++i)
        {
            ss.insert(Fill(i, s));
            ss.insert(Empty(i, s));
            for (int j = 0; j < _capacities.size(); ++j)
                if (i != j)
                    ss.insert(Pour(i, j, s));
        }
        return ss;
    }

    bool found(State s, int target)
    {
        for (auto i : s)
            if (i == target)
                return true;
        return false;
    }

public:
    Pouring(State s) : _capacities(s) {}

    void solve(int target, int steps)
    {
        _paths.insert(Path{State(_capacities.size())});

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
                        if (found(s, target))
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
            auto i = p.cbegin();
            for (; i != --p.cend(); ++i)
                cout << *i << "->";
            cout << *i << endl;
        }
    }
};

int main()
{
    Pouring problem{State{3, 5, 6, 7}};
    problem.solve(2, 4);
    problem.show();
}
