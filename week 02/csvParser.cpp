#include <iostream>
#include <fstream>
#include <sstream>
#include<assert.h>

namespace GlobalConstants
{
	constexpr int FIELD_MAX_SIZE = 30;
	constexpr int MAX_FIELDS_ROW = 10;
	constexpr int ROWS_MAX_SIZE = 300;
	constexpr int BUFFER_SIZE = 1024;
	constexpr char SEP = ';';
}

typedef char Field[GlobalConstants::FIELD_MAX_SIZE];
typedef Field Row[GlobalConstants::MAX_FIELDS_ROW];

struct CsvTable
{
	Row rows[GlobalConstants::ROWS_MAX_SIZE];
	size_t rowsCount = 0;
	size_t colsCount = 0;
};

size_t parseRow(const char* row, Row& toReturn)
{
	std::stringstream ss(row);
	size_t currColCount = 0;
	while (!ss.eof())
	{
		ss.getline(toReturn[currColCount], GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
		//zapisvame dannite ot ss na toReturn[currColCount], dokato ne sreshtnem razdelitel, ili ne zapalnim bufera(FIELD_MAX_SIZE)
	}
	return currColCount;
}

CsvTable parseFromFile(std::ifstream& ifs)
{
	CsvTable result;
	char rowStr[GlobalConstants::BUFFER_SIZE];
	while (ifs.eof())
	{
		ifs.getline(rowStr, GlobalConstants::BUFFER_SIZE, '\n');//zapisvame row kojto vzemame ot ifs vremenno v rowstr
		result.colsCount = parseRow(rowStr, result.rows[result.rowsCount++]);
	}
	return result;
}

CsvTable parseFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return {};
	}

	parseFromFile(ifs);
}

void printTable(const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		for (int j = 0; j < table.colsCount; j++)
		{
			std::cout << table.rows[i][j] << "		";
		}
		std::cout << std::endl;
	}
}

void saveRowToFile(std::ostream& ofs, const Row& row, size_t colsCount)
{
	for (int i = 0; i < colsCount; i++)
	{
		ofs << row[i];
		if (i<colsCount-1)
		{
			ofs << GlobalConstants::SEP;
		}
	}
}

void saveToFile(std::ostream& ofs, const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		saveRowToFile(ofs, table.rows[i], table.colsCount);
		if (i<table.rowsCount-1)
		{
			ofs << '\n';
		}
	}
}

void saveToFile(const char* fileName, const CsvTable& table)
{
	std::ofstream ofs(fileName);
	if (!ofs.is_open())
	{
		return;
	}
	saveToFile(ofs, table);
	ofs.close();
}

int getCollumnInd(const CsvTable& table, const char* colName)
{
	assert(table.rowsCount >= 1);
	for (int i = 0; i < table.colsCount; i++)
	{
		if (strcmp(table.rows[0][i],colName)==0)
		{
			return i;
		}
	}
	return -1;
}

bool modify(CsvTable& table, const char* colName, const char* newValues, char sep)
{
	int colInd = getCollumnInd(table, colName);
	if (colInd<0)
	{
		return false;
	}

	std::stringstream ss(newValues);
	int rowInd = 1;
	while (!ss.eof())
	{
		if (rowInd>table.rowsCount)
		{
			break;
		}
		ss.getline(table.rows[rowInd++][colInd], GlobalConstants::FIELD_MAX_SIZE, sep);

	}
	return true;
}

int main()
{
	CsvTable myFile = parseFromFile("students1.csv");
	printTable(myFile);
	modify(myFile, "Ime", "Katerina|Petya", '|'); //shte promenim imenata samo na parvite dvama choveka v tablicata saotvetno parviyat stava Katerina, a vtoriyat Petya, zashtoto v newValues nyama dostatachno imena za vseki red ot tablicata
	saveToFile("students_new.csv", myFile);
}