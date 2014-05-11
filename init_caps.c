#include "mynotsominishell.h"

void init_caps()
{
  char ex[2];
  char *term;
  term = getenv("TERM");
  if(!term)
    {
      my_str("Error initializing caps\n");
      restore_terminal();
      exit(0);
    }
  char bp[2048];
  tgetent(bp, term);
  gl_env.standout = get_term_cap(STANDOUT);
  gl_env.stand_end = get_term_cap(STAND_END);
  gl_env.left = get_term_cap(LEFT);
  gl_env.right = get_term_cap(RIGHT);
  gl_env.up = get_term_cap(UP);
  gl_env.down = get_term_cap(DOWN);
}
