//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#ifndef SENTINET_POLARITYTYPE_H
#define SENTINET_POLARITYTYPE_H

enum polarity_type {
    POLARITY_POSITIVE, POLARITY_NEGATIVE, POLARITY_NEUTRAL
};

typedef enum polarity_type Polarity_type;

Polarity_type get_polarity_type(const char* polarity);

char* polarity_to_string(Polarity_type polarity_type);

#endif //SENTINET_POLARITYTYPE_H
