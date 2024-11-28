/* address_list.c */
// This program should be completed such that it maintains a list of students
//x TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
//x TO DO 2: Use a variable to count the number of students stored in the array.
//x TO DO 3: Write a function printStudent(i), which prints student i stored in the array
//x TO DO 4: Write functions addStudent(), for adding a student at the first free position, and printAllStudents() for printing all students stored.
//x TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
//x TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
//x TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc.
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>
#define MAX_STUDENTS 100
#define MAX_INPUT_LENGTH 30

int student_count = 0;

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

struct person students[MAX_STUDENTS];

void inputStudent(int i) {
   printf("Enter first name: ");
   scanf("\n %s", students[i].first_name);
   printf("Enter last name: ");
   scanf("\n %s", students[i].last_name);

   char gender_input;
   printf("Enter gender (m/f/o): ");
   scanf("\n %c", &gender_input);
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

   printf("Enter birth date day: ");
   scanf("%d", &students[i].birth_date.day);
   printf("Enter birth date month: ");
   scanf("%d", &students[i].birth_date.month);
   printf("Enter birth date year: ");
   scanf("%d", &students[i].birth_date.year);

   printf("Enter enrollment date day: ");
   scanf("%d", &students[i].enrollment_date.day);
   printf("Enter enrollment date month: ");
   scanf("%d", &students[i].enrollment_date.month);
   printf("Enter enrollment date year: ");
   scanf("%d", &students[i].enrollment_date.year);

   printf("Ender street: ");
   scanf(" %[^\n]s", students[i].address.street);
   getchar();
   printf("Enter number: ");
   scanf(" %d", &students[i].address.number);
   printf("Enter zip code: ");
   scanf(" %d", &students[i].address.zip_code);
   printf("Enter city: ");
   scanf("\n %s", students[i].address.city);
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
   printf("Student %d| %s %s", i, students[i].first_name, students[i].last_name);
   switch (students[i].gender) {
      case male:
         printf(", Male");
      break;
      case female:
         printf(", Female");
      break;
      case other:
         printf(", Other");
      break;
   }
   printf(", Birth: %d.%d.%d", students[i].birth_date.day, students[i].birth_date.month, students[i].birth_date.year);
   printf(", Enrollment: %d.%d.%d", students[i].enrollment_date.day, students[i].enrollment_date.month, students[i].enrollment_date.year);
   printf(", Address: %s %d, %d %s", students[i].address.street, students[i].address.number, students[i].address.zip_code, students[i].address.city);
   printf("\n");
}

void printAllStudents() {
   for (int i = 0; i < student_count; i++) {
      printStudent(i);
   }
}

void menu() {
   char choice = 0;
   while (1) {
      printf("1: Add Student\n");
      printf("2: Print all students\n");
      printf("3: Quit\n");
      printf("What do you want to do? ");
      scanf("\n %c", &choice);
      switch (choice) {
         case '1':
            addStudent();
         break;
         case '2':
            printAllStudents();
         break;
         case '3':
            return;
         default:
            printf("Wrong input\n");
      }
      printf("************************\n");
   }
}

int main() {
   menu();
}