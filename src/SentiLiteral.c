//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "SentiLiteral.h"

/**
 * Constructor of SentiLiteral. Gets input id, positiveScore, negativeScore and sets all corresponding attributes.
 * @param name Name of the SentiLiteral.
 * @param positive_score Positive score of the SentiLiteral.
 * @param negative_score Negative score of the SentiLiteral.
 */
Senti_literal_ptr create_senti_literal(char *name, double positive_score, double negative_score) {
    Senti_literal_ptr result = malloc(sizeof(Senti_literal));
    result->name = str_copy(result->name, name);
    result->positive_score = positive_score;
    result->negative_score = negative_score;
    return result;
}

void free_senti_literal(Senti_literal_ptr senti_literal) {
    free(senti_literal->name);
    free(senti_literal);
}

/**
 * Returns the polarityType of the SentiLiteral. If the positive score is larger than the negative score, the polarity is
 * positive; if the negative score is larger than the positive score, the polarity is negative; if both positive
 * score and negative score are equal, the polarity is neutral.
 * @return PolarityType of the SentiLiteral.
 */
Polarity_type get_polarity_literal(Senti_literal_ptr senti_literal) {
    if (senti_literal->positive_score > senti_literal->negative_score) {
        return POSITIVE;
    } else {
        if (senti_literal->positive_score < senti_literal->negative_score) {
            return NEGATIVE;
        } else {
            return NEUTRAL;
        }
    }
}
