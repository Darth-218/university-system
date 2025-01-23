/**
 * @file entities.h
 * @brief Defines the Student and Course classes.
 */

#pragma once

#include "structures.h"

class Student;
class Course;

/**
 * @class Course
 * @brief The Course class.
 */
class Course {
public:
  int id;                       ///< The Course's ID.
  int credits;                  ///< No. of credits.
  int max_seats;                ///< Max seats.
  int seats;                    ///< Taken seats.
  string name;                  ///< The Course's name.
  string instructor;            ///< Instructor
  Stack<Course> *prerequisites; ///< A stack holding the Course's prerequisites.
  Queue<Student> *waitlist;     ///< A queue managing the Course's wait-list.

  /**
   * @brief Constructs a new Course object with given values.
   * @param id the course's ID.
   * @param credits the credits taken from this course.
   * @param name this course's name.
   * @param instructor this course instructor's name.
   * @param max_seats this course's max seats.
   * @param seats this course's taken seats.
   */
  Course(int id, int credits, string name, string instructor, int max_seats,
         int seats);

  /**
   * @brief Constructs an empty Course object.
   */
  Course();

  /**
   * @brief Checks if a student is eligible to enroll in this course.
   * @param student The student to enroll.
   * @return boolean.
   */
  bool isEligible(Student student);

  /**
   * @brief A function that adds students to this course's waitlist when no
   * seats are available.
   * @param student The student enrolling in this course.
   * @return boolean.
   */
  bool addToWaitlist(Student student);

  /**
   * @brief A function that adds prerequisites to this course.
   * @param course The prerequisite course.
   * @return boolean.
   */
  bool addPrequisite(Course course);

  /**
   * @brief A function that displays this course's details.
   */
  void displayDetails();

  /**
   * @brief Less Than operator.
   * @param other The object to compare
   * @return boolean.
   */
  bool operator<(const Course &other) {
    return this->id < other.id;
  }

  /**
   * @brief Greater Than operator.
   * @param other The object to compare.
   * @return boolean.
   */
  bool operator>(const Course &other) {
    return this->id > other.id;
  }

  /**
   * @brief Equality operator.
   * @param other The object to compare.
   * @return boolean.
   */
  bool operator==(const Course &other) {
    return this->id == other.id;
  }

  /**
   * @brief Inequality operator.
   * @param other The objects to compare.
   * @return boolean.
   */
  bool operator!=(const Course &other) {
    return this->id != other.id;
  }

  /**
   * @brief Stream insertion operator.
   * @param os The input stream.
   * @param course The object to insert in the stream.
   * @return os
   */
  friend ostream &operator<<(std::ostream &os, Course &course);
};

/**
 * @class Student
 * @brief The Student class.
 */
class Student {

public:
  string name;     ///< Student name.
  string email;    ///< Student email.
  string password; ///< Student password.
  string address;  ///< Student address.
  int id;          ///< Student ID.
  int phone;       ///< Student phone number.
  DoublyLinkedList<Course>
      *course_history; ///< The Student's enrollment history.

  /**
   * @brief Constructs a new Student object with given values.
   * @param id the student's ID.
   * @param name this student's name.
   * @param email this student's email.
   * @param password this student's password.
   * @param address this student's address.
   * @param phone this student's phone.
   */
  Student(int id, string name, string email, string password, string address,
          int phone);

  /**
   * @brief Constructs an empty Student object.
   */
  Student();

  /**
   * @brief Checks if this student is already enrolled in a course.
   * @param course the course this student intends to be enrolled in.
   */
  bool alreadyEnrolled(Course course);

  /**
   * @brief A function that adds a course to this student's enrollment history.
   * @param course a pointer to the course to add.
   */
  bool addCourse(Course *course);

  /**
   * @brief A function that views course enrollment history.
   */
  void viewCourses();

  /**
   * @brief A function that displays this course's details
   */
  void displayDetails();

  /**
   * @brief Inequality Operator.
   * @param other The objects to compare.
   * @return boolean.
   */
  bool operator!=(const Student &other) {
    return this->id != other.id;
  }

  /**
   * @brief Stream insertion operator.
   * @param os The input stream.
   * @param student The object to insert in the stream.
   * @return os
   */
  friend ostream &operator<<(std::ostream &os, Student &student);
};

#include "../templates/student.tpp"

#include "../templates/course.tpp"
