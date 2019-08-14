#include "XMLLine.h"

void XMLLine::Add(std::string data) {
	parts.push_back(data);
}

void XMLLine::Indent(int location, indentSide beforeOrAfter) {
	if (beforeOrAfter == BEFORE) {
		std::vector<std::string> temp;
		for (int i = 0; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = location; i < GetParts().size(); i++) {
			temp.pop_back();
		}
		temp.push_back("");
		for (int i = location; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = 0; i < GetParts().size(); i++) {
			SetPart(i, temp[i]);
		}

		parts.push_back(temp[temp.size() - 1]);
	}
	else if (beforeOrAfter == AFTER) {
		std::vector<std::string> temp;
		for (int i = 0; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = location+1; i < GetParts().size(); i++) {
			temp.pop_back();
		}
		temp.push_back("");
		for (int i = location+1; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = 0; i < GetParts().size(); i++) {
			SetPart(i, temp[i]);
		}

		parts.push_back(temp[temp.size() - 1]);
	}
}

void XMLLine::Indent(int location, indentSide beforeOrAfter, int count) {
	if (beforeOrAfter == BEFORE) {
		std::vector<std::string> temp;
		for (int i = 0; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = location; i < GetParts().size(); i++) {
			temp.pop_back();
		}

		for (int i = 0; i < count; i++) {
			temp.push_back("");
		}

		for (int i = location; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = 0; i < GetParts().size(); i++) {
			SetPart(i, temp[i]);
		}
		for (int i = GetParts().size() - 1; i < GetParts().size() + count; i++) {
			parts.push_back(temp[i]);
		}
	}
	else if (beforeOrAfter == AFTER) {
		std::vector<std::string> temp;
		for (int i = 0; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = location+1; i < GetParts().size(); i++) {
			temp.pop_back();
		}

		for (int i = 0; i < count; i++) {
			temp.push_back("");
		}

		for (int i = location+1; i < GetParts().size(); i++) {
			temp.push_back(GetParts()[i]);
		}

		for (int i = 0; i < GetParts().size(); i++) {
			SetPart(i, temp[i]);
		}
		for (int i = GetParts().size() - 1; i < GetParts().size() + count; i++) {
			parts.push_back(temp[i]);
		}
	}
}

void XMLLine::Delete(int location) {
	std::vector<std::string> temp;
	for (int i = 0; i < GetParts().size(); i++) {
		temp.push_back(GetParts()[i]);
	}

	for (int i = location; i < GetParts().size()-1; i++) {
		temp[i] = temp[i + 1];
	}

	for (int i = 0; i < GetParts().size(); i++) {
		SetPart(i, temp[i]);
	}

	parts.pop_back();
}

void XMLLine::Delete(int location, int count) {
	std::vector<std::string> temp;
	for (int i = 0; i < GetParts().size(); i++) {
		temp.push_back(GetParts()[i]);
	}

	for (int c = location + count; c >= location; c--) {
		for (int i = c; i < GetParts().size() - count; i++) {
			temp[i] = temp[i + 1];
		}
	}

	for (int i = 0; i < GetParts().size(); i++) {
		SetPart(i, temp[i]);
	}

	for (int i = 0; i < count; i++) {
		parts.pop_back();
	}
}

void XMLLine::Copy(int fromLocation, int toLocation) {
	SetPart(toLocation, GetParts()[fromLocation]);
}

void XMLLine::Insert(std::string data, int location) {
	Indent(location, BEFORE);
	std::vector<std::string> temp;
	temp = GetParts();
	temp[location] = data;
	SetParts(temp);
}

std::vector<std::string> XMLLine::GetParts() const {
	return parts;
}

void XMLLine::SetParts(std::vector<std::string> p) {
	parts = p;
}

std::string XMLLine::GetPart(int location) const {
	if (location < 0 || location > GetParts().size()) {
		return "";
	}
	else {
		return GetParts()[location];
	}
}

void XMLLine::SetPart(int location, std::string data) {
	parts[location] = data;
}
