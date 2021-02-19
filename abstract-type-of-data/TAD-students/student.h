// exported type
typedef struct student Student;
// function that reads an student type
void readStudent(Student *student);
// function that displays a student
void displayStudent(Student *student);
// function that releases a student
void freeStudent(Student *student);
// function that calculates the student average
float calculateAverageStudent(Student *student);
// function that creates an instance of student
Student* createStudent();
