#include "pch.h"
#include "FileDeleter.h"

FileDeleter::FileDeleter() :path{ "" } {}
FileDeleter::FileDeleter(std::string pth) :path{ pth } {}

void FileDeleter::setPath(std::string pth) {
	this->path = pth;
}

bool FileDeleter::pathOk() {
	return (fsys::exists(path));
}


bool FileDeleter::deletePaths(std::vector<fsys::path> files,int *counter) {

	for (auto& f : files) {
		fsys::remove_all(f);
		(*counter)++;
	}
	return true;
}
static std::time_t to_time_t(std::string str)
{
	struct tm when = { 0 };

	int yyyy, mm, dd;

	sscanf_s(str.c_str(), "%d-%d-%d", &yyyy, &mm, &dd);

	when.tm_year = yyyy - 1900;
	when.tm_mon = mm - 1;
	when.tm_mday = dd;

	return mktime(&when);

}

bool FileDeleter::deleteEmptyCatalogues() {

	bool result{ false };
	std::vector<fsys::path> dirs;

		for (auto& p : fsys::recursive_directory_iterator(path)) {
			if (fsys::is_directory(p)) {
				dirs.push_back(p);
			}
		}
		if (dirs.size() > 0) {
			for (auto di = dirs.rbegin(); di != dirs.rend(); ++di) {
				if (fsys::is_empty(*di)) {
					fsys::remove(*di);
					result = true;
				}
				else { break; }
			}

		}

	return result;
}
bool FileDeleter::dateTest(const fsys::path& p, const std::string& dateLow, const std::string& dateHigh, const int& filterType) {


	struct stat fileInfo;
	time_t fileTime{ 0 };
	std::string stringPath{ p.generic_string() };

	char* path = _strdup(stringPath.c_str());

	stat(path, &fileInfo);

	switch (filterType) {
	case 0:
		fileTime = fileInfo.st_mtime;
		break;
	case 1:
		fileTime = fileInfo.st_atime;
		break;
	case 2:
		fileTime = fileInfo.st_ctime;
		break;
	default:
		fileTime = fileInfo.st_mtime;
		break;
	}
	delete[] path;

	
	return (fileTime >= to_time_t(dateLow) && fileTime <= to_time_t(dateHigh));
}

std::vector<fsys::path> FileDeleter::findRequiredFiles(const int& filterType, const std::string& dateLow, const std::string& dateHigh) {

	std::string date1{ "1900-01-01" };
	std::string date2{ "2999-01-01" };
	int filter{ 1 };

	if (dateLow.length() > 0) { date1 = dateLow; }
	if (dateHigh.length() > 0) { date2 = dateHigh; }
	if (filterType >= 0) filter = filterType;


	std::vector<fsys::path> files;
	if (pathOk()) {

		for (auto& p : fsys::recursive_directory_iterator(path)) {
			if (fsys::is_regular_file(p) && dateTest(p, date1, date2, filterType)) {
				files.push_back(p);
			}

		}
	}

	return files;
}
