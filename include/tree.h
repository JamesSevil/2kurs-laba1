#pragma once

#include "includes.h"

struct NodeT {
    int data;
    NodeT* left;
    NodeT* right;

    NodeT(int value);
};
struct BinaryTree {
    NodeT* root;
    int size;

    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    bool search(int value);
    bool isComplete();
    void print();
    string toString();

private:
    NodeT* insertRec(NodeT* node, int value);
    bool searchRec(NodeT* node, int value);
    int countNodes(NodeT* node);
    bool isCompleteRec(NodeT* node, int index, int numberNodes);
    void printTreeRec(NodeT* node, int depth);
    void destroyTree(NodeT* node);
    string toStringRec(NodeT* node);
};

#include "../src/tree.cpp" // Включаем реализацию шаблона