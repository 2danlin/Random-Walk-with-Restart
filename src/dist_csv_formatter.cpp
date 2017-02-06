//
// Created by 林丹丹 on 17/2/6.
//

#include <vector>
#include <ostream>
#include "dist_csv_formatter.h"

using namespace std;

void DistCsvFormatter::format(const vector<uint_fast32_t>& distribution, ostream& out, bool include_headers) {
    if(include_headers){
        out << "value,count"<<endl;
    }

    uint_fast32_t i = 0;
    for(auto d : distribution){
        if(d > 0){
            out << i << "," << d <<endl;
        }
        i++;
    }
}

void DistCsvFormatter::format(const vector<uint_fast32_t>& distribution, ostream& out) {
    format(distribution,out, false);
}
