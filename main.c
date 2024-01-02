#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000000
#define HIGHEST_NUMBER 10

int Collatz(int number);
int GetRandomNumber(int min, int max);

int main(int argc, char *argv[]) {
  int number_array[HIGHEST_NUMBER];
  bool dataset_grade = true;
  printf("3x+1 PROGRAMM!\n\n");
  printf("Generating Numbers:\n");
  for (size_t i = 0; i < HIGHEST_NUMBER; i++) {
    number_array[i] = i + 1;
  }
  printf("Done!\n\n");
  printf("Calculating Data:\n");

  for (size_t i = 0; i < HIGHEST_NUMBER; i++) {
    number_array[i] = Collatz(number_array[i]);
  }
  printf("Done!\n\n");
  printf("Printing Data:\n");
  for (size_t i = 0; i < HIGHEST_NUMBER; i++) {
    printf("%d\n", number_array[i]);
  }
  printf("Done!\n\n");
  printf("Judging Data:\n");
  for (size_t i = 0; i < HIGHEST_NUMBER; i++) {
    if (number_array[i] != 1) {
      printf("ANOMALY FOUND!\n");
      dataset_grade = 0;
    }
  }
  if (dataset_grade == true) {
    printf("Dataset OK!\n");
  } else {
    printf("Dataset ANOMALY\n");
  }
  return 0;
}

int Collatz(int number) {
  int result = number;
  int iterator = 0;
  while (result != 1 && iterator < MAX_ITERATIONS) {
    if (result % 2 == 0) {
      result /= 2;
    } else {
      result = (result * 3) + 1;
    }
    iterator++;
  }
  return result;
}

int GetRandomNumber(int min, int max) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Generate a random number within the range
  int randomNumber = min + rand() % (max - min + 1);

  return randomNumber;
}
