# ParsingSets
Parsing sets of data

Create a library to detect duplicate sets of integer values. Two sets are considered duplicate when they contain the same number of items and their items are of the same value no matter what positions they are at.

Example:
   * 1,2,3 is considered a duplicate of 2,1,3
   * 1,2,3 is not considered a duplicate of 1,2,3,1
   
Library is required to provide:
   a) a way to accept a string representing a new set of values delimited by comma sign “,” (e.g. “1,2,3”) and return true/false if the given set is a duplicate of a set seen before,
   b) b) a way to return an information on number of duplicates and non-duplicates seen so far,
   c) a way to list members of the most frequent duplicate group seen so far,
   d) a way to return human readable report on list of invalid inputs seen so far.
