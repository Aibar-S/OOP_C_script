#include "group.h"

using namespace std;

Group::Group(int size) : size(size), persons(new Person[size]) {
}

Group::Group(const Group &other) : size(0), persons(NULL) {
  copyFrom(other);
}

Group &Group::operator=(const Group &other) {
  if (this != &other) {
    copyFrom(other);
  }
  return *this;
}

Group::~Group() {
  delete [] persons;
}
//���������� ���������� �� ������� ��� ������������� �������� � ������
const Person &Group::getPerson(int index) const {
  return persons[index];
}
//�������� ������� ������ � ������ ������
void Group::setPerson(int index, const Person &person) {
  persons[index] = person;
}

//������ ��� ����������� �������� ���������� size
int Group::getSize() const {
  return size;
}

void Group::copyFrom(const Group &other) {
  delete [] persons;
  size = other.getSize();
  persons = new Person[size];
  for (int i = 0; i < size; ++i)
    persons[i] = other.getPerson(i);

}

ostream &operator<<(ostream &stream, const Group &group) {
  for (int i = 0; i < group.getSize(); ++i)
    stream << group.getPerson(i) << endl;
  return stream;
}

//2 ������������� �������, ������� ���������� ��������
//������ ������� ���������� ������� ������� ����� � ������, �������
//������� �� ������ ���������� ���������� �������� limit
double Group::getAverageAge(int limit) {
  double sum = 0;
  int count = 0;
  for (int i = 0; i < getSize(); ++i) {
    if (limit == -1 || getPerson(i).getAge() < limit) {
      sum += getPerson(i).getAge();
      ++count;
    }
  }
  return sum / count;
}

//������ ������� ���������� ������� ������� �����
double Group::getAverageAge() {
  return getAverageAge(-1);
}

//������� ������ � ������ ������
void Group::PutPerson(int i, const Person &man) {
  setPerson(i, man);
}

//C ������� ��������� ����� operator ��������� �������� ��������������,
//������������ i-�� ������� �������, �.�. ������ Person
Person &Group::operator[](int index) {
  return persons[index];
}
const Person &Group::operator[](int index) const {
  return persons[index];
}
//����� ���������� �� ������� (������ � ������)
void Group::Print() const {
  cout << *this << endl;
}

