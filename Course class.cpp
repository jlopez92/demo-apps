#include<iostream>
using namespace std;

//function creates an array larger than the input array
//the new array then copies the data from the original array into the new one
//returns the new array pointer
string* increaseSize(string arr[], int size, int newSize) {
	string* newArray;
	newArray = new string[newSize];
	for (int i = 0; i < size; i++) {

		*(newArray + i) = *(arr + i);
	}

	delete[] arr;
	return newArray;
}

/*course class
private data members include two ints for student count and array capacity,
a string for the course name, and a string pointer to become an array
private members include a two arg constructor that takes in the course name and the capacity of the class
a set of getter functions, and finally a add student function which adds students to the class and increases 
array size by calling the increase size function if class is to capacity
*/
class course {
private:
	string courseName;
	int studentCount;
	int capacity;
	string* studentNames;
	
public:
	course(string _courseName, int _capacity) {
		courseName = _courseName;
		capacity = _capacity;
		studentNames = new string[capacity];
		studentCount = 0;
	}
	
	string getCourseName() {
		return courseName;
	}

	int getstudentCount() {
		return studentCount;
	}

	void addStudent(string _studentName) {
		if (studentCount == capacity) {
			studentNames = increaseSize(studentNames, capacity, capacity + 5);
			cout << "Class has been expanded to " << capacity + 5 << endl;
			capacity = capacity + 5;
		}
		*(studentNames + studentCount) = _studentName;
		studentCount = studentCount + 1;
	}

	void printStudents() {
		cout << "The names of every student." << endl;
		for (int i = 0; i < studentCount; i++) {
			cout << *(studentNames + i) << endl;
		}
	}

	~course() {
		delete[] studentNames;
	}
};

int main() {
	cout << "The Course Class" << endl;
	cout << "****************" << endl << endl;
	//testing out the function members of the course class
	course course("Physics", 3);
	course.addStudent("Ruth");
	course.addStudent("Jose");
	course.addStudent("Miranda");
	course.addStudent("Jessie");
	course.addStudent("Taylor");

	cout << "Course: " << course.getCourseName() << endl;
	cout << "Student count: " << course.getstudentCount() << endl;
	course.printStudents();

	system("pause");
	return 0;
}