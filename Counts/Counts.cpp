#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;
    vector<int>* mass = new vector<int>[N];
    int* stepen = new int[N] { 0 };
    string res = "";
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        stepen[b - 1]++;
        mass[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < N; i++)
    {
        if (stepen[i] == 0) que.push(i);
    }

    while (!que.empty())
    {

        int out = que.top();
        res += to_string(out + 1) + " ";
        que.pop();
        stepen[out] = -1;
        for (int i = 0; i < mass[out].size(); i++)
        {
            int s = mass[out][i];
            stepen[s]--;
            if (stepen[s] == 0)
            {
                que.push(s);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (stepen[i] != -1)
        {
            cout << "bad course";
            return 0;
        }
    }
    cout << res;

    return 0;
}

