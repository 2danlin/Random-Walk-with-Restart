#include <iostream>
#include <stdio.h>
#include "RandomWalker.h"
#include "Graph.h"
#include <vector>

#define TEST_SEED 0

using namespace std;

int main() {
    Graph g;
    g.add_vertex();
    for(int i = 0; i < 9; i++){
        g.add_vertex();
        g.add_edge(i, i+1);
    }
    g.add_edge(0,9);

    std::mt19937 mt(TEST_SEED);
    RandomWalker walker(&mt, &g);
    cout << walker.location() <<endl;

    // From now on, this is a regression test
    for(int j=1;j<10;j++)
    {
        walker.take_step();
        cout<< walker.location() <<endl;
    }
}