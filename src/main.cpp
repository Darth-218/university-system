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

bool view(string arg);

bool remove(string arg);

bool enroll();

void testData();

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
      cout << "\nInvalid Student Parameters.\n\n";
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
      cout << "\nInvalid Course Parameters.\n\n";
    }
    return true;
  }
  if (arg == "prerequisite") {
    string course_id;
    cout << "Course ID: ", getline(cin, course_id);
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
    Course course = us.courses_table->get(stoi(course_id));
    Course pre = us.courses_table->get(stoi(input));
    course.addPrequisite(pre);
    cout << endl
         << pre.name << " is Now a Prerequisite for " << course.name << endl
         << endl;
    return true;
  }
  cout << "\nInvalid Argument.\n\n";
  return false;
}

bool search(string arg) {
  string id;
  bool searching;
  if (arg == "student") {
    cout << "Student ID: ", getline(cin, id);
    if (!us.studentExists(stoi(id))) {
      cout << "\nStudent Does not Exist!\n\n";
      return false;
    }
    searching = us.searchStudent(stoi(id));
    return searching;
  }
  if (arg == "course") {
    cout << "Course ID: ", getline(cin, id);
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
  if (arg == "student") {
    us.listStudents();
    return true;
  } else if (arg == "course") {
    us.listCourses();
    return true;
  } else if (arg == "history") {
    string id;
    cout << "Student ID: ", getline(cin, id);
    if (!us.studentExists(stoi(id))) {
      cout << "\nStudent Does not Exist!\n\n";
      return false;
    }
    us.students_table->get(stoi(id)).viewCourses();
    return true;
  }
  cout << "\nInvalid Arguemnt.\n\n";
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
  cout << "\nInvalid Argument.\n\n";
  return false;
}

bool enroll() {

  string student_id, course_id;

  cout << "Student ID: ", getline(cin, student_id);
  cout << "Course ID: ", getline(cin, course_id);

  Course course = us.courses_table->get(stoi(course_id));
  Student student = us.students_table->get(stoi(student_id));

  if (!(us.courseExists(course.id) && us.studentExists(student.id))) {
    cout << "\nEither the Student or the Course Does Not Exist.\n\n";
    return false;
  }

  if (course.isEligible(student)) {
    student.addCourse(course);
    cout << "\nStudent Enrolled!\n\n";
    return true;
  }
  return false;
}

int main() {
  testData();
  loop();
  return 0;
}

void testData() {
  us.addStudent(68349, "Emily Carter", "emily.c@example.com", "Emily123",
                "London", 1234567);
  us.addStudent(21756, "Liam Neeson", "liam.n@example.com", "Liam456",
                "California", 2345678);
  us.addStudent(94512, "Sophia Sartor", "sophia.s@example.com", "Sophia789",
                "Rome", 3456789);
  us.addStudent(37084, "Noah Kim", "noah.k@example.com", "Noah012", "Istanbul",
                4567890);
  us.addStudent(52963, "Ava Martinez", "ava.m@example.com", "Ava345",
                "New Mexico", 5678901);

  us.addCourse(47281, "Math", 4, "Josh Mika", 5);
  us.addCourse(15827, "Physics", 2, "Albert Einstien", 8);
  us.addCourse(35920, "Chemistry", 3, "Walter White", 3);
  us.addCourse(93654, "English", 3, "Tom Riddle", 10);
}
