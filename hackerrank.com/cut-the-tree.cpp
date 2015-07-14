#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int sum, ans;
std::vector<int> weights;
std::vector<std::vector<int> > graph;
void dfs(int start, int cur) {
    ans = min(ans, sum - cur);
    printf("start=%d, cur=%d, ans=%d \n", start, cur, ans);
    for (int v : graph[start]) {
        dfs(v, cur + weights[start]);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    int n, weight;
    cin >> n;
    graph.resize(n);
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weight;
        sum += weight;
        weights.push_back(weight);
    }
    int start, end;
    for (int i = 0; i < n - 1; ++i) {
        cin >> start >> end;
        graph[start - 1].push_back(end - 1);
    }
    ans = sum;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}