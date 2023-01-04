#include <iostream>
#include <string>

enum MeasureUnit
{
	BYTE,
	KILOBYTE,
	MEGABYTE,
	GIGABYTE
};

MeasureUnit GetMeasureUnit()
{
	std::cout << "Chose a size measurement unit :\n\nbyte (b)\n\nkilobyte (k)\n\nmegabyte (m)\n\ngigabyte (g)\n\n";
	std::string _userInput = "";
	while (true)
	{
		std::cin >> _userInput;
		if (_userInput == "b")
			return BYTE;
		if (_userInput == "k")
			return KILOBYTE;
		if (_userInput == "m")
			return MEGABYTE;
		if (_userInput == "g")
			return GIGABYTE;
	}
}

__int64 constexpr GetFactorForMeasureUnit(MeasureUnit _unit)
{
	switch (_unit)
	{
	case BYTE:
		return 1;
	case KILOBYTE:
		return 1024;
	case MEGABYTE:
		return 1024 * 1024;
	case GIGABYTE:
		return 1024 * 1024 * 1024;
	}
}

int GetFileSize()
{
	std::cout << "Enter file size\n";
	int _result = -1;
	std::string _resultString = "";
	while (_result == -1)
	{
		std::cin >> _resultString;
		try
		{
			_result = std::stoi(_resultString);
		}
		catch (...)
		{
			std::cout << "make sure to use numbers only\n";
		}
	}
	return _result;
}

void main()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "GeneratedFile.bin", "w+");
	if (!fp)
		return;
	MeasureUnit measureUnit = GetMeasureUnit();
	system("cls");
	__int64 factor = GetFactorForMeasureUnit(measureUnit);
	__int64 fileSize = GetFileSize();
	__int64 bytesCount = fileSize * factor;
	std::cout << bytesCount << " bytes to write\n";
	bool* bytes = (bool*)malloc(bytesCount);
	if (!bytes)
	{
		std::cout << "an error occured, try asking for a smaller file";
		fclose(fp);
		return;
	}
	std::cout << "working on it...\n";
	memset(bytes, 0, bytesCount);
	fwrite(bytes, 1, bytesCount, fp);
	free(bytes);
	fclose(fp);
	std::cout << "done !\n";
}