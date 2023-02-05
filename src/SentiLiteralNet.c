//
// Created by Olcay Taner YILDIZ on 4.02.2023.
//

#include <stdlib.h>
#include <XmlElement.h>
#include <XmlDocument.h>
#include <string.h>
#include <HashMap/HashNode.h>
#include "SentiLiteralNet.h"
#include "SentiLiteral.h"

/**
 * Constructor of Turkish SentiNet. Reads the turkish_sentiliteralnet.xml file. For each
 * sentiSynSet read, it adds it to the sentiSynSetList.
 */
Senti_literal_net_ptr create_senti_literal_net() {
    Senti_literal_net_ptr result = malloc(sizeof(Senti_literal_net));
    result->senti_literal_list = create_hash_map((int (*)(void *, int)) hash_function_string,
                                                 (int (*)(void *, void *)) compare_string);
    load_senti_literal_net(result, "turkish_sentiliteralnet.xml");
    return result;
}

void free_senti_literal_net(Senti_literal_net_ptr senti_literal_net) {
    free_hash_map(senti_literal_net->senti_literal_list, (void (*)(void *)) free_senti_literal);
    free(senti_literal_net);
}

void load_senti_literal_net(Senti_literal_net_ptr senti_literal_net, char *file_name) {
    Xml_element_ptr rootNode, sentiSynSetNode, partNode;
    char* name = NULL;
    double positiveScore = 0.0, negativeScore = 0.0;
    Xml_document_ptr doc = create_xml_document(file_name);
    parse(doc);
    rootNode = doc->root;
    sentiSynSetNode = rootNode->first_child;
    while (sentiSynSetNode != NULL){
        partNode = sentiSynSetNode->first_child;
        while (partNode != NULL){
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
        if (name != NULL){
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
Senti_literal_ptr get_senti_literal(Senti_literal_net_ptr senti_literal_net, char *name) {
    if (hash_map_contains(senti_literal_net->senti_literal_list, name)){
        return hash_map_get(senti_literal_net->senti_literal_list, name);
    } else {
        return NULL;
    }
}

/**
 * Constructs and returns an {@link vector} of ids, which are the ids of the {@link SentiLiteral}s having polarity
 * polarityType.
 * @param polarityType PolarityTypes of the searched {@link SentiLiteral}s
 * @return An array of id having polarityType polarityType.
 */
Array_list_ptr get_literals_with_polarity(Senti_literal_net_ptr senti_literal_net, Polarity_type polarity_type) {
    Array_list_ptr result = create_array_list();
    Array_list_ptr list = key_value_list(senti_literal_net->senti_literal_list);
    for (int i = 0; i < list->size; i++){
        Hash_node_ptr hash_node = array_list_get(list, i);
        if (get_polarity_literal(hash_node->value) == polarity_type){
            array_list_add(result, hash_node->key);
        }
    }
    free_array_list(list, NULL);
    return result;
}

/**
 * Returns the ids of all positive {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all positive {@link SentiLiteral}s.
 */
Array_list_ptr get_positive_literals(Senti_literal_net_ptr senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, POSITIVE);
}

/**
 * Returns the ids of all negative {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all negative {@link SentiLiteral}s.
 */
Array_list_ptr get_negative_literals(Senti_literal_net_ptr senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, NEGATIVE);
}

/**
 * Returns the ids of all neutral {@link SentiLiteral}s.
 * @return A {@link vector} of ids of all neutral {@link SentiLiteral}s.
 */
Array_list_ptr get_neutral_literals(Senti_literal_net_ptr senti_literal_net) {
    return get_literals_with_polarity(senti_literal_net, NEUTRAL);
}
