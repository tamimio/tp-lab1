#include <iostream>
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
	FileItem * doSearch(); // ���� � ���/���������, ����� ����������
	FileItem * cache; // ���-� ������ hasMore()

public:
	bool hasMore(); // true, ���� ��� ���� � ���/��������� �����, �����. �����
	FileItem * Next();
};