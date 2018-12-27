//
// Created by 长颈鹿 on 2018-12-20.
//

#ifndef COMMNET_NODE_H
#define COMMNET_NODE_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class NetNode {
public:
    void w_name(string name);
    void w_value(double value);
    void w_node(string name, double value);
    void w_num(int num);
    string r_name();
    double r_value();
    int r_num();
    void r_locus(string name, vector<string>& names);

    void set_weight(string name, double weight);
    void set_locus(string name, vector<string> locus_names);
    void add_locus(string name, string next_name);
    void add_locus_list(string name, vector<string> next_name);
    void headadd_locus(string name, string next_name);
    void headadd_locus_list(string name, vector<string> next_name);
    void renew_locus(string name, vector<string> names, char state);
    void print_locus(string name);
    void print_all();
private:
    string Name;
    double Value;
    int Num;
    map<string,double> Weight;
    map<string,vector<string>> Locus;
};


#endif //COMMNET_NODE_H
