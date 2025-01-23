/**
 * @file course.tpp
 * @brief Template file for the Course class.
 */

#pragma once

#include "../include/entities.h"
#include "../include/system.h"

Course::Course(int id, int credits, string name, string instructor,
               int max_seats, int seats) {

  /**
   * @brief Constructs a new Course object with given values.
   * @param id The course's ID.
   * @param credits The credits taken from this course.
   * @param name This course's name.
   * @param instructor This course instructor's name.
   * @param max_seats This course's max seats.
   * @param seats This course's taken seats.
   */

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

  /**
   * @brief Constructs an empty Course object.
   */

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

  /**
   * @brief Checks if a student is eligible to enroll in this course.
   * @param student The student to enroll.
   * @return boolean.
   */

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

  /**
   * @brief A function that adds students to this course's waitlist when no
   * seats are available.
   * @param student The student enrolling in this course.
   * @return boolean.
   */

  waitlist->enqueue(student);

  cout << "\nAdded Student to Waitlist\n\n";

  return false;
}

bool Course::addPrequisite(Course course) {

  /**
   * @brief A function that adds prerequisites to this course.
   * @param course The prerequisite course.
   * @return boolean.
   */

  this->prerequisites->push(course);

  return true;
}

void Course::displayDetails() {

  /**
   * @brief A function that displays this course's details.
   */

  cout << endl << *this << endl;
}

ostream &operator<<(std::ostream &os, Course &course) {

  /**
   * @brief Stream insertion operator.
   * @param os The input stream.
   * @param student The object to insert in the stream.
   * @return os
   */

  cout << "ID: " << course.id << ", ";
  cout << "Name: " << course.name << ", ";
  cout << "Credits: " << course.credits << ", ";
  cout << "Instructor: " << course.instructor << ", ";
  cout << "Max seats: " << course.max_seats << ", ";
  cout << "Taken Seats: " << course.seats << endl;

  return os;
}
