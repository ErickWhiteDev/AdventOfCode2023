//
// Created by erick on 12/24/2023.
//

#ifndef ADVENTOFCODE2023_NODE_H
#define ADVENTOFCODE2023_NODE_H

#include <vector>
#include <string>

using namespace std;

struct Node {
    int cardNum;
    vector<int> characteristics;
    Node* parent;
    vector<Node*> children;
};

struct Node* getNewNode(int cardNum, vector<int> characteristics, Node* parent);

int countNodes(Node* node);

void generateTree(Node* node);

void deleteTree(Node* node);

#endif //ADVENTOFCODE2023_NODE_H
