/*

*     *     *     *     *     *     *     *     *     *
	*     *     *     *     *     *     *     *     *

                   || مصنف:موسیقار پروگرامر ||

    *     *     *     *     *     *     *     *     *
*      *     *     *     *     *     *     *     *     *


*/

/*
 * main.cpp
 *
 *  Created on: Jul 19, 2020
 *      Author: موسیقار پروگرامر (Programming Musician)
 */

#include <unordered_set>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include  <vector>
#include "csv_parse_utilities.hpp"
using namespace std;

typedef unordered_set<string> EdgeSet;
typedef string Key;
typedef unordered_map<Key,EdgeSet> Graph;
/*
 *  Create a graph of match results, an edge from a node means
 *  that source node has beaten the destination node, where any
 *  node represents a team.
 *          A ------> B :  'A' has beaten B
 */

struct MatchResults
{
	string winner;
	string looser;
};

Graph buildGraph(vector<MatchResults> &p_matchResults)
{
	Graph resultsGraph;
	for(auto &matchResult : p_matchResults)
	{
		resultsGraph[matchResult.winner].emplace(matchResult.looser);
	}

	return resultsGraph;
}


int  main(int argc, char *argv[])
{
	string test = "Hello,";
	vector<string> aVec;
	splitString(test, ',',aVec);
	for(auto &field : aVec)
	{
		std::cout<<field<<std::endl;
	}

	std::vector<std::vector<std::string>> textualGraph;
	textualGraph = readCsvRecords("graph1.csv",',');
	cout<<"Number of Node:" << textualGraph.size()<<endl;
	for(auto &record : textualGraph)
	{
		for(auto &field : record)
		{
			cout<<field<<", ";
		}
		cout<<endl;
	}
	cout<<"done";

	return 0;
}
