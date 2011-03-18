/*BEGIN header*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//#include </uhome/f/friedly.1/myquicksort.h>

int main ()
{
	//print my info
	printf ("This is an open source program written by Joel Friedly (Class of 2014) to \ntake the boredom out of adding a million 'fprintf' statements to all \nthe assignments.  If you don't know how an fprintf statement works, you \nshould not be running this program.  This code is distributed under an \nopen GPL license.\n\nNotes:  The output file from this code assumes that your target program \nhas an output file pointer called 'outfile'.  Also, the end product will \nbe called '[FILENAME]-with-fprintf.cpp'.\n\n");


	//declare input and result files
	FILE *outfile, *infile;
	char input_name[100], * output_name;
	
	//get name of input file and open it:
	printf("Enter the name of the file to be completed: ");
	scanf("%s", &input_name);
	infile = fopen (input_name, "r");
	
	//open the output file
	output_name = strtok (input_name, ".");
	strcat (output_name, "-with-fprintf.cpp");
	outfile = fopen (output_name, "w");

	//declare some variables for the actual program 
	char line[200], linesub[100], line_two[200], line_three[200], line_four[200];
	char * strptr, * strptr2, * strptr3, * strptr4;
	int i=0, j;
	
	//open the while loop that will scan the entire file
	while (fgets(line, 200, infile) != NULL)
	{
		/*Unfortunately, it's a real pain to make c++ just insert data into a file.  So instead we'll just creat a new one, by the name of '[FILENAME]-with-fprintf.cpp' that contains all the old code with the new code.  Here's the line to include all the old code: */
		fprintf(outfile,"%s", line);

		//check for quotes, if there aren't any, count the squigly brackets
		if(strstr(line, "\"")==NULL)
		{
			if(strstr(line, "{"))
				i++;
			if(strstr(line, "}"))
				i--;
		}
		//if there are quotes, check the text before the quotes to see if there's a squigly bracket there
		else
		{
			strcpy(line_two, line);
			strptr3 = strtok(line_two, "\"");
			if(strstr(strptr3, "{"))
				i++;
			if(strstr(strptr3, "}"))
				i--;
			
		}
		//copy and separate the line at any left parentheses
		strcpy(line_three, line);
		strptr = strtok(line_three, "(");
		
		/*looks for the end of the current line and captures everything between where we are and that end*/
		strptr2 = strtok(NULL, "\n");
			
		//for debugging, should print every token in the file on a new line
		printf("\nWorking... %d ... %s", i, line);
		
		if (strstr(line, "printf"))
		{
			//for debugging, will alert on successfully finding a printf
			printf(" --Works!");
			

			strcpy(line_four, line);
			strptr4 = strstr(line_four, "printf(");
			
			//more debugging
			printf("  Scanned %s.", strptr4);
			
			/*the important bit.  Assuming strptr2 isn't null, print it out to the outfile with that special 'fprintf(outfile, ' in front.*/
			if (strptr4!=NULL)
			{
				for(j=0;j<i;j++)
					fprintf(outfile, "	");
				fprintf(outfile, "fprintf(outfile, %s\n", strptr4);
			}
		}
	}
	
	printf("\n\n\nSee %s to view the output code.\n", output_name);
	fclose (infile);
	fclose (outfile);
	return 0;
}
