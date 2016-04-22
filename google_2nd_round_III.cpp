/*
There are three commands:

peer A B
manages M N
is_manager X Y

serve is_manager queries as they come

managers are transitive: 	if A manages B and B manages C than is_manager A C is true
peers share managers:		if A and B are peer and C manages A than is_manager C B is true

This was completed using a union find for the peers
and a simple linked list for the structures

example:
input:
peer A B
peer B C
manages D C
is_manager D A

out:
D manages A

*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define MAX_EMP 256
#define DEBUG false

typedef struct Emp* Employee;

struct Emp {
	Emp (char _id) : id{_id} {
		manager = nullptr;
		official = nullptr;
	};
	char id;
	Employee manager;
	Employee official;
};

Employee emps[MAX_EMP];

void manages (char m, char e) {
	// get the official of e's group
	Employee curr = emps[e];
	while (curr->official != curr) {
		curr = curr->official;
	}

	curr->manager = emps[m]	;
}

void peer (char a, char b) {
	
	Employee currA = emps[a];
	// get the official of a's group
	while (currA->official != currA) {
		currA = currA->official;
	}

	Employee currB = emps[b];
	// get the official of b's group
	while (currB->official != currB) {
		currB = currB->official;
	}

	// if they are the same, do nothing
	if (currA != currB) {
		currB->official = currA;
	}
}

// does a manage b?
bool is_manager(char a, char b) {
	Employee curr = emps[b];
	while (curr->manager != nullptr) { 	//if manager is null, then we are at the top and havent found manager
									//so procede to return false
		// get the the current official of my group
		while (curr != curr->official) { // terminate when I am the official of myself
			curr = curr->official;
		}
		if (curr->manager==emps[a]) return true;
		// escalate to next level of managers
		curr = curr->manager;
	}
	return false;
}

Employee makeEmp (char id) {
	if (DEBUG) cout << "Making new peer id: " << id << endl;
	Employee tmp = new struct Emp(id);//= new Employee{id};
	tmp->official = tmp;
	return tmp;
}

int main () {

	string input;
	int num=0;
	vector<string> tokens;

	while (getline(cin,input)) {

		if (DEBUG) cout << "the line is: " << input << endl;

		std::stringstream ss(input);
		std::string item;
		while (std::getline(ss, item, ' ')) {
			tokens.push_back(item);
		}

		if (tokens[0].compare(string("peer"))==0) {
			char peer1 = tokens[1][0];
			char peer2 = tokens[2][0];

			if (emps[peer1] == nullptr) {
				emps[peer1] = makeEmp(peer1);
			}

			if (emps[peer2] == nullptr) {
				emps[peer2] = makeEmp(peer2);
			}
			peer(peer1, peer2);
		} else if (tokens[0].compare(string("manages"))==0) {
			char peer1 = tokens[1][0];
			char peer2 = tokens[2][0];

			if (emps[peer1] == nullptr) {
				emps[peer1] = makeEmp(peer1);
			}

			if (emps[peer2] == nullptr) {
				emps[peer2] = makeEmp(peer2);
			}

			manages(peer1, peer2);
		} else if (tokens[0].compare(string("is_manager"))==0) {
			char peer1 = tokens[1][0];
			char peer2 = tokens[2][0];

			if (is_manager(peer1, peer2)) {
				cout << peer1 << " manages " << peer2 << endl;
			} else {
				cout << peer1 << " does not manage " << peer2 << endl;
			}
		}
		tokens.clear();
	}

	return 0;
}