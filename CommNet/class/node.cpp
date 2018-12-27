#include <utility>

//
// Created by 长颈鹿 on 2018-12-20.
//

#include "node.h"

void NetNode :: w_name(string name){
    Name = std::move(name);
}
void NetNode :: w_value(double value){
    Value = value;
}
string NetNode :: r_name(){
    return Name;
}
double NetNode :: r_value(){
    return Value;
}
void NetNode :: w_node(string name, double value){
    Name = std::move(name);
    Value = value;
}
void NetNode :: w_num(int num){
    Num = num;
}
int NetNode :: r_num(){
    return Num;
}
void NetNode:: r_locus(string name, vector<string>& names){
    names.clear();
    for (const auto &i : Locus[name]) names.push_back(i);
}


void NetNode :: set_weight(string name, double weight){
    Weight[name] = weight;
}
void NetNode :: set_locus(string name, vector<string> locus_names){
    Locus[name] = std::move(locus_names);
}
void NetNode :: add_locus(string name, string next_name){
    Locus[name].push_back(next_name);
}
void NetNode :: add_locus_list(string name, vector<string> next_name){
    for (const auto &i : next_name) this->add_locus(name, i);
}
void NetNode :: headadd_locus(string name, string next_name){
    Locus[name].insert(Locus[name].begin(), next_name);
}
void NetNode :: headadd_locus_list(string name, vector<string> next_name){
    //for (int i = static_cast<int>(next_name.size() - 1); i >= 0; --i) this->headadd_locus(name, next_name[i]);
    for (const auto &i : next_name) {
        this->headadd_locus(name, i);
    }
}
void NetNode :: renew_locus(string name, vector<string> names, char state){
    this->Locus[name].clear();
    if (state == 'p'){
        this->add_locus_list(name, names);
    }
    if (state == 'n'){
        this->headadd_locus_list(name, names);
    }
}
void NetNode :: print_locus(string name){
    cout << r_name() << " -> " << name << ": " << Name;
    for (const auto &i : Locus[name]) {
        cout << " -> " << i;
    }
}
void NetNode :: print_all(){
    for (auto &Locu : Locus) {
        print_locus(Locu.first);
        cout << endl;
    }
}