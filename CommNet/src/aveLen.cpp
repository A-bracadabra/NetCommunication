//
// Created by 长颈鹿 on 2018-12-21.
//

#include "commNet.h"

double aveLen(){
    double temp;
    double ** unite_value;
    //double * _value_list = new double [len - dn.size()];
    //double ** _locus_weight_matrix;
    unite_value = new double * [len - dn.size()];
    //_locus_weight_matrix = new double * [len - dn.size()];
    int * mapping = new int [len - dn.size()];
    for (int i = 0; i < len - dn.size(); ++i) {
        unite_value[i] = new double [len - dn.size()];
        //_locus_weight_matrix[i] = new double [len - dn.size()];
    }
    double sum = 0, self_unite_sum = 0, weight_sum = 0;
    int k = 0;
    for (int i = 0; i < len - dn.size(); ++i) {
        for (int j : dn) {
            if (j == i) {
                k++;
                continue;
            }

        }
        sum += value_list[i + k];
        self_unite_sum += pow (value_list[i + k], 2);
        mapping[i] = i + k;
        //_value_list[k++] = value_list[i];
    }
    sum = pow (sum, 2);
    sum -= self_unite_sum;
    for (int i = 0; i < len - dn.size(); ++i) {
        for (int j = i; j < len - dn.size(); ++j) {
            temp = value_list[mapping[i]] * value_list[mapping[j]] / sum;
            weight_sum += temp * locus_weight_matrix[mapping[i]][mapping[j]] * 2;
            unite_value[i][j] = temp;
            unite_value[j][i] = temp;

        }
    }

    return weight_sum;
}