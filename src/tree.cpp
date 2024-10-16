#include "../include/tree.h"

NodeT::NodeT(int value) : data(value), left(nullptr), right(nullptr) {}


BinaryTree::BinaryTree() : root(nullptr), size(0) {}
BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::insert(int value) {
    root = insertRec(root, value);
    size++;
}

bool BinaryTree::search(int value) {
    return searchRec(root, value);
}

bool BinaryTree::isComplete() {
    int nodeCount = countNodes(root);
    return isCompleteRec(root, 0, nodeCount);
}

string BinaryTree::toString() {
    return toStringRec(root);
}

void BinaryTree::print() {
    printTreeRec(root, 0);
    cout << endl;
}



NodeT* BinaryTree::insertRec(NodeT* node, int value) {
    if (node == nullptr) {
        return new NodeT(value);
    }
    if (value < node->data) {
        node->left = insertRec(node->left, value);
    } else {
        node->right = insertRec(node->right, value);
    }
    return node;
}

bool BinaryTree::searchRec(NodeT* node, int value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;

    if (value < node->data) {
        return searchRec(node->left, value);
    } else {
        return searchRec(node->right, value);
    }
}

int BinaryTree::countNodes(NodeT* node) {
    if (node == nullptr) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

bool BinaryTree::isCompleteRec(NodeT* node, int index, int numberNodes) {
    if (node == nullptr) return true;
    if (index >= numberNodes) return false;

    return isCompleteRec(node->left, 2 * index + 1, numberNodes) &&
            isCompleteRec(node->right, 2 * index + 2, numberNodes);
}

string BinaryTree::toStringRec(NodeT* node) {
    if (node == nullptr) return "";

    ostringstream oss;
    oss << node->data << " "; // Добавляем текущий узел

    // Рекурсивно добавляем элементы из левого и правого поддеревьев
    oss << toStringRec(node->left);
    oss << toStringRec(node->right);

    return oss.str();
}

void BinaryTree::printTreeRec(NodeT* node, int depth) {
    if (node == nullptr) return;

    // Сначала выводим правое поддерево
    printTreeRec(node->right, depth + 1);

    // Затем выводим текущий узел
    cout << setw(4 * depth) << " " << node->data << endl;

    // Затем выводим левое поддерево
    printTreeRec(node->left, depth + 1);
}

void BinaryTree::destroyTree(NodeT* node) {
    if (node != nullptr) {
        destroyTree(node->left);   // Освобождаем левое поддерево
        destroyTree(node->right);  // Освобождаем правое поддерево
        delete node;               // Освобождаем текущий узел
    }
}