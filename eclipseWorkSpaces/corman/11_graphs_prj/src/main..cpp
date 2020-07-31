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

vector<MatchResults> recordsToMatchResults(vector<vector<string>> &p_records)
{
	vector<MatchResults> allMatchResults;
	for(auto &record : p_records)
	{
		MatchResults temp = {record[0], record[1]};
		allMatchResults.emplace_back(temp);
	}
	return allMatchResults;

}
Graph buildGraph(vector<MatchResults> &p_matchResults)
{
	Graph resultsGraph;
	for(auto &matchResult : p_matchResults)
	{
		resultsGraph[matchResult.winner].emplace(matchResult.looser);
	}

	return resultsGraph;
}


bool isDFSReachable(Graph &p_graph, EdgeSet &p_visited, string p_src, string p_dest)
{
	std::cout<<"src"<<p_src<<endl;
	std::cout<<"dst"<<p_dest<<endl;
	if(p_src == p_dest)
		return true;
	else if(p_visited.find(p_src)!=p_visited.end() || p_visited.empty()) // if node not visited
	{
		if(p_graph[p_src].find(p_dest)!=p_graph[p_src].end()) // dest is neighbour
		{
			return true;
		}
		else
		{
			p_visited.insert(p_src); // mark current as visisted
			auto  allEdges = p_graph[p_src];
			for(auto &edge : allEdges) // iterate over all edges
			{
				std::cout<<"Next Edge to Visit"<<edge<<std::endl;
				for(auto &vis : p_visited)
				{
					std::cout<<"visited::"<<vis<<std::endl;
				}
				if(isDFSReachable(p_graph, p_visited,edge, p_dest))
					return true;
			}

		}
		return false;
	}
	return false;
}
bool isBeatable(Graph &p_graph, const string &p_teamA,const string &p_teamB)
{
	EdgeSet visited;
	return isDFSReachable(p_graph,visited,p_teamA,p_teamB);
}

void testSplitString()
{
	string test = "Hello,";
	vector<string> aVec;
	splitString(test, ',',aVec);
	for(auto &field : aVec)
	{
		std::cout<<field<<std::endl;
	}
}
void testCsvReader()
{
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
}


void testGraphTraversal()
{
	std::vector<std::vector<std::string>> textualGraph;
	textualGraph = readCsvRecords("graph1.csv",',');
	vector<MatchResults> matchResultGraph = recordsToMatchResults(textualGraph);
	Graph p_graph = buildGraph(matchResultGraph);
	string teamA("A");
	string teamB("X");
	std::cout<<"Is team:"<<teamA<<" Beatable by Team:"<<teamB<<" = "<<std::endl;
	if(isBeatable(p_graph, teamA, teamB))
	{
		std::cout<<"Yes"<<std::endl;
	}
	else
	{
		std::cout<<"NO"<<std::endl;

	}
	for(auto &rslt : matchResultGraph)
	{
		//std::cout<<"Winner ="<<rslt.winner<<": Looser ="<<rslt.looser<<std::endl;
	}
}
int  main(int argc, char *argv[])
{

	//testSplitString();
	//testCsvReader();
	testGraphTraversal()
;	return 0;
}
