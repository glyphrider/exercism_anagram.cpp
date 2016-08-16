// vim: ts=4:nu
#include "anagram.h"

#include <iostream>
#include <set>

namespace anagram
{
	Anagram::Anagram(const std::string &word):_word(word) {}
	Anagram::Anagram(const Anagram &other) { _word = other._word; }
	Anagram& Anagram::operator=(const Anagram &other) { _word = other._word; return *this; }
	bool words_match(const std::multiset<std::string::value_type> &word, const std::multiset<std::string::value_type> &candidate)
	{
		std::multiset<std::string::value_type>::const_iterator it1, it2;
		for(it1 = word.begin(), it2 = candidate.begin();
			(it1 != word.end()) || (it2 != candidate.end()); it1++, it2++)
		{
			// std::cout << "comparing " << *it1 << " with " << *it2 << "." << std::endl;
			if(toupper(*it1) != toupper(*it2))
			{
				// std::cout << "failing" << std::endl;
				return false;
			}
		}
		// std::cout << "passing" << std::endl;
		return true;
	}
	std::vector<std::string> Anagram::matches(const std::vector<std::string> &word_bank)
	{
		std::multiset<std::string::value_type> word; // (_word.begin(),_word.end());
		for(std::string::const_iterator word_it = _word.begin(); word_it != _word.end(); word_it++)
			word.insert(toupper(*word_it));
		std::vector<std::string> result;
		for(std::vector<std::string>::const_iterator it = word_bank.begin(); it != word_bank.end(); it++)
		{
			std::multiset<std::string::value_type> candidate; // (it->begin(),it->end());
			for(std::string::const_iterator candidate_it = it->begin(); candidate_it != it->end(); candidate_it++)
				candidate.insert(toupper(*candidate_it));
			if(words_match(word,candidate))
				result.push_back(*it);
		}
		return result;
	}
	Anagram anagram(const std::string &word)
	{
		return Anagram(word);
	}
}
