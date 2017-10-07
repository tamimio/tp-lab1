#include <io.h>
#include <string>

#include "FileIterator.h"

void main (int argc, char *argv[])
{
	std::string FileMask; 
	FileIterator * it = new FileIterator ();

	if (argc > 1)
		FileMask = argv[1];
	else
	{  
		std::cout << "Enter a drive, directory, and/or file mask to list ([drive:][path]filemask) -> " << std::endl;
		std::cin >> FileMask;
		if (!FileMask.length())
			return;
	}
  
	/*
		~smth~

		while(it->hasMore)
			it->Next();

	*/
}