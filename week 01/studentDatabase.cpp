#include <iostream>
#include <assert.h>

enum class Major
{
	Undefined,
	S,
	Inf,
	InfS,
	CS,
};

const char* getMajor(Major m)
{
	switch (m)
	{
	case Major::S: return "S";
	case Major::Inf: return "Inf";
	case Major::InfS: return "Infs";
	case Major::CS: return "CS";
	}
	return "";
}

struct Student
{
	char name[100] = "";
	unsigned fn = 0;
	Major major=Major::Undefined;
};

void printStudent(const Student& st)
{
	std::cout << st.name << ' ' << st.fn << ' ' << getMajor(st.major)<<std::endl;
}

const size_t MAX_STUDENTS = 10;

struct StudentDatabase
{
	unsigned studentsCount = 0;
	Student students[MAX_STUDENTS];
};

void sortStudents(StudentDatabase& students)
{
	assert(students.studentsCount <= MAX_STUDENTS);
}

void printStudents(const StudentDatabase& students)
{
	assert(students.studentsCount <= MAX_STUDENTS);
	for (int i = 0; i < students.studentsCount; i++)
	{
		printStudent(students.students[i]);
	}
}

enum class Criteria
{
	sortByName,
	sortByMajor,
	sortByFn
};

void sortDatabase(StudentDatabase& students, bool(*isLess)(const Student& st1, const Student& st2))
{
	assert(students.studentsCount <= MAX_STUDENTS);
	for (int i = 0; i < students.studentsCount-1; i++)
	{
		int minElInd = i;
		for (int j = i+1; j < students.studentsCount; j++)
		{
			if (isLess(students.students[j],students.students[minElInd]))
			{
				minElInd = j;
			}
		}
		if (minElInd != i)
		{
			std::swap(students.students[i], students.students[minElInd]);
		}
	}
}

void sortByCriteria(StudentDatabase& database, Criteria cr)
{
	switch (cr)
	{
	case Criteria::sortByName:return sortDatabase(database,[](const Student& lhs, const Student& rhs) {return strcmp(lhs.name, rhs.name) < 0; });
	case Criteria::sortByMajor:return sortDatabase(database,[](const Student& lhs, const Student& rhs) {return lhs.major < rhs.major; });
	case Criteria::sortByFn:return sortDatabase(database,[](const Student& lhs, const Student& rhs) {return lhs.fn < rhs.fn; });
	}
}

//int main()
//{
//	StudentDatabase db =
//	{
//		3,{{"Petur",1234,Major::Inf}, {"Yana",2345,Major::InfS},{"Iliana",326,Major::S}}
//	};
//
//	printStudents(db);
//	sortByCriteria(db, Criteria::sortByName);
//	printStudents(db);
//	sortByCriteria(db, Criteria::sortByFn);
//	printStudents(db);
//	sortByCriteria(db, Criteria::sortByMajor);
//	printStudents(db);
//}