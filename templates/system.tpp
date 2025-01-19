#pragma once

#include "../include/system.h"

UniSystem::UniSystem() {
  students = new SinglyLinkedList<Student>;
  courses = new BinaryTree<Course>;
  courses_table = new HashTable<int, Course>(100);
  students_table = new HashTable<int, Student>(100);
}

bool UniSystem::addStudent(int id, string name, string email, string password,
                           string address, int phone) {
  if (students_table->get(id) != Student()) {
    deleteStudent(id);
  }
  Student new_student = Student(id, name, email, password, address, phone);
  students->append(new_student);
  students_table->insert(new_student.id, new_student);
  return true;
}

bool UniSystem::deleteStudent(int id) {
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
                          int max_seats) {
  if (courses_table->get(id) != Course()) {
    dropCourse(id);
  }
  Course new_course = Course(id, credits, name, instructor, max_seats);
  courses->insert(new_course);
  courses_table->insert(new_course.id, new_course);
  return true;
}

bool UniSystem::dropCourse(int id) {
  courses->deleteNode(courses_table->get(id));
  courses_table->remove(id);
  return true;
}

bool UniSystem::searchStudent(int id) {
  students_table->get(id).displayDetails();
  return true;
}

bool UniSystem::searchCourse(int id) {
  /* cout << courses_table->get(id) << endl; */
  courses_table->get(id).displayDetails();
  return true;
}
