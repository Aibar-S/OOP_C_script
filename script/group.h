#ifndef GROUP_HPP_INCLUDED_
#define GROUP_HPP_INCLUDED_
#include <iostream>
#include "person.h"

using namespace std;

class Group {
 public:
  explicit Group(int size);
  Group(const Group &other);
  Group &operator=(const Group &other);
  virtual ~Group();
  void copyFrom(const Group &other);
//геттер дл€ возвращени€ значени€ переменной size
  int getSize() const;
//возвращает информацию по персоне под определленным индексом в группе
  const Person &getPerson(int index) const;
//помогает занести персон в массив группы
  void setPerson(int index, const Person &person);
  friend ostream &operator<<(ostream &stream,
    const Group &group);
//2 перегруженные функции, имеющие одинаковое название
//перва€ функци€ возвращает средний возраст людей
//втора€ функци€ возвращает средний возраст людей в группе, возраст
//которых не больше некоторого граничного значени€ limit
  double getAverageAge();
  double getAverageAge(int limit);

//C помощью ключевого слова operator определ€ю оператор индексировани€,
//возвращающий i-ый элемент массива, т.е. объект Person
  Person &operator[](int index);
  const Person &operator[](int index) const;

//заносим персон в массив группы
  void PutPerson(int i, const Person &man);

//вывод информации по массиву (персон в группе)
  void Print() const;
//данные приватные
 private:
//размер группы
  int size;
  Person *persons;
};

#endif

