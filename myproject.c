//James Dunlap
//jcd160230@utdallas.edu
//3377.501

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yyparse (void);
int yylex(void);
extern char *yytext;

int main(int argc, char *argv[])
{
  if(strstr(argv[0], "scanner")){/*If the linked name scanner is use, call the scanner*/
      printf("Operating in scan mode\n");

      int token;
      token = yylex();

      while(token != 0)
	{
	  printf("yylex returned ");
	  
	  switch(token)/*Match the returned token with it's type*/
	    {
	    case EOLTOKEN:
	      printf("EOLTOKEN token (\\n)\n");
	      break;
	    case COMMATOKEN:
	      printf("COMMATOKEN token (,)\n");
	      break;
	    case NAME_INITIAL_TOKEN:
	      printf("NAME_INITIAL_TOKEN token (%s)\n",yytext);
	      break;
	    case HASHTOKEN:
              printf("HASHTOKEN token (#)\n");
              break;
	    case DASHTOKEN:
	      printf("DASHTOKEN token (-)\n");
	      break;
	    case IDENTIFIERTOKEN:
	      printf("IDENTIFIERTOKEN token (%s)\n", yytext);
	      break;
	    case SRTOKEN:
	      printf("SRTOKEN token (Sr.)\n");
	      break;
	    case ROMANTOKEN:
	      printf("ROMANTOKEN token (%s)\n",yytext);
	      break;
	    case JRTOKEN:
	      printf("JRTOKEN token (Jr.)\n");
	      break;
	    case INTTOKEN:
	      printf("INTEGERTOKEN token (%s)\n", yytext);
	      break;
	    case NAMETOKEN:
	      printf("NAMETOKEN token (%s)\n", yytext);
	      break;
	    default:
	      printf("UNKNOWN\n");
	    }

	  token = yylex();
	}
      printf("Scan Successful!\n");
  }/*if the link name parser is called, run the parser*/
  else if(strstr(argv[0], "parser")){
     printf("Calling the parser.\n");
     switch (yyparse())
       {/*Print if the parse works or not based on it's output*/
	case 0:
	  printf("\nParse Successful!\n");
	  break;
	case 1:
	  printf("Parse Failed!\n");
	  break;
	case 2:
	  printf("Out of Memory\n");
	  break;
	default:	
	  printf("Unknown result from yyparse()\n");
	  break;
	}

      printf("Parsing Finished.\n");
    }
  return 0;
}
