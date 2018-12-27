//
// Created by 长颈鹿 on 2018-12-20.
//

#include "commNet.h"
double **locus_weight_matrix;
double max_min_weight = 0;
int dijkstra(){
    string name;
    double *array;
    array = new double [len];
    double min;
    int key = 0;
    locus_weight_matrix = new double *[len];
    vector<string> names;
    for (int i = 0; i < len; ++i) {
        locus_weight_matrix[i] = new double [len];
    }
    array = new double [len];
    for (int i = len - 1; i >= 0; --i) {
        locus_weight_matrix[i][i] = 0;
        name = number[i];
        for (int j = 0; j < len; ++j) {
            array[j] = weight_matrix [i][j];
        }

        for (int j = 0; j < len - 1; ++j) {
            min = MAXIMUM;

            for (int k = 0; k < len; ++k) {
                if (array[k] <= min && array[k] != 0) {
                    key = k;
                    min = array[k];
                }
            }
            array[key] = 0;
            if (min == MAXIMUM){
                names.clear();
                names.emplace_back("null");
                net_map[name].renew_locus(number[key], names, 'p');
                net_map[name].set_weight(number[key], min);
                locus_weight_matrix[i][key] = min;
            }
            else {
                net_map[name].add_locus(number[key], number[key]);
                net_map[name].set_weight(number[key], min);
                //net_map[number[key]].add_locus(name, name);
                //net_map[number[key]].set_weight(name, min);
                locus_weight_matrix[i][key] = min;
                //locus_weight_matrix[key][i] = min;
                if (min > max_min_weight) max_min_weight = min;
                //cout << min << endl;
                for (int k = 0; k < len; ++k) {
                    //cout << array[k] << " ";
                    if (array[k] > min + weight_matrix[key][k]){
                        array[k] = min + weight_matrix[key][k];
                        names.clear();
                        net_map[name].r_locus(number[key],names);
                        net_map[name].renew_locus(number[k], names, 'p');
                        //net_map[number[k]].renew_locus(name, names, 'n');
                        //net_map[name].add_locus(number[k], number[key]);
                        //net_map[number[k]].headadd_locus(name, number[key]);
                    }
                }
            }

        }
        //delete [] array;
    }
    return 0;
}