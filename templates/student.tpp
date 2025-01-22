#pragma once

#include "../include/entities.h"
#include "../include/system.h"

Student::Student(int id, string name, string email, string password,
                 string address, int phone) {
  this->id = id;
  this->name = name;
  this->email = email;
  this->password = password;
  this->address = address;
  this->phone = phone;
  course_history = new DoublyLinkedList<Course>;
}

Student::Student() {
  this->id = 0;
  this->name = "";
  this->email = "";
  this->password = "";
  this->address = "";
  this->phone = 0;
  course_history = new DoublyLinkedList<Course>;
}

bool Student::alreadyEnrolled(Course course) {
  DNode<Course> *current_course = course_history->getHead();
  while (current_course != NULL) {
    if (current_course->value == course) {
      return true;
    }
    current_course = current_course->next;
  }
  return false;
}

bool Student::addCourse(Course *course) {
  course_history->append(*course);
  course->seats = course->seats + 1;
  return true;
}

void Student::viewCourses() {
  cout << "\n ";
  course_history->display();
  cout << "\n";
}

void Student::displayDetails() {
  cout << endl << *this << endl;
}

ostream &operator<<(std::ostream &os, Student &student) {
  cout << "ID: " << student.id << ", ";
  cout << "Name: " << student.name << ", ";
  cout << "Email: " << student.email << ", ";
  cout << "Password: " << student.password << ", ";
  cout << "Address: " << student.address << ", ";
  cout << "Phone: " << student.phone << endl;
  return os;
}
