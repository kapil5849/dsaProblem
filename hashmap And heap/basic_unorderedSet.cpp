#include <unordered_set>
#include <iostream>
using namespace std;
int main()
{
    unordered_set<string> people;
    // Insert
    people.insert(string{"Michael"});
    people.insert("Chris");

    // Check if key exists
    string query;
    query = "Michael";
    if (people.find(query) == people.end())
    {
        cout << query << " is not in the dictionary!" << endl;
    }

    // Delete
    people.erase(query);
    if (people.find(query) == people.end())
    {
        cout << query << " is not in the dictionary!" << endl;
    }

    // Iterate
    for (const string& name : people)
    {
        cout << "Name: " << name << endl;
    }
    // unordered_set<string> :: iterator itr;
    // for (itr = people.begin(); itr != people.end(); itr++)
    //     cout << (*itr) << endl;
    return 0;
}
