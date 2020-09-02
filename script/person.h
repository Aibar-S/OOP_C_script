#ifndef PERSON_HPP_INCLUDED_
#define PERSON_HPP_INCLUDED_
#include <iostream>
#include <cstring>

using namespace std;

class Person {
 public:
  Person();
//создание персоны для группы
  Person(const char *name, bool gender, double age);
  Person(const Person &other);
  virtual ~Person();
  Person &operator=(const Person &other);
//сеттеры и геттеры для установки и запроса имени, пола и возраста кторые являются приватными
  const char *getName() const;
  void setName(const char *name);
  bool getGender() const;
  void setGender(bool gender);
  double getAge() const;
  void setAge(double age);
  friend ostream &operator<<(ostream &stream,
    const Person &person);
//перегрузка бинарного оператора сложения (+),
//возвращает суммарный возраст двух человек
  friend double operator+(const Person &a, const Person &b);
//вывод информации на экран
  void Print() const;
//запрашивает ввод информации по имени, полу и возрасту и присваивает их созаддному объекту с помощью сеттеров
  void Input();
//функция объекта Person, которая преобразует тип Person в double. функция возвращает возраст человека
  operator double() const;
//данные приватные
 private:
//имя
  char *name;
//пол
  bool gender;
//возраст
  double age;
};
#endif
