/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/structs_and_pointers01.c
*/

#include <stdio.h>

struct student {
	char *name;
	int id;
};

void print_student(struct student s) {
	printf("name: %s\t id: %d\n", s.name, s.id);
}

int main() {
	// Create a student.
	struct student s1;
	s1.name = "Oliver";
	s1.id = 1;
	print_student(s1);

	// Create a pointer to a student.
	struct student *ps;
	ps = &s1;
	print_student(*ps);
	
	// Create another student.
	struct student s2;
	s2.name = "Jonathan";
	s2.id = 2;
	print_student(s2);

	ps = &s2;
	print_student(*ps);
	
	return 0;
}