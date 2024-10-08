#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

template<typename T>
struct MyArray {
    T* data;       // Указатель на массив
    size_t capacity; // Вместимость массива
    size_t size;     // Текущий размер массива


    MyArray() : capacity(10), size(0) { // Инициализация массива
        data = new T[capacity]; 
    }

    ~MyArray() { // Освобождение памяти
        delete[] data;
    }

    void resize() { // ф-ия увеличения вместимости
        capacity *= 2; 
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i]; // Копируем старые данные
        }
        delete[] data; // Освобождаем старый массив
        data = newData; // Указываем на новый массив
    }

    void add(T value) { // ф-ия добавления элемента в конец массива
        if (size == capacity) {
            resize(); // Увеличиваем массив, если он заполнен
        }
        data[size++] = value;
    }

    void addAt(size_t index, T value) { // ф-ия добавления элемента по индексу
        if (index > size) {
            throw out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(); // Увеличиваем массив, если он заполнен
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1]; // Сдвигаем элементы вправо
        }
        data[index] = value;
        ++size;
    }

    int get(size_t index) const { // ф-ия получения элемента по индексу
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void remove(size_t index) { // ф-ия удаления элемента по индексу
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1]; // Сдвигаем элементы влево
        }
        --size; // Уменьшаем размер
    }

    void replace(size_t index, T value) { // ф-ия замены элемента по индексу
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = value; // Заменяем элемент по индексу
    }

    size_t length() { // ф-ия вывода размера массива
        return size; 
    }

    void print() { // ф-ия вывода массива
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {} // конструктор узла
};
template<typename T>
struct SinglyLinkedList {
    Node<T>* head;

    SinglyLinkedList() : head(nullptr) {} // конструктор листа

    void print() { // ф-ия вывода списка
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void push_front(T value) { // ф-ия добавления элемента в начало
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T value) { // ф-ия добавления элемента в конец
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void pop_front() { // ф-ия удаления элемента с начала
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() { // ф-ия удаления элемента с конца
        if (head == nullptr) return;
        if (!head->next) { // если только 1 элемент
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next; // Удаляем последний элемент
        current->next = nullptr; // Обнуляем указатель
    }

    void remove(T value) { // ф-ия удаления элемента по значению
        if (head == nullptr) return;
        if (head->data == value) {
            pop_front();
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool find(T value) { // ф-ия нахождения элемента по значению
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true; // Элемент найден
            }
            current = current->next;
        }
        return false; // Элемент не найден
    }

    ~SinglyLinkedList() { // деструктор
        while (head) {
            pop_front();
        }
    }
    
};

template <typename T>
struct Node2 {
    T data;
    Node2* next;
    Node2* prev;

    Node2(T value) : data(value), next(nullptr), prev(nullptr) {} // конструктор узла
};
template <typename T>
struct DoublyLinkedList {
    Node2<T>* head;
    Node2<T>* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {} // конструктор листа

    void print() { // ф-ия вывода списка
        Node2<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void push_front(T value) { // ф-ия добавления элемента в начало
        Node2<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T value) { // ф-ия добавления элемента в конец
        Node2<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() { // ф-ия удаления элемента в начале
        if (head == nullptr) return;
        Node2<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // Список стал пустым
        }
        delete temp;
    }

    void pop_back() { // ф-ия удаления элемента в конце
        if (tail == nullptr) return; // Список пуст
        Node2<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // Список стал пустым
        }
        delete temp;
    }

    void remove(T value) { // ф-ия удаления элемента по значению
        Node2<T>* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; // Удаляем голову
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; // Удаляем хвост
                }
                delete current;
                return; // Выход после удаления первого найденного элемента
            }
            current = current->next;
        }
    }

    bool find(T value) { // ф-ия поиска элемента по значению
        Node2<T>* current = head;
        while (current) {
            if (current->data == value) {
                return true; // Элемент найден
            }
            current = current->next;
        }
        return false; // Элемент не найден
    }

    ~DoublyLinkedList() { // деструктор списка
        while (head) {
            pop_front();
        }
    }
};

template <typename T>
struct Stack {
    T* data;        // Указатель на массив данных
    int top;        // Индекс верхнего элемента
    int capacity;   // Вместимость стека

    Stack(int size) : capacity(size), top(-1) { // конструктор
        data = new T[capacity];
    }

    ~Stack() { // деструктор
        delete[] data; 
    }

    void push(T value) { // ф-ия добавления элемента
        if (top == capacity - 1) {
            throw overflow_error("Стек переполнен"); // Проверка на переполнение
        }
        data[++top] = value; // Увеличение индекса и добавление элемента
    }

    T pop() { // ф-ия удаления элемента и возврат значения
        if (top == -1) {
            throw underflow_error("Стек пуст"); // Проверка на пустоту
        }
        return data[top--]; // Возврат верхнего элемента и уменьшение индекса
    }

    void peek() { // ф-ия вывода вершины стэка
        if (top == -1) {
            throw underflow_error("Стек пуст"); // Проверка на пустоту
        }
        cout << data[top] << endl; // вывод верхнего элемента без его удаления
    }

    bool isEmpty() { // ф-ия проверки стэка на пустоту
        return top == -1;
    }

    int size() { // ф-ия размера стэка
        return top + 1;
    }
};

template <typename T>
struct Queue {
    T* data;        // Указатель на массив данных
    int front;      // Индекс первого элемента
    int rear;       // Индекс последнего элемента
    int capacity;   // Вместимость очереди
    int size;       // Текущий размер очереди

    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) { // конструктор
        data = new T[capacity];
    }

    ~Queue() { // деструктор
        delete[] data;
    }

    void push(T value) { // ф-ия добавления элемента в конец очереди
        if (size == capacity) {
            throw overflow_error("Очередь переполнена"); // Проверка на переполнение
        }
        rear = (rear + 1) % capacity; // Циклическое увеличение индекса
        data[rear] = value; // Добавление элемента
        size++; // Увеличение размера очереди
    }

    T pop() { // ф-ия удаления элемента с начала очереди и его возврат
        if (size == 0) {
            throw underflow_error("Очередь пуста"); // Проверка на пустоту
        }
        T value = data[front]; // Сохранение значения для возврата
        front = (front + 1) % capacity; // Циклическое увеличение индекса
        size--; // Уменьшение размера очереди
        return value; // Возврат удаленного элемента
    }

    T peek() { // ф-ия вывода элемента в начале очереди
        if (size == 0) {
            throw underflow_error("Очередь пуста"); // Проверка на пустоту
        }
        cout << data[front] << endl;
    }

    bool isEmpty() { // ф-ия проверки очереди на пустоту
        return size == 0;
    }

    int getSize() { // ф-ия получения размера очереди
        return size;
    }
};

const int TABLE_SIZE = 10; // Размер таблицы
template<typename T>
struct KeyValuePair {
    string key;
    T value;
    KeyValuePair* next; // Указатель на следующий элемент (для цепочек)
};
template<typename T>
struct HashTable {
    KeyValuePair<T>* table[TABLE_SIZE]; // Массив указателей на элементы

    HashTable() { // Инициализация массива указателей
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    int hashFunction(const string& key) { // Хеш-функция
        hash<string> hashFn;
        return hashFn(key) % TABLE_SIZE;
    }

    void insert(const string& key, T value) { // ф-ия добавления элемента
        int index = hashFunction(key);
        KeyValuePair<T>* newPair = new KeyValuePair<T>{key, value, nullptr};

        if (!table[index]) {
            table[index] = newPair; // Если ячейка пустая, добавляем новый элемент
        } else {
            KeyValuePair<T>* current = table[index];
            while (current->next) {
                if (current->key == key) {
                    current->value = value; // Обновляем значение, если ключ существует
                    delete newPair; // Удаляем временный элемент
                    return;
                }
                current = current->next;
            }
            current->next = newPair; // Добавляем новый элемент в конец цепочки
        }
    }

    bool get(const string& key, T& value) { // ф-ия получения элемента по ключу
        int index = hashFunction(key);
        KeyValuePair<T>* current = table[index];
        while (current) {
            if (current->key == key) {
                value = current->value; // Возвращаем значение
                return true; // Успешное получение
            }
            current = current->next;
        }
        return false; // Ключ не найден
    }

    bool remove(const string& key) { // ф-ия удаления элемента по ключу
        int index = hashFunction(key);
        KeyValuePair<T>* current = table[index];
        KeyValuePair<T>* previous = nullptr;

        while (current) {
            if (current->key == key) {
                if (previous) {
                    previous->next = current->next; // Удаляем элемент из цепочки
                } else {
                    table[index] = current->next; // Если это первый элемент в цепочке
                }
                delete current; // Освобождаем память
                return true; // Успешное удаление
            }
            previous = current;
            current = current->next;
        }
        return false; // Ключ не найден
    }

    ~HashTable() { // деструктор
        for (int i = 0; i < TABLE_SIZE; ++i) {
            KeyValuePair<T>* current = table[i];
            while (current) {
                KeyValuePair<T>* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
    }
};

struct NodeT {
    int data;
    NodeT* left;
    NodeT* right;

    NodeT(int value) : data(value), left(nullptr), right(nullptr) {}
};
struct CompleteBinaryTree {
    NodeT* root;
    int size;

    CompleteBinaryTree() : root(nullptr), size(0) {}

    void insert(int value) { // ф-ия добавления элемента
        NodeT* newNode = new NodeT(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            // Используем массив для хранения узлов для упрощения вставки
            NodeT** nodes = new NodeT*[size + 1];
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

    bool search(NodeT* node, int value) { // ф-ия поиска элемента
        if (node == nullptr) return false;
        if (node->data == value) return true;
        return search(node->left, value) || search(node->right, value);
    }

    bool isComplete(NodeT* node, int index, int totalNodes) { // проверка на complete
        if (node == nullptr) return true;
        if (index >= totalNodes) return false;
        return isComplete(node->left, 2 * index + 1, totalNodes) &&
               isComplete(node->right, 2 * index + 2, totalNodes);
    }

    void fillArray(NodeT** arr, NodeT* node, int index = 0) { // Заполнение массива узлов
        if (node == nullptr) return;
        arr[index] = node;
        fillArray(arr, node->left, 2 * index + 1);
        fillArray(arr, node->right, 2 * index + 2);
    }

    void printTree(NodeT* node, int depth = 0) { // функция вывода дерева на экран
        if (node == nullptr) return;

        // Сначала выводим правое поддерево
        printTree(node->right, depth + 1);

        // Затем выводим текущий узел
        std::cout << setw(4 * depth) << " " << node->data << endl;

        // Затем выводим левое поддерево
        printTree(node->left, depth + 1);
    }

    void clear(NodeT* node) { // освобождение памяти
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~CompleteBinaryTree() {
        clear(root);
    }
};

int main() {

    CompleteBinaryTree tree;

    tree.insert(5);
    tree.insert(20);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.printTree(tree.root);

    return 0;
}