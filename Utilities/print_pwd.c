#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

char* stack[100];
int stk_cnt = 0;

char* get_file_name_with_inode(ino_t file_inode)
{
	// Dir_inode is the directory inode
	struct dirent* dir;
	DIR* dp = opendir(".");
	if( dp==NULL )
	{
		perror("DIR");
		exit(0);
	}
	while( (dir = readdir(dp)) != NULL )
	{
		// Read an entry of the directory
		// Do stat and get the inode and compare it
		if( dir->d_ino == file_inode )
		{
			// return the name of the file
			char* str = (char*)malloc(sizeof(char)*strlen(dir->d_name));
			strcpy(str,dir->d_name);
			close(dp);
			return str;
		}
	}
	printf("Given path is incorrect\n");
	exit(0);
}

ino_t get_inode_for_a_file(char* file_name)
{
	struct stat buf;
	if( stat(file_name, &buf) < 0 )
	{
		perror("Stat");
	}
	return buf.st_ino;
}

int main()
{
	while(1)
	{
		// get the current inode entry
		ino_t dir_inode = get_inode_for_a_file(".");
		if( chdir("..") == -1 )
		{
			perror("Chdir");
			exit(0);
		}
		// This is for checking root
		ino_t dir_inode_new = get_inode_for_a_file(".");
		if( dir_inode == dir_inode_new )
		{
			// Root found
			printf("/");
			int i;
			for(i = stk_cnt-1;i>=0;i--)
			{
				printf("%s",stack[i]);
				if( i!=0 )
					printf("/");
			}
			printf("\n");
			exit(0);
		}
		char* file_name = get_file_name_with_inode(dir_inode);
		stack[stk_cnt++] = file_name;
	}
}
