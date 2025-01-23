/**
 * @file main.cpp
 * @brief Main program code.
 */

#include "../include/entities.h"
#include "../include/includes.h"
#include "../include/structures.h"
#include "../include/system.h"

#define slls SinglyLinkedList<string>

bool runCommand(slls *commands);

slls *splitInput(string input);

string strip(string arg);

bool add(string arg);

bool search(string arg);

bool view(string arg);

bool remove(string arg);

bool enroll();

void testData();

bool freeSeat();

void printHelp();

UniSystem us;

void loop() {
  /**
   * @brief The main program loop.
   */
  string input;
  while (true) {
    cout << ">>> ";
    getline(cin, input);
    if (input.size() < 1)
      continue;
    slls *command = splitInput(input);
    runCommand(command);
  }
}

slls *splitInput(string input) {
  /**
   * @brief Splits the string input and stores it in a linked list.
   * @param input, a string.
   * @return A singly linked list with each node holding a part of the string.
   */
  slls *split_string = new slls;
  string arg = "";
  int index = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      split_string->append(arg);
      arg = "";
      index++;
    }
    arg += input[i];
  }
  split_string->append(arg);
  return split_string;
}

string strip(string arg) {
  /**
   * @brief strips all whitespaces in a string.
   * @param arg, the string.
   * @return A string free of whitespace.
   */
  string str = "";
  for (int i = 0; i < arg.size(); i++) {
    if (arg[i] != ' ') {
      str += arg[i];
    }
  }
  return str;
}

bool runCommand(slls *commands) {
  /**
   * @brief The function responsible for running commands.
   * @param The SLL with the command as well as the arguments.
   * @return A boolean for debugging purposes.
   */
  string command = strip(commands->getHead()->value);
  commands->removeHead();
  string arg = (commands->getLength()) ? strip(commands->getHead()->value) : "";
  if (command == "exit")
    exit(1);
  if (command == "add")
    return add(arg);
  if (command == "remove")
    return remove(arg);
  if (command == "view")
    return view(arg);
  if (command == "search")
    return search(arg);
  if (command == "enroll")
    return enroll();
  if (command == "free")
    return freeSeat();
  if (command == "help") {
    printHelp();
    return true;
  } else
    cout << "\nInvalid command.\n\n";
  return false;
}

bool add(string arg) {
  /**
   * @brief A function that adds students, courses, or prerequisites in their
   * respective data structures.
   * @param arg, argument string.
   * @return boolean for debugging purposes.
   */
  HashTable<int, string> inputs(4);
  string input;
  if (arg == "student") {
    cout << "\nStudent ID: ", getline(cin, input);
    inputs.insert(0, input);

    cout << "Student Name: ", getline(cin, input);
    inputs.insert(1, input);

    cout << "Student Email: ", getline(cin, input);
    inputs.insert(2, input);

    cout << "Student Password: ", getline(cin, input);
    inputs.insert(3, input);

    cout << "Student Address: ", getline(cin, input);
    inputs.insert(4, input);

    cout << "Student Phone: ", getline(cin, input);
    inputs.insert(5, input);

    try {
      us.addStudent(stoi(*inputs.get(0)), *inputs.get(1), *inputs.get(2),
                    *inputs.get(3), *inputs.get(4), stoi(*inputs.get(5)));
      cout << "\nStudent Added!\n\n";
    } catch (const exception &e) {
      cout << "\nInvalid Student Parameters.\n\n";
    }
    return true;
  }
  if (arg == "course") {
    cout << "\nCourse ID: ", getline(cin, input);
    inputs.insert(0, input);

    cout << "Course Name: ", getline(cin, input);
    inputs.insert(1, input);

    cout << "Course Credits: ", getline(cin, input);
    inputs.insert(2, input);

    cout << "Course Instructor: ", getline(cin, input);
    inputs.insert(3, input);

    cout << "Course Max Seats: ", getline(cin, input);
    inputs.insert(4, input);

    try {
      us.addCourse(stoi(*inputs.get(0)), *inputs.get(1), stoi(*inputs.get(2)),
                   *inputs.get(3), stoi(*inputs.get(4)), 0);
      cout << "\nCourse Added!\n\n";
    } catch (const exception &e) {
      cout << "\nInvalid Course Parameters.\n\n";
    }
    return true;
  }
  if (arg == "prerequisite") {
    string course_id;
    cout << "\nCourse ID: ", getline(cin, course_id);
    cout << "Prerequisite ID: ", getline(cin, input);
    try {
      if (!(us.courseExists(stoi(course_id)) && us.courseExists(stoi(input)))) {
        cout << "\nOne or Both Courses Does Not Exist.\n\n";
        return false;
      }
    } catch (exception &e) {
      cout << "\nInvalid Course ID's\n\n";
      return false;
    }
    Course *course = us.courses_table->get(stoi(course_id));
    Course *pre = us.courses_table->get(stoi(input));
    course->addPrequisite(*pre);
    cout << endl
         << pre->name << " is Now a Prerequisite for " << course->name << endl
         << endl;
    return true;
  }
  cout << "\nInvalid Argument.\n\n";
  return false;
}

bool search(string arg) {
  /**
   * @brief A function that searches the respective hash table for students or
   * courses.
   * @param arg, the argument to search for.
   * @return boolean for debugging purposes.
   */
  string id;
  bool searching;
  if (arg == "student") {
    cout << "\nStudent ID: ", getline(cin, id);
    if (!us.studentExists(stoi(id))) {
      cout << "\nStudent Does not Exist!\n\n";
      return false;
    }
    searching = us.searchStudent(stoi(id));
    return searching;
  }
  if (arg == "course") {
    cout << "\nCourse ID: ", getline(cin, id);
    if (!us.courseExists(stoi(id))) {
      cout << "\nCourse Does not Exist!\n\n";
      return false;
    }
    searching = us.searchCourse(stoi(id));
    return searching;
  }
  cout << "\nInvalid Argument.\n\n";
  return false;
}

bool view(string arg) {
  /**
   * @brief A function that lists students, courses, or enrollment histories.
   * @param arg, the object to list.
   * @return boolean for debugging purposes.
   */
  if (arg == "students") {
    us.listStudents();
    return true;
  } else if (arg == "courses") {
    us.listCourses();
    return true;
  } else if (arg == "history") {
    string id;
    cout << "\nStudent ID: ", getline(cin, id);
    if (!us.studentExists(stoi(id))) {
      cout << "\nStudent Does not Exist!\n\n";
      return false;
    }
    us.students_table->get(stoi(id))->viewCourses();
    return true;
  }
  cout << "\nInvalid Arguemnt.\n\n";
  return false;
}

bool remove(string arg) {
  /**
   * @brief A function that removes students or courses from their respective
   * data structures.
   * @param arg, the object to remove.
   * @return boolean for debugging purposes.
   */
  string id;
  bool deletion;
  if (arg == "student") {
    cout << "\nStudent ID: ", getline(cin, id);
    deletion = us.deleteStudent(stoi(id));
    return deletion;
  }
  if (arg == "course") {
    cout << "\nCourse ID: ", getline(cin, id);
    deletion = us.dropCourse(stoi(id));
    return deletion;
  }
  cout << "\nInvalid Argument.\n\n";
  return false;
}

bool enroll() {

  /**
   * @brief A function that adds courses to students' enrollment histories.
   * @return boolean for debugging purposes.
   */

  string student_id, course_id;

  cout << "\nStudent ID: ", getline(cin, student_id);
  cout << "Course ID: ", getline(cin, course_id);

  try {
    Course *course = us.courses_table->get(stoi(course_id));
    Student *student = us.students_table->get(stoi(student_id));

    if (!(us.courseExists(stoi(course_id)) &&
          us.studentExists(stoi(student_id)))) {
      cout << "\nEither the Student or the Course Does Not Exist.\n\n";
      return false;
    }

    if (course->isEligible(*student)) {
      student->addCourse(course);
      us.addCourse(*course);
      cout << endl << *course << endl;
      return true;
    }
  } catch (exception &e) {
    cout << "\nInvalid ID's\n\n";
    return false;
  }
  return false;
}

bool freeSeat() {
  /**
   * @brief a function that frees course seats.
   * @return boolean for debugging purposes.
   */
  string course_id;
  cout << "\nCourse ID: ", getline(cin, course_id);
  Course *course = us.courses_table->get(stoi(course_id));
  if (course->seats > 0) {
    course->seats--;
    us.addCourse(*course);
    cout << "\nSeat Freed! Occupied seats: " << course->seats << "\n\n";
    if (us.checkWaitlist(*course)) {
      cout << "\nStudent added from wait-list!\n\n";
    }
  } else {
    cout << "\nNo seats to free!\n\n";
  }
  return true;
}

void testData() {
  /**
   * @brief A function that adds dummy data for testing purposes
   */
  us.addStudent(1, "Emily Carter", "emily.c@example.com", "Emily123", "London",
                1234567);
  us.addStudent(2, "Liam Neeson", "liam.n@example.com", "Liam456", "California",
                2345678);
  us.addStudent(3, "Sophia Sartor", "sophia.s@example.com", "Sophia789", "Rome",
                3456789);
  us.addStudent(4, "Noah Kim", "noah.k@example.com", "Noah012", "Istanbul",
                4567890);
  us.addStudent(5, "Ava Martinez", "ava.m@example.com", "Ava345", "New Mexico",
                5678901);

  us.addCourse(1, "Math", 4, "Josh Mika", 5, 0);
  us.addCourse(2, "Physics", 2, "Albert Einstien", 8, 0);
  us.addCourse(3, "Chemistry", 3, "Walter White", 3, 0);
  us.addCourse(4, "English", 3, "Tom Riddle", 10, 0);
}

void printHelp() {
  /**
   * @brief A function that prints a help manual.
   */
  cout << "\nadd [course, student, prerequisite]: to add a course, a student, "
          "or "
          "prerequisites to a course.\n\n";
  cout << "view [courses, students, history]: to list courses, students, or "
          "view a students enrollment history.\n\n";
  cout << "search [course, student]: to print out a specific course or student "
          "details.\n\n";
  cout << "remove [course, student]: to remove a specific course or "
          "student.\n\n";
  cout << "enroll: to enroll a student in a course.\n\n";
  cout << "free: to free a seat in a course.\n\n";
  cout << "help: to print this help manual.\n\n";
  cout << "exit: to exit the program.\n\n";
}

int main() {
  printHelp();
  testData();
  loop();
  return 0;
}
