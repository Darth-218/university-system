#pragma once

#include "structures.h"

class Student;
class Course;

class Course {
public:
  int id, credits, max_seats, seats;
  string name, instructor;
  Stack<Course> *prerequisites;
  Queue<Student> *waitlist;

  Course(int id, int credits, string name, string instructor, int max_seats);

  Course();

  bool isEligible(Student student);

  bool addToWaitlist(Student student);

  void displayDetails();
};

class Student {

public:
  string name, email, password, address;
  int id, phone;
  DoublyLinkedList<Course> *course_history;

  Student(int id, string name, string email, string password, string address,
          int phone);

  Student();

  bool addCourse(Course course);

  bool dropCourse(Course course);

  void viewCourses();

  void displayDetails();
};

#include "../templates/student.tpp"

#include "../templates/course.tpp"
