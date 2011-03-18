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

	//declare some variables for the actual program. i is used to count open squilgy brackets so that it knows how many times to indent a given fprintf
	//statement, j is used to do the actual indenting. The rest of them are explained where they are used.
	char line[256], line_two[256], line_three[256];
	char * quote_strptr, * second_quote_strptr, * rest_of_line_strptr, * print_stmt_strptr;
	int i=0, j;
	
	//open the while loop that will scan the entire file
	while (fgets(line, 255, infile) != NULL)
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
		//if there are quotes, check the text before and after the quotes to see if there's a squigly bracket there
		//have to make a copy of the line too so that we don't mess with string tokens later on
		else
		{
			strcpy(line_two, line);						//make a copy
			quote_strptr = strtok(line_two, "\"");  			//everything before the first quotes
			second_quote_strptr = strtok(NULL, "\"");			//everything inside the quotes
			rest_of_line_strptr = strtok(NULL, "\n");			//everything after the second quotes
			if(strstr(quote_strptr, "{")||strstr(rest_of_line_strptr, "{"))
				i++;
			if(strstr(quote_strptr, "}")||strstr(rest_of_line_strptr, "}"))
				i--;
		}
			
		//for debugging, should print every line in the file as it's working
		printf("Working... %d ... %s", i, line);
		
		//look through the entire line for the string 'printf'	
		if (strstr(line, "printf"))
		{
			//for debugging, will alert on successfully finding a printf
			printf("----------------Works!");
			
			//figure out where in the line the 'printf' is and get a pointer to that spot
			print_stmt_strptr = strstr(line, "printf(");
			
			//more debugging, prints what is being put after the fprintf statement in the outfile
			printf("  Scanned %s", print_stmt_strptr);
			

			/*THE IMPORTANT PART.  Assuming print_stmt_strptr isn't null, print it out to the outfile with that special 'fprintf(outfile, ' in 
			front.*/
			if (print_stmt_strptr!=NULL)
			{
				for(j=0;j<i;j++)
					fprintf(outfile, "	");
				fprintf(outfile, "fprintf(outfile, %s", print_stmt_strptr);
			}
		}
	}
	
	printf("\n\n\nSee %s to view the output code.\n", output_name);
	fclose (infile);
	fclose (outfile);
	return 0;
}

