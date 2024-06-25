//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    const size_t d = 8;     // 学号�?�?
//    int x = 7;              // 随意指定.
//    vector<int> V;
//    V.reserve(3);           // 假定向量初始容量�?.
//    for (size_t i = 0; i < d; ++i)
//        V.push_back(d);
//    for (size_t i = 0; i < d; ++i)
//        V.pop_back();
//    for (size_t i = 0; i < d; ++i)
//    {
//        int num;
//        cin >> num;           // 依次输入你的学号, 每次输入1个数�?
//        V.push_back(num * x);
//    }
//    V.push_back(x);
//    for (auto iter = V.cbegin(); iter != V.cend(); ++iter)
//        cout << *iter << "...";
//    return 0;
//}