#include <iostream>
#include "person.h"
#include "group.h"

using namespace std;

int main() {
//заношу имена персон
  char names[][15] = {"Aibar", "Aliya", "Yerlan", "Saule", "Kairat"};
//создаю объект с именем group типа Group размером 5 записей
  Group group(5);
//заполняю массив данными. Создаю объекты с именами, возрастом и полом
  bool gender = true;
  for (int i = 0; i < group.getSize(); ++i) {
    Person person(names[i], gender =! gender, 16. + i);
    group.PutPerson(i, person);
  }

//вывожу массив на экран
  cout << "Below is the information for each of 5 persons in the group: " << endl;
  group.Print();

//функция объекта Person, которая преобразует тип Person в double. функция возвращает возраст человека
//нахожу возраст персоны под индексом 2
  double age = group.getPerson(2);
//вывожу на экран имя и возраст персоны под индексом 2
  cout << group.getPerson(2).getName() << " is " <<
    age << " years old." << endl;

//2 перегруженные функции, имеющие одинаковое название
//первая функция возвращает средний возраст людей
//вторая функция возвращает средний возраст людей в группе, возраст
//которых не больше некоторого граничного значения limit
  cout << "Average age of all people is " << group.getAverageAge() << endl;
  cout << "Average age of people younger than 19 y.o. is " << group.getAverageAge(19) << endl;

//проверяем оператор индексирования
//возвращает информацию по 3-му элементу массива объекта Person
  cout << "Below is the information for person under index 3: " << endl;
  group[3].Print();
  cout << " " << endl;

  //проверяем работу оператора сложения
  double sumAge = group[1] + group[3];
  cout << "Sum of ages of persons under index 1 (Aliya) and 3 (Saule) is " << sumAge << endl;
//добавил для того чтобы программа не делала exit
  cin.get();
}
