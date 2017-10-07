#include <iostream>
#include <string>

/*
class Item
{
public:
	virtual string name()=0; // полное имя
	virtual string date()=0; // дата создания файла, YYYY-MM-DD
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
	Item * doSearch(); // ищет в под/каталогах, потом возвращает
	Item * cache; // рез-т поиска hasMore()

public:
	bool hasMore(); // true, если ещё есть в под/каталогах файлы, удовл. маске
	Item * Next();
};*/

class FileIterator
{
	FileItem * doSearch(); // ищет в под/каталогах, потом возвращает
	FileItem * cache; // рез-т поиска hasMore()

public:
	bool hasMore(); // true, если ещё есть в под/каталогах файлы, удовл. маске
	FileItem * Next();
};