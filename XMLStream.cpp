#include "XMLStream.h"

XMLStream::XMLStream() {
	path = "Config.xml";
}

XMLStream::XMLStream(std::string pathToFile) {
	path = pathToFile;
}

bool XMLStream::open() {
	iStream.open(GetPath());
	return eof();
}

bool XMLStream::open(std::string pathToFile) {
	SetPath(pathToFile);
	iStream.open(GetPath());
	return eof();
}

void XMLStream::inputLines() {
	char tempFileC[100000];
	std::string tempFile = "";
	std::string tempPart = "";
	XMLLine tempLine;

	while (!eof()) {
		iStream.getline(tempFileC, 100000, EOF);
	}
	tempFile = tempFileC;
	tempFile += EOF;

	for (int i = 0; i < tempFile.size(); i++) {
		if (tempFile[i+1] != EOF && tempFile[i + 1] != '\n' && tempFile[i + 1] != ' ') {
			tempPart += tempFile[i];
		}
		else if (tempFile[i + 1] == ' ') {
			tempPart += tempFile[i++];
			tempLine.Add(tempPart);
			tempPart = "";
		}
		else if (tempFile[i + 1] == EOF || tempFile[i + 1] == '\n') {
			tempPart += tempFile[i++];
			tempLine.Add(tempPart);
			tempPart = "";
			lines.push_back(tempLine);
			tempLine.Delete(0, tempLine.GetParts().size());
		}
	}
}

void XMLStream::outputLines() {
	if (is_open()) {
		close();
	}

	oStream.open(GetPath());
	for (int i = 0; i < GetLines().size(); i++) {
		for (int c = 0; c < GetLines()[i].GetParts().size(); c++) {
			oStream << GetLines()[i].GetPart(c);
			if (c != GetLines()[i].GetParts().size()-1) {
				oStream << ' ';
			}
			else {
				oStream << '\n';
			}
		}
	}
	oStream.close();
}

bool XMLStream::is_open() const {
	if (iStream.is_open()) {
		return true;
	}
	else {
		return false;
	}
}

bool XMLStream::eof() {
	if (iStream.peek() == EOF) {
		return true;
	}
	else {
		return false;
	}
}

bool XMLStream::eol() {
	if (iStream.peek() == '\n') {
		return true;
	}
	else {
		return false;
	}
}

bool XMLStream::eop() {
	if (iStream.peek() == ' ') {
		return true;
	}
	else {
		return false;
	}
}

void XMLStream::close() {
	if (is_open()) {
		iStream.close();
	}
}

void XMLStream::IndentLine(int location, XMLLine::indentSide beforeOrAfter) {
	if (beforeOrAfter == XMLLine::BEFORE) {
		std::vector<XMLLine> temp;
		for (int i = 0; i < GetLines().size(); i++) {
			temp.push_back(GetLines()[i]);
		}

		for (int i = location; i < GetLines().size(); i++) {
			temp.pop_back();
		}
		temp.push_back(XMLLine());
		for (int i = location; i < GetLines().size(); i++) {
			temp.push_back(GetLines()[i]);
		}

		SetLines(temp);
	}
	else if (beforeOrAfter == XMLLine::AFTER) {
		std::vector<XMLLine> temp;
		for (int i = 0; i < GetLines().size(); i++) {
			temp.push_back(GetLines()[i]);
		}

		for (int i = location + 1; i < GetLines().size(); i++) {
			temp.pop_back();
		}
		temp.push_back(XMLLine());
		for (int i = location + 1; i < GetLines().size(); i++) {
			temp.push_back(GetLines()[i]);
		}

		SetLines(temp);
	}
}

void XMLStream::InsertLine(int location, XMLLine line) {
	IndentLine(location, XMLLine::BEFORE);
	std::vector<XMLLine> temp;
	temp = GetLines();
	temp[location] = line;
	SetLines(temp);
}

std::string XMLStream::GetPath() const {
	return path;
}

void XMLStream::SetPath(std::string p) {
	path = p;
}

std::vector<XMLLine> XMLStream::GetLines() const {
	return lines;
}

void XMLStream::SetLines(std::vector<XMLLine> l) {
	lines = l;
}
