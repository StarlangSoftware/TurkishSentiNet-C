//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#ifndef SENTINET_SENTISYNSET_H
#define SENTINET_SENTISYNSET_H

#include "PolarityType.h"

struct senti_synset{
    char* id;
    double positive_score;
    double negative_score;
};

typedef struct senti_synset Senti_synset;
typedef Senti_synset* Senti_synset_ptr;

Senti_synset_ptr create_senti_synset(char* id, double positive_score, double negative_score);
void free_senti_synset(Senti_synset_ptr senti_synset);
Polarity_type get_polarity_synset(Senti_synset_ptr senti_synset);

#endif //SENTINET_SENTISYNSET_H
