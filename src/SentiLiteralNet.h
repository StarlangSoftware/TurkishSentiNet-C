//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#ifndef SENTINET_SENTILITERALNET_H
#define SENTINET_SENTILITERALNET_H

#include <HashMap/HashMap.h>
#include "SentiLiteral.h"

struct senti_literal_net{
    Hash_map_ptr senti_literal_list;
};

typedef struct senti_literal_net Senti_literal_net;
typedef Senti_literal_net* Senti_literal_net_ptr;

Senti_literal_net_ptr create_senti_literal_net();
void free_senti_literal_net(Senti_literal_net_ptr senti_literal_net);
void load_senti_literal_net(Senti_literal_net_ptr senti_literal_net, char* file_name);
Senti_literal_ptr get_senti_literal(Senti_literal_net_ptr senti_literal_net, char* name);
Array_list_ptr get_literals_with_polarity(Senti_literal_net_ptr senti_literal_net, Polarity_type polarity_type);
Array_list_ptr get_positive_literals(Senti_literal_net_ptr senti_literal_net);
Array_list_ptr get_negative_literals(Senti_literal_net_ptr senti_literal_net);
Array_list_ptr get_neutral_literals(Senti_literal_net_ptr senti_literal_net);

#endif //SENTINET_SENTILITERALNET_H
