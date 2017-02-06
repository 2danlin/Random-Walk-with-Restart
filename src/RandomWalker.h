//
// Created by 林丹丹 on 17/2/6.
//

#include <random>
#include <functional>
#include <stdint.h>
#include "Graph.h"

#pragma once

using namespace std;

class RandomWalker{
public:
    RandomWalker(mt19937* mt, Graph* graph);

    uint_fast32_t location(){
        return m_location;
    }

    uint_fast32_t take_step();

private:
    uint_fast32_t m_location;
    mt19937* twister;
    Graph* graph_ptr;
};
