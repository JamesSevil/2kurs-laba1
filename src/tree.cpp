#include "../include/tree.h"

template<typename T>
NodeT<T>::NodeT(T value) : data(value), left(nullptr), right(nullptr) {}

template<typename T>
CompleteBinaryTree<T>::CompleteBinaryTree() : root(nullptr), size(0) {}

template<typename T>
void CompleteBinaryTree<T>::insert(T value) {
    NodeT<T>* newNode = new NodeT<T>(value);
    if (root == nullptr) {
        root = newNode;
    } else {
        // Используем массив для хранения узлов для упрощения вставки
        NodeT<T>** nodes = new NodeT<T>*[size + 1];
        fillArray(nodes, root);
        nodes[size] = newNode;

        // Вставка в полный бинарный дерево
        for (int i = 0; i < size; ++i) {
            if (nodes[i] != nullptr) {
                if (nodes[i]->left == nullptr) {
                    nodes[i]->left = newNode;
                    break;
                } else if (nodes[i]->right == nullptr) {
                    nodes[i]->right = newNode;
                    break;
                }
            }
        }

        delete[] nodes;
    }
    size++;
}

template<typename T>
bool CompleteBinaryTree<T>::search(NodeT<T>* node, T value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    return search(node->left, value) || search(node->right, value);
}

template<typename T>
bool CompleteBinaryTree<T>::isComplete(NodeT<T>* node, int index, int totalNodes) {
    if (node == nullptr) return true;
    if (index >= totalNodes) return false;
    return isComplete(node->left, 2 * index + 1, totalNodes) &&
            isComplete(node->right, 2 * index + 2, totalNodes);
}

template<typename T>
void CompleteBinaryTree<T>::fillArray(NodeT<T>** arr, NodeT<T>* node, int index) {
    if (node == nullptr) return;
    arr[index] = node;
    fillArray(arr, node->left, 2 * index + 1);
    fillArray(arr, node->right, 2 * index + 2);
}

template<typename T>
string CompleteBinaryTree<T>::toString(NodeT<T>* node) { // Функция для получения строки из элементов дерева
    if (node == nullptr) return "";

    ostringstream oss;
    oss << node->data << " "; // Добавляем текущий узел

    // Рекурсивно добавляем элементы из левого и правого поддеревьев
    oss << toString(node->left);
    oss << toString(node->right);

    return oss.str();
}

template<typename T>
void CompleteBinaryTree<T>::printTree(NodeT<T>* node, int depth) {
    if (node == nullptr) return;

    // Сначала выводим правое поддерево
    printTree(node->right, depth + 1);

    // Затем выводим текущий узел
    cout << setw(4 * depth) << " " << node->data << endl;

    // Затем выводим левое поддерево
    printTree(node->left, depth + 1);
}

template<typename T>
void CompleteBinaryTree<T>::clear(NodeT<T>* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
CompleteBinaryTree<T>::~CompleteBinaryTree() {
    clear(root);
}