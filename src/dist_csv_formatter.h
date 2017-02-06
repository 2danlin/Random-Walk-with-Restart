//
// Created by 林丹丹 on 17/2/6.
//

#include <vector>
#include <stdint.h>
#include <ostream>
#pragma once

using namespace std;

namespace DistCsvFormatter{
    void format(const vector<uint_fast32_t>&, ostream&);
    void format(const vector<uint_fast32_t>&, ostream&, bool);
}
