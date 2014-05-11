#ifndef _MYNOTSOMINISHELL_H_
#define _MYNOTSOMINISHELL_H_
#include "../lib/my.h"
#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/termios.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <termcap.h>

#define READTIME 1
#define READMIN 3
#define KU "\E[A"
#define KD "\E[B"
#define KR "\E[C"
#define KL "\E[D"
#define UP "ku"
#define DOWN "kd"
#define LEFT "kl"
#define RIGHT "kr"
#define STANDOUT "so"
#define STAND_END "se"

typedef struct s_env
{
  char *left;
  char *up;
  char *down;
  char *right;
  char *standout;
  char *stand_end;
  struct termio line_backup;
  char *input_line;
  int flag;
  int stdio_backup;
  int pos;
} t_env;

t_env gl_env;

void init_terminal(); //Done
void init_caps(); //Done
char *get_term_cap(char*); //Done
void restore_terminal(); //Done
//void check_char(char*);
void term_standout(); //Done
void term_standend(); //Done
int my_termprint(int); //Done
#endif
