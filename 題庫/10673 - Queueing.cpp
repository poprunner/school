#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    queue<string> q;
    string cmd;
    while (cin >> cmd)
        if (cmd == "Push")
        {
            string name;
            cin >> name;
            q.push(name);
        }
        else if (cmd == "Pop")
        {
            if (!q.empty())
                q.pop();
        }
        else if (cmd == "Front")
        {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "empty\n";
        }
}
