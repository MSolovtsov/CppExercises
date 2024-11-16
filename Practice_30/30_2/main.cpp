#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
    cout << "\nTask #2\n  Capturing the title of a web page\n" << endl;

    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"accept", "text/html"}}));
    string tag = "<p>";
    string header = r.text.substr((r.text.find("<p>") + tag.length()), (r.text.find("</p>") - r.text.find("<p>") - tag.length()));
    cout << header << endl;
    return 0;
}
