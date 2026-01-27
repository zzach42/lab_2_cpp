#include "tasks.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Введите номер задачи:\n"
        << "1 - Вывод половин дека в обратном порядке\n"
        << "2 - Вставка последних 5 элементов дека в список\n"
        << "3 - Перемещение среднего элемента списка в вектор\n"
        << "4 - Удвоенные кодовые значения символов\n"
        << "5 - Удаление элементов между первыми двумя отрицательными\n"
        << "6 - Копирование положительных элементов\n"
        << "7 - Сортировка дека слов: сначала по алфавиту, потом по длине\n";

    int n;
    cin >> n;

    switch (n)
    {
    case 1: {
        deque<int> D;
        int colich;
        cout << "Введите количество элементов дека (четное): ";
        cin >> colich;
        for (int i = 0; i < colich; i++) { int x; cin >> x; D.push_back(x); }
        cout << "Созданный дек: "; PrintDeque(D);
        PrintPolDec(D);
        break;
    }
    case 2: {
        int n; cout << "Введите количество элементов дека (>=5): "; cin >> n;
        deque<int> D; for (int i = 0; i < n; i++) { int x; cin >> x; D.push_back(x); }
        cout << "Созданный дек: "; PrintDeque(D);
        int n1; cout << "Введите количество элементов списка (>=5): "; cin >> n1;
        list<int> L; for (int i = 0; i < n1; i++) { int x; cin >> x; L.push_back(x); }
        cout << "Созданный список: "; PrintList(L);
        InsertLast5DequeToList(D, L);
        cout << "Список после вставки: "; PrintList(L);
        break;
    }
    case 3: {
        int n; cout << "Введите количество элементов списка (нечетное): "; cin >> n;
        list<int> L; for (int i = 0; i < n; i++) { int x; cin >> x; L.push_back(x); }
        int m; cout << "Введите количество элементов вектора: "; cin >> m;
        vector<int> V; for (int i = 0; i < m; i++) { int x; cin >> x; V.push_back(x); }
        cout << "Список L: "; PrintList(L);
        cout << "Вектор V: "; PrintVector(V);
        MoveMiddleElement(L, V);
        cout << "После перемещения:\nСписок L: "; PrintList(L);
        cout << "Вектор V: "; PrintVector(V);
        cout << "Вектор V (обратный порядок): "; PrintVectorReverse(V);
        break;
    }
    case 4: {
        string name; cout << "Введите имя файла: "; cin >> name;
        cin.ignore();
        WriteDoubleCodesToFile(name);
        ReadAndPrintFromFile(name);
        break;
    }
    case 5: {
        int n; cout << "Введите количество элементов списка: "; cin >> n;
        list<int> L; for (int i = 0; i < n; ++i) { int x; cin >> x; L.push_back(x); }
        cout << "Исходный список:\n"; PrintList(L);
        RemoveBetweenNegatives(L);
        cout << "Список после обработки:\n"; PrintList(L);
        break;
    }
    case 6: {
        int n; cout << "Введите количество элементов списка (четное): "; cin >> n;
        list<int> L; for (int i = 0; i < n; ++i) { int x; cin >> x; L.push_back(x); }
        cout << "Исходный список:\n"; PrintList(L);
        CopyPositiveFromSecondHalf(L);
        cout << "Список после копирования:\n"; PrintList(L);
        break;
    }
    case 7: {
        deque<string> D;
        InputDequeStrings(D);
        cout << "\nИсходный дек:\n"; PrintDeque(D);
        SortAlphabetically(D);
        cout << "\nПосле sort (по алфавиту):\n"; PrintDeque(D);
        StableSortByLength(D);
        cout << "\nПосле stable_sort (по длине):\n"; PrintDeque(D);
        break;
    }
    default: cout << "Неверный номер задачи!" << endl;
    }
    return 0;
}
