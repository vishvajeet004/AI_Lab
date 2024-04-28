#include <iostream>
using namespace std;
void moveTower(int disks, char source, char auxiliary, char destination) 
{
    	if (disks == 1) 
   	{
   		cout << "Move disk 1 from " << source << " to " << destination << endl;
        	return;
    	}
	moveTower(disks - 1, source, destination, auxiliary);
    	cout << "Move disk " << disks << " from " << source << " to " << destination << endl;
    	moveTower(disks - 1, auxiliary, source, destination);
	}
int main() 
{
    	int numDisks;
    	cout << "Enter the number of disks: ";
    	cin >> numDisks;
	cout << "Tower of Hanoi solution:" << endl;
    	moveTower(numDisks, 'A', 'B', 'C');
	return 0;
}

