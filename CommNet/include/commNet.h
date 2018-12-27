//
// Created by 长颈鹿 on 2018-12-20.
//

#ifndef COMMNET_HEAD_H
#define COMMNET_HEAD_H
#define MAXIMUM 1000000
#define netFilename "chinese_ver_nodes"
#define linkFilename "chinese_ver_links"
#define delete_node_Filename "delete_nodes"


#include "node.h"
#include <vector>
#include <math.h>
int nodeRead();
int linkRead();
extern map<string, NetNode> net_map;
extern map<int, string> number;
extern vector<double> value_list;
extern double **weight_matrix;
extern int len;
extern double **locus_weight_matrix;
extern double max_min_weight;
extern vector<int> dn;

int dijkstra();
double aveLen();
int netChange();
void netPrint();






#endif //COMMNET_HEAD_H
