#include "../include/includes.h"
#include "../include/array.h"
#include "../include/list.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/hashtable.h"
#include "../include/tree.h"

string Fulltext (string& filename, string& nameStruct) { // ф-ия сохранения фулл текста файла без нужной структуры
    string str, textfull;
    ifstream fileinput;
    fileinput.open(filename);
    while(getline(fileinput, str)) { // сохранение фулл текста в переменную
        stringstream ss(str);
        string token;
        getline(ss, token, ' ');
        if (token != nameStruct) {
            textfull += str + "\n";
        }
    }
    fileinput.close();
    return textfull;
}
void writefile (string& filename, string& textfull) { // ф-ия записи данных в файл
    ofstream fileoutput;
    fileoutput.open(filename);
    fileoutput << textfull;
    fileoutput.close();
}

Array<string> Mreadfile (string& filename, string& arrayName) {
    Array<string> nums;
    string str;
    ifstream fileinput;
    fileinput.open(filename);
    while (getline(fileinput, str)) { // добавления значения в массив
        stringstream ss(str);
        string token;
        getline(ss, token, ' ');
        if (token == arrayName) {
            while (getline(ss, token, ' ')) {
                nums.add(token);
            }
        }
    }
    fileinput.close();
    return nums;
}
void MADD(string& arrayName, string& value, string& filename) {
    string textfull = Fulltext(filename, arrayName); // весь файл
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0) {
        nums.add(value);
        str = arrayName + ' ';
        for (int i = 0; i < nums.length(); ++i) {
            str += nums.get(i) + ' ';
        }
        textfull += str;
        writefile(filename, textfull);
    } else { // создание массива, если его нет
        str = arrayName + ' ' + value;
        textfull += str;
        writefile(filename, textfull);
    }
}
void MADDAT(string& arrayName, string& value, int& index, string& filename) {
    string textfull = Fulltext(filename, arrayName);
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0 && index < nums.length()) {
        nums.addAt(index, value);
        str = arrayName + ' ';
        for (int i = 0; i < nums.length(); ++i) {
            str += nums.get(i) + ' ';
        }
        textfull += str;
        writefile(filename, textfull);
    } else if (nums.length() == 0 && index == 0){ // создание массива, если его нет
        str = arrayName + ' ' + value;
        textfull += str;
        writefile(filename, textfull);
    } else {
        cout << "Ошибка, индекс выходит за размеры массива!" << endl;
        exit(1);
    }
}
void MREMOVE (string& arrayName, int& index, string& filename) {
    string textfull = Fulltext(filename, arrayName);
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0 && index < nums.length()) {
        nums.remove(index);
        str = arrayName + ' ';
        for (int i = 0; i < nums.length(); ++i) {
            str += nums.get(i) + ' ';
        }
        textfull += str;
        writefile(filename, textfull);
    } else {
        cout << "Ошибка, нет такого массива или он пуст!" << endl;
        exit(1);
    }
}
void MREPLACE (string& arrayName, string& value, int& index, string& filename) {
    string textfull = Fulltext(filename, arrayName); // весь файл
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0 && index < nums.length()) {
        nums.replace(index, value);
        str = arrayName + ' ';
        for (int i = 0; i < nums.length(); ++i) {
            str += nums.get(i) + ' ';
        }
        textfull += str;
        writefile(filename, textfull);
    } else {
        cout << "Ошибка, нет такого массива или индекс выходит за его размеры!" << endl;
        exit(1);
    }
}
void MGET (string& arrayName, int& index, string& filename) {
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0 && index < nums.length()) {
        cout << nums.get(index) << endl;
    } else {
        cout << "Нет такого массива или индекс выходит за его размеры!" << endl;
        exit(1);
    }
}
void MSIZE(string& arrayName, string& filename) {
    Array<string> nums = Mreadfile(filename, arrayName);

    if (nums.length() != 0) {
        cout << nums.length() << endl;
    } else {
        cout << "Ошибка, нет такого массива или он пуст!" << endl;
        exit(1);
    }
}
void MPRINT(string& arrayName, string& filename) {
    Array<string> nums = Mreadfile(filename, arrayName);

    string str;
    if (nums.length() != 0) {
        nums.print();
    } else {
        cout << "Ошибка, нет такого массива или он пуст!" << endl;
        exit(1);
    }
}
void Mprocessing(string& command, string& filename) { // ф-ия обработки команд массива
    string name, value;
    int index;
    if (command.substr(0, 5) == "MADD ") {
        stringstream stream(command.substr(5));;
        stream >> name >> value;
        MADD(name, value, filename);
    } else if (command.substr(0, 7) == "MADDAT ") {
        stringstream stream(command.substr(7));
        stream >> name >> value >> index;
        MADDAT(name, value, index, filename);
    } else if (command.substr(0, 8) == "MREMOVE ") {
        stringstream stream(command.substr(8));
        stream >> name >> index;
        MREMOVE(name, index, filename);
    } else if (command.substr(0, 9) == "MREPLACE ") {
        stringstream stream(command.substr(9));
        stream >> name >> value >> index;
        MREPLACE(name, value, index, filename);
    } else if (command.substr(0, 5) == "MGET ") {
        stringstream stream(command.substr(5));
        stream >> name >> index;
        MGET(name, index, filename);
    } else if (command.substr(0, 6) == "MSIZE ") {
        stringstream stream(command.substr(6));
        stream >> name;
        MSIZE(name, filename);
    } else if (command.substr(0, 7) == "MPRINT ") {
        stringstream stream(command.substr(7));
        stream >> name;
        MPRINT(name, filename);
    } else {
        cout << "Ошибка, нет такой команды!" << endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Использование: " << argv[0] << " --file <filename> --query '<command>'" << endl;
        return 1;
    }

    // Разбор аргументов командной строки
    string filename;
    string query;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--file") {
            filename = argv[++i];
        } else if (string(argv[i]) == "--query") {
            query = argv[++i];
        }
    }

    // Обработка команды
    string name;
    int value, index;
    if (query.substr(0, 1) == "M") { // Массив
        Mprocessing(query, filename);
    } else {
        cout << "Ошибка, неизвестная принадлежность структуры данных!" << endl;
        return 1;
    }

    return 0;
}