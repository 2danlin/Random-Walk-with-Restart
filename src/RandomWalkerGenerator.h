//
// Created by 林丹丹 on 17/2/6.
//

#include <random>
#include <vector>
#include <functional>
#include <stdint.h>
#include "Graph.h"

#pragma once

using namespace std;

namespace RandomWalkGenerator{
    struct Statistics {
        vector<uint_fast32_t> degree_distribution;
        vector<uint_fast32_t> vertices_per_depth;
    };

    void sum_list_to(vector<uint_fast32_t>& from, vector<uint_fast32_t>& to);

    Graph run(mt19937* mt, uint_fast32_t max_order, uint_fast32_t steps, uint_fast32_t initial_order, bool selfloop);

    Graph run_one_or_two(mt19937* mt, uint_fast32_t max_order, double p, uint_fast32_t initial_order, bool selfloop);

    Statistics measure(Graph&, uint_fast32_t initial_order);

    Statistics accumulate_measure(function<Graph(void)> runner, uint_fast32_t runs, uint_fast32_t initial_order);

}
