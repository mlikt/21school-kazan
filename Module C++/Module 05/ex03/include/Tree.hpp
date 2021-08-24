#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <string>

class Tree
{
private:
	std::string tree[4];
public:
	Tree();
	std::string getTree() const;
	~Tree() {}
};

#endif