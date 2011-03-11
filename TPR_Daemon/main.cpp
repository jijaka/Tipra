#include "TPR_Daemon_Watcher.h"
#include <windows.h>
#include <iostream>


int main()
{
	LPCTSTR strPrinter = "Epson Stylus COLOR 670 ESC/P 2";
	TPR_Daemon_Watcher myWatcher(strPrinter);
	myWatcher.Watch();
	std::cout << "Watching" << std::endl;
	std::string str;
	while (str != "exit") {
		std::cin >> str;
		if (str == "stop") {
			myWatcher.Stop();
			break;
		}
	}
	return 0;
}