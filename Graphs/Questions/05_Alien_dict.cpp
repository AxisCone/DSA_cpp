#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

/*
    ALIEN DICTIONARY

    Goal:
    We are given words sorted according to an unknown alphabet.

    Example:
        ["baa", "abcd", "abca", "cab", "cad"]

    From the first different characters of adjacent words,
    we can determine relationships such as:

        b < a
        d < a
        a < c

    These relationships form a DIRECTED GRAPH.

    Then we use TOPOLOGICAL SORT to find a valid ordering
    of all characters.

    Important idea:

        Character relationship
                ↓
        Directed Graph
                ↓
        Topological Sort
                ↓
        Alien Alphabet Order
*/


string find_order(string dict[], int N, int K) {

    /*
        Adjacency List

        Adj[u] contains all characters that must come AFTER u.

        Example:
            If we discover:

                a < c

            then:

                Adj[a].push_back(c)

            Graph:

                a -----> c

            Meaning:
                'a' must appear before 'c'.
    */
    vector<vector<int>> Adj(K);


    /*
        Indegree

        Indeg[v] = number of characters that must come
        before character v.

        Example:

            a ---> c
            b ---> c

        Then:

            Indeg[a] = 0
            Indeg[b] = 0
            Indeg[c] = 2

        In Kahn's Topological Sort, characters with
        indegree 0 can be processed first.
    */
    vector<int> Indeg(K, 0);


    /*
        edge[u][v] tells us whether the edge u -> v
        has already been added.

        Why do we need this?

        Suppose while comparing different pairs of words
        we discover:

            a < c

        multiple times.

        Without this matrix, we might add:

            a -> c
            a -> c
            a -> c

        and increase indegree[c] multiple times.

        edge[u][v] = true means:

            "We have already added u -> v."
    */
    vector<vector<bool>> edge(K, vector<bool>(K, false));


    /*
        present[i] tells us whether character i actually
        appears anywhere in the dictionary.

        Example:

            K = 5
            alphabet = a b c d e

            Dictionary:
                ["abc", "abd"]

        Characters present:

            a, b, c, d

        Character e never appears.

        We don't want to unnecessarily put 'e' in our answer.
    */
    vector<bool> present(K, false);


    /*
        Mark every character that appears in the dictionary.

        c - 'a' converts a character into an integer index.

        Example:

            'a' - 'a' = 0
            'b' - 'a' = 1
            'c' - 'a' = 2
            ...
            'z' - 'a' = 25
    */
    for (int i = 0; i < N; i++) {

        for (char c : dict[i]) {

            present[c - 'a'] = true;
        }
    }


    /*
        -------------------------------------------------------
        STEP 1: BUILD THE GRAPH
        -------------------------------------------------------

        We only need to compare ADJACENT words.

        Why?

        Because the dictionary is already sorted.

        Example:

            word1
            word2
            word3

        Comparing word1 with word2 can tell us one
        character relationship.

        Comparing word2 with word3 can tell us another.

        These relationships are enough to construct
        the ordering constraints.
    */

    for (int i = 0; i < N - 1; i++) {

        string str1 = dict[i];
        string str2 = dict[i + 1];


        /*
            j -> pointer for first word
            k -> pointer for second word

            We move both pointers together until we find
            the FIRST DIFFERENT CHARACTER.
        */
        int j = 0;
        int k = 0;


        /*
            Find the first position where the two words differ.

            Example:

                str1 = "baa"
                str2 = "abcd"

                Comparison:

                b == a ? NO

                So we immediately get:

                    b < a

                because the first word comes before the second.
        */
        while (j < str1.size() &&
               k < str2.size() &&
               str1[j] == str2[k]) {

            j++;
            k++;
        }


        /*
            ---------------------------------------------------
            INVALID CASE: PREFIX PROBLEM
            ---------------------------------------------------

            Example:

                str1 = "abc"
                str2 = "ab"

            Normally, if one word is a prefix of another,
            the SHORTER word must come first.

            Correct:

                "ab"
                "abc"

            Incorrect:

                "abc"
                "ab"

            Therefore, this dictionary is invalid.
        */
        if (k == str2.size() && j < str1.size()) {

            return "";
        }


        /*
            If j reached the end of str1, then str1 is a
            prefix of str2.

            Example:

                str1 = "ab"
                str2 = "abcd"

                This is perfectly valid.

            There is no new character relationship to extract,
            so simply move to the next pair of words.
        */
        if (j == str1.size()) {

            continue;
        }


        /*
            ---------------------------------------------------
            FIRST DIFFERENT CHARACTERS
            ---------------------------------------------------

            Suppose:

                str1 = "abc"
                str2 = "axc"

            First different characters are:

                b and x

            Since str1 comes before str2:

                b < x

            Therefore we create:

                b -----> x

            In the graph:
                u = b
                v = x
        */

        int u = str1[j] - 'a';
        int v = str2[k] - 'a';


        /*
            Add the edge only if it doesn't already exist.

            Example:

                If a -> c was already discovered,
                don't add it again.

            This also prevents us from increasing
            indegree[c] multiple times for the same
            relationship.
        */
        if (!edge[u][v]) {

            // Add directed edge:
            // u must come before v
            Adj[u].push_back(v);

            // v now has one more prerequisite
            Indeg[v]++;

            // Remember that this edge already exists
            edge[u][v] = true;
        }
    }


    /*
        -------------------------------------------------------
        STEP 2: TOPOLOGICAL SORT USING KAHN'S ALGORITHM
        -------------------------------------------------------

        We now have a directed graph representing
        character dependencies.

        Example:

            b ---> a ---> c

        Indegrees:

            b = 0
            a = 1
            c = 1

        Start with nodes having indegree = 0.

        These characters have NO dependency, so they
        can safely appear first.
    */

    queue<int> q;


    /*
        Put all characters with:

            1. present[i] == true
            2. Indeg[i] == 0

        into the queue.

        We only consider characters that actually appeared
        in the dictionary.
    */
    for (int i = 0; i < K; i++) {

        if (present[i] && Indeg[i] == 0) {

            q.push(i);
        }
    }


    /*
        This string will store the final alphabet order.

        Example:

            b -> a -> c

        result becomes:

            "bac"
    */
    string result = "";


    /*
        -------------------------------------------------------
        KAHN'S ALGORITHM
        -------------------------------------------------------

        Basic process:

        1. Take a node with indegree 0.
        2. Add it to the answer.
        3. Remove its outgoing edges.
        4. If any neighbor's indegree becomes 0,
           put that neighbor into the queue.

        This continues until the queue becomes empty.
    */

    while (!q.empty()) {

        /*
            Take a character that currently has
            no remaining prerequisites.
        */
        int u = q.front();
        q.pop();


        /*
            Convert integer index back into character.

            Example:

                u = 0  -> 'a'
                u = 1  -> 'b'
                u = 2  -> 'c'

            Formula:

                'a' + u
        */
        result += (char)('a' + u);


        /*
            Visit every character that depends on u.

            Example:

                u = a

                a ---> b
                a ---> c

            Then b and c have one prerequisite removed.
        */
        for (int v : Adj[u]) {

            /*
                Remove the dependency:

                    u ---> v

                Therefore v has one less prerequisite.
            */
            Indeg[v]--;


            /*
                If v now has ZERO prerequisites,
                it is ready to be processed.

                Put it into the queue.
            */
            if (Indeg[v] == 0) {

                q.push(v);
            }
        }
    }


    /*
        -------------------------------------------------------
        STEP 3: CHECK FOR A CYCLE
        -------------------------------------------------------

        Suppose the graph contains:

            a ---> b
            b ---> c
            c ---> a

        This is a cycle.

        Every character in the cycle has an incoming edge,
        so none of them can ever reach indegree = 0.

        Therefore Kahn's algorithm cannot process all
        characters.

        Example:

            Total characters = 3
            Result contains = 0

        So:

            result.size() != totalPresent

        means a valid ordering does not exist.
    */

    int totalPresent = 0;

    for (int i = 0; i < K; i++) {

        if (present[i]) {

            totalPresent++;
        }
    }


    /*
        If the number of characters in the result is not
        equal to the number of characters that actually
        appeared in the dictionary, then there is a cycle.

        Return empty string to indicate invalid ordering.
    */
    if (result.size() != totalPresent) {

        return "";
    }


    /*
        Everything worked successfully.

        Return the topological ordering of characters.
    */
    return result;
}


int main() {

    int N, K;


    /*
        N = number of words
        K = number of possible characters in the alphabet
    */
    cout << "Enter number of words: ";
    cin >> N;


    cout << "Enter size of alphabet (K, e.g. 26 for full a-z): ";
    cin >> K;


    /*
        Dynamically create an array of N strings.

        Example:

            N = 5

        dict[0]
        dict[1]
        dict[2]
        dict[3]
        dict[4]
    */
    string* dict = new string[N];


    /*
        Read the dictionary words.

        IMPORTANT:
        These words must already be in the order defined
        by the unknown/alien alphabet.
    */
    cout << "Enter the " << N
         << " words (in dictionary order):\n";

    for (int i = 0; i < N; i++) {

        cin >> dict[i];
    }


    /*
        Find the alien alphabet order.

        If successful:

            order = something like "bac"

        If unsuccessful:

            order = ""
    */
    string order = find_order(dict, N, K);


    /*
        Empty string means either:

        1. Invalid prefix case
        2. Graph contains a cycle
        3. Therefore no valid alphabet order exists
    */
    if (order.empty()) {

        cout << "No valid alphabet order exists "
             << "(invalid input or cycle detected)."
             << endl;
    }
    else {

        cout << "Inferred order of characters: "
             << order << endl;
    }


    /*
        We used:

            new string[N]

        Therefore we must free that memory using:

            delete[]

        Otherwise we create a memory leak.
    */
    delete[] dict;


    return 0;
}