/*
There are three commands:

peer A B
manager M N
is_manager X Y

serve is_manager queries as they come

managers are transitive: 	if A manages B and B manages C than is_manaher A C is true
peers share managers:		if A and B are peer and C manages A than is_manager C B is true

This was completed using a union find for the peers
and a simple linked list for the structures

*/
typedef struct Emp* Employee;

struct Emp {
	int id;
	Employee manager;
	Employee official;
};

// does a manage b?
bool is_manager(Employee a, Employee b) {
	Employee curr = b;
	while (b.manager != NULL) { 	//if manager is null, then we are at the top and havent found manager
									//so procede to return false
		// get the the current official of my group
		while (curr != curr.official) { // terminate when I am the official of myself
			curr = curr.official;
		}
		// escalate to next level of managers
		curr = curr.manager;
	}
	return false;
}


int main () {

	return 0;
}