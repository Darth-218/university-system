/**
 * @file student.tpp
 * @brief Template file for the student class.
 */

#pragma once

#include "../include/entities.h"
#include "../include/system.h"

Student::Student(int id, string name, string email, string password,
                 string address, int phone) {

  /**
   * @brief Constructs a new Student object with given values.
   * @param id, the student's ID.
   * @param name, this student's name.
   * @param email, this student's email.
   * @param password, this student's password.
   * @param address, this student's address.
   * @param phone, this student's phone.
   */

  this->id = id;
  this->name = name;
  this->email = email;
  this->password = password;
  this->address = address;
  this->phone = phone;

  course_history = new DoublyLinkedList<Course>;
}

Student::Student() {

  /**
   * @brief Constructs an empty Student object.
   */

  this->id = 0;
  this->name = "";
  this->email = "";
  this->password = "";
  this->address = "";
  this->phone = 0;

  course_history = new DoublyLinkedList<Course>;
}

bool Student::alreadyEnrolled(Course course) {

  /**
   * @brief Checks if this student is already enrolled in a course.
   * @param course, the course this student intends to be enrolled in.
   */

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
  /**
   * @brief A function that adds a course to this student's enrollment history.
   * @param course, a pointer to the course to add.
   */

  course_history->append(*course);

  course->seats = course->seats + 1;

  return true;
}

void Student::viewCourses() {

  /**
   * @brief A function that views course enrollment history.
   */

  cout << "\n ";
  course_history->display();
  cout << "\n";
}

void Student::displayDetails() {

  /**
   * @brief A function that displays this course's details
   */

  cout << endl << *this << endl;
}

ostream &operator<<(std::ostream &os, Student &student) {

  /**
   * @brief Overloading the "<<" operator.
   */

  cout << "ID: " << student.id << ", ";
  cout << "Name: " << student.name << ", ";
  cout << "Email: " << student.email << ", ";
  cout << "Password: " << student.password << ", ";
  cout << "Address: " << student.address << ", ";
  cout << "Phone: " << student.phone << endl;

  return os;
}
