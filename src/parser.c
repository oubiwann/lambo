#include "parser.h"
#include "eval.h"


void parse_input(char* input, mpc_parser_t* Lambo) {
  mpc_result_t r;
  if (mpc_parse("<stdin>", input, Lambo, &r)) {
    lval result = eval(r.output);
    lval_println(result);
    mpc_ast_delete(r.output);
  } else {    
    mpc_err_print(r.error);
    mpc_err_delete(r.error);
  }
}
