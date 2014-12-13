/*

At the beginning of the quarter, as a side project, I wanted to create a Pythagorean Theorem calculator.  During my research on how to write a program in C to handle the necessary mathematical functions I found a program that handles complex numbers.  This calculator can perform add, subtract, multiply, and divide operations on problems containing a real and an imaginary number.  

While the calculator performs as intended, the issue I saw with this code was a lack of compartmentalization.  The entire program is run in the main() function.  While this provides the convenience of having all of the code located in one spot, it makes digging through the whole code to edit a particular area more time consuming than need be.  

My objectives for this project are as follows: 

  1.  Divide this complex number calculator into several function-specific files to 
      make editing easier.

  2.  Create object (.o) files as part of a static library.

  3.  Create a makefile and link the separated mathematic functions to perform the 
      same calculator functions as the original source code.

*/  
#include <stdio.h>
#include <stdlib.h>
#include "add.c"
#include "add.h"
#include "subtract.c"
#include "subtract.h"
#include "multiply.c"
#include "multiply.h"
#include "divide.c"
#include "divide.h"
#include "complex.h"
 

int main()
{
  int choice, temp1, temp2, temp3;
  complex a;
  complex b;
  complex c;
 
  while(1)
  {
    printf("Press 1 to add two complex numbers.\n");
    printf("Press 2 to subtract two complex numbers.\n");
    printf("Press 3 to multiply two complex numbers.\n");
    printf("Press 4 to divide two complex numbers.\n");
    printf("Press 5 to exit.\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
 
    if( choice == 5)
  	{
        exit(0);
  	}
 
    if(choice >= 1 && choice <= 4)
    {
      printf("Enter a and b where a + ib is the first complex number.");
      printf("\na = ");
      scanf("%d", &a.real);
      printf("b = ");
      scanf("%d", &a.img);
      printf("Enter c and d where c + id is the second complex number.");
      printf("\nc = ");
      scanf("%d", &b.real);
      printf("d = ");
      scanf("%d", &b.img);
    }
	
    if ( choice == 1 )
    {
      c = addition(a, b);
 
      if ( c.img >= 0 )
	  {
        printf("Sum of two complex numbers = %d + %di",c.real,c.img);
	  }
      else
	  {
        printf("Sum of two complex numbers = %d %di",c.real,c.img);
	  }
    }
    else if ( choice == 2 )
    {
	  c = subtraction(a, b);
 
      if ( c.img >= 0 )
	  {
        printf("Difference of two complex numbers = %d + %di",c.real,c.img);
	  }
      else
	  {
        printf("Difference of two complex numbers = %d %di",c.real,c.img);
	  }
    }
    else if ( choice == 3 )
    {
      c = multiply(a, b);
 
      if ( c.img >= 0 )
	  {
        printf("Multiplication of two complex numbers = %d + %di",c.real,c.img);
	  }
      else
	  {
        printf("Multiplication of two complex numbers = %d %di",c.real,c.img);
	  }
    }
    else if ( choice == 4 )
    {
      if ( b.real == 0 && b.img == 0 )
	  {
        printf("Division by 0 + 0i is not allowed.");
	  }
      else
      {
        c = divide(a, b);
		
		if ( c.img >= 0 )
		{
			printf("Division of two complex numbers = %d + %di",c.real,c.img);
		}
		else
		{
			printf("Division of two complex numbers = %d %di",c.real,c.img);
		}
      
	  }
    }
    else
	{
      printf("Invalid choice.");
	}
 
    printf("\nPress any key to enter choice again...\n");
  }
}

/* Old code ----
#include <stdio.h>

void choices(void)
  { 
    if(choice >= 1 && choice <= 4)
	    {
	      printf("Enter a and b where a + ib is the first complex number.");
	      printf("\na = ");
	      scanf("%d", &a.real);
	      printf("b = ");
	      scanf("%d", &a.img);
	      printf("Enter c and d where c + id is the second complex number.");
	      printf("\nc = ");
	      scanf("%d", &b.real);
	      printf("d = ");
	      scanf("%d", &b.img);
	    }

/*void choices(void)
	{
		if (choice == 1)
		{
			
			if ( c.img >= 0 )
				printf("Sum of two complex numbers = %d + %di",c.real,c.img);
		      	else
				printf("Sum of two complex numbers = %d %di",c.real,c.img);
		}
		else if (choice == 2)
		{
			void subtraction(void)
		}
		else if (choice == 3)
		{
			void multiply(void)
		}
		else if (choice == 4)
		{
			void divide(void)
		}
	}
    
    if(choice == 5)
	    {	
	      exit(0);
	    }
    
    else
	    {
	      printf("Invalid choice.");
	 
	      printf("\nPress any key to enter choice again...\n");
	    }
  }*/
