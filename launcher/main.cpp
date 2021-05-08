#include "Engine.h"
#ifdef WIN32
#include <Windows.h>
#endif
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef APPLE
#include <mach-o/dyld.h>
#endif

#include <filesystem>
#include <string>

#ifndef MAX_PATH
#define MAX_PATH 256
#endif

#define ROOT_FOLDER_NAME "HurricaneEngine3D"



std::filesystem::path get_root_path(){
	std::filesystem::path root_path;

#ifdef WIN32
	char * exePath = new char[MAX_PATH];
	GetModuleFileName(NULL, exePath, MAX_PATH);
	root_path = std::filesystem::path(exePath);

#endif

#ifdef LINUX
	char buff[MAX_PATH];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {
      buff[len] = '\0';
      root_path = std::filesystem::path(buff);
    }
#endif

#ifdef APPLE
	char path[MAX_PATH];
	uint32_t size = sizeof(path);
	if (_NSGetExecutablePath(path, &size) == 0){
		root_path = std::filesystem::path(path);
	}
#endif

	while (root_path.filename().string() != ROOT_FOLDER_NAME){
		root_path = root_path.parent_path();
	}

	return root_path;
}

int main(int argc, const char** argv) {
	std::filesystem::path root_path = std::filesystem::path("/home/ami/Code/HurricaneEngine3D");

	
	Engine testEngine;
	testEngine.Initialize(root_path.string().c_str());
	testEngine.Run();
	testEngine.Shutdown();
}
