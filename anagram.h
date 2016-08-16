// vim: ts=4:nu
//
#ifndef __anagram_h__
#define __anagram_h__

#include <vector>
#include <string>

namespace anagram
{
	class Anagram
	{
			std::string _word;
		public:
			Anagram(const std::string &word);
			Anagram(const Anagram &other);
			Anagram& operator=(const Anagram &other);
			virtual std::vector<std::string> matches(const std::vector<std::string> &);
	};
	Anagram anagram(const std::string &word);
}

#endif
