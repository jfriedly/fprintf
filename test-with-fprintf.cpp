#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	FILE *outfile;
	outfile=fopen("test-result.txt","w");
	printf("\nWhattup\n");
	fprintf(outfile, printf("\nWhattup\n");

	for (i=0;i<5;i++)	{
		printf("Now calculating...");
		fprintf(outfile, printf("Now calculating...");

		printf("%d\n", rand());
		fprintf(outfile, printf("%d\n", rand());

	}
	printf("\n\n\nYay!  I cal{culated 5 random numbers!");
	fprintf(outfile, printf("\n\n\nYay!  I cal{culated 5 random numbers!");


	for(i=0;i<3;i++) { printf("Hey guys!"); }
		fprintf(outfile, printf("Hey guys!"); }


}
