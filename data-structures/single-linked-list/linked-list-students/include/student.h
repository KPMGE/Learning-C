#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED

  typedef struct _student Student_t;

  Student_t* createStudent(char* name, unsigned int age, int registration, float p1, float p2, float p3);
  char* getNameStudent(Student_t* student);
  unsigned int getAgeStudent(Student_t* student);
  int getRegistrationStudent(Student_t* student);
  float getP1Student(Student_t* student);
  float getP2Student(Student_t* student);
  float getP3Student(Student_t* student);
  float calculateAverageStudent(Student_t* student);
  void displayStudent(Student_t* student);
  void freeStudent(Student_t* student);


#endif