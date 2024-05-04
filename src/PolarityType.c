//
// Created by Olcay Taner YILDIZ on 16.11.2023.
//
#include <string.h>
#include "PolarityType.h"

/**
 * Returns the polarity type of a string. If the string is pos or positive, it returns POLARITY_POSITIVE.
 * If the string is neg or negative, it returns POLARITY_NEGATIVE. For all other cases, it returns POLARITY_NEUTRAL.
 * @param polarity
 * @return
 */
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

/**
 * Converts polarity type to string. If the polarity type is POLARITY_POSITIVE, it returns "POSITIVE". If the polarity
 * type is POLARITY_NEGATIVE, it returns "NEGATIVE". Otherwise it returns "NEUTRAL".
 * @param polarity_type Polarity type
 * @return Returns "POSITIVE", "NEGATIVE", or "NEUTRAL" depending on the polarity type.
 */
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
