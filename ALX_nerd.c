#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
void push(char *file_name, char *proj);

int main()
{

	char project[100];   //variable to store project name
	char command[1000];  // variable to store command 
	DIR *d;		     // pointer to a dir
	struct dirent *dir;        // i dont fully get it yet 
	char path[300];           // variable to store path to source
				// where we have the sultions

	printf("enter project name:  ");     
	gets(project,100*sizeof(char));     // get the project name
	
	sprintf(command,"mkdir alx_low_level_thisisatest/%s",project);   // sprintf is like strcpy but we can us % operators like printf here command = "mkdir .....thisisatest/project_name"
	system(command);  //execute the comande to creat directory with project name
	
	sprintf(path,"../alx-low_level_programming/%s",project);   // store solutions path to path
	d = opendir(path);     //open solution directory 

	if(d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.')
			{
				sprintf(command,"cp ../alx-low_level_programming/%s/%s alx_low_level_thisisatest/%s/%s",project,dir->d_name,project,dir->d_name);      // store the command to copy file from solution directory to working directory
				system(command);  // execute the command

				sleep(60);   // wait 60 sec
				push(dir->d_name, project);   // push to github

				sleep(3*60);
			}
		}
		closedir(d);
	}



	return 0;
}


void push(char *file_name, char *proj)
{
	char git_command[1000];
	sprintf(git_command,"git add alx_low_level_thisisatest/%s/.",proj);
	system(git_command);
	sprintf(git_command,"git commit -m \"%s\"",file_name);
	system(git_command);
	system("git push");
}
