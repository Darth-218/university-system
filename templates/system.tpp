/**
 * @file system.tpp
 * @brief Template file for the system (UniSystem) class.
 */

#pragma once

#include "../include/system.h"

UniSystem::UniSystem() {

  /**
   * @brief Constructs an empty UniSystem object.
   */

  students = new SinglyLinkedList<Student>;
  courses = new BinaryTree<Course>;
  courses_table = new HashTable<int, Course>(100);
  students_table = new HashTable<int, Student>(100);
}

bool UniSystem::studentExists(int id) {

  /**
   * @brief A function that checks if a student exists.
   * @param id, the student's ID.
   */

  return students_table->get(id) != 0;
}

bool UniSystem::courseExists(int id) {

  /**
   * @brief A function that checks if a course exists.
   */

  return courses_table->get(id) != 0;
}

bool UniSystem::addStudent(int id, string name, string email, string password,
                           string address, int phone) {

  /**
   * @brief A function that adds a student to the UniSystem object.
   * @param id, the student's ID.
   * @param name, this student's name.
   * @param email, this student's email.
   * @param password, this student's password.
   * @param address, this student's address.
   * @param phone, this student's phone.
   */

  if (students_table->get(id) != NULL) {
    deleteStudent(id);
  }

  Student new_student = Student(id, name, email, password, address, phone);

  students->append(new_student);
  students_table->insert(new_student.id, new_student);

  return true;
}

bool UniSystem::deleteStudent(int id) {

  /**
   * @brief A function that removes a student from the UniSystem object.
   * @param id, the student's ID.
   */

  if (!studentExists(id)) {
    cout << "\nStudent Does not Exist!\n\n";
    return false;
  }

  SNode<Student> *current = students->getHead();
  int current_position = 0;

  while (current != NULL) {

    if (current->value.id == id)
      break;

    current_position++;
    current = current->next;
  }

  students->deleteNode(current_position);
  students_table->remove(id);

  return true;
}

void UniSystem::listStudents() {

  /**
   * @brief A function that lists all students in the UniSystem object.
   */

  if (students->isEmpty()) {
    return;
  }

  cout << endl << " ";
  students->display();
}

void UniSystem::listCourses() {

  /**
   * @brief A function that lists all courses in the UniSystem object.
   */

  if (courses->isEmpty()) {
    return;
  }

  cout << endl << " ";
  courses->displayTree();
}

bool UniSystem::addCourse(int id, string name, int credits, string instructor,
                          int max_seats, int seats) {

  /**
   * @brief A function that adds a course to the UniSystem with given
   * parameters.
   * @param id, the course's ID.
   * @param credits, the credits taken from this course.
   * @param name, this course's name.
   * @param instructor, this course instructor's name.
   * @param max_seats, this course's max seats.
   * @param seats, this course's taken seats.
   */

  if (courses_table->get(id) != NULL) {
    dropCourse(id);
  }

  Course new_course = Course(id, credits, name, instructor, max_seats, seats);

  courses->insert(new_course);
  courses_table->insert(new_course.id, new_course);

  return true;
}

bool UniSystem::addCourse(Course course) {

  /**
   * @brief A function that adds a course to the UniSystem.
   * @param course, Course object.
   */

  courses->deleteNode(course);
  courses->insert(course);

  return true;
}

bool UniSystem::checkWaitlist(Course &course) {
  /**
   * @brief A function that checks the waitlist when a course gets a free seat.
   * @param course, a reference to the Course Object.
   */

  if (course.waitlist->isEmpty()) {
    return false;
  }

  while (course.seats < course.max_seats) {

    Student *student = course.waitlist->peek();

    student->addCourse(&course);
    course.waitlist->dequeue();

    cout << "\nStudent with ID (" << student->id
         << ") Enrolled from Wait-list\n\n";
  }

  return true;
}

bool UniSystem::dropCourse(int id) {

  /**
   * @brief A function that removes a course from the UniSystem object.
   * @param id, The course ID.
   */

  if (!courseExists(id)) {
    cout << "\nCourse Does not Exist!\n\n";
  }

  courses->deleteNode(*courses_table->get(id));
  courses_table->remove(id);

  return true;
}

bool UniSystem::searchStudent(int id) {

  /**
   * @brief A function that displays a specific student details.
   * @param id, student ID.
   */

  students_table->get(id)->displayDetails();
  return true;
}

bool UniSystem::searchCourse(int id) {

  /**
   * @brief A function that displays a specific course details.
   * @param id, course ID.
   */

  courses_table->get(id)->displayDetails();
  return true;
}
