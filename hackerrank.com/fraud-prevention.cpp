#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cassert>
using namespace std;

string trim(string s) {
    string t = "";
    int end = (int)s.size() - 1;
    for (; end >= 0; end--) {
        if (s[end] != ' ')
            break;
    }
    bool ok = 0;
    for (int i = 0; i <= end; i++) {
        if (s[i] != ' ')
            ok = 1;
        if (ok)
            t += s[i];
    }
    return t;
}

string toLower(string s) {
    s = trim(s);
    string t = "";
    for (char ch : s) {
        if ('A' <= ch && ch <= 'Z') {
            ch = (char)(ch - ('Z' - 'z'));
        }
        t.append(1, ch);
    }
    return t;
}

string getEmail(string s) {
    // printf("getEmail: %s\n", s.c_str());
    s = toLower(s);
    int at = (int)s.find('@');
    // printf("\t@ is at %d position\n", at);
    string pref = s.substr(0, at);
    // printf("\tprefix=%s\n", pref.c_str());
    string buf = "";
    for (char ch : pref) {
        if (ch == '.')
            continue;
        if (ch == '+')
            break;
        buf += ch;
    }
    string r = buf + s.substr(at);
    // printf("\treturn %s\n", r.c_str());
    return r;
}

string getStreet(string s) {
    s = toLower(s);
    vector<pair<string, string>> vps = {{"street", "st."}, {"road", "rd."}};
    for (auto p : vps) {
        size_t i = s.find(p.first);
        if (i != string::npos) {
            s.replace(i, p.first.size(), p.second);
        }
    }
    return s;
}

string getState(string s) {
    s = toLower(s);
    vector<pair<string, string>> vps = {
        {"illinois", "il"}, {"california", "ca"}, {"new york", "ny"}};
    for (auto p : vps) {
        size_t i = s.find(p.first);
        if (i != string::npos) {
            s.replace(i, p.first.size(), p.second);
        }
    }
    return s;
}

string getZipCode(string s) {
    s = toLower(s);
    string buf = "";
    for (char ch : s) {
        if (ch != '-') {
            buf += ch;
        }
    }
    return buf;
}

class Record {
    int orderId;
    int dealId;
    string email;
    string street;
    string city;
    string state;
    string zipCode;
    string creditCard;

  public:
    Record(vector<string>);
    void print();
    string getKey1();
    string getKey2();
    int getOrderId();
    string getCreditCard();
};

Record::Record(vector<string> vs) {
    // printf("Record::Record vs.size()=%lu\n", vs.size());
    orderId = stoi(trim(vs[0]));
    dealId = stoi(trim(vs[1]));
    email = getEmail(vs[2]);
    street = getStreet(vs[3]);
    city = toLower(vs[4]);
    state = getState(vs[5]);
    zipCode = getZipCode(vs[6]);
    creditCard = trim(vs[7]);
}

void Record::print() {
    printf("oId: %d, dID: %d\n%s\n %s, %s\n %s %s\n %s \n", orderId, dealId,
           email.c_str(), street.c_str(), city.c_str(), state.c_str(),
           zipCode.c_str(), creditCard.c_str());
    printf("============================\n");
}

string Record::getKey1() { return email + to_string(dealId); }

string Record::getKey2() {
    return street + ";" + city + ";" + state + ";" + zipCode + ";" +
           to_string(dealId);
}

int Record::getOrderId() { return orderId; }

string Record::getCreditCard() { return creditCard; }

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // turn the string into stream
    string tok;
    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

vector<int> getFraudOrders(map<string, vector<Record>> m) {
    vector<int> v;
    for (map<string, vector<Record>>::iterator it = m.begin(); it != m.end();
         ++it) {
        vector<Record> vi = it->second;
        bool ok = 0;
        for (Record r : vi) {
            if (r.getCreditCard() != vi[0].getCreditCard()) {
                ok = 1;
            }
        }
        if (ok) {
            for (Record r : vi) {
                v.push_back(r.getOrderId());
            }
        }
    }
    return v;
}

vector<int> removeDuplicates(vector<int> v) {
    vector<int> r;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (r.empty() || (v[i] != r[r.size() - 1])) {
            r.push_back(v[i]);
        }
    }
    return r;
}

void mainTest() {
    assert(getEmail("bugs@bunny.com") == getEmail("BuGS@BuNNy.COM"));
    assert(getStreet("123 Sesame St.") == getStreet("123 SeSAME st."));
    assert(getEmail("bugs1@bunny.com") == getEmail("bugs.1@bunny.com"));
    assert(getEmail("bugs@bunny.com") == getEmail("bugs+10@bunny.com"));
    assert(getStreet("123 Sesame St.") == getStreet("123 Sesame Street"));
    assert(getState("IL") == getState("Illinois"));
    assert(getStreet("Road") == getStreet("Rd."));
    assert(getState("California") == getState("CA"));
    assert(getState("New York") == getState("NY"));
    assert(getZipCode("12345689010") == getZipCode("123-45-689010"));
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string line;
    vector<Record> recs;
    getchar();
    map<string, vector<Record>> m1, m2;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        if (line.size() < 5) {
            i--;
            continue;
        }
        vector<string> vs = split(line, ',');

        // test
        // for (string s : vs) {
        // printf("\t%s\n", s.c_str());
        // }
        // printf("=============================\n");
        // end test

        Record r(vs);
        recs.push_back(r);

        // for_each(vs.begin(), vs.end(),
        //          [](string s) { printf("'%s'; ", s.c_str()); });
        // printf("\n");

        // email + dealId
        string k1 = r.getKey1();
        if (m1.find(k1) == m1.end()) {
            vector<Record> vi;
            m1[k1] = vi;
        }
        m1[k1].push_back(r);

        // Address/City/State/Zip + dealId
        string k2 = r.getKey2();
        if (m2.find(k2) == m2.end()) {
            vector<Record> vi;
            m2[k2] = vi;
        }
        m2[k2].push_back(r);
    }

    // // for (Record r : recs) {
    // //     r.print();
    // // }
    vector<int> ans1 = getFraudOrders(m1);
    vector<int> ans2 = getFraudOrders(m2);
    vector<int> ans;
    ans.insert(ans.end(), ans1.begin(), ans1.end());
    ans.insert(ans.end(), ans2.begin(), ans2.end());
    sort(ans.begin(), ans.end());
    ans = removeDuplicates(ans);
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i != (int)ans.size() - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
