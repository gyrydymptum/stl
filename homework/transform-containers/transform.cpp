
#include "transform.hpp"
#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> lis, std::deque<int> deq) {
    lis.sort();
    lis.erase(std::unique(lis.begin(), lis.end()), lis.end());
    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    std::map<int, std::string> map;
    if (lis.size() != deq.size()) {
        std::cerr << "Containers must be of the same size";
    } else {
        //https://stackoverflow.com/questions/46948042/using-stdtransform-to-convert-a-stdvectorstructkey-val-into-a-stdmap
        std::transform(deq.begin(), deq.end(), lis.begin(), std::inserter(map, map.end()),
                       [](auto key, auto value) { return std::make_pair(key, value); });
    }
    return map;
}