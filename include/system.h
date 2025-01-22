#pragma once

#include "entities.h"
#include "structures.h"

class UniSystem {
private:
  SinglyLinkedList<Student> *students;
  BinaryTree<Course> *courses;

public:
  HashTable<int, Course> *courses_table;
  HashTable<int, Student> *students_table;

  UniSystem();

  bool courseExists(int id);

  bool studentExists(int id);

  bool addStudent(int id, string name, string email, string password,
                  string address, int phone);

  bool deleteStudent(int id);

  void listStudents();

  void listCourses();

  bool freeSeat(Course &course);

  bool addCourse(int id, string name, int credits, string instructor,
                 int max_seats, int seats);

  bool dropCourse(int id);

  bool searchStudent(int id);

  bool searchCourse(int id);
};

#include "../templates/system.tpp"
