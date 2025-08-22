#ifndef ITEM_TRACKING_H
#define ITEM_TRACKING_H

#include <string>
#include <map>

class ItemTracking {
public:
	ItemTracking(const std::string& inputFile, const std::string& outputFile); 
	int GetItemCount(const std::string& itemName) const;
	void PrintAllCount() const;
	void PrintHistogram() const;
	void PrintMenu() const;


private:
	std::map<std::string, int> countMap;

	void LoadFile(const std::string& fileName);
	void SaveCountInFile(const std::string& itemName);

};

#endif

