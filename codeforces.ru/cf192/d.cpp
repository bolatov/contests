/*
 * cf192_d.cpp
 *
 *  Created on: 31.07.2013
 *      Author: Almer Bolatov
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

void bfs(int source, vector< vector<int> > &g, vector<int> &memo);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int R, C;
    cin >> R >> C;

    int start, end, xend, yend;
    vector< vector<char> > m(R, vector<char>(C, '0'));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'S')
                start = i*C + j;
            else if (ch == 'E') {
                end = i*C + j;
                xend = j;
                yend = i;
            }
            m[i][j] = ch;
        }
    }
    vector< vector<int> > g(R*C, vector<int>());
    vector< pair<int,int> > mikemons;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char ch = m[i][j];
            int pos = i*C + j;


            if (ch != 'T') {
                if (i >= 0 && i+1 < R && m[i+1][j] != 'T') {
                    int nb = (i+1)*C + j;
                    g[pos].push_back(nb);
                }
                if (i-1 >= 0 && i < R && m[i-1][j] != 'T') {
                    int nb = (i-1)*C + j;
                    g[pos].push_back(nb);
                }
                if (j >= 0 && j+1 < C && m[i][j+1] != 'T') {
                    int nb = i*C + j+1;
                    g[pos].push_back(nb);
                }
                if (j-1 >= 0 && j < C && m[i][j-1] != 'T') {
                    int nb = i*C + j-1;
                    g[pos].push_back(nb);
                }

                if (ch != 'S' && ch != 'E' && ch-'0' > 0) {
                    mikemons.push_back( make_pair(pos, ch-'0') );
                }
            }
        }
    }

//    for (vector<int> &row : g) {
//        for (int &pos : row) {
//            cout << pos << endl;
//        }
//    }

//  for (size_t i = 0; i < g.size(); ++i) {
//      printf("%d: ", i);
//      vector<int> row = g[i];
//      for (int child : row) {
//          printf("%d ", child);
//      }
//      printf("\n");
//  }

    vector<int> distance(g.size(), -1);
    bfs(end, g, distance);

    int mydist = distance[start];

//  printf("mydist = %d\n", mydist);
//  printf("start=%d, end=%d\n", start, end);


    int enemies = 0;
//  printf("mikemons cells: %d\n", mikemons.size());
    for (pair<int,int> p : mikemons) {

//        printf("cell = %d, enemies=%d, distance=%d\n", p.first, p.second, distance[p.first]);

        if (distance[p.first] > -1 && distance[p.first] <= mydist) {
//          printf("\tok: cell=%d\n", p.first);
            enemies += p.second;
        }
    }
    printf("%d\n", enemies);

    return 0;
}

void bfs(int source, vector< vector<int> > &graph, vector<int> &distance) {
    queue<int> q;
    q.push(source);

    vector<bool> u(graph.size(), false);
    u[source] = true;
    distance[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int child : graph[node]) {
            if (!u[child]) {
                u[child] = true;
                q.push(child);
                distance[child] = distance[node] + 1;
            }
        }
    }
}
