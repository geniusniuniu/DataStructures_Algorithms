#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    const size_t d = 8;       // 学号�?�?
    int x = 7;                // 随意指定.
    stack<int> S;
    queue<char> Q;
    for (size_t i = 0; i < d; ++i)
    {
        int num;
        cin >> num;             // 依次输入你的学号, 每次输入1个数�?
        S.push(num);
        Q.push('A' + num);
        S.top() *= x;
    }
    S.push(x);
    x %= 2 * d;
    Q.push('B' + x);
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        S.push(Q.front() - 'C');
        Q.pop();
    }
    cout << endl;
    while (!S.empty())
    {
        cout << S.top() << ", ";
        S.pop();
    }
    cout << endl;
    return 0;
}