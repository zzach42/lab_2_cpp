#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

// =================== ВЫВОД КОНТЕЙНЕРОВ ===================

void PrintDeque(const deque<int>& D)
{
    for (auto it = D.begin(); it != D.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void PrintList(const list<int>& L)
{
    for (auto it = L.begin(); it != L.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void PrintVector(const vector<int>& V)
{
    for (auto it = V.begin(); it != V.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void PrintVectorReverse(const vector<int>& V)
{
    for (auto it = V.rbegin(); it != V.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}
void PrintDeque(const deque<string>& D)
{
    for (auto it = D.begin(); it != D.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// ---------- Чтение и вывод данных из файла ----------
void ReadAndPrintFromFile(const string& name)
{
    ifstream fin(name);
    if (!fin)
    {
        cout << "Ошибка открытия файла для чтения\n";
        return;
    }

    cout << "\nСодержимое файла:\n";

    istream_iterator<int> in(fin);
    istream_iterator<int> eof;

    ostream_iterator<int> out(cout, " ");

    copy(in, eof, out);

    cout << endl;
    fin.close();
}

// =================== ЗАДАНИЕ 1 ===================

void PrintPolDec(const deque<int>& D)
{
    int Razmer = D.size();
    int Polovina = Razmer / 2;

    cout << "Первая половина в обратном порядке: ";
    for (auto it = D.rbegin() + Polovina; it != D.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Вторая половина в обратном порядке: ";
    for (auto it = D.rbegin(); it != D.rbegin() + Polovina; ++it)
        cout << *it << " ";
    cout << endl;
}

// =================== ЗАДАНИЕ 2 ===================

void InsertLast5DequeToList(deque<int>& D, list<int>& L)
{
    if (D.size() < 5 || L.size() < 5)
    {
        cout << "Оба контейнера должны содержать как минимум 5 элементов\n";
        return;
    }

    auto it = L.end();
    advance(it, -5);

    vector<int> tmp(D.rbegin(), D.rbegin() + 5);
    L.insert(it, tmp.begin(), tmp.end());
}

// =================== ЗАДАНИЕ 3 ===================

void MoveMiddleElement(list<int>& L, vector<int>& V)
{
    if (L.empty())
        return;

    auto it = L.begin();
    advance(it, L.size() / 2);

    V.push_back(*it);
    L.erase(it);
}

// ---------- ЗАДАНИЕ 4 ----------
void WriteDoubleCodesToFile(const string& name)
{
    ofstream fout(name);
    if (!fout)
    {
        cout << "Ошибка открытия файла\n";
        return;
    }

    cout << "Введите набор символов (Ctrl+Z для окончания ввода):\n";

    istream_iterator<char> in(cin);
    istream_iterator<char> eof;

    ostream_iterator<int> out(fout, " ");

    transform(in, eof, out,
        [](char c)
        {
            return static_cast<int>(c) * 2;
        }
    );

    fout.close();
}

// ---------- ЗАДАНИЕ 5 ----------
void RemoveBetweenNegatives(list<int>& L)
{

    auto firstNeg = find_if(L.begin(), L.end(),
        [](int x) { return x < 0; });

    if (firstNeg == L.end())
        return;

    auto secondNeg = find_if(next(firstNeg), L.end(),
        [](int x) { return x < 0; });

    if (secondNeg == L.end())
    {
        L.erase(next(firstNeg), L.end());
    }
    else
    {
        L.erase(next(firstNeg), secondNeg);
    }
}

// ---------- ЗАДАНИЕ 6 ----------
void CopyPositiveFromSecondHalf(list<int>& L)
{
    //на начало второй половины
    auto mid = L.begin();
    advance(mid, L.size() / 2);

    //вставка в начало списка
    auto insertIt = inserter(L, L.begin());

    remove_copy_if(
        mid, L.end(),
        insertIt,
        [](int x)
        {
            return x <= 0;
        }
    );
}

// ---------- ЗАДАНИЕ 7 ----------

// Сортировка по алфавиту
void SortAlphabetically(deque<string>& D)
{
    sort(D.begin(), D.end());
}

// Функциональный объект для сортировки по длине
struct CompareByLength
{
    bool operator()(const string& a, const string& b) const
    {
        return a.length() < b.length();
    }
};

// Стабильная сортировка по длине
void StableSortByLength(deque<string>& D)
{
    stable_sort(D.begin(), D.end(), CompareByLength());
}

// Ввод дека строк
void InputDequeStrings(deque<string>& D)
{
    int n;
    cout << "Введите количество слов: ";
    cin >> n;

    cout << "Введите " << n << " английских слов:\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        D.push_back(s);
    }
}




int main()
{
    cout << "Введите номер задачи:\n"
        << "1 - Вывод половин дека в обратном порядке\n"
        << "2 - Вставка последних 5 элементов дека в список\n"
        << "3 - Перемещение среднего элемента списка в вектор\n"
        << "4 - удвоенные кодовые значения символов\n"
        << "5 - удаление все элементы списка, расположенные между первым и вторым отрицательным элементом\n"
        << "6 - Копирование положительных элементов\n"
        << "7 - Сортировка дека слов: сначала по алфавиту, потом по длине\n";

    int n;
    cin >> n;

    switch (n)
    {
        // ---------- ЗАДАНИЕ 1 ----------
    case 1:
    {
        deque<int> D;
        int colich;
        cout << "Введите количество элементов дека (четное): ";
        cin >> colich;

        for (int i = 0; i < colich; i++)
        {
            int x;
            cin >> x;
            D.push_back(x);
        }

        cout << "Созданный дек: ";
        PrintDeque(D);

        PrintPolDec(D);
        break;
    }

    // ---------- ЗАДАНИЕ 2 ----------
    case 2:
    {
        int n;
        cout << "Введите количество элементов дека (>=5): ";
        cin >> n;

        deque<int> D;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            D.push_back(x);
        }

        cout << "Созданный дек: ";
        PrintDeque(D);

        int n1;
        cout << "Введите количество элементов списка (>=5): ";
        cin >> n1;

        list<int> L;
        for (int i = 0; i < n1; i++)
        {
            int x;
            cin >> x;
            L.push_back(x);
        }

        cout << "Созданный список: ";
        PrintList(L);

        InsertLast5DequeToList(D, L);

        cout << "Список после вставки: ";
        PrintList(L);
        break;
    }

    // ---------- ЗАДАНИЕ 3 ----------
    case 3:
    {
        int n;
        cout << "Введите количество элементов списка (нечетное): ";
        cin >> n;

        list<int> L;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            L.push_back(x);
        }

        int m;
        cout << "Введите количество элементов вектора: ";
        cin >> m;

        vector<int> V;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            V.push_back(x);
        }

        cout << "Список L: ";
        PrintList(L);

        cout << "Вектор V: ";
        PrintVector(V);

        MoveMiddleElement(L, V);

        cout << "После перемещения:\n";
        cout << "Список L: ";
        PrintList(L);

        cout << "Вектор V: ";
        PrintVector(V);

        cout << "Вектор V (обратный порядок): ";
        PrintVectorReverse(V);
        break;
    }
    // ---------- ЗАДАНИЕ 4 ----------
    case 4:
    {
        string name;
        cout << "Введите имя файла: ";
        cin >> name;

        cin.ignore(); // очистка буфера

        WriteDoubleCodesToFile(name);
        ReadAndPrintFromFile(name);
        break;
    }
    // ---------- ЗАДАНИЕ 5 ----------
    case 5:
    {
        int n;
        cout << "Введите количество элементов списка: ";
        cin >> n;

        list<int> L;
        cout << "Введите элементы списка:\n";
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            L.push_back(x);
        }

        cout << "Исходный список:\n";
        PrintList(L);

        RemoveBetweenNegatives(L);

        cout << "Список после обработки:\n";
        PrintList(L);
        break;
    }
    case 6:
    {
        int n;
        cout << "Введите количество элементов списка (четное): ";
        cin >> n;

        list<int> L;
        cout << "Введите элементы списка:\n";
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            L.push_back(x);
        }

        cout << "Исходный список:\n";
        PrintList(L);

        CopyPositiveFromSecondHalf(L);

        cout << "Список после копирования:\n";
        PrintList(L);
        break;
    }
    // ---------- ЗАДАНИЕ 7 ----------
    case 7:
    {
        deque<string> D;

        // Ввод дека
        InputDequeStrings(D);

        cout << "\nИсходный дек:\n";
        PrintDeque(D);

        // Сортировка по алфавиту
        SortAlphabetically(D);
        cout << "\nПосле sort (по алфавиту):\n";
        PrintDeque(D);

        // Стабильная сортировка по длине
        StableSortByLength(D);
        cout << "\nПосле stable_sort (по длине):\n";
        PrintDeque(D);

        break;
    }

    default:
        cout << "Неверный номер задачи!" << endl;
    }



    return 0;
}
