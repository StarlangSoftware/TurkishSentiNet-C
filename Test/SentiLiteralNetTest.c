//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include "../src/SentiLiteralNet.h"
#include <stdio.h>
#include <Memory/Memory.h>

void getPositives(Senti_literal_net_ptr senti_net) {
    Array_list_ptr list = get_positive_literals(senti_net);
    if (list->size != 4335) {
        printf("Test Failed in getPositives\n");
    }
    free_array_list(list, NULL);
}

void getNegatives(Senti_literal_net_ptr senti_net) {
    Array_list_ptr list = get_negative_literals(senti_net);
    if (list->size != 13011) {
        printf("Test Failed in getNegatives\n");
    }
    free_array_list(list, NULL);
}

void getNeutrals(Senti_literal_net_ptr senti_net) {
    Array_list_ptr list = get_neutral_literals(senti_net);
    if (list->size != 62379) {
        printf("Test Failed in getNeutrals\n");
    }
    free_array_list(list, NULL);
}

int main() {
    Senti_literal_net_ptr senti_net = create_senti_literal_net();
    getPositives(senti_net);
    getNegatives(senti_net);
    getNeutrals(senti_net);
    free_senti_literal_net(senti_net);
}