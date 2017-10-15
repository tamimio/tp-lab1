#include <io.h>
//#include <iostream>
#include <string>

/*
class Item
{
public:
	virtual string name()=0; // ������ ���
	virtual string date()=0; // ���� �������� �����, YYYY-MM-DD
};*/

class FileItem
{
	std::string name;
	std::string path;

public: 
	FileItem() {};

	FileItem (const std::string& name, const std::string& path)
	{
		this->name = name;
		this->path = path;
	}

	void show()
	{
		std::cout << "File: "		<< name << std::endl;
		std::cout << "Directory: "	<< path << std::endl;
		std::cout << "---------" << std::endl;
	}
};

//--------------

/*
class Iterator
{
	Item * doSearch(); // ���� � ���/���������, ����� ����������
	Item * cache; // ���-� ������ hasMore()

public:
	bool hasMore(); // true, ���� ��� ���� � ���/��������� �����, �����. �����
	Item * Next();
};*/

class FileIterator
{
	FileItem * cache; // ���-� ������ hasMore()
	std::string FileMask;

	FileItem * doSearch(); // ���� � ���/���������, ����� ����������
	FileItem * doSearch(const std::string & _fileMask);

    inline bool IsDirectory(const _finddata_t &FindData);
	int compareToMask(const std::string & mask, const std::string & file);
	
public:
	FileIterator () {};
	FileIterator (const std::string & _fileMask);

	bool hasMore(); // true, ���� ��� ���� � ���/��������� �����, �����. �����
	FileItem * Next();
};