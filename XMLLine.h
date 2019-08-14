#pragma once
#ifndef XMLLINE_H
#define XMLLINE_H
#include <vector>

class XMLLine {
public:
	enum indentSide {BEFORE, AFTER};

	void Add(std::string data);
	void Insert(std::string data, int location);
	void Indent(int location, indentSide beforeOrAfter);
	void Indent(int location, indentSide beforeOrAfter, int count);
	void Delete(int location);
	void Delete(int location, int count);
	void Copy(int fromLocation, int toLocation);

	//Getters & Setters
	std::vector<std::string> GetParts() const;
	void SetParts(std::vector<std::string> parts);
	std::string GetPart(int location) const;
	void SetPart(int location, std::string data);
private:
	std::vector<std::string> parts;
};
#endif //XMLLINE_H
