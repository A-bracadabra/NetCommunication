//
// Created by 长颈鹿 on 2018-12-20.
//

#include "commNet.h"
#include <fstream>
map<string, NetNode> net_map;
map<int, string> number;
vector<double> value_list;
double **weight_matrix = {0};
int len = 0;
static vector<string> delete_names;
vector<int> dn;
int nodeRead(){
    ifstream fin;
    string name;
    int i = 0;
    NetNode net_node;
    double value;
    fin.open(netFilename);
    getline(fin,name);
    while(fin.good() && !fin.eof()) {
        fin >> name >> value;
        net_node.w_node(name,value);
        net_node.w_num(i);
        net_map[name] = net_node;
        number[i++] = name;
        value_list.push_back(value);
    }
    fin.close();
    fin.open(delete_node_Filename);
    while(fin.good() && !fin.eof()){
        fin >> name;
        dn.push_back(net_map[name].r_num());
    }
    fin.close();
    return 0;
}

int linkRead(){
    ifstream fin;
    string name1, name2;
    double weight;
    len = static_cast<int>(value_list.size());
    weight_matrix = new double * [len];
    for(int i = 0; i < len; ++i) {
        weight_matrix[i] = new double [len];
        for (int j = 0; j < len; ++j) {
            if(i == j)
                weight_matrix[i][j] = 0;
            else
                weight_matrix[i][j] = MAXIMUM;
        }
    }
    fin.open(linkFilename);
    getline(fin,name1);
    while(fin.good() && !fin.eof()){
        fin >> name1 >> name2 >>weight;
        net_map[name1].set_weight(name2, weight);
        net_map[name2].set_weight(name1, weight);
        weight_matrix[net_map[name1].r_num()][net_map[name2].r_num()] = weight;
        weight_matrix[net_map[name2].r_num()][net_map[name1].r_num()] = weight;
    }
    fin.close();
    return 0;
}
int netChange(){
    int _nodeRead();
    int _linkRead();
    extern map<string, NetNode> net_map;
    extern map<int, string> number;
    extern vector<double> value_list;
    extern double **weight_matrix;
    extern int len;
    extern double **locus_weight_matrix;
    net_map.clear();
    number.clear();
    value_list.clear();
    for (int i = 0; i < len; ++i) {
        delete [] weight_matrix[i];
        delete [] locus_weight_matrix[i];
    }



    ifstream fin;
    string name;
    fin.open(delete_node_Filename);
    while(fin.good() && !fin.eof()){
        fin >> name;
        delete_names.push_back(name);
    }
    fin.close();
    _nodeRead();
    _linkRead();
    dn.clear();
    return 0;
}
int _nodeRead(){
    ifstream fin;
    string name;
    int i = 0;
    NetNode net_node;
    double value;
    fin.open(netFilename);
    getline(fin,name);
    while(fin.good() && !fin.eof()) {
        fin >> name >> value;
        if (find(delete_names.begin(), delete_names.end(), name) != delete_names.end()) {
            continue;
        }
        net_node.w_node(name,value);
        net_node.w_num(i);
        net_map[name] = net_node;
        number[i++] = name;
        value_list.push_back(value);
    }
    fin.close();
    return 0;
}

int _linkRead(){
    ifstream fin;
    string name1, name2;
    double weight;
    len = value_list.size();
    weight_matrix = new double * [len];

    for(int i = 0; i < len; ++i) {
        weight_matrix[i] = new double [len];
        for (int j = 0; j < len; ++j) {
            if(i == j)
                weight_matrix[i][j] = 0;
            else
                weight_matrix[i][j] = MAXIMUM;
        }
    }

    fin.open(linkFilename);
    getline(fin,name1);
    while(fin.good() && !fin.eof()){
        fin >> name1 >> name2 >>weight;
        if (find(delete_names.begin(), delete_names.end(), name1) != delete_names.end()) {
            continue;
        }
        else if (find(delete_names.begin(), delete_names.end(), name2) != delete_names.end()) {
            continue;
        }
        net_map[name1].set_weight(name2, weight);
        net_map[name2].set_weight(name1, weight);
        weight_matrix[net_map[name1].r_num()][net_map[name2].r_num()] = weight;
        weight_matrix[net_map[name2].r_num()][net_map[name1].r_num()] = weight;
    }

    fin.close();
    return 0;
}
void netPrint(){
    for (int i = 0; i < len; ++i) {
        net_map[number[i]].print_all();
        cout << endl;
    }
}