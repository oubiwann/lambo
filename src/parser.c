#include "parser.h"

void parse_input (char* input, mpc_parser_t* Lambo) {
  mpc_result_t r;
  if (mpc_parse("<stdin>", input, Lambo, &r)) {
    long result = eval(r.output);
    printf("%li\n", result);
    mpc_ast_delete(r.output);
  } else {
    /* Otherwise print and delete the Error */
    mpc_err_print(r.error);
    mpc_err_delete(r.error);
  }
}
