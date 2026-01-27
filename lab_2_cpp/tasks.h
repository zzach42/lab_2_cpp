#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <deque>
#include <list>
#include <vector>

// Вывод контейнеров
void PrintDeque(const std::deque<int>& D);
void PrintDeque(const std::deque<std::string>& D);
void PrintList(const std::list<int>& L);
void PrintVector(const std::vector<int>& V);
void PrintVectorReverse(const std::vector<int>& V);

// Работа с файлами
void ReadAndPrintFromFile(const std::string& name);

// Задачи
void PrintPolDec(const std::deque<int>& D);
void InsertLast5DequeToList(std::deque<int>& D, std::list<int>& L);
void MoveMiddleElement(std::list<int>& L, std::vector<int>& V);
void WriteDoubleCodesToFile(const std::string& name);
void RemoveBetweenNegatives(std::list<int>& L);
void CopyPositiveFromSecondHalf(std::list<int>& L);
void SortAlphabetically(std::deque<std::string>& D);
void StableSortByLength(std::deque<std::string>& D);
void InputDequeStrings(std::deque<std::string>& D);

#endif
