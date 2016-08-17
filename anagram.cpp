// vim: ts=4:nu:ar
//
#include "anagram.h"

#include <iostream>
#include <set>

namespace anagram
{
	class Word
	{
		const std::string _original;
		std::string _toupper;
		std::multiset<char> _ordered;
	public:
		Word(const std::string &other):_original(other)
		{
			for(std::string::const_iterator it = other.begin(); it != other.end(); it++)
			{
				_toupper.push_back(toupper(*it));
				_ordered.insert(toupper(*it));
			}
		}
		const std::string &upper()
		{
			return _toupper;
		}
		const std::multiset<char> &ordered()
		{
			return _ordered;
		}
		const std::string &original()
		{
			return _original;
		}
	};
	Anagram::Anagram(const std::string &word):_word(word) {}
	Anagram::Anagram(const Anagram &other) { _word = other._word; }
	Anagram& Anagram::operator=(const Anagram &other) { _word = other._word; return *this; }
	bool words_match(const std::multiset<std::string::value_type> &word, const std::multiset<std::string::value_type> &candidate)
	{
		std::multiset<std::string::value_type>::const_iterator it1, it2;
		for(it1 = word.begin(), it2 = candidate.begin();
			(it1 != word.end()) || (it2 != candidate.end()); it1++, it2++)
		{
			if(toupper(*it1) != toupper(*it2))
			{
				return false;
			}
		}
		return true;
	}
	std::vector<std::string> Anagram::matches(const std::vector<std::string> &word_bank)
	{
		std::vector<std::string> result;
		Word word(_word);
		for(std::vector<std::string>::const_iterator it = word_bank.begin(); it != word_bank.end(); it++)
		{
			Word candidate(*it);
			if(word.upper() == candidate.upper()) continue;
			if(words_match(word.ordered(),candidate.ordered())) result.push_back(candidate.original());
		}
		return result;
	}
	Anagram anagram(const std::string &word)
	{
		return Anagram(word);
	}
}
