/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

void	bigargs(int32 argc, int32 *argv)
{
	int a = argv[0];
	int b = argv[1];
	int c = argv[2];
	int d = argv[3];
	int e = argv[4];
	int f = argv[5];
	kprintf("bigargs(%d, %d, %d, %d, %d, %d) == %d\r\n", a, b, c, d, e, f, a+b+c+d+e+f);
}


void	printpid(int32 argc, int32 *argv)
{
	int i;
	for (i=0; i<argv[0]; i++)
	{
		kprintf("This is process %d (%s)\r\n", currpid, proctab[currpid].prname);
		resched();
	}
}

int	main(uint32 argc, uint32 *argv)
{
	static uint32 args[] = {1, 2, 3};
	static uint32 *args1 = args;
	static uint32 args2[] = {10, 20, 30, 40, 50, 60};

	kprintf("Hello XINU WORLD!\r\n");

	//priority of process is input as the 3rd argument of create()
	ready(create((void*) printpid, INITSTK, 1, "PRINTER-1", 2, 1, args1++), FALSE);
	ready(create((void*) printpid, INITSTK, 5, "PRINTER-B", 2, 1, args1++), FALSE);
	ready(create((void*) printpid, INITSTK, 10, "PRINTER-C", 2, 1, args1++), FALSE);
	ready(create((void*) printpid, INITSTK, 5, "PRINTER-D", 2, 1, args1++), FALSE);
	ready(create((void*) bigargs, INITSTK, 5, "BIGARGS", 2, 6, args2), FALSE);

	return 0;
}
