//functors are the function objects, they are the functions with a state
//functors are objects that can be treated as though they are functions.
//yt link: https://youtube.com/watch?v=6otobPdNFz4 --> but gpt explaination better
//overloads the functional call operator '()' 
//Advantages of Functors
// Statefulness: Unlike regular functions, functors can hold state (e.g., factor in the example).
// Reusability: You can define complex behavior in a functor class and reuse it.
// Customization: Functors can be tailored to different tasks through member variables or templates.
// Integration with STL: Functors are extensively used in the C++ Standard Template Library (STL) as custom predicates or operations, such as in sort, for_each, etc.

#include <bits/stdc++.h>
using namespace std;


class MultiplyBy{
    int factor;
    public:
    MultiplyBy(int x):factor(x){};
    int operator ()(int val){
        return val*factor;
    }

};

// int main()
// {
//     MultiplyBy multiplier(3); //--decleared the data member using constructor
//     cout<<multiplier(5); //-- input the parameter
     
//     return 0;
// }


//-------------------------

struct Person {
    string name;
    int age;

    // Constructor
    Person(const string& n, int a) : name(n), age(a) {}

    // For displaying Person objects
    void print() const {
        cout << name << " (" << age << ")" << endl;
    }
};

// Functor for custom sorting
class PersonSorter {
public:
    int flag;
    PersonSorter(bool f):flag(f){};
    bool operator()(const Person& p1, const Person& p2) const {
        // Primary criterion: Sort by age (ascending)
        if (p1.age != p2.age) {
            return (p1.age < p2.age)^flag;
        }
        // Secondary criterion: Sort by name (alphabetically)
        return (p1.name < p2.name)^flag;
    }
};

int main() {
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 30},
        {"David", 20},
        {"Eve", 25}
    };

    // Sort the vector using the custom functor
    PersonSorter ps(1);
    PersonSorter ps2(0);
    sort(people.begin(), people.end(), ps);

    // Display the sorted list
    cout << "Sorted list of people:" << endl;
    for (const Person& person : people) {
        person.print();
    }
    cout<<endl;
    sort(people.begin(), people.end(), ps2);
    cout << "Sorted list of people descending:" << endl;
    for (const Person& person : people) {
        person.print();
    }


    return 0;
}
