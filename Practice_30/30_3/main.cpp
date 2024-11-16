#include <iostream>
#include <cpr/cpr.h>
#include <vector>

using namespace std;
using namespace cpr;

string url_str(vector<cpr::Pair>& a){
    string a_str = "?";
    for (int i =0; i < a.size(); i++) {
        a_str += a[i].key + "=" + a[i].value + "&";
    }
    a_str.pop_back();

    return a_str;
}

int main() {
    cout << "\nTask #3\n  Queries with arguments\n" << endl;

    string key;
    vector<cpr::Pair> arg;
    Response res;

    do {
        cout << "enter key:";
        cin >> key;

        if (key == "get"){
            if (!arg.empty()) {
                string url = "httpbin.org/get";
                url += url_str(arg);
                cout << url << endl;
                res = Get(Url(url));
                cout << res.text << endl;
                cout << "==========================================" << endl;
                arg.clear();
            } else cout << "nothing to add" << endl;

        } else if (key == "post") {
            if (!arg.empty()) {
                res = Post(Url("httpbin.org/post"),
                           /*Payload(&arg[0], &arg[arg.size()])*/
                           Payload(arg.begin(), arg.end()) //*/
                );

                arg.clear();
                cout << res.text << endl;
                cout << "==========================================" << endl;
            } else cout << "nothing to add" << endl;

        } else if (key != "exit"){
            string value;
            cout << "enter value:";
            cin >> value;

            arg.push_back(Pair(key, value));

        }


    } while (key != "exit");

    return 0;
}
