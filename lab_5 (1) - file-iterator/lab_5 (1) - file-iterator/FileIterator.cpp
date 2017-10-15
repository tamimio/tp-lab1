#include <iostream>
#include "FileIterator.h"

FileIterator::FileIterator (const std::string & _fileMask)
{
		this -> FileMask = _fileMask ;
}


bool FileIterator::hasMore()
{
	if (cache != NULL)
		return true;

	cache = doSearch();
	return cache!=NULL;
}


FileItem * FileIterator::Next()
{
	if (!hasMore())
		throw "File not found.";
	FileItem * res=cache;
	cache=NULL;
	return res;
}


FileItem * doSearch()
{
	//...
}
FileItem * doSearch(const std::string & _fileMask)
{
	//...
}


inline bool FileIterator::IsDirectory(const _finddata_t &FindData)
{
    return ((FindData.attrib & _A_SUBDIR) != 0);
}


int FileIterator::compareToMask(const std::string & _mask, const std::string & _file)
{
    int pos=0;
    for (int i=0; i < _mask.length(); i++)
        for (int j=pos; j < _file.length(); j++)
        {
            pos=j;
            if (_mask[i] == '*')
            {
                if (_file[j] == '.')
                    break;
                else
                    continue;
            }
            else if ((_mask[i] == '?') || (_mask[i] == _file[j]))
            {
                pos++;
                break;
            }
            return 0;
        }
    return 1;
}