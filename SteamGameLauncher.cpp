#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: SteamGameLauncher.exe <AppID> <-D>\n";
		std::cout << "\tAppID = steam ID of the application\n";
		std::cout << "\t-D = Debug flag to keep the console open\n";
		std::cin.get();
		return 1;
	}

	const char* appId = argv[1];
	std::string steamUrl = "steam://rungameid/" + std::string(appId);

	HINSTANCE result = ShellExecuteA(NULL, "open", steamUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);

	if ((int)result <= 32)
	{
		std::cerr << "Failed to launch Steam game. Error code: " << (int)result << "\n";
		return 1;
	}

	std::cout << "Launching Steam game with AppID: " << appId << "\n";

	if (argc == 3 && std::string(argv[2]) == "-D")
	{
		std::cin.get();
	}
	return 0;
}
