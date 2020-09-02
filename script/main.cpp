#include <iostream>
#include "person.h"
#include "group.h"

using namespace std;

int main() {
//������ ����� ������
  char names[][15] = {"Aibar", "Aliya", "Yerlan", "Saule", "Kairat"};
//������ ������ � ������ group ���� Group �������� 5 �������
  Group group(5);
//�������� ������ �������. ������ ������� � �������, ��������� � �����
  bool gender = true;
  for (int i = 0; i < group.getSize(); ++i) {
    Person person(names[i], gender =! gender, 16. + i);
    group.PutPerson(i, person);
  }

//������ ������ �� �����
  cout << "Below is the information for each of 5 persons in the group: " << endl;
  group.Print();

//������� ������� Person, ������� ����������� ��� Person � double. ������� ���������� ������� ��������
//������ ������� ������� ��� �������� 2
  double age = group.getPerson(2);
//������ �� ����� ��� � ������� ������� ��� �������� 2
  cout << group.getPerson(2).getName() << " is " <<
    age << " years old." << endl;

//2 ������������� �������, ������� ���������� ��������
//������ ������� ���������� ������� ������� �����
//������ ������� ���������� ������� ������� ����� � ������, �������
//������� �� ������ ���������� ���������� �������� limit
  cout << "Average age of all people is " << group.getAverageAge() << endl;
  cout << "Average age of people younger than 19 y.o. is " << group.getAverageAge(19) << endl;

//��������� �������� ��������������
//���������� ���������� �� 3-�� �������� ������� ������� Person
  cout << "Below is the information for person under index 3: " << endl;
  group[3].Print();
  cout << " " << endl;

  //��������� ������ ��������� ��������
  double sumAge = group[1] + group[3];
  cout << "Sum of ages of persons under index 1 (Aliya) and 3 (Saule) is " << sumAge << endl;
//������� ��� ���� ����� ��������� �� ������ exit
  cin.get();
}
