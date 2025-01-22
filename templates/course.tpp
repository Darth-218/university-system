#pragma once

#include "../include/entities.h"
#include "../include/system.h"

Course::Course(int id, int credits, string name, string instructor,
               int max_seats, int seats) {
  this->id = id;
  this->credits = credits;
  this->name = name;
  this->instructor = instructor;
  this->max_seats = max_seats;
  this->seats = seats;
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
  if (student.alreadyEnrolled(*this)) {
    cout << "\nStudent Already Enrolled in This Coures!\n\n";
    return false;
  }
  if (seats >= max_seats) {
    addToWaitlist(student);
    return false;
  }
  if (prerequisites->isEmpty()) {
    return true;
  }
  Stack<Course> *preq = prerequisites;
  DNode<Course> *head = student.course_history->getHead();
  DNode<Course> *current = head;
  while (current != NULL) {
    Course top = preq->peek();
    if (current->value.id == top.id) {
      preq->pop();
      current = head;
    }
    current = current->next;
  }
  if (preq->isEmpty()) {
    return true;
  }
  cout << "\nStudent Not Eligible to be Enrolled! missing:\n";
  while (!preq->isEmpty()) {
    cout << preq->peek().name << endl;
    preq->pop();
  }
  cout << endl;
  return false;
}

bool Course::addToWaitlist(Student student) {
  waitlist->enqueue(student);
  cout << "\nAdded Student to Waitlist\n";
  return false;
}

bool Course::addPrequisite(Course course) {
  this->prerequisites->push(course);
  return true;
}

void Course::displayDetails() {
  cout << endl << *this << endl;
}

ostream &operator<<(std::ostream &os, Course &course) {
  cout << "ID: " << course.id << ", ";
  cout << "Name: " << course.name << ", ";
  cout << "Credits: " << course.credits << ", ";
  cout << "Instructor: " << course.instructor << ", ";
  cout << "Max seats: " << course.max_seats << ", ";
  cout << "Taken Seats: " << course.seats << endl;
  return os;
}
