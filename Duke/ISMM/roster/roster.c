#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "roster.h"

roster_t * readInput(const char * fname) {
    FILE * f = fopen(fname, "r");
    if (f == NULL) {
        return NULL;
    }
    roster_t * ans = malloc(sizeof(*ans));
    ans->numStudents = readAnInteger(f);
    ans->students = malloc(ans->numStudents * sizeof(*ans->students));
    if (ans == NULL) {
        free(ans);
        return NULL;
    }

    for (int i = 0; i < ans->numStudents; i++) {
        ans->students[i] = readAStudent(f);
    }
    assert(fclose(f) == 0);
    return ans;
}

int readAnInteger(FILE * f) {
    int ans = 0;
    char * line = NULL;
    size_t sz = 0;
    getline(&line, &sz, f);
    ans = atoi(line);
    free(line);
    return ans;
}

void stripNewline(char * str) {
    char * p = strchr(str, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}

student_t * readAStudent(FILE * f) {
    student_t * s = malloc(sizeof(*s));
    size_t sz = 0;
    s->name = NULL;
    getline(&s->name, &sz, f);
    stripNewline(s->name);
    s->numClasses = readAnInteger(f);
    s->classes = malloc(s->numClasses * sizeof(*s->classes));
    for (int i = 0; i < s->numClasses; i++) {
        s->classes[i] = NULL;
        getline(&s->classes[i], &sz, f);
        stripNewline(s->classes[i]);
    }
    return s;
}

void printClassRoster(roster_t * r) {
    for (int i = 0; i < r->numStudents; i++) {
        printf("student name: %s\nclass: ", r->students[i]->name);
        for (int j = 0; j < r->students[i]->numClasses; j++) {
            printf("%s\t", r->students[i]->classes[j]);
        }
        printf("\n");
    }
}

int isExist(char ** list, int n, const char * str) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(list[i], str)) {
            return 1;
        }
    }
    return 0;
}

void addClassToList(classes_t * classes, char * className) {
    classes->classNames = realloc(classes->classNames, (classes->numClasses + 1) * 
                                                sizeof(*classes->classNames));
    classes->classNames[classes->numClasses] = className;
    classes->numClasses++;
}

classes_t * getClassList(roster_t * roster) {
    classes_t * ans = malloc(sizeof(*ans));
    assert(ans != NULL);

    ans->numClasses = 0;
    ans->classNames = NULL;
    for (int i = 0; i < roster->numStudents; i++) {
        student_t * student = roster->students[i];
        for (int j = 0; j < student->numClasses; j++) {
            if(!isExist(ans->classNames, ans->numClasses, student->classes[j])) {
                addClassToList(ans, student->classes[j]);
            }
        }
    }
    return ans;
}

char * makeRosterFileName(const char * name) {
    const char * suffix = ".roster.txt";
    unsigned len = strlen(name) + strlen(suffix) + 1;
    char * ans = malloc(len * sizeof(*ans));
    snprintf(ans, len, "%s%s", name, suffix);
    return ans;
}

void writeOneFile(const char * cName, roster_t * r) {
    char * fname = makeRosterFileName(cName);
    FILE * outputFile = fopen(fname, "w");
    if (outputFile == NULL) {
        perror("fopen");
        fprintf(stderr,"Trying to open %s\n", fname);
        abort();
    }
    free(fname);
    for (int i = 0; i < r->numStudents; i++) {
        student_t * s = r->students[i];
        if (isExist(s->classes, s->numClasses, cName)) {
            fprintf(outputFile, "%s\n", s->name);
        }
    }
    assert(fclose(outputFile) == 0);
}

void writeAllFiles(classes_t * unique_class_list, roster_t * roster) {
    for (int i = 0; i < unique_class_list->numClasses; i++) {
        writeOneFile(unique_class_list->classNames[i], roster);
    }
}

void freeClasses(classes_t * unique_class_list) {
    free(unique_class_list->classNames);
    free(unique_class_list);
}

void freeRoster(roster_t * roster) {
    for (int i = 0; i < roster->numStudents; i++) {
        student_t * s = roster->students[i];
        free(s->name);
        for (int j = 0; j < s->numClasses; j++) {
             free(s->classes[j]);
        }
        free(s->classes);
        free(s);
    }
    free(roster->students);
    free(roster);
}

