//
// Created by 林丹丹 on 17/2/6.
//


#include<vector>
#include <stdint.h>

using namespace std;

#pragma once

class Graph {
private:
    vector<vector<uint_fast32_t>> adjacency_vector;
    uint_fast32_t size_cache = 0;

public:
    Graph(){};
    Graph(uint_fast32_t prealloc){
        adjacency_vector.reserve(prealloc);
    }

    uint_fast32_t order() const;

    uint_fast32_t size() const;

    uint_fast32_t max_degree() const;

    void add_vertex();

    void add_edge(uint_fast32_t, uint_fast32_t);

    const vector<uint_fast32_t>* neighbors_of(uint_fast32_t) const;

    const vector<uint_fast32_t> degree_distribution() const;
};
