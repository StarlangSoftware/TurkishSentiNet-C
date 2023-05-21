//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#ifndef SENTINET_SENTINET_H
#define SENTINET_SENTINET_H

#include <HashMap/HashMap.h>
#include "SentiSynSet.h"

struct senti_net {
    Hash_map_ptr senti_synset_list;
};

typedef struct senti_net Senti_net;
typedef Senti_net *Senti_net_ptr;

Senti_net_ptr create_senti_net();

void free_senti_net(Senti_net_ptr senti_net);

void load_senti_net(Senti_net_ptr senti_net, const char *file_name);

Senti_synset_ptr get_senti_synset(const Senti_net* senti_net, const char *id);

Array_list_ptr get_synsets_with_polarity(const Senti_net* senti_net, Polarity_type polarity_type);

Array_list_ptr get_positive_synsets(const Senti_net* senti_net);

Array_list_ptr get_negative_synsets(const Senti_net* senti_net);

Array_list_ptr get_neutral_synsets(const Senti_net* senti_net);

void remove_senti_synset(Senti_net_ptr senti_net, Senti_synset_ptr senti_synset);


#endif //SENTINET_SENTINET_H
