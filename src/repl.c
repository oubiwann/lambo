#include "lambo.h"

void show_banner () {
  /* Print Version and Exit Information */
  puts("LAMBO Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
}

int main(int argc, char** argv) {

  show_banner();

  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    char* input = readline("lambo> ");

    /* Add input to history */
    add_history(input);

    /* Echo input back to user */
    printf("No you're a %s\n", input);

    /* Free retrieved input */
    free(input);
  }

  return 0;
}
