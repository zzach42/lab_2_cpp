#include "tasks.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

// =================== ВЫВОД КОНТЕЙНЕРОВ ===================
void PrintDeque(const deque<int>& D) { /* твой код */ }
void PrintDeque(const deque<string>& D) { /* твой код */ }
void PrintList(const list<int>& L) { /* твой код */ }
void PrintVector(const vector<int>& V) { /* твой код */ }
void PrintVectorReverse(const vector<int>& V) { /* твой код */ }

// ---------- Чтение и вывод данных из файла ----------
void ReadAndPrintFromFile(const string& name) { /* твой код */ }

// =================== ЗАДАНИЕ 1 ===================
void PrintPolDec(const deque<int>& D) { /* твой код */ }

// =================== ЗАДАНИЕ 2 ===================
void InsertLast5DequeToList(deque<int>& D, list<int>& L) { /* твой код */ }

// =================== ЗАДАНИЕ 3 ===================
void MoveMiddleElement(list<int>& L, vector<int>& V) { /* твой код */ }

// ---------- ЗАДАНИЕ 4 ----------
void WriteDoubleCodesToFile(const string& name) { /* твой код */ }

// ---------- ЗАДАНИЕ 5 ----------
void RemoveBetweenNegatives(list<int>& L) { /* твой код */ }

// ---------- ЗАДАНИЕ 6 ----------
void CopyPositiveFromSecondHalf(list<int>& L) { /* твой код */ }

// ---------- ЗАДАНИЕ 7 ----------
void SortAlphabetically(deque<string>& D) { /* твой код */ }
struct CompareByLength { bool operator()(const string& a, const string& b) const { return a.length() < b.length(); } };
void StableSortByLength(deque<string>& D) { /* твой код */ }
void InputDequeStrings(deque<string>& D) { /* твой код */ }
