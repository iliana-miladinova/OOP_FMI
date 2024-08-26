#include <iostream>
#include <fstream>

enum class Major
{
	S,
	Inf,
	InfS,
	Cs,
	undefined
};

struct Student
{
	char name[100] = "";
	unsigned fn = 0;
	Major major = Major::undefined;
};

const size_t MAX_STUDENTS = 10;
struct StudentDatabase
{
	unsigned studentsCount = 0;
	Student students[MAX_STUDENTS];
};

void serializeStudent(std::ostream& os, const Student& st)
{
	os << st.name << std::endl << st.fn << std::endl << (int)st.major << std::endl;
}

void serializeDatabase(std::ostream& os, const StudentDatabase& db)
{
	os << db.studentsCount << std::endl;
	for (int i = 0; i < db.studentsCount; i++)
	{
		serializeStudent(os, db.students[i]);
	}
}

void deserializeStudent(std::istream& is, Student& st)
{
	is.ignore();//bazata zapochva s broya na horata v neya. Preskachame tova chislo s ignore
	is.getline(st.name, 100);//zapisvane imeto ot faila(chetem do nov red) v st.name 
	is >> st.fn;//zapisvame fn v st.fn
	int tempMajor;
	is >> tempMajor;//zapisvame Major kato int(zashto sme ya zapazili kato int) vremmeno v tempMajor;
	st.major = (Major)tempMajor;//preobrazuvame dannite ot int v major 

}

StudentDatabase deserializaDatabase(std::istream& is)
{
	StudentDatabase db;
	is >> db.studentsCount;
	for (int i = 0; i < db.studentsCount; i++)
	{
		deserializeStudent(is, db.students[i]);
	}
	return db;
}
//int main()
//{
//	/*std::ofstream ofs("students_to_text.txt");
//	if (!ofs.is_open())
//	{
//		std::cout << "error";
//		return -1;
//	}
//	StudentDatabase db =
//	{
//		3,
//		"Iliana Miladinova", 326, Major::S,
//		"Ivan Popov",1234,Major::Cs,
//		"Vyara Georgieva",2345,Major::InfS
//	};
//	serializeDatabase(ofs, db);*/
//
//	std::ifstream ifs("students_to_text.txt");
//	if (!ifs.is_open())
//	{
//		std::cout << "error";
//		return -1;
//	}
//	StudentDatabase db = deserializaDatabase(ifs);
//	serializeDatabase(std::cout, db);//printirame na konzolata
//}