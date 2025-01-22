#pragma once

#include "../include/system.h"

UniSystem::UniSystem() {
  students = new SinglyLinkedList<Student>;
  courses = new BinaryTree<Course>;
  courses_table = new HashTable<int, Course>(100);
  students_table = new HashTable<int, Student>(100);
}

bool UniSystem::studentExists(int id) {
  return students_table->get(id) != 0;
}

bool UniSystem::courseExists(int id) {
  return courses_table->get(id) != 0;
}

bool UniSystem::addStudent(int id, string name, string email, string password,
                           string address, int phone) {
  if (students_table->get(id) != NULL) {
    deleteStudent(id);
  }
  Student new_student = Student(id, name, email, password, address, phone);
  students->append(new_student);
  students_table->insert(new_student.id, new_student);
  return true;
}

bool UniSystem::deleteStudent(int id) {
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
  if (students->isEmpty()) {
    return;
  }
  cout << endl << " ";
  students->display();
}

void UniSystem::listCourses() {
  if (courses->isEmpty()) {
    return;
  }
  cout << endl << " ";
  courses->displayTree();
}

bool UniSystem::addCourse(int id, string name, int credits, string instructor,
                          int max_seats, int seats) {
  if (courses_table->get(id) != NULL) {
    dropCourse(id);
  }
  Course new_course = Course(id, credits, name, instructor, max_seats, seats);
  courses->insert(new_course);
  courses_table->insert(new_course.id, new_course);
  return true;
}

bool UniSystem::addCourse(Course course) {
  courses->deleteNode(course);
  courses->insert(course);
  return true;
}

bool UniSystem::checkWaitlist(Course &course) {
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
  if (!courseExists(id)) {
    cout << "\nCourse Does not Exist!\n\n";
  }
  courses->deleteNode(*courses_table->get(id));
  courses_table->remove(id);
  return true;
}

bool UniSystem::searchStudent(int id) {
  students_table->get(id)->displayDetails();
  return true;
}

bool UniSystem::searchCourse(int id) {
  courses_table->get(id)->displayDetails();
  return true;
}
