/**
 * @file system.h
 * @brief Defines the University System (UniSystem) class.
 */

#pragma once

#include "entities.h"
#include "structures.h"

/**
 * @class UniSystem
 * @brief The UniSystem class.
 */
class UniSystem {
private:
  SinglyLinkedList<Student>
      *students; ///< A Singly Linked List to store Student objects.
  BinaryTree<Course>
      *courses; ///< A Binary Search Tree to store Course objects.

public:
  HashTable<int, Course>
      *courses_table; ///< A hash table to store Course objects.
  HashTable<int, Student>
      *students_table; ///< A hash table to store Student objects.

  /**
   * @brief Constructs an empty UniSystem object.
   */
  UniSystem();

  /**
   * @brief A function that checks if a course exists.
   * @param id The course's ID.
   * @return True if the course exists, false otherwise.
   */
  bool courseExists(int id);

  /**
   * @brief A function that checks if a student exists.
   * @param id The student's ID.
   * @return True if the student exists, false otherwise.
   */
  bool studentExists(int id);

  /**
   * @brief A function that adds a student to the UniSystem object.
   * @param id The student's ID.
   * @param name This student's name.
   * @param email This student's email.
   * @param password This student's password.
   * @param address This student's address.
   * @param phone This student's phone.
   * @return boolean.
   */
  bool addStudent(int id, string name, string email, string password,
                  string address, int phone);

  /**
   * @brief A function that removes a student from the UniSystem object.
   * @param id the student's ID.
   * @return boolean.
   */
  bool deleteStudent(int id);

  /**
   * @brief A function that lists all students in the UniSystem object.
   */
  void listStudents();

  /**
   * @brief A function that lists all courses in the UniSystem object.
   */
  void listCourses();

  /**
   * @brief A function that adds a course to the UniSystem with given
   * parameters.
   * @param id The course's ID.
   * @param credits The credits taken from this course.
   * @param name This course's name.
   * @param instructor This course instructor's name.
   * @param max_seats This course's max seats.
   * @param seats This course's taken seats.
   * @return boolean.
   */
  bool addCourse(int id, string name, int credits, string instructor,
                 int max_seats, int seats);

  /**
   * @brief A function that adds a course to the UniSystem.
   * @param course Course object to add.
   * @return boolean.
   */
  bool addCourse(Course course);

  /**
   * @brief A function that removes a course from the UniSystem object.
   * @param id The course ID.
   * @return boolean.
   */
  bool dropCourse(int id);

  /**
   * @brief A function that checks the waitlist when a course gets a free seat.
   * @param course A reference to the Course Object.
   * @return boolean.
   */
  bool checkWaitlist(Course &course);

  /**
   * @brief A function that displays a specific student details.
   * @param id Student ID.
   * @return boolean.
   */
  bool searchStudent(int id);

  /**
   * @brief A function that displays a specific course details.
   * @param id Course ID.
   * @return boolean.
   */
  bool searchCourse(int id);
};

#include "../templates/system.tpp"
