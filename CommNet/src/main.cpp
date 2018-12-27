#include "commNet.h"

int main() {
    nodeRead();
    linkRead();
    dijkstra();
    netPrint();
    double ave1 = aveLen();
    //cout << endl << "aveLen = " << ave1;
    double max = max_min_weight;
    netChange();
    dijkstra();
    netPrint();
    //cout << endl << "aveLen = " << aveLen();
    cout << endl << "value = " << (aveLen()-ave1)/max << endl;
    net_map.clear();
    number.clear();
    value_list.clear();
    for (int i = 0; i < len; ++i) {
        delete [] weight_matrix[i];
        delete [] locus_weight_matrix[i];
    }
    len = 0;
}

