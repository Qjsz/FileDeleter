#pragma once
#include <filesystem>
#include <vector>
#include <string>

namespace fsys = std::filesystem;

class FileDeleter
{
protected:
	fsys::path path;
	bool dateTest(const fsys::path&, const std::string&, const std::string&, const int&);
	void vectorPrint(const std::vector<fsys::path>&);

public:
	FileDeleter();
	FileDeleter(std::string);
	bool pathOk();
	void setPath(std::string);
	bool deletePaths(std::vector<fsys::path>);
	std::vector<fsys::path> findRequiredFiles(const int& filterType, const std::string& dateLow, const std::string& dateHigh);
	bool deleteEmptyCatalogues();
};

