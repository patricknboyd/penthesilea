// Penthesilea.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int returnStatus = 0;

	try
	{
		World w;
		w.Build();
		w.RenderScene();

		std::cout << "Done!\r\n";
	}
	catch (...)
	{
		std::cerr << "An error occurred, exiting.\r\n";
		returnStatus = -1;
	}

	/*std::cout << "\r\nPress <Enter> to continue...\r\n";
	std::cin.get();*/

	return returnStatus;


}

