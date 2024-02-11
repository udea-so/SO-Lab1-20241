/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/structs_and_pointers02.c
*/


#include <stdio.h>

struct student {
	char *name;
	int id;
};

typedef struct student Student;

void print_student(Student *ps) {
	printf("name: %s\t id: %d\n", ps->name, ps->id);
}

int main() {
	// Create an array of Students.
	Student s[3];

	s[0].name = "Liangchen";
	s[0].id = 1;

	s[1].name = "Olivia";
	s[1].id = 2;

	s[2].name = "Kelsey";
	s[2].id = 3;

	int i = 0;
	for (i = 0; i < 3; ++i) {
		print_student(&s[i]);
	}

	return 0;
}

