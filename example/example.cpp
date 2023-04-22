
#include "TableSerialize/TableDeserializer.h"
#include "TableSerialize/TableSerializer.h"
#include "TableSerialize/SerializeUtils.h"
#include "TableCore/Table.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// the example for easy table.
std::string table1 =
{
	"key,fv1(type=float),fv2(type=float),num1(type=num),num2(type=num),b1(type=bool),b2(type=bool),txt1(type=text),txt2\r\n" \
	"rrf,451.8589,4.0,1000,9,1,0,txt1,98.0f\r\n" \
	"keynn,123.8589,789.0,20,30,0,1,txt1,txt2\r\n" \
	"err,,,,\r\n"\
	"err,,,,,,,,,,,\r\n"\
	"fft,f1,f2,n1,n2,,b1,b2,txt1,10.0f\r\n"
};

using TextStream = tab::TWriteStream<std::basic_stringstream<tab::TextChar>> ;

//-*****************************************************************************
int main( int argc, char *argv[] )
{

	tab::Table tbl;

	tab::TableDeserializer deser(tbl);

	deser.Deserialize(table1);


	TextStream stream;

	tab::TableSerializer ser(stream);

	ser.Serialize(tbl);

	std::wcout << stream.rdbuf() << std::endl;
	std::wcout << TABLE_TEXT("--------------------------------------------------------") << std::endl;
	auto result = tbl.SearchRecord(TABLE_TEXT("keynn"));

	std::wcout << TABLE_TEXT("keynn: ") << std::endl;

	if (result.IsValid())
	{
		tab::utils::SerializeTableRecord(std::wcout, result);
	}
	else
	{
		std::wcout << TABLE_TEXT("Record not found.") << std::endl;
	}



	std::getchar();
    return 0;
}
