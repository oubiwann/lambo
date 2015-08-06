#include "lambo.h"
#include "parser.h"


void show_banner () {
  /* Print Version and Exit Information */
  puts("LAMBO Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");
}

void parse_input (char* input,mpc_parser_t* Lambo) {
  mpc_result_t r;
  if (mpc_parse("<stdin>", input, Lambo, &r)) {
    /* On success print and delete the AST */
    mpc_ast_print(r.output);
    mpc_ast_delete(r.output);
  } else {
    /* Otherwise print and delete the Error */
    mpc_err_print(r.error);
    mpc_err_delete(r.error);
  }
}

int main(int argc, char** argv) {

  show_banner();

  /* Create Some Parsers */
  mpc_parser_t* Number   = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr     = mpc_new("expr");
  mpc_parser_t* Lambo    = mpc_new("lambo");
  
  /* Define them with the following Language */
  mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      lambo    : /^/ <operator> <expr>+ /$/ ;             \
    ", Number, Operator, Expr, Lambo);

  
  /* In a never ending loop */
  while (1) {

    /* Output our prompt and get input */
    char* input = readline("lambo> ");
    
    /* Add input to history */
    add_history(input);

    /* Attempt to parse input */
    parse_input(input, Lambo);

    /* Free retrieved input */
    free(input);
  }

  mpc_cleanup(4, Number, Operator, Expr, Lambo);
  return 0;
}
