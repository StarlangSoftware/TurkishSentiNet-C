//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//
#include "../src/SentiNet.h"
#include <stdio.h>

void getPositives(Senti_net_ptr senti_net){
    if (get_positive_synsets(senti_net)->size != 3100){
        printf("Test Failed in getPositives\n");
    }
}

void getNegatives(Senti_net_ptr senti_net){
    if (get_negative_synsets(senti_net)->size != 10191){
        printf("Test Failed in getNegatives\n");
    }
}

void getNeutrals(Senti_net_ptr senti_net){
    if (get_neutral_synsets(senti_net)->size != 63534){
        printf("Test Failed in getNeutrals\n");
    }
}

int main(){
    Senti_net_ptr senti_net = create_senti_net();
    getPositives(senti_net);
    getNegatives(senti_net);
    getNeutrals(senti_net);
    free_senti_net(senti_net);
}