/*
#include <iostream>
using namespace std;

struct Node
{
    int prev;
    int next;
};

Node A[1000010];

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 1000010; ++i)
    {
        A[i].prev = i - 1;
        A[i].next = i + 1;
    }
    int N;
    cin >> N;
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "Exit")
        {
            int i = A[0].next;
            while (i != A[N + 1].prev)
            {
                cout << i << " ";
                i = A[i].next;
            }
            cout << i << endl;
            break;
        }
        if (cmd == "Move")
        {
            int from, to;
            cin >> from >> to;
            if (A[from].next == to) // 若前後已相接 跳過此過程
                continue;
            A[A[0].next].prev = A[to].prev; // 頭接後的前一個
            A[A[to].prev].next = A[0].next;
            A[A[from].next].prev = 0; // 前的後一個接頭
            A[0].next = A[from].next;
            A[from].next = to; // 前接後
            A[to].prev = from;
        }
    }
}
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
struct Node
{
    int prev;
    int next;
};
Node S[1000003];
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i <= N + 1; i++)
    {
        S[i].next = i + 1;
        S[i].prev = i - 1;
    }
    while (1)
    {
        string str;
        cin >> str;
        if (str == "Exit")
            break;

        int a, b;
        cin >> a >> b;

        int p, q, r;
        p = S[a].next;
        q = S[b].prev;
        if (a == q)
            continue;
        r = S[0].next;

        S[a].next = b;
        S[b].prev = a;
        S[r].prev = q;
        S[q].next = r;
        S[0].next = p;
        S[p].prev = 0;
    }
    if (N > 0)
    {
        int t = S[0].next;
        cout << t;
        --N;
        while (N > 0)
        {
            t = S[t].next;
            cout << " " << t;
            --N;
        }
        cout << "\n";
    }
}
