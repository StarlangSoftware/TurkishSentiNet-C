//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include <string.h>
#include <HashMap/HashNode.h>
#include <Memory/Memory.h>
#include "SentiLiteralNet.h"
#include "SentiLiteral.h"

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentiliteralnet.xml file. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
Senti_literal_net_ptr create_senti_literal_net() {
    Senti_literal_net_ptr result = malloc_(sizeof(Senti_literal_net), "create_senti_literal_net");
    result->senti_literal_list = create_string_hash_map();
    load_senti_literal_net(result, "turkish_sentiliteralnet.xml");
    return result;
}

/**
 * Destructor of the SentiLiteralNet. Frees memory allocated for the senti_literal_list hash map.
 * @param senti_literal_net Current senti literal net.
 */
void free_senti_literal_net(Senti_literal_net_ptr senti_literal_net) {
    free_hash_map(senti_literal_net->senti_literal_list, (void (*)(void *)) free_senti_literal);
    free_(senti_literal_net);
}

/**
 * Reads the Xml file that contains names of sentiLiterals and their positive, negative scores.
 * @param file_name Xml document that contains the SentiLiteralNet.
 */
void load_senti_literal_net(Senti_literal_net_ptr senti_literal_net, const char *file_name) {
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
            if (strcmp(partNode->name, "NAME") == 0) {
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
            hash_map_insert(senti_literal_net->senti_literal_list,
                            name,
                            create_senti_literal(name, positiveScore, negativeScore));
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
 * @param name Name of the searched SentiLiteral.
 * @return SentiSynSet with the given name.
 */
Senti_literal_ptr get_senti_literal(const Senti_literal_net* senti_literal_net, const char *name) {
    if (hash_map_contains(senti_literal_net->senti_literal_list, name)) {
        return hash_map_get(senti_literal_net->senti_literal_list, name);
    } else {
        return NULL;
    }
}

/**
 * Constructs and returns an vector of ids, which are the ids of the SentiLiterals having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched SentiLiterals
 * @return An array of id having polarityType polarityType.
 */
Array_list_ptr get_literals_with_polarity(const Senti_literal_net* senti_literal_net, Polarity_type polarity_type) {
    Array_list_ptr result = create_array_list();
    Array_list_ptr list = key_value_list(senti_literal_net->senti_literal_list);
    for (int i = 0; i < list->size; i++) {
        Hash_node_ptr hash_node = array_list_get(list, i);
        if (get_polarity_literal(hash_node->value) == polarity_type) {
            array_list_add(result, hash_node->key);
        }
    }
    free_array_list(list, NULL);
    return result;
}

/**
 * Returns the ids of all positive SentiLiterals.
 * @return A vector of ids of all positive SentiLiterals.
 */
Array_list_ptr get_positive_literals(const Senti_literal_net* senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, POLARITY_POSITIVE);
}

/**
 * Returns the ids of all negative SentiLiterals.
 * @return A vector of ids of all negative SentiLiterals.
 */
Array_list_ptr get_negative_literals(const Senti_literal_net* senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, POLARITY_NEGATIVE);
}

/**
 * Returns the ids of all neutral SentiLiterals.
 * @return A vector of ids of all neutral SentiLiterals.
 */
Array_list_ptr get_neutral_literals(const Senti_literal_net* senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, POLARITY_NEUTRAL);
}
