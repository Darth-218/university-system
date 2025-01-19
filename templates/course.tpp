#pragma once

#include "../include/entities.h"

Course::Course(int id, int credits, string name, string instructor,
               int max_seats) {
  this->id = id;
  this->credits = credits;
  this->name = name;
  this->instructor = instructor;
  this->max_seats = max_seats;
  this->seats = 0;
  prerequisites = new Stack<Course>;
  waitlist = new Queue<Student>;
}

Course::Course() {
  this->id = 0;
  this->credits = 0;
  this->name = "";
  this->instructor = "";
  this->max_seats = 0;
  this->seats = 0;
  prerequisites = new Stack<Course>;
  waitlist = new Queue<Student>;
}

bool Course::isEligible(Student student) {
  if (seats >= max_seats) {
    return false;
  }
  DNode<Course> *head = student.course_history->getHead();
  DNode<Course> *current = head;
  while (current != NULL) {
    Course top = prerequisites->peek();
    if (current->value.id == top.id) {
      prerequisites->pop();
      current = head;
    }
    current = current->next;
  }
  return false;
}

bool Course::addToWaitlist(Student student) {
  return false;
}

void Course::displayDetails() {
  cout << endl << this;
}

bool operator<(const Course &lhs, const Course &rhs) {
  return lhs.id < rhs.id;
}

bool operator>(const Course &lhs, const Course &rhs) {
  return lhs.id > rhs.id;
}

bool operator==(const Course &lhs, const Course &rhs) {
  return lhs.id == rhs.id;
}

bool operator!=(const Course &lhs, const Course &rhs) {
  return lhs.id != rhs.id;
}

std::ostream &operator<<(std::ostream &os, Course &course) {
  cout << "ID: " << course.id << ", ";
  cout << "Name: " << course.name << ", ";
  cout << "Credits: " << course.credits << ", ";
  cout << "Instructor: " << course.instructor << ", ";
  cout << "Max seats: " << course.seats << endl;
  return os;
}
