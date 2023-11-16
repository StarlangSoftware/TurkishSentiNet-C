//
// Created by Olcay Taner YILDIZ on 16.11.2023.
//
#include <string.h>
#include "PolarityType.h"

Polarity_type get_polarity_type(const char *polarity) {
    if (strcmp(polarity, "positive") == 0 || strcmp(polarity, "pos") == 0){
        return POLARITY_POSITIVE;
    } else {
        if (strcmp(polarity, "negative") == 0 || strcmp(polarity, "neg") == 0){
            return POLARITY_NEGATIVE;
        } else {
            return POLARITY_NEUTRAL;
        }
    }
}

char *polarity_to_string(Polarity_type polarity_type) {
    switch (polarity_type) {
        default:
        case POLARITY_NEUTRAL:
            return "NEUTRAL";
        case POLARITY_POSITIVE:
            return "POSITIVE";
        case POLARITY_NEGATIVE:
            return "NEGATIVE";
    }
}
