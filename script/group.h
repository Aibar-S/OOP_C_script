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
//������ ��� ����������� �������� ���������� size
  int getSize() const;
//���������� ���������� �� ������� ��� ������������� �������� � ������
  const Person &getPerson(int index) const;
//�������� ������� ������ � ������ ������
  void setPerson(int index, const Person &person);
  friend ostream &operator<<(ostream &stream,
    const Group &group);
//2 ������������� �������, ������� ���������� ��������
//������ ������� ���������� ������� ������� �����
//������ ������� ���������� ������� ������� ����� � ������, �������
//������� �� ������ ���������� ���������� �������� limit
  double getAverageAge();
  double getAverageAge(int limit);

//C ������� ��������� ����� operator ��������� �������� ��������������,
//������������ i-�� ������� �������, �.�. ������ Person
  Person &operator[](int index);
  const Person &operator[](int index) const;

//������� ������ � ������ ������
  void PutPerson(int i, const Person &man);

//����� ���������� �� ������� (������ � ������)
  void Print() const;
//������ ���������
 private:
//������ ������
  int size;
  Person *persons;
};

#endif

