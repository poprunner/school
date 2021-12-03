/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Torch
{
private:
    struct State
    {
        vector<int> here;
        vector<int> there;
        int direction; // torch position : {1 : here, -1 : there}

        State() {}
        State(vector<int> ini) : here(ini.size()), there(ini.size()), direction{1}
        {
            for (auto &i : here)
                i = 1;
        }
        State(const State &s) : here{s.here}, there{s.there}, direction{s.direction} {}

        State &operator=(const State &s)
        {
            State tmp{s};
            swap(here, tmp.here);
            swap(there, tmp.there);
            direction = tmp.direction;
            return *this;
        }

        bool operator<(const State &s) const
        {
            return (here < s.here) || ((here == s.here) && (there < s.there)) ||
                   ((here == s.here) && (there == s.there) && (direction < s.direction));
        }

        void show()
        {
            for (auto i : here)
                cout << i << " ";
            cout << "| ";
            for (auto i : there)
                cout << i << " ";
            if (direction == 1)
                cout << "left\n";
            else
                cout << "right\n";
        }
    };

    using Choice = pair<int, State>; // <-cost time, state>

    vector<int> walking_time;
    map<State, int> best_cost;
    map<State, State> prev_state;

    set<Choice> extend(Choice ch)
    {
        set<Choice> sch;
        auto s = ch.second;
        if (s.direction == 1) // torch is here
        {
            for (int i = 0; i < s.here.size(); ++i)
            {
                if (s.here[i] == 1)
                {
                    // alone
                    State ns{s};
                    ns.here[i] = 0;
                    ns.there[i] = 1;
                    ns.direction = -1;
                    Choice nch{ch.first - walking_time[i], ns};
                    sch.insert(nch);
                    // with company
                    for (int j = i + 1; j < s.here.size(); ++j)
                    {
                        if (s.here[j] == 1)
                        {
                            State ns2{ns};
                            ns2.here[j] = 0;
                            ns2.there[j] = 1;
                            int cost = (walking_time[i] > walking_time[j])
                                           ? walking_time[i]
                                           : walking_time[j];
                            Choice nch2{ch.first - cost, ns2};
                            sch.insert(nch2);
                        }
                    }
                }
            }
        }
        else // torch is there;
        {
            for (int i = 0; i < s.here.size(); ++i)
            {
                if (s.there[i] == 1)
                {
                    // alone
                    State ns{s};
                    ns.there[i] = 0;
                    ns.here[i] = 1;
                    ns.direction = 1;
                    Choice nch{ch.first - walking_time[i], ns};
                    sch.insert(nch);
                    // with company
                    for (int j = i + 1; j < s.here.size(); ++j)
                    {
                        if (s.there[j] == 1)
                        {
                            State ns2{ns};
                            ns2.there[j] = 0;
                            ns2.here[j] = 1;
                            int cost = (walking_time[i] > walking_time[j])
                                           ? walking_time[i]
                                           : walking_time[j];
                            Choice nch{ch.first - cost, ns2};
                            sch.insert(nch);
                        }
                    }
                }
            }
        }
        return sch;
    }

    bool found(State s)
    {
        if (s.direction == 1)
            return false;
        for (auto i : s.here)
            if (i != 0)
                return false;
        return true;
    }

    void trace_back(State s)
    {
        State ini(walking_time);
        while (s < ini || ini < s)
        {
            s.show();
            s = prev_state[s];
        }
        ini.show();
    }

public:
    Torch(vector<int> wt) : walking_time{wt} {}
    void solve()
    {
        State ini(walking_time);
        best_cost[ini] = 0;
        prev_state[ini] = ini;
        Choice ini_choice = make_pair(0, ini);

        priority_queue<Choice> pq;
        pq.push(ini_choice);

        while (!pq.empty())
        {
            Choice current_choice = pq.top();
            pq.pop();

            if (found(current_choice.second))
            {
                cout << -current_choice.first << endl;
                trace_back(current_choice.second);
                break;
            }

            set<Choice> new_choices = extend(current_choice);
            for (auto c : new_choices)
            {
                if (best_cost.count(c.second) == 0)
                {
                    best_cost[c.second] = c.first;
                    prev_state[c.second] = current_choice.second;
                    pq.push(c);
                }
                else if (c.first > best_cost[c.second]) // 因為是負數所以越大時間越短
                {
                    best_cost[c.second] = c.first;
                    prev_state[c.second] = current_choice.second;
                    pq.push(c);
                }
            }
        }
    }
};

int main()
{
    vector<int> walking_time{3, 5, 8, 10};
    Torch problem(walking_time);
    problem.solve();
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Torch
{
private:
    struct State
    {
        vector<int> here;
        vector<int> there;
        int dir; // 1 is left(here), -1 is right(there)

        State() {}
        State(vector<int> ini) : here(ini.size()), there(ini.size()), dir{1}
        {
            for (int &i : here)
                i = 1;
        }
        State(const State &s) : here{s.here}, there{s.there}, dir{s.dir} {}

        State &operator=(const State &s)
        {
            State tmp{s};
            swap(here, tmp.here);
            swap(there, tmp.there);
            dir = tmp.dir;
            return *this;
        }

        bool operator<(const State &s) const
        {
            return (here < s.here) || ((here == s.here) && (there < s.there)) ||
                   ((here == s.here) && (there == s.there) && (dir < s.dir));
        }

        void show()
        {
            for (int i : here)
                cout << i << " ";
            cout << "| ";
            for (int i : there)
                cout << i << " ";
            if (dir == 1)
                cout << "left\n";
            else
                cout << "right\n";
        }
    };

    using Choice = pair<int, State>;

    vector<int> walking_time;
    map<State, int> best_cost;
    map<State, State> prev_state;

    set<Choice> extend(Choice ch)
    {
        set<Choice> sch;

        int cost = ch.first;
        State s = ch.second;
        if (s.dir == 1) // here
        {
            for (int i = 0; i < s.here.size(); ++i)
            {
                if (s.here[i] == 1)
                {
                    State ns{s};
                    ns.here[i] = 0;
                    ns.there[i] = 1;
                    ns.dir = -1;
                    Choice nch{cost - walking_time[i], ns};
                    sch.insert(nch);
                    for (int j = i + 1; j < s.here.size(); ++j)
                    {
                        if (s.here[j] == 1)
                        {
                            State ns2{ns};
                            ns2.here[j] = 0;
                            ns2.there[j] = 1;
                            int newcost = (walking_time[i] > walking_time[j])
                                              ? walking_time[i]
                                              : walking_time[j];
                            Choice nch2{cost - newcost, ns2};
                            sch.insert(nch2);
                        }
                    }
                }
            }
        }
        else // there
        {
            for (int i = 0; i < s.here.size(); ++i)
            {
                if (s.there[i] == 1)
                {
                    State ns{s};
                    ns.there[i] = 0;
                    ns.here[i] = 1;
                    ns.dir = 1;
                    Choice nch{cost - walking_time[i], ns};
                    sch.insert(nch);
                    for (int j = i + 1; j < s.here.size(); ++j)
                    {
                        if (s.there[j] == 1)
                        {
                            State ns2{ns};
                            ns2.there[j] = 0;
                            ns2.here[j] = 1;
                            int newcost = (walking_time[i] > walking_time[j])
                                              ? walking_time[i]
                                              : walking_time[j];
                            Choice nch2{cost - newcost, ns2};
                            sch.insert(nch2);
                        }
                    }
                }
            }
        }

        return sch;
    }

    bool found(State s)
    {
        if (s.dir != -1)
            return false;
        for (int i : s.here)
            if (i != 0)
                return false;
        return true;
    }

    void show_answer(State s) // trace back
    {
        State ini(walking_time);
        while (ini < s || s < ini) // if not equal
        {
            s.show();
            s = prev_state[s];
        }
        ini.show();
    }

public:
    Torch(vector<int> wt) : walking_time{wt} {}

    void solve()
    {
        State ini(walking_time);
        best_cost[ini] = 0;
        prev_state[ini] = ini;
        Choice item{0, ini};

        priority_queue<Choice> pq;
        pq.push(item);

        while (!pq.empty())
        {
            Choice cur_ch = pq.top();
            pq.pop();

            if (found(cur_ch.second))
            {
                cout << "Answer : " << -cur_ch.first << endl;
                show_answer(cur_ch.second);
                break;
            }

            set<Choice> nchs{extend(cur_ch)};
            for (Choice nch : nchs)
            {
                if (best_cost.count(nch.second) == 0)
                {
                    best_cost[nch.second] = nch.first;
                    prev_state[nch.second] = cur_ch.second;
                    pq.push(nch);
                }
                else if (nch.first > best_cost[nch.second])
                {
                    best_cost[nch.second] = nch.first;
                    prev_state[nch.second] = cur_ch.second;
                    pq.push(nch);
                }
            }
        }
    }
};

int main()
{
    vector<int> walking_time{1, 3, 6, 9};
    Torch problem{walking_time};
    problem.solve();
}