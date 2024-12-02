/* address_list.c
 This program should be completed such that it maintains a list of students
✓ TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
✓ TO DO 2: Use a variable to count the number of students stored in the array.
✓ TO DO 3: Write a function printStudent(i), which prints student i stored in the array
✓ TO DO 4: Write functions addStudent(), for adding a student at the first free position, and printAllStudents() for printing all students stored.
✓ TO DO 5: Write a function menu(), which allows the user to select one of the actions
            - add Student
            - print all students
            - quit program
✓ TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
✓ TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc.
✓ TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
✓ TO DO 9: optional: Add a function and menu item for deleting a selected student.
  TO DO 10: optional: Add a function to sort the data according to given criteria
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_INPUT_LENGTH 30
void addDummyData(int count);

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

struct person {
   char first_name[MAX_INPUT_LENGTH];
   char last_name[MAX_INPUT_LENGTH];
   enum gender gender;
   struct date birth_date;
   struct date enrollment_date;
   struct address address;
};

int student_count = 0;
struct person students[MAX_STUDENTS];

void inputStudent(int i) {
   system("cls");
   printf("-------Add Student------\n");

   printf("Enter first name: ");
   scanf("%30s", students[i].first_name);
   printf("Enter last name: ");
   scanf("%30s", students[i].last_name);

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
         printf("Wrong input\n");
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

void addStudent() {
   if (student_count < MAX_STUDENTS) {
      inputStudent(student_count);
      student_count++;
   } else {
      printf("Student list is full.\n");
   }
}


void printStudent(int i) {
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

void printAllStudents() {
   system("cls");
   printf("--------------------------------------Students-------------------------------------\n");
   for (int i = 0; i < student_count; i++) {
      printStudent(i);
   }
   printf("\n Press enter to continue...");
   getchar(); // remove input buffer
   getchar(); // wait for user enter
}

void deleteStudent() {
   int student_id;
   system("cls");
   printf("-------Delete Student------\n");
   printf("Enter student id to delete: ");
   scanf("%d", &student_id);
   if (student_id < student_count) {
      for (int i = student_id; i < student_count; i++) {
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


void menu() {
   addDummyData(5);
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
            addStudent();
         break;
         case '2':
            printAllStudents();
         break;
         case '3':
            deleteStudent();
         break;
         case '4':
            return;
         default:
            printf("Wrong input\n");
      }
   }
}

int main() {
   menu();
}



void addDummyData(int count) {
   count++;
   for (int i = 0; i < count && i < MAX_STUDENTS; i++) {
      snprintf(students[i].first_name, MAX_INPUT_LENGTH, "FirstName%d", i + 1);
      snprintf(students[i].last_name, MAX_INPUT_LENGTH, "LastName%d", i + 1);
      students[i].gender = (i % 3 == 0) ? male : (i % 3 == 1) ? female : other;
      students[i].birth_date = (struct date){1 + (i % 28), 1 + (i % 12), 2000 + (i % 20)};
      students[i].enrollment_date = (struct date){1 + (i % 28), 1 + (i % 12), 2020 + (i % 3)};
      snprintf(students[i].address.street, MAX_INPUT_LENGTH, "Street%d", i + 1);
      students[i].address.number = i + 1;
      students[i].address.zip_code = 10000 + i;
      snprintf(students[i].address.city, MAX_INPUT_LENGTH, "City%d", i + 1);
   }
   student_count = count < MAX_STUDENTS ? count : MAX_STUDENTS;
}