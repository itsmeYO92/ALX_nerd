#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
void push(char *file_name, char *proj);

int main()
{	char project[100];
	char command[1000];
	DIR *d;
	struct dirent *dir;
	char path[300];
	printf("enter project name:  ");
	gets(project,100*sizeof(char));
	
	sprintf(command,"mkdir alx_low_level_thisisatest/%s",project);
	system(command);
	
	sprintf(path,"../alx-low_level_programming/%s",project);
	d = opendir(path);

	if(d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.')
			{
				sprintf(command,"cp ../alx-low_level_programming/%s/%s alx_low_level_thisisatest/%s/%s",project,dir->d_name,project,dir->d_name);
				system(command);

				sleep(60);
				push(dir->d_name, project);

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
