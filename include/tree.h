#pragma once

#include "includes.h"

template<typename T>
struct NodeT {
    T data;
    NodeT* left;
    NodeT* right;

    NodeT(T value);
};

template<typename T>
struct CompleteBinaryTree {
    NodeT<T>* root;
    int size;

    CompleteBinaryTree();
    ~CompleteBinaryTree();

    void insert(T value); // ф-ия добавления элемента
    bool search(NodeT<T>* node, T value); // ф-ия поиска элемента
    bool isComplete(NodeT<T>* node, int index, int totalNodes); // проверка на complete
    void fillArray(NodeT<T>** arr, NodeT<T>* node, int index = 0); // Заполнение массива узлов
    string toString(NodeT<T>* node);
    void printTree(NodeT<T>* node, int depth = 0); // функция вывода дерева на экран
    void clear(NodeT<T>* node);// освобождение памяти
};

#include "../src/tree.cpp" // Включаем реализацию шаблона