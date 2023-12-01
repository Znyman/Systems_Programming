#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

struct Student {
	int studentId;
	int assignmentGrades[4];
};

void seekReadWrite(Student* studentExamplePointer, FILE* currentFilePointer, Student* studentRecordsArrayPointer)
{
	char currentGrade;
	int currentSeekStatus, currentWriteStatus, currentReadStatus;
	for (int i = 1; i < 6; i++)
	{
		currentSeekStatus = fseek(currentFilePointer, -1 * (sizeof(Student)*i), SEEK_END);
		currentReadStatus = fread(studentExamplePointer, sizeof(Student), 1, currentFilePointer);
		//Part 3.a. in Lab5 description
		cout << "Seek status: " << currentSeekStatus << "\nRead status: " << currentReadStatus << endl;
		//Part 3.b. in Lab5 description
		cout << "Student ID: " << studentExamplePointer->studentId << endl;
		for (int j = 0; j < 4; j++)
		{
			//Part 3.b. in Lab5 description
			cout << "Assignment " << j + 1 << " letter grade: ";
			printf("%c", studentExamplePointer->assignmentGrades[j]);
			cout << endl;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "Student ID: " << i << endl;
		for (int j = 0; j < 4; j++)
		{
			//Part 3.c. in Lab5 description
			cout << "Input assignment " << j + 1 << " letter grade: ";
			cin >> currentGrade;
			studentRecordsArrayPointer[i].assignmentGrades[j] = currentGrade;
		}
	}
	//Part 3.c. in Lab5 description
	currentSeekStatus = fseek(currentFilePointer, 0, SEEK_SET);
	currentWriteStatus = fwrite(studentRecordsArrayPointer, sizeof(Student), 5, currentFilePointer);
	//Part 3.d. in Lab5 description
	cout << "Seek status: " << currentSeekStatus << '\n' << currentWriteStatus << " values were written to disk" << endl;
}

int main() {

	char grade;
	int writeStatus;
	//Part 1 in Lab5 description
	FILE* filePointer = fopen("student-records.bin", "w+b");
	if (!filePointer)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}

	//Part 2 in Lab5 description
	Student studentRecords[5];
	studentRecords[0] = { 0 };
	studentRecords[1] = { 1 };
	studentRecords[2] = { 2 };
	studentRecords[3] = { 3 };
	studentRecords[4] = { 4 };

	for (int i = 0; i < 5; i++)
	{
		cout << "Student ID: " << i << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << "Input assignment " << j+1 << " letter grade: ";
			cin >> grade;
			studentRecords[i].assignmentGrades[j] = grade;
		}
	}
	//Part 2.d. in Lab5 description
	writeStatus = fwrite(studentRecords, sizeof(Student), 5, filePointer);
	cout << writeStatus << " values were written to disk" << endl;
	//Part 3 in Lab5 description
	Student studentExample;
	seekReadWrite(&studentExample, filePointer, studentRecords);
	//Part 4 in Lab5 description
	seekReadWrite(&studentExample, filePointer, studentRecords);
	//Part 5 in Lab5 description
	fclose(filePointer);

	return 0;
}