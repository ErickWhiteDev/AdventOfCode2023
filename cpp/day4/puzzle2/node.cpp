//
// Created by erick on 12/24/2023.
//

#include "node.h"

#include <utility>

Node* getNewNode(int cardNum, vector<int> characteristics, Node* parent) {
    Node* newNode = new Node();
    newNode->cardNum = cardNum;
    newNode->characteristics = std::move(characteristics);
    newNode->parent = parent;
    return newNode;
}

int countNodes(Node* node) {
    int count = 0;
    count++;
    for (Node* n : node->children) {
        count += countNodes(n);
    }
    return count;
}

void generateTree(Node* node) {
    int characteristic = node->characteristics.at(node->cardNum - 1);

    for (int i = 1; i <= characteristic; i++) {
        Node* child = getNewNode(node->cardNum + i, node->characteristics, node);
        node->children.push_back(child);
        generateTree(child);
    }
}

void deleteTree(Node* node) {
    for (Node* n : node->children) {
        deleteTree(n);
    }

    delete node;
}