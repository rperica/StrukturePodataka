#include "stdio.h"
#include "stdlib.h"

#include "Assert.h"

typedef struct _student
{
	char name[20];
	char lastName[20];
	int score;

}student;

int NumberOfRows(const char*);
int PrintStudentsData(student*, int);
student* CreateStudents(const char*, int);

int main()
{
	int numberOfStudents = NumberOfRows("res/StudentData.txt");
	student* students = CreateStudents("res/StudentData.txt", numberOfStudents);

	PrintStudentsData(students,numberOfStudents);

	free(students);
	return 0;
}

int NumberOfRows(const char* filePath)
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

student* CreateStudents(const char* filePath, int numberOfStudents)
{
	student* students = NULL;
	FILE* file = NULL;
	int i = 0;

	ASSERT(file = fopen(filePath, "r"));
	ASSERT(students = (student*)malloc(sizeof(student) * numberOfStudents));

	while (!feof(file))
	{
		fscanf(file, " %s %s %d", students[i].name, students[i].lastName, &(students[i].score));
		i++;
	}
	fclose(file);

	return students;
}

int PrintStudentsData(student* students, int numberOfStudents)
{
	int i = 0;
	float highestScore = 0.0f;

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
			printf("Score: %d \n", students[i].score);
			printf("Relative Score: %.2f \n", (float)(students[i].score / highestScore) * 100.0f);
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
			printf("Score: %d \n", students[i].score);
			printf("Relative Score: 0 \n");
			printf("#########################\n");
		}
	}

	return 0;
}