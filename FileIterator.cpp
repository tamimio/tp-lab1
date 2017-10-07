#include <iostream>
#include "FileIterator.h"

bool FileIterator::hasMore()
{
	if (cache != NULL)
		return true;

	cache = doSearch();
	return cache!=NULL;
}

/*
FileItem * FileIterator::Next()
{
	if (cache != NULL)
	{
		FileItem * res=cache;
		cache=NULL;
		return res;
	}
	FileItem * res=doSearch();
	if (res==NULL)
		throw "File not found.";
	return res;
}

»À»:
*/
FileItem * FileIterator::Next()
{
	if (!hasMore())
		throw "File not found.";
	FileItem * res=cache;
	cache=NULL;
	return res;
}