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


bool FileDeleter::deletePaths(std::vector<fsys::path> files) {

	for (auto& f : files) {
		fsys::remove_all(f);
	}
	return true;
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
