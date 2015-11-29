

int 
list<string> vertok(const string & ver) {
    list<string> returned;
    string ver_copy = ver;
    while (ver_copy.length() > 0) {
        for (int i = 0; i < ver_copy.length(); i++) {

