/*
 * CSE 351 HW1 (Data Lab - Pointers)
 *
 * <Vamshi k.vamshi2008@gmail.com>
 *
 * pointer.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, the following function declaration should prevent a
 * compiler warning. In general, it's not good practice to ignore
 * compiler warnings, but in this case it's OK.
 */
int printf(const char *, ...);

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. For 1-4, only Unary integer operations *, & and Binary integer
      operations - + * are allowed. For the last three, you may also
      use shifts (<<, >>), ~, ==, and ^.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, ?: or sizeof.
  6. Use any data type other than those already in the declarations provided.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 * Test the code below in your own 'main' program.
 *
 */

#endif

/*
 * Return the size of an integer in bytes.
 */
int intSize() {
  /*
  	Returns the size of the integer
  */
  int a[2];
  return ((long)(a+1)-(long)a);
}

/*
	 * Return the size of a double in bytes.
 */
int doubleSize() {
  double a[2];
  return ((long)(a+1) - (long)a);
}

/*
 * Return the size of a pointer in bytes.
 */
int pointerSize() {
  int* p[2];
  return ((long)(p+1) - (long)p);
}

/*
 * Modify intArray[5] to be the value 351 using only &intArray and
 * pointer arithmetic.
 */
int changeValue() {
  int intArray[10];
  int * intPtr1 = intArray;
  // TODO: Write code to change value of intArray[5] to 351 using only
  //       intPtr1 and the + operator.
  *(intPtr1+5) = 351; 
  return intArray[5];
}


/*
 * Return 1 if ptr1 and ptr2 are within the *same* 64-byte aligned
 * block (or word) of memory. Return zero otherwise.
 *
 * Operators / and % and loops are NOT allowed.
 */
int withinSameBlock(int * ptr1, int * ptr2) {
	unsigned long l1 = ptr1;
	unsigned long l2 = ptr2;
	long mask = 0x3F;
	return ((l1 & ~mask) == (l2 & ~mask)); 
}

/*
 * Return 1 if ptr points to an element within the specified intArray,
 * 0 otherwise.
 */
int withinArray(int * intArray, int size, int * ptr) {

	

}

/*
 * Return x with the n bits that begin at position p inverted (i.e.,
 * turn 0 into 1 and vice versa) and the rest left unchanged. Consider
 * the indices of x to begin with the low-order bit numbered as 0.
 */

int invert(int x, int p, int n) {

	// Check if 'n' is 0 or not
	int n_val = n;
	int temp1 = 1;
	int masker = 0;
	
	n = n | ( n >> 16 );
	n = n | ( n >> 8 );
	n = n | ( n >> 4 );
	n = n | ( n >> 2 );
	n = n | ( n >> 1 );
	n = ( n << 31 ) >> 31;

	//printf(" n is %x\n",n);

	// 1 in MSB
	temp1 = 1 << 31;

	// Form masker 
	masker = temp1 >> (32-n_val-p-1);
	
	//printf("Masker is %x\n",masker);
	
	temp1 = temp1 >> (n_val-1);

	//printf("xor bit string is %x\n",temp1);

	temp1 = temp1 >> (32-n_val-p);

	//printf("xor bit string positioned properly %x",temp1);
	
	temp1 = temp1 & ~ masker;

	//printf("temp final is %x\n",temp1);

	temp1 = ( n & temp1 );
	//printf("After checking temp is %x\n",temp1);
	return x ^ temp1;
}
/*
int main()
{
	int a = 0xFFFFFFFF;
	int n = 0;
	int p = 16;
	printf("From pos %d and %d digits \nResult is %x\n\n",p,n,invert(a,p,n));
}
*/
