//
// Created by 林丹丹 on 17/2/6.
//

#include <stdint.h>
#include <vector>
#include "Graph.h"

using namespace std;

uint_fast32_t Graph::order() const {
    return adjacency_vector.size();
}

uint_fast32_t Graph::size() const {
    return size_cache;
}

void Graph::add_vertex() {
    vector<uint_fast32_t> vec(0);
    adjacency_vector.push_back(vec);
}

void Graph::add_edge(uint_fast32_t from, uint_fast32_t to) {
    if((from > adjacency_vector.size() - 1) || (to > adjacency_vector.size() - 1 )){
        throw "node does not exist";
    }

    size_cache++;
    adjacency_vector[from].push_back(to);
    //adjacency_vector[to].push_back(from);
}

const vector<uint_fast32_t>* Graph::neighbors_of(uint_fast32_t vertex) const {
    return &adjacency_vector[vertex];
}

uint_fast32_t Graph::max_degree() const {
    uint_fast32_t degree = 0;

    for(auto v : adjacency_vector){
        if(v.size() > degree){
            degree = v.size();
        }
    }

    return degree;
}

const vector<uint_fast32_t> Graph::degree_distribution() const {
    vector<uint_fast32_t> degree_dist(max_degree()+1,0);

    for(auto v: adjacency_vector){
        degree_dist[v.size()]++;
    }

    return degree_dist;
}