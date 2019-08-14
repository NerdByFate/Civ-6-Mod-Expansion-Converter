#pragma once
#ifndef XMLSTREAM_H
#define XMLSTREAM_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "XMLLine.h"

class XMLStream {
public:
	XMLStream();
	XMLStream(std::string pathToFile);
	bool open();
	bool open(std::string pathToFile);
	void inputLines();
	void outputLines();
	bool is_open() const;
	void close();
	bool eof(); //end of file
	bool eop(); //end of part
	bool eol(); //end of line

	void InsertLine(int location, XMLLine line);
	void IndentLine(int location, XMLLine::indentSide beforeAfter);

	//Getters & Setters
	std::string GetPath() const;
	void SetPath(std::string path);
	std::vector<XMLLine> GetLines() const;
	void SetLines(std::vector<XMLLine> lines);
private:
	std::string path; 
	std::vector<XMLLine> lines;

	std::ifstream iStream;
	std::ofstream oStream;
};
#endif //XMLSTREAM_H
