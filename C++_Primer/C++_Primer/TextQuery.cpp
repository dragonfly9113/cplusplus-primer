#include "pch.h"
#include "TextQuery.h"

// Read the input file and build the map of lines to line numbers
TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;

	while (std::getline(is, text)) {    // for each line in the file
		file->push_back(text);			// remember this line of text
		int n = file->size() - 1;		// the current line number
		std::istringstream line(text);	// separate the line into words
		std::string word;
		while (line >> word) {			// for each word in that line
			auto &lines = wm[word];		// lines is a shared_ptr
			if (!lines)		// that pointer is null the first time we see word
				lines.reset(new std::set<line_no>);	// allocate a new set
			lines->insert(n);			// insert this line number
		}
	}
}
