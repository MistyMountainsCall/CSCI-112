/*
 * Walker VanHouten
 * Lab 8
 * CSCI 112
 * Due: 4/18/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 25

typedef struct s {	//defining student data type
	int id;
	char l_name[NAME_SIZE];
	char f_name[NAME_SIZE];
	float* grades;
	float gpa;
} student;

/*		FUNCTION PROTOTYPES		*/
float	calc_gpa(student st, int n);
student	create_student(int n);
void 	free_mem(student *s);
void		print_records(student *first_student, int st_num, int gr_num);

int main() {
	int st_num, gr_num, i, j;
	scanf("%d%d", &st_num, &gr_num);	//get number of students and grades
	printf("Number of students: %d\n", st_num);	//give input confirmation
	printf("Number of grades (each): %d\n", gr_num);
	//allocate memory for the appropriate number of students (with the given
	//number of grades)
	student* start = (student *) calloc(st_num, sizeof(student));
	student store;
	
	for(i = 0; i < st_num; i++) {	//get information for each student from input
		store = create_student(gr_num);	//create and store new student
		start[i].id = store.id;		//copy over student to allocated memory
		j=0;
		while(store.f_name[j]!='\0') {
			start[i].f_name[j] = store.f_name[j];
			j++;
		}
		start[i].f_name[j+1] = '\0';
		j=0;
		while(store.l_name[j]!='\0') {
			start[i].l_name[j] = store.l_name[j];
			j++;
		}
		start[i].l_name[j+1] = '\0';
		start[i].grades = store.grades;
		start[i].gpa = store.gpa;
	}
	print_records(start, st_num, gr_num);	//print out the entire student records
	return 0;
}

float calc_gpa(student st, int n) {
	float sum;
	int i;
	for(i = 0; i < n; i++) {	//get the sum of all of the students grades
		sum += st.grades[i];
	}
	return sum / n;		//then return the average of them
}

student create_student(int n) {
	student s;
	scanf("%d %s %s", &s.id, s.l_name, s.f_name);	//parse input and store
	int i;
	float gr;
	s.grades = (float*) calloc(n, sizeof(float));
	for(i = 0; i < n; i++) {	//get the correct number of grades
		scanf("%f", &gr);
		memcpy(&(s.grades[i]), &gr, sizeof(float));
	}
	s.gpa = calc_gpa(s, n);	//calculate the gpa of the grades for the student
	return s;
}

void print_records(student *first_student, int st_num, int gr_num) {
	int i, j;
	for(i = 0; i < st_num; i++) {	//cycle throught students and print out their info
		printf(	"ID: %d, Name: %s %s, GPA: %.2f\n", 	//with some formatting
				first_student[i].id, 
				first_student[i].f_name, 
				first_student[i].l_name, 
				first_student[i].gpa
		);
		printf("Grades:");
		for(j = 0; j < gr_num; j++) {
			printf(" %.1f", first_student[i].grades[j]);
		}
		printf("\n");
	}
}

void free_mem(student *s) {	//frees up memory for the passed student
	free(&(s->grades));
	free(s);
}
