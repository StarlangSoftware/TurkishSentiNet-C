//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//
#include "../src/SentiNet.h"
#include <stdio.h>
#include <Memory/Memory.h>

void getPositives(Senti_net_ptr senti_net) {
    Array_list_ptr list = get_positive_synsets(senti_net);
    if (list->size != 3100) {
        printf("Test Failed in getPositives\n");
    }
    free_array_list(list, NULL);
}

void getNegatives(Senti_net_ptr senti_net) {
    Array_list_ptr list = get_negative_synsets(senti_net);
    if (list->size != 10191) {
        printf("Test Failed in getNegatives\n");
    }
    free_array_list(list, NULL);
}

void getNeutrals(Senti_net_ptr senti_net) {
    Array_list_ptr list = get_neutral_synsets(senti_net);
    if (list->size != 63534) {
        printf("Test Failed in getNeutrals\n");
    }
    free_array_list(list, NULL);
}

int main() {
    Senti_net_ptr senti_net = create_senti_net();
    getPositives(senti_net);
    getNegatives(senti_net);
    getNeutrals(senti_net);
    free_senti_net(senti_net);
}