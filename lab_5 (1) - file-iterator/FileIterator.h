#include <io.h>

class FileItem
{
	std::string name;
	std::string path;
public: 
	FileItem() {};
	FileItem (const std::string& name, const std::string& path);
	void Show();
};

class FileIterator
{
	FileItem* cache;
	std::string FileMask;

	FileIterator* subIterator;
	intptr_t FindHandle;

	FileItem* doSearch (const std::string & fileMask);	
	
	inline bool IsDirectory (const _finddata_t & FindData);	
	
	bool compareToMask (const std::string & mask , const std::string & file);

public :
	FileIterator () : FindHandle (NULL) {};
	FileIterator (const std::string & fileMask);

	bool hasMore();

	FileItem * Next();

	void setFileMask (const std::string & mask);
};

