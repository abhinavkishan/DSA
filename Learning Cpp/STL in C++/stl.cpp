#include<bits/stdc++.h>
using namespace std;

void pairs() {
    pair<int, int> p {1, 2};
    cout << p.first << " " << p.second << endl;
    pair<int, pair<int, int>> p1 {1, {2, 3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    for (auto x : arr) {
        cout << x.first << " " << x.second << endl;
    }

}

void vectors() {
    vector<int> v;
    v.push_back(1);
    // emplace_back is faster than push_back
    v.emplace_back(2);
    
    vector<pair<int, int>> v1;
    v1.push_back({1, 2});
    // emplace back creates the pair in place
    v1.emplace_back(3, 4);
    for (auto x : v1) {
        cout << x.first << " " << x.second << endl;
    }

    vector<int> v3(5, 0);
    for (auto x : v3) {
        cout << x << " ";
    }
    cout << endl;
    v3.push_back(1);

    vector<int> v4(v3);
    for (auto x : v4) {
        cout << x << " ";
    }
    cout << endl;
    // iterators
    vector<int>::iterator it = v3.begin();
    
    cout << *it << endl;

    vector<pair<int, int>>::iterator it1 = v1.begin();

    cout << it1->first << " " << it1->second << endl;

    it1++;
    cout << it1->first << " " << it1->second << endl;
    // other iterators: rbegin, rend, cbegin, cend, crbegin, crend
    // end points to the next of the last element
    // rbegin points to the last element
    // rend points to the element before the first element
    // cbegin, cend, crbegin, crend are const iterators
    vector<int> v5 {1, 2, 3, 4, 5};
    vector<int>::iterator it2 = v5.end();
    // it2 points to the next of the last element
    it2--;
    cout << *it2 << endl;
    // rbegin moves in the reverse direction
    vector<int>::reverse_iterator rit = v5.rbegin();
    cout << *rit << endl;
    rit++;
    cout << *rit << endl;

    cout << v5.back() << endl;

    // printing vector using iterators
    // for(vector<int>::iterator it3 = v5.begin(); it3 != v5.end(); it3++) {
    //     cout << *it3 << " ";
    // }
    // cout << endl;
    for (auto it3 = v5.begin(); it3 != v5.end(); it3++) {
        cout << *it3 << " ";
    }
    cout << endl;

    // erase 
    // erase takes the iterator of the element to be deleted, till the element before which we want to delete
    // erase returns the iterator of the element after the last element deleted
    vector<int> v6 {1, 2, 3, 4, 5};
    vector<int>::iterator it4 = v6.begin();
    it4++;
    v6.erase(it4, it4 + 2);
    v6.insert(v6.begin() + 1, 2, 10);
    // cout << "v6" << endl;
    // for (auto x : v6) {
    //     cout << x << " ";
    // }
    // cout << endl;
    vector<int> v7 {1, 2, 3, 4, 5};
    v7.insert(v7.begin() + 1,v6.begin(), v6.end());
    cout << "v7" << endl;
    for (auto x : v7) {
        cout << x << " ";
    }
    cout << v.empty() << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;

}

void lists() {
    // front operations in lists are faster than vectors
    list<int> l {1, 2, 3, 4, 5};
    l.push_back(6);
    l.push_front(0);
    l.emplace_front(-1);
    l.emplace_back(7);
    for (auto x : l) {
        cout << x << " ";
    }
}

void dequeue() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.emplace_back(3);
    dq.emplace_front(4);
    cout << dq.front() << " " << dq.back() << endl;
    for (auto x : dq) {
        cout << x << " ";
    }
}

void stacks() {
    stack<int> st;
    st.push(1);
    st.push(2);
    // emplace is faster than push
    st.emplace(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;
    // st.swap(st1);
}

void queues() {
    // queue is a container adapter
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    cout << q.front() << " " << q.back() << endl;
    cout << typeid(q.back()).name() << endl;
    q.back() = 4;
    cout << q.back() << endl;
}

void pq() {
    // maintained as a heap
    // push -> O(logn), pop -> O(logn), top -> O(1)
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(7);
    cout << "Top of pq" << " " << pq.top() << endl;
    pq.pop();
    cout << "Top of pq" << " " << pq.top() << endl;

    priority_queue<int> pq2;
    pq2.push(5);
    // pq2.top() = 6; -> this is not possible as pq2.top() is a const reference
    cout << pq2.top() << endl;
    // min heap
    priority_queue<int , vector<int>, greater<int>> pq3;
    pq3.push(5);
    pq3.push(2);
    pq3.push(7);
    cout << pq3.top() << endl;
}

void sets() {
    // sorted, unique elements
    // maintained as a balanced binary search tree
    // everything in logaritmic time
    set<int> s {1, 2, 3, 4, 5, 5};
    s.insert(4);
    s.insert(1);
    s.insert(2);
    // emplace is faster than insert
    s.emplace(3);
    cout << "Set" << endl;
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
    auto it = s.find(3);
    // it+= 1; -> this is not possible as it is a set iterator
    cout << *it << endl;
    auto it1 = s.find(6);
    if (it1 == s.end()) {
        cout << "Not found" << endl;
    }

    s.erase(3); // takes logaritmic time , takes element to be deleted as input or iterator to the element to be deleted

    cout << "Count of 3: " << s.count(3) << endl;
    // erasing multiple elements
    // 4 is not erased
    s.erase(s.begin(), s.find(4));
    cout << "Set" << endl;
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
    // convert vector to set
    vector<int> v {1, 2, 2, 3, 3, 3};
    set<int> s1(v.begin(), v.end());
    cout << "Set" << endl;
    for (auto x : s1) {
        cout << x << " ";
    }
    cout << endl;
    // upper bound and lower bound
    // lower bound returns the iterator to the first element greater than or equal to the element
    // upper bound returns the iterator to the first element greater than the element
    auto it2 = s1.lower_bound(2);
    cout << *it2 << endl;
}

void multisets() {
    // sorted, can have multiple elements
    // everything in logaritmic time
    multiset<int> s {1, 2, 3, 4, 5, 5};
    s.insert(4);
    s.insert(1);
    s.insert(2);
    // emplace is faster than insert
    s.emplace(3);
    s.erase(4); // -> this will erase all the 4's
    s.insert(4);
    s.insert(4);
    // s.erase(s.find(4), s.find(4) + 1); -> this will erase only one 4
    cout << "Count of 3: " << s.count(3) << endl;
    s.erase(s.find(3)); // takes logaritmic time , takes element to be deleted as input or iterator to the element to be deleted
    cout << "Count of 3: " << s.count(3) << endl;
    cout << "Multi Set" << endl;
}

void unordered_sets() {
    // not in sorted order, unique elements
    unordered_set<int> s {1, 2, 3, 4, 5, 5};
    // O(1) time, worst case O(n)
    // LOWER AND UPPER BOUND NOT POSSIBLE

}

void Maps() {
    // duplocate values, but unique keys
    // sorted according to keys
    // everything in logaritmic time
    // here multiple mpp are possible as keys are unique
    map<int, int> mpp;
    // map<int, pair<int, int>> mpp;
    // map<pair<int, int>, int> mpp;
    mpp[1] = 2;
    // emplace needs a key and a value
    mpp.emplace(2, 3); // faster than insert
    // insert needs a pair
    mpp.insert({3, 4});
    map<int, int>::iterator it;
    // for(it = mpp.begin(); it != mpp.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    for(auto x: mpp) {
        cout << x.first << " " << x.second << endl;
    }
    
    cout << "value at key 3: " << mpp[3] << endl;
    cout << "value at key 4: " << mpp[4] << "\nZero as key doesnt exist!" << endl;

    // searching in map using find, takes key as input
    auto it1 = mpp.find(3);
    if (it1 != mpp.end()) {
        cout << "Found!\t" << "Value: " << it1->second << endl;
    }
    else {
        cout << "Not found" << endl;
    }    

    map<int, pair<int, int>> mpp1;
    mpp1[1] = {2, 3};
    mpp1.emplace(2,make_pair(4,5));
    mpp1.insert({3, {4, 5}});

}

void mutlimap() {
    // duplicate keys, sorted according to keys
    multimap<int, int> mpp;
    mpp.insert({1, 2});
    mpp.insert({1, 3});
    mpp.insert({1, 4});
    for(auto x: mpp) {
        cout << x.first << " " << x.second << endl;
    }
}

void unordered_maps() {
    // not sorted, unique keys
    // operations in O(1) time, worst case O(n)
    unordered_map<int, int> mpp;
    mpp[1] = 2;
    mpp.insert({3, 4});
    mpp.emplace(2, 3);
    for(auto x: mpp) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    // pairs();
    // vectors();
    // lists();
    // dequeue();
    // stacks();
    // queues();
    // pq();
    // sets();
    // multisets(); 
    // unordered_sets();
    // Maps();
    // mutlimap();
    // unordered_maps();
    cout << "Select the function to run: \n1. pairs()\n2. vectors()\n3. lists()\n4. dequeue()\n5. stacks()\n6. queues()\n7. pq()\n8. sets()\n9. multisets()\n10. unordered_sets()\n11. Maps()\n12. mutlimap()\n13. unordered_maps()\n";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "Pairs" << endl; 
            pairs();
            break;
        case 2:
            cout << "Vectors" << endl;
            vectors();
            break;
        case 3:
            cout << "Lists" << endl;
            lists();
            break;
        case 4:
            cout << "Dequeue" << endl;
            dequeue();
            break;
        case 5:
            cout << "Stacks" << endl;
            stacks();
            break;
        case 6:
            cout << "Queues" << endl;
            queues();
            break;
        case 7:
            cout << "Priority Queues" << endl;
            pq();
            break;
        case 8:
            cout << "Sets" << endl;
            sets();
            break;
        case 9:
            cout << "Multi Sets" << endl;
            multisets();
            break;
        case 10:
            cout << "Unordered Sets" << endl;
            unordered_sets();
            break;
        case 11:
            cout << "Maps" << endl;
            Maps();
            break;
        case 12:
            cout << "Multi Maps" << endl;
            mutlimap();
            break;
        case 13:
            cout << "Unordered Maps" << endl;
            unordered_maps();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    cout << "Program ended!" << endl;
    return 0;
}