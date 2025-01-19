#include "../include/entities.h"
#include "../include/includes.h"
#include "../include/structures.h"
#include "../include/system.h"

#define slls SinglyLinkedList<string>

bool runCommand(slls *commands);

slls *splitInput(string input);

string strip(string arg);

bool checkValidity(slls *commands, int argc);

bool add(string arg);

bool search(string arg);

bool list(string arg);

bool remove(string arg);

bool enroll();

UniSystem us;

void loop() {
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
  string str = "";
  for (int i = 0; i < arg.size(); i++) {
    if (arg[i] != ' ') {
      str += arg[i];
    }
  }
  return str;
}

bool checkValidity(slls *commands, int argc) {
  if (commands->getLength() < argc) {
    cout << "Invalid command.\n";
    return false;
  }
  return true;
}

bool runCommand(slls *commands) {
  string command = strip(commands->getHead()->value);
  commands->removeHead();
  string arg = (commands->getLength()) ? strip(commands->getHead()->value) : "";
  if (command == "add")
    return add(arg);
  if (command == "remove")
    return remove(arg);
  if (command == "list")
    return list(arg);
  if (command == "search")
    return search(arg);
  if (command == "enroll")
    return enroll();
  else
    cout << "Invalid command.\n";
  return false;
}

bool add(string arg) {
  HashTable<int, string> inputs(4);
  string input;
  if (arg == "student") {
    cout << "Student ID: ", getline(cin, input);
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
      us.addStudent(stoi(inputs.get(0)), inputs.get(1), inputs.get(2),
                    inputs.get(3), inputs.get(4), stoi(inputs.get(5)));
      cout << "\nStudent Added!\n\n";
    } catch (const exception &e) {
      cout << "Invalid Student Parameters.\n";
    }
    return true;
  }
  if (arg == "course") {
    cout << "Course ID: ", getline(cin, input);
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
      us.addCourse(stoi(inputs.get(0)), inputs.get(1), stoi(inputs.get(2)),
                   inputs.get(3), stoi(inputs.get(4)));
      cout << "\nCourse Added!\n\n";
    } catch (const exception &e) {
      cout << "Invalid Course Parameters.\n";
    }
    return true;
  }
  cout << "Invalid Argument.\n";
  return false;
}

bool search(string arg) {
  string id;
  bool searching;
  if (arg == "student") {
    cout << "Student ID: ", getline(cin, id);
    searching = us.searchStudent(stoi(id));
    return searching;
  }
  if (arg == "course") {
    cout << "Course ID: ", getline(cin, id);
    searching = us.searchCourse(stoi(id));
    return searching;
  }
  cout << "Invalid Argument.\n";
  return false;
}

bool list(string arg) {
  if (arg == "student") {
    us.listStudents();
    return true;
  } else if (arg == "course") {
    us.listCourses();
    return true;
  }
  cout << "\nInvalid Arguemnt.\n";
  return false;
}

bool remove(string arg) {
  string id;
  bool deletion;
  if (arg == "student") {
    cout << "Student ID: ", getline(cin, id);
    deletion = us.deleteStudent(stoi(id));
    return deletion;
  }
  if (arg == "course") {
    cout << "Course ID: ", getline(cin, id);
    deletion = us.dropCourse(stoi(id));
    return deletion;
  }
  cout << "Invalid Argument.\n";
  return false;
}

bool enroll() {

  string student_id, course_id;

  cout << "Student ID: ", getline(cin, student_id);
  cout << "Course ID: ", getline(cin, course_id);

  Course course = us.courses_table->get(stoi(course_id));
  Student student = us.students_table->get(stoi(student_id));

  if (course.isEligible(student)) {
    course.seats++;
    student.addCourse(course);
    cout << "\nStudent Enrolled!\n\n";
    return true;
  }

  cout << "\nStudent Not Eligible to be Enrolled!\n\n";
  return false;
}

int main() {
  loop();
  return 0;
}
