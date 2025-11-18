#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE

	std::ofstream fout;

	fout.open("File.txt");

	fout << "Hello Word!" << endl;

	fout.close();

	system("notepad File.txt");
#endif 


	std::ifstream fin("File.txt");


	if (fin.is_open())
	{
	
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fin.close();
}