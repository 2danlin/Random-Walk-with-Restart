//
// Created by 林丹丹 on 17/2/6.
//

#include "RandomWalkerGenerator.h"
#include "RandomWalker.h"
#include "Graph.h"
#include <queue>
#include <algorithm>
#include <stdint.h>

using namespace std;

namespace RandomWalkGenerator{
    void initialize_complete_graph(Graph& graph, uint_fast32_t order, bool selfloop){
        uint_fast32_t i, j;
        for(i = 0; i < order; i++){
            graph.add_vertex();
        }

        for(i = 0; i < order; i++){
            if(selfloop){
                graph.add_edge(i,i);
            }

            for(j = i+1; j < order; j++){
                graph.add_edge(i,j);
            }
        }
    }

    Graph run(mt19937* mt, uint_fast32_t max_order, uint_fast32_t steps, uint_fast32_t initial_order, bool selfloop){
        Graph graph(max_order);

        initialize_complete_graph(graph, initial_order, selfloop);

        RandomWalker walker(mt, &graph);

        while(graph.order() < max_order){
            for(uint_fast32_t i = 0; i < steps; i++){
                walker.take_step();
            }

            graph.add_vertex();
            graph.add_edge(graph.order()-1, walker.location());
        }

        return graph;
    }

    Graph run_one_or_two(mt19937* mt, uint_fast32_t max_order, double p, uint_fast32_t initial_order, bool selfloop){
        Graph graph(max_order);

        initialize_complete_graph(graph, initial_order, selfloop);

        uniform_real_distribution<> dist(0,1);

        RandomWalker walker(mt, &graph);

        while(graph.order() < max_order){
            walker.take_step();

            if(dist(*mt) > p){
                walker.take_step();
            }

            graph.add_vertex();
            graph.add_edge(graph.order()-1, walker.location());

        }
        return graph;
    }

    struct VerticeDepth{
        uint_fast32_t vertice;
        uint_fast32_t depth;
    };

    Statistics measure(Graph& graph, uint_fast32_t initial_order){
        Statistics statistics;

        vector<bool> explored(graph.order(), false);

        queue<VerticeDepth> queue;

        for(uint_fast32_t start = 0; start < initial_order; start++){
            queue.push({start, 0});

            explored[start] = true;
        }

        while(!queue.empty()){
            auto curr = queue.front();

            queue.pop();

            if(curr.depth >= statistics.vertices_per_depth.size()){
                statistics.vertices_per_depth.push_back(1);
            }else{
                statistics.vertices_per_depth[curr.depth]++;
            }

            for(auto n : *graph.neighbors_of(curr.vertice)) {
                if(!explored[n]){
                    queue.push({n, curr.depth + 1});
                    explored[n] = true;
                }
            }
        }

        statistics.degree_distribution = graph.degree_distribution();

        return statistics;
    }

    void sum_list_to(vector<uint_fast32_t>& from, vector<uint_fast32_t>& to){
        for(uint_fast32_t i = 0; i < from.size(); i++){
            if(to.size() > i){
                to[i] += from[i];
            }else{
                to.push_back(from[i]);
            }
        }
    }

    Statistics accumulate_measure(function<Graph(void)> runner, uint_fast32_t runs, uint_fast32_t initial_order){
        Statistics measurement;
        Statistics statistics;

        for(uint_fast32_t run = 0; run < runs; run++){
            Graph graph = runner();
            measurement = measure(graph, initial_order);
            sum_list_to(measurement.degree_distribution, statistics.degree_distribution);
            sum_list_to(measurement.vertices_per_depth, statistics.vertices_per_depth);
        }

        return statistics;
    }
}
