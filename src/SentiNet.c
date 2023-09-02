//
// Created by Olcay Taner YILDIZ on 5.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include <string.h>
#include <HashMap/HashNode.h>
#include "SentiNet.h"
#include "SentiSynSet.h"

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentinet.xml file. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
Senti_net_ptr create_senti_net() {
    Senti_net_ptr result = malloc(sizeof(Senti_net));
    result->senti_synset_list = create_string_hash_map();
    load_senti_net(result, "turkish_sentinet.xml");
    return result;
}

void free_senti_net(Senti_net_ptr senti_net) {
    free_hash_map(senti_net->senti_synset_list, (void (*)(void *)) free_senti_synset);
    free(senti_net);
}

void load_senti_net(Senti_net_ptr senti_net, const char *file_name) {
    Xml_element_ptr rootNode, sentiSynSetNode, partNode;
    char *name = NULL;
    double positiveScore = 0.0, negativeScore = 0.0;
    Xml_document_ptr doc = create_xml_document(file_name);
    parse(doc);
    rootNode = doc->root;
    sentiSynSetNode = rootNode->first_child;
    while (sentiSynSetNode != NULL) {
        partNode = sentiSynSetNode->first_child;
        while (partNode != NULL) {
            if (strcmp(partNode->name, "ID") == 0) {
                name = partNode->pcData;
            } else {
                if (strcmp(partNode->name, "PSCORE") == 0) {
                    positiveScore = atof(partNode->pcData);
                } else {
                    if (strcmp(partNode->name, "NSCORE") == 0) {
                        negativeScore = atof(partNode->pcData);
                    }
                }
            }
            partNode = partNode->next_sibling;
        }
        if (name != NULL) {
            hash_map_insert(senti_net->senti_synset_list,
                            name,
                            create_senti_synset(name, positiveScore, negativeScore));
        }
        sentiSynSetNode = sentiSynSetNode->next_sibling;
        name = NULL;
        positiveScore = 0.0;
        negativeScore = 0.0;
    }
    free_document(doc);
}

/**
 * Accessor for a single SentiSynSet.
 * @param id Id of the searched SentiSynSet.
 * @return SentiSynSet with the given id.
 */
Senti_synset_ptr get_senti_synset(const Senti_net* senti_net, const char *id) {
    if (hash_map_contains(senti_net->senti_synset_list, id)) {
        return hash_map_get(senti_net->senti_synset_list, id);
    } else {
        return NULL;
    }
}

/**
 * Constructs and returns an {@link vector} of ids, which are the ids of the {@link SentiSynSet}s having polarity
 * polarityType.
 * @param polarity_type PolarityTypes of the searched {@link SentiSynSet}s
 * @return A {@link vector} of id having polarityType polarityType.
 */
Array_list_ptr get_synsets_with_polarity(const Senti_net* senti_net, Polarity_type polarity_type) {
    Array_list_ptr result = create_array_list();
    Array_list_ptr list = key_value_list(senti_net->senti_synset_list);
    for (int i = 0; i < list->size; i++) {
        Hash_node_ptr hash_node = array_list_get(list, i);
        if (get_polarity_synset(hash_node->value) == polarity_type) {
            array_list_add(result, hash_node->key);
        }
    }
    free_array_list(list, NULL);
    return result;
}

/**
 * Returns the ids of all positive {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all positive {@link SentiSynSet}s.
 */
Array_list_ptr get_positive_synsets(const Senti_net* senti_net) {
    return get_synsets_with_polarity(senti_net, POSITIVE);
}

/**
 * Returns the ids of all negative {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all negative {@link SentiSynSet}s.
 */
Array_list_ptr get_negative_synsets(const Senti_net* senti_net) {
    return get_synsets_with_polarity(senti_net, NEGATIVE);
}

/**
 * Returns the ids of all neutral {@link SentiSynSet}s.
 * @return A {@link vector} of ids of all neutral {@link SentiSynSet}s.
 */
Array_list_ptr get_neutral_synsets(const Senti_net* senti_net) {
    return get_synsets_with_polarity(senti_net, NEUTRAL);
}

/**
 * Removes specified SentiSynSet from the SentiSynSet list.
 *
 * @param senti_synset SentiSynSet to be added
 */
void remove_senti_synset(Senti_net_ptr senti_net, Senti_synset_ptr senti_synset) {
    hash_map_remove(senti_net->senti_synset_list, senti_synset->id, (void (*)(void *)) free_senti_synset);
}
