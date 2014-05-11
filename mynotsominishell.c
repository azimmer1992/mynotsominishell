#include "../lib/my.h"

int main()
{
  char *dir = (char *)xmalloc(BUF_SZ*sizeof(char));
  pid_t pid;
  char **vect;
  char *buffer;
  int n;
  while(1)
    {
      buffer = (char *)xmalloc(BUF_SZ*sizeof(char));
      dir = getcwd(NULL, BUF_SZ-1);
      dir[BUF_SZ-1] = '\0';
      my_str("minishell:");
      my_str(dir);
      my_str("$");
      n = read(0, buffer, BUF_SZ-1);
      buffer[n-1]='\0';
      vect = my_str2vect(buffer);
      if(!my_strcmp(vect[0],"cd"))
	chdir(vect[1]);
      else if(!my_strcmp(vect[0],"exit"))
	{
	  my_str("The NSA sends its regards.\n");
	  break;
	}
      else
	{
	  if((pid=fork())==0)
	    {
	      if(execvp(vect[0],vect)<0)
		{
		  my_str(vect[0]);
		  my_str(":This is an invalid command\n");
		  exit(0);
		}
	      exit(0);
	    }
	  else
	    wait();
	}
      free(buffer);
      for(n=0; vect[n]!='\0'; n++)
	{
	  free(vect[n]);
	  vect[n]=NULL;
	}
    }
  return 0;
}
