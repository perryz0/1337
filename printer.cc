#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[ ";
    for (const auto& v : vec) cout << v << " ";
    cout << "]\n";
}

template <typename T>
void printQueue(queue<T> q) { // Pass by value to avoid modifying the original queue
    cout << "[ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "]\n";
}

template <typename K, typename V>
void printMap(const unordered_map<K, V>& mp) {
    cout << "{ ";
    for (const auto& p : mp) cout << p.first << ": " << p.second << ", ";
    cout << "}\n";
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    queue<int> q;
    for (int i : v) q.push(i);
    unordered_map<string, int> mp = {{"Alice", 10}, {"Bob", 20}};

    printVector(v);
    printQueue(q);
    printMap(mp);

    return 0;
}
