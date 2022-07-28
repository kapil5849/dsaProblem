#include <unordered_map>
#include <iostream>
using namespace std;

int main(){
    unordered_map<string,int> age;
    // Insert
    age["Michael"] = 16;
    age.insert(pair<string, int>{"Bill", 25});
    age.insert({"Chris", 30});

    // Search and change
    age["Michael"] = 18;
    age.at("Chris") = 27;

    // Check if key exists
    string query;
    query = "Eric";
    if (age.find(query) == age.end())
    {
        cout << query << " is not in the dictionary!" << endl;
    }

    // Delete
    query = "Michael";
    if (age.find(query) == age.end())
    {
        cout << query << " is not in the dictionary!" << endl;
    }
    age.erase(query);
    if (age.find(query) == age.end())
    {
        cout << query << " is not in the dictionary!" << endl;
    }

    // Iterate
    for (const pair<string, int>& tup : age)
    {
        cout << "Name: " << tup.first << endl;
        cout << "Age: " << tup.second << endl;
    }
    return 0;
}
