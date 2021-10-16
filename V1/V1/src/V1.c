#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Assert.h"

typedef struct _student
{
	char name[20];
	char lastName[20];
	double score;

}student;

int NumberOfRows(char* filePath);
int PrintData(student* students, int numberOfStudents);
student* CreateStudents(char* filePath,int numberOfStudents);

int main()
{
	int row = 0;
	student* students = NULL;

	row = NumberOfRows("res/StudentData.txt");
	students = CreateStudents("res/StudentData.txt", row);

	PrintData(students,row);

	return 0;
}

int NumberOfRows(char* filePath)
{
	int numberOfRows = 0;
	FILE* file = NULL;
	char buffer[1024] = { 0 };

	ASSERT(file = fopen(filePath, "r"));

	while (!feof(file))
	{
		fgets(buffer,1024,file);
		numberOfRows++;
	}
	fclose(file);

	return numberOfRows;
}

student* CreateStudents(char* filePath,int numberOfStudents)
{
	student* students = NULL;
	FILE* file = NULL;
	int i = 0;

	ASSERT(file = fopen(filePath, "r"));
	ASSERT(students = (student*)malloc(sizeof(student) * numberOfStudents));

	while (!feof(file))
	{
		fscanf(file, " %s %s %lf", students[i].name, students[i].lastName, &(students[i].score));
		i++;
	}
	fclose(file);

	return students;
}

int PrintData(student* students, int numberOfStudents)
{
	int i = 0;
	double highestScore = 0;

	for (i = 0; i < numberOfStudents; i++)
	{
		if (students[i].score > highestScore)
		{
			highestScore = students[i].score;
		}
	}

	if (highestScore > 0)
	{
		printf("#########################\n");
		for (i = 0; i < numberOfStudents; i++)
		{
			printf("Name: %s \n", students[i].name);
			printf("Last Name: %s \n", students[i].lastName);
			printf("Score: %.2lf \n", students[i].score);
			printf("Relative Score: %.2lf \n", (double)(students[i].score / highestScore) * 100);
			printf("#########################\n");
		}
	}
	else
	{
		printf("#########################\n");
		for (i = 0; i < numberOfStudents; i++)
		{
			printf("Name: %s \n", students[i].name);
			printf("Last Name: %s \n", students[i].lastName);
			printf("Score: %.2lf \n", students[i].score);
			printf("Relative Score: 0 \n");
			printf("#########################\n");
		}
	}

	return 0;
}