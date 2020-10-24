/*

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 
 */
 
 
 def group_anagrams(strs):
	results = {}
	for _str in strs:
		sorted_str = str(sorted(_str))
		if sorted_str in results:
			results[sorted_str].append(_str)
		else:
			results[sorted_str] = [_str]
	return results.values()
