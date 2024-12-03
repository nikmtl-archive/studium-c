/* pointers.c
✓   TO DO 1:  Extend/modify the address_list.c program such that the student data is not stored
             in a global but in local data structures in main.
✓   TO DO 2:  Use pointers/call by reference to pass student data to the different functions.
✓   TO DO 3:  use typedef to define a type for 'struct person' and use this type

*/

/*
void print_student(struct person *s){

  printf("%s", (*s).first_name );
  // as the notation (*s).firstname is somewhat clumsy, there is a special operator for this frequently used * . operation:
  printf("%s", s->first_name );

}

int main()
{

  print_student(&students[i]);
  // or simpler:
  print_student(students+i);      // Note, that this addition of i to a pointer is special as it considers the size of type pointed to

  ...
}
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_INPUT_LENGTH 30


enum gender {
   male, female, other
};

struct date {
   int day;
   int month;
   int year;
};

struct address {
   char street[MAX_INPUT_LENGTH];
   int number;
   int zip_code;
   char city[MAX_INPUT_LENGTH];
};

typedef struct person {
   char first_name[MAX_INPUT_LENGTH];
   char last_name[MAX_INPUT_LENGTH];
   enum gender gender;
   struct date birth_date;
   struct date enrollment_date;
   struct address address;
} person;


void inputStudent(int i, person *students) {
   system("cls");
   printf("-------Add Student------\n");

   printf("Enter first name: ");
   scanf("%30s", &students[i].first_name);
   printf("Enter last name: ");
   scanf("%30s", &students[i].last_name);

   char gender_input;
   printf("Enter gender (m/f/o): ");
   scanf("\n %1c", &gender_input);
   switch (gender_input) {
      case 'm':
         students[i].gender = male;
      break;
      case 'f':
         students[i].gender = female;
      break;
      case 'o':
         students[i].gender = other;
      break;
      default:
         printf("Wrong input using other\n");
         students[i].gender = other;
      break;
   }

   printf("Enter birth date \n");
   printf("Day:");
   scanf("%d", &students[i].birth_date.day);
   printf("Month:");
   scanf("%d", &students[i].birth_date.month);
   printf("Year:");
   scanf("%d", &students[i].birth_date.year);

   printf("Enter enrollment date \n");
   printf("Day:");
   scanf("%d", &students[i].enrollment_date.day);
   printf("Month:");
   scanf("%d", &students[i].enrollment_date.month);
   printf("Year:");
   scanf("%d", &students[i].enrollment_date.year);

   printf("Ender address \n");
   printf("Street: ");
   scanf(" %30[^\n]s", students[i].address.street);
   printf("Number: ");
   scanf(" %d", &students[i].address.number);
   printf("Zip code: ");
   scanf(" %d", &students[i].address.zip_code);
   printf("City: ");
   scanf("%30s", students[i].address.city);
}

void addStudent(int *student_count, person *students) {
   if (*student_count < MAX_STUDENTS) {
      inputStudent(*student_count, students);
      (*student_count)++;
   } else {
      printf("Student list is full.\n");
   }
}


void printStudent(int i,person *students) {
   printf("Student %d \t| %s %s", i+1, students[i].first_name, students[i].last_name);
   switch (students[i].gender) {
      case male:
         printf("\t| Male \t");
      break;
      case female:
         printf("\t| Female");
      break;
      case other:
         printf("\t| Other\t");
      break;
   }
   printf("\t| Birth: %d.%d.%d", students[i].birth_date.day, students[i].birth_date.month, students[i].birth_date.year);
   printf("\t| Enrollment: %d.%d.%d", students[i].enrollment_date.day, students[i].enrollment_date.month, students[i].enrollment_date.year);
   printf("\t| Address: %s %d, %d %s", students[i].address.street, students[i].address.number, students[i].address.zip_code, students[i].address.city);
   printf("\n");
}

void printAllStudents(int *student_count, person *students) {
   system("cls");
   printf("--------------------------------------Students-------------------------------------\n");
   for (int i = 0; i < *student_count; i++) {
      printStudent(i, students);
   }
   printf("\n Press enter to continue...");
   getchar(); // remove input buffer
   getchar(); // wait for user enter
}

void deleteStudent(int *student_count, struct person *students) {
   int student_id;
   system("cls");
   printf("-------Delete Student------\n");
   printf("Enter student id to delete: ");
   scanf("%d", &student_id);
   if (student_id < *student_count) {
      for (int i = student_id; i < *student_count; i++) {
         students[i] = students[i+1];
      }
      student_count--;
   } else {
      printf("Student not found\n");
   }
   printf("\n Press enter to continue...");
   getchar(); // remove input buffer
   getchar(); // wait for user enter
}


void menu(int *student_count, person *students) {
   char choice = 0;
   while (1) {
      system("cls");
      printf("-------MENU------\n");
      printf("[1] Add Student\n");
      printf("[2] Print all students\n");
      printf("[3] Delete student\n");
      printf("[4] Quit\n");
      printf("> ");
      scanf("%c", &choice);
      switch (choice) {
         case '1':
            addStudent(student_count, students);
         break;
         case '2':
            printAllStudents(student_count, students);
         break;
         case '3':
            deleteStudent(student_count, students);
         break;
         case '4':
            return;
         default:
            printf("Wrong input\n");
      }
   }
}

int main() {
   int student_count = 0;
   person students[MAX_STUDENTS];
   menu(&student_count, students);
}

