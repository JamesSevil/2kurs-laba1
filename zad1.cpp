#include <iostream>

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
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} // конструктор узла
};
template<typename T>
struct LinkedList {
    Node<T>* head;

    LinkedList() : head(nullptr) {} // конструктор листа

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

    ~LinkedList() { // деструктор
        while (head) {
            pop_front();
        }
    }
    
};



int main() {

    // Массив
    cout << "Массив:" << endl;
    MyArray<int> arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.print();
    arr.remove(0);
    arr.print();
    arr.addAt(1, 15);
    arr.print();
    arr.replace(0, 1);
    arr.print();
    cout << "Элемент по индексу 2: " << arr.get(2) << endl;
    cout << "Размер массива: " << arr.length() << endl;

    //Список
    LinkedList<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(10);
    nums.push_front(2);
    nums.print();
    nums.pop_back();
    nums.pop_front();
    nums.remove(4);
    nums.print();
    cout << "Find 5: " << (nums.find(5) ? "Yes" : "No") << endl;
    


    return 0;
}