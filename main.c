#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_ITERATIONS 1000
#define HIGHEST_NUMBER 100

int Collatz(int number);
int GetRandomNumber(int min, int max);

char program_entry[] = {"3x+1 PROGRAMM!\n"};

int main(int argc, char *argv[]) {
  int max_iterations = MAX_ITERATIONS;
  int number_array[MAX_NUMBERS];
  printf("3x+1 PROGRAMM!\n\n");
  printf("Generating Random Numbers:\n");
  for (size_t i = 0; i < MAX_NUMBERS; i++) {
    number_array[i] = GetRandomNumber(0, HIGHEST_NUMBER);
  }
  printf("Done!\n\n");
  printf("Calculating Data:\n");
}

int Collatz(int number) {
  int modulo;
  int result;
  modulo = number % 2;

  if (modulo) {
    result = number / 2;
  } else {
    result = (3 * number) + 1;
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
