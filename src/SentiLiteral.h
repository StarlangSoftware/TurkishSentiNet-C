//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#ifndef SENTINET_SENTILITERAL_H
#define SENTINET_SENTILITERAL_H

#include "PolarityType.h"

struct senti_literal{
    char* name;
    double positive_score;
    double negative_score;
};

typedef struct senti_literal Senti_literal;
typedef Senti_literal* Senti_literal_ptr;

Senti_literal_ptr create_senti_literal(char* name,
                                       double positive_score,
                                       double negative_score);
void free_senti_literal(Senti_literal_ptr senti_literal);
Polarity_type get_polarity_literal(Senti_literal_ptr senti_literal);

#endif //SENTINET_SENTILITERAL_H
