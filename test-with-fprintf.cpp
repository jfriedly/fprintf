#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	FILE *outfile;
	outfile=fopen("test-result.txt","w");
	printf("\nWhattup\n");
	fprintf(outfile, "\nWhattup\n");
	for (i=0;i<5;i++)
	{
		printf("Now calculating...");
	fprintf(outfile, "Now calculating...");
		printf("%d\n", rand());
	fprintf(outfile, "%d\n", rand());
	}
	printf("\n\n\nYay!  I calculated 5 random numbers!");
	fprintf(outfile, "\n\n\nYay!  I calculated 5 random numbers!");
}
