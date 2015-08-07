#ifndef __LAMBO_H__
#define __LAMBO_H__


#include <stdio.h>
#include <stdlib.h>

#if defined(__linux__)
#include <editline/history.h>
#endif

#ifdef _WIN32

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

static const char *PROJECT_TITLE = "LAMBO";
static const char *PROJECT_NAME = "lambo";

#endif/*__LAMBO_H__*/
