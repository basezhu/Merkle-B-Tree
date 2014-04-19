//////////////////////////////////////////////////
//
// Node.h
//
// Ke Wang
// 10300240013@fudan.edu.cn
//
//////////////////////////////////////////////////

#ifndef _NODE_H_
#define _NODE_H_

#include <vector>

#include "Edge.h"

class Edge;

class Node {
public:
	enum NODETYPE {NORMAL, POI}; // an enum type for node type
private:
	unsigned int nodeId; // the index given by the file, start from 0
	unsigned int indexId; // the index of a node after a certain sorting
						  // will be used as the key for the B+ tree
	double longitude;
	double latitude;
	NODETYPE nodeType; // the type of the node
	std::vector<Edge*> edges; // the edges connected to the node
	
public:
	Node(double longitude,double latitude) {
		this->nodeId = 0;
		this->indexId = 0;
		this->longitude = longitude;
		this->latitude = latitude;
		this->nodeType = NORMAL;
	}
	Node(unsigned int nodeId, double longitude, double latitude, NODETYPE nodeType = NORMAL) {
		this->nodeId = nodeId;
		this->indexId = 0;
		this->longitude = longitude;
		this->latitude = latitude;
		this->nodeType = nodeType;
	}
	~Node(){}

	unsigned int getNodeId() {
		return this->nodeId;
	}
	void setNodeId(unsigned int value) {
		this->nodeId = value;
	}
	unsigned int getIndexId() {
		return this->indexId;
	}
	void setIndexId(unsigned int value) {
		this->indexId = value;
	}
	double getLongitude() {
		return this->longitude;
	}
	void setLongitude(double value) {
		this->longitude = value;
	}
	double getLatitude() {
		return this->latitude;
	}
	void setLatitude(double value) {
		this->latitude = value;
	}
	NODETYPE getNodeType() {
		return this->nodeType;
	}
	void setNodeType(NODETYPE value) {
		this->nodeType = value;
	}
	const std::vector<Edge*>& getEdges() {
		return this->edges;
	}
	void addEdge(Edge* value) {
		this->edges.push_back(value);
	}
};

#endif //_NODE_H_