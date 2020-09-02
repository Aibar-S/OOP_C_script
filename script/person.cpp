#include <iostream>
#include "person.h"

using namespace std;

Person::Person() : name(NULL), gender(false), age(0.0) {
}

//создание персоны дл€ группы
Person::Person(const char *name, bool gender, double age)
    : name(strcpy(new char[strlen(name) + 1], name)),
    gender(gender), age(age) {
}

Person::Person(const Person &other) : name(strcpy(new char[strlen(other.getName()) + 1], other.getName())),
  gender(other.getGender()), age(other.getAge()) {
}

Person::~Person() {
  delete [] name;
}

Person &Person::operator=(const Person &other) {
  if (this != &other) {
    setName(other.getName());
    setGender(other.getGender());
    setAge(other.getAge());
  }
  return *this;
}

//ниже сеттеры и геттеры дл€ установки и запроса имени, пола и возраста кторые €вл€ютс€ приватными
const char *Person::getName() const {
  return name;
}
void Person::setName(const char *name) {
  delete [] this->name;
  this->name = strcpy(new char[strlen(name) + 1], name);
}
bool Person::getGender() const {
  return gender;
}
void Person::setGender(bool gender) {
  this->gender = gender;
}
double Person::getAge() const {
  return age;
}
void Person::setAge(double age) {
  this->age = age;
}

ostream &operator<<(ostream &stream, const Person &person) {
  return stream << "Person{" <<
    "name=" << person.getName() <<
    ", gender=" << (person.getGender() ? "female" : "male") <<
    ", age=" << person.getAge() <<
    "}";
};

//вывод информации на экран
void Person::Print() const {
  cout << *this << endl;
}

//запрашивает ввод информации по имени, полу и возрасту и присваивает их созаддному объекту с помощью сеттеров
void Person::Input() {
  int id;
  char name[1024];
  bool gender;
  double age;
  cout << "name: ";
  cin >> name;
  cout << "gender [0 - male, 1 - female]: ";
  cin >> gender;
  cout << "age: ";
  cin >> age;
  setName(name);
  setGender(gender);
  setAge(age);
}
//функци€ объекта Person, котора€ преобразует тип Person в double. функци€ возвращает возраст человека
Person::operator double() const {
  return getAge();
}
//определ€ю оператор сложени€ дл€ 2-х человек
double operator+(const Person &a, const Person &b) {
  return a.getAge() + b.getAge();
}
