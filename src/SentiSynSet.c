//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "SentiSynSet.h"

/**
 * Constructor of SentiSynSet. Gets input _id, positiveScore, negativeScore and sets all corresponding attributes.
 * @param id Id of the SentiSynSet.
 * @param positive_score Positive score of the SentiSynSet.
 * @param negative_score Negative score of the SentiSynSet.
 */
Senti_synset_ptr create_senti_synset(char *id, double positive_score, double negative_score) {
    Senti_synset_ptr result = malloc(sizeof(Senti_synset));
    result->id = str_copy(result->id, id);
    result->positive_score = positive_score;
    result->negative_score = negative_score;
    return result;
}

void free_senti_synset(Senti_synset_ptr senti_synset) {
    free(senti_synset->id);
    free(senti_synset);
}

/**
 * Returns the polarityType of the sentiSynSet. If the positive score is larger than the negative score, the polarity is
 * positive; if the negative score is larger than the positive score, the polarity is negative; if both positive
 * score and negative score are equal, the polarity is neutral.
 * @return PolarityType of the sentiSynSet.
 */
Polarity_type get_polarity_synset(Senti_synset_ptr senti_synset) {
    if (senti_synset->positive_score > senti_synset->negative_score) {
        return POSITIVE;
    } else {
        if (senti_synset->positive_score < senti_synset->negative_score) {
            return NEGATIVE;
        } else {
            return NEUTRAL;
        }
    }
}
