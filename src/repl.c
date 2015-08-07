#include "lambo.h"
#include "parser.h"


void show_banner () {
  /* Print Version and Exit Information */
  printf("%s Version 0.0.0.0.1\n", PROJECT_TITLE);
  printf("Press Ctrl+c to Exit\n\n");
}


int main(int argc, char** argv) {

  show_banner();

  /* Create Some Parsers */
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Symbol = mpc_new("symbol");
  mpc_parser_t* Sexpr  = mpc_new("sexpr");
  mpc_parser_t* Expr   = mpc_new("expr");
  mpc_parser_t* Lambo    = mpc_new(PROJECT_NAME);

  /* Define them with the following Language */
  mpca_lang(MPCA_LANG_DEFAULT,
    "                                          \
      number : /-?[0-9]+/ ;                    \
      symbol : '+' | '-' | '*' | '/' ;         \
      sexpr  : '(' <expr>* ')' ;               \
      expr   : <number> | <symbol> | <sexpr> ; \
      lambo  : /^/ <expr>* /$/ ;               \
    ",
    Number, Symbol, Sexpr, Expr, Lambo);


  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    printf("%s> ", PROJECT_NAME);
    char* input = readline("");

    /* Add input to history */
    add_history(input);

    /* Attempt to parse input */
    parse_input(input, Lambo);

    /* Free retrieved input */
    free(input);
  }

  mpc_cleanup(5, Number, Symbol, Sexpr, Expr, Lambo);
  return 0;
}
