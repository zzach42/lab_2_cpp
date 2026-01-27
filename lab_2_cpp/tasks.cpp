#include "tasks.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using std::advance;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::find_if;
using std::ifstream;
using std::inserter;
using std::list;
using std::next;
using std::ofstream;
using std::stable_sort;
using std::string;
using std::vector;

// =================== ВЫВОД КОНТЕЙНЕРОВ ===================

void PrintDeque(const deque<int>& d) {
  for (int x : d) {
    cout << x << " ";
  }
  cout << endl;
}

void PrintDeque(const deque<string>& d) {
  for (const string& s : d) {
    cout << s << " ";
  }
  cout << endl;
}

void PrintList(const list<int>& l) {
  for (int x : l) {
    cout << x << " ";
  }
  cout << endl;
}

void PrintVector(const vector<int>& v) {
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void PrintVectorReverse(const vector<int>& v) {
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

// =================== ЧТЕНИЕ ФАЙЛА ===================

void ReadAndPrintFromFile(const string& name) {
  ifstream fin(name);
  int value;

  cout << "Содержимое файла:\n";
  while (fin >> value) {
    cout << value << " ";
  }
  cout << endl;
}

// =================== ЗАДАНИЕ 1 ===================
// Вывод половин дека в обратном порядке

void PrintPolDec(const deque<int>& d) {
  int half = d.size() / 2;

  cout << "Первая половина в обратном порядке: ";
  for (int i = half - 1; i >= 0; --i) {
    cout << d[i] << " ";
  }

  cout << "\nВторая половина в обратном порядке: ";
  for (int i = d.size() - 1; i >= half; --i) {
    cout << d[i] << " ";
  }

  cout << endl;
}

// =================== ЗАДАНИЕ 2 ===================
// Вставка последних 5 элементов дека перед последними 5 элементами списка

void InsertLast5DequeToList(deque<int>& d, list<int>& l) {
  if (d.size() < 5 || l.size() < 5) {
    return;
  }

  vector<int> temp(d.end() - 5, d.end());

  auto it = l.end();
  advance(it, -5);

  l.insert(it, temp.begin(), temp.end());
}

// =================== ЗАДАНИЕ 3 ===================
// Перемещение среднего элемента списка в вектор

void MoveMiddleElement(list<int>& l, vector<int>& v) {
  int size = l.size();
  auto it = l.begin();
  advance(it, size / 2);

  v.push_back(*it);
  l.erase(it);
}

// =================== ЗАДАНИЕ 4 ===================
// Удвоенные ASCII-коды символов

void WriteDoubleCodesToFile(const string& name) {
  ofstream fout(name);
  char c;

  cout << "Введите набор символов: ";

  while (cin.get(c)) {
    if (cin.eof()) {
      break;
    }
    if (c != '\n') {
      fout << static_cast<int>(c) * 2 << " ";
    }
  }
}

// =================== ЗАДАНИЕ 5 ===================
// Удаление элементов между первыми двумя отрицательными

void RemoveBetweenNegatives(list<int>& l) {
  auto first = find_if(l.begin(), l.end(), [](int x) { return x < 0; });
  if (first == l.end()) {
    return;
  }

  auto second = find_if(next(first), l.end(), [](int x) { return x < 0; });
  if (second == l.end()) {
    return;
  }

  l.erase(next(first), second);
}

// =================== ЗАДАНИЕ 6 ===================
// Копирование положительных из второй половины в начало списка

void CopyPositiveFromSecondHalf(list<int>& l) {
  int size = l.size();
  auto mid = l.begin();
  advance(mid, size / 2);

  list<int> temp;
  remove_copy_if(mid, l.end(), inserter(temp, temp.begin()),
                 [](int x) { return x <= 0; });

  l.insert(l.begin(), temp.begin(), temp.end());
}

// =================== ЗАДАНИЕ 7 ===================
// Сортировка дека строк

void SortAlphabetically(deque<string>& d) {
  sort(d.begin(), d.end());
}

struct CompareByLength {
  bool operator()(const string& a, const string& b) const {
    return a.length() < b.length();
  }
};

void StableSortByLength(deque<string>& d) {
  stable_sort(d.begin(), d.end(), CompareByLength());
}

void InputDequeStrings(deque<string>& d) {
  int count;
  cout << "Введите количество слов: ";
  cin >> count;
  cin.ignore();

  for (int i = 0; i < count; ++i) {
    string s;
    getline(cin, s);
    d.push_back(s);
  }
}
