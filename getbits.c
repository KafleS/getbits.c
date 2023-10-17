/*****
 * Name : Suman Kafle
 * Class : CS241 
 * Lab-03 : getbits.c */


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* function declared */
unsigned getbits(unsigned given_Number, int position, int bit_Extracted);

int main ()
{
  int answer;
  double  you_Entered;
  unsigned  you_Entered1;
  int positional_Value,num_Of_Bits;
  char str[1000];


  while (1)
    {
      /*  to read input from the user */
      fgets(str, sizeof(str), stdin);

      /*  to Check if the user wants to exit */
      if (feof(stdin))
	{
	  break;
	}

      /* to separe unsingend and integer and to store them into corresponding variable*/
      if (sscanf(str, "%lf:%d:%d", &you_Entered, &positional_Value, &num_Of_Bits))
	{
	  /* to print out error if too many bits are requested from the position */
	  if( num_Of_Bits> positional_Value+1)
	    {
	      printf("Error: too many bits requested from position\n");
	    }

	  /* to print out error if the position is out of the range */
	  else if ( positional_Value>31)
	    {
	      printf("Error: position out of range\n");
	    }

	  /* to print out error if the value is out of the range */
	  else if (you_Entered > UINT_MAX )
	    {
	      printf("Error: value out of range\n");
	    }

	  /* to print out error if the number of bits are out of the range */
	  else if(num_Of_Bits>31)
	    {
	      printf("Error: number of bits out of range\n");
	    }

	  /* to print the value if there are no errors*/
	  else
	    {
	      you_Entered1 = (unsigned)you_Entered;
	      answer = getbits(you_Entered1,positional_Value,num_Of_Bits);
	      printf("getbits(x=%u, p=%d, n=%d) = %d\n", you_Entered1,positional_Value, num_Of_Bits, answer);
	    }
	}
    }
  return 0;
 }

/* usigned function is made*/
unsigned getbits(unsigned given_Number, int position, int bit_Extracted)
{
  return (given_Number >> ( position+1-bit_Extracted)) & ~(~0 << bit_Extracted);
}
