#ifndef ROSTER_H
#define ROSTER_H
struct student_tag {
    char * name;
    char ** classes;
    int numClasses;
};
typedef struct student_tag student_t;

struct roster_tag {
    student_t ** students;
    int numStudents;
};
typedef struct roster_tag roster_t;

struct classes_tag {
    char ** classNames;
    int numClasses;
};
typedef struct classes_tag classes_t;

void stripNewline(char * str);
int readAnInteger(FILE * f);
student_t * readAStudent(FILE * f);
roster_t * readInput(const char * fname);
void printClassRoster(roster_t * r);
int isExist(char ** list, int n, const char * str);
void addClassToList(classes_t * classes, char * className);
classes_t * getClassList(roster_t * roster);
char * makeRosterFileName(const char * name);
void writeOneFile(const char * cName, roster_t * r);
void writeAllFiles(classes_t * unique_class_list, roster_t * roster);
void freeClasses(classes_t * unique_class_list);
void freeRoster(roster_t * roster);

#endif