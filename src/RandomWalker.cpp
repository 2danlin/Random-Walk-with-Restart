//
// Created by 林丹丹 on 17/2/6.
//
#include <stdint.h>
#include "RandomWalker.h"

using namespace std;

RandomWalker::RandomWalker(mt19937 *mt, Graph *graph) {
    m_location = 0;
    graph_ptr = graph;

    twister = mt;
}

uint_fast32_t RandomWalker::take_step() {
    auto neighbors = graph_ptr->neighbors_of(m_location);

    if(neighbors->size() == 0){
        return m_location;
    }

    uniform_int_distribution<uint_fast32_t> dist(0,neighbors->size()-1);

    m_location = (*neighbors)[dist(*twister)];

    return m_location;
}