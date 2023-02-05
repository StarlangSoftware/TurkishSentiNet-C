//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include "../src/SentiLiteralNet.h"
#include <stdio.h>

void getPositives(Senti_literal_net_ptr senti_net){
    if (get_positive_literals(senti_net)->size != 4335){
        printf("Test Failed in getPositives\n");
    }
}

void getNegatives(Senti_literal_net_ptr senti_net){
    if (get_negative_literals(senti_net)->size != 13011){
        printf("Test Failed in getNegatives\n");
    }
}

void getNeutrals(Senti_literal_net_ptr senti_net){
    if (get_neutral_literals(senti_net)->size != 62379){
        printf("Test Failed in getNeutrals\n");
    }
}

int main(){
    Senti_literal_net_ptr senti_net = create_senti_literal_net();
    getPositives(senti_net);
    getNegatives(senti_net);
    getNeutrals(senti_net);
    free_senti_literal_net(senti_net);
}