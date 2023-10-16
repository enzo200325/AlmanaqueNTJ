#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

string path = "../codigos/";
string github_link= "https://github.com/enzo200325/AlmanaqueNTJ/blob/main";

string get_name(string file) {
	ifstream fin(file.c_str());
	string line;
	getline(fin, line);
	fin.close();
    if (line[2] == ' ') {
        return line.substr(3);
    }
    return line.substr(2);
}

string parse(string s){
    vector<char> dont {'/', '+', '?', '&', '#', '=', '.'};

    auto in = [&] (char c){
        for(char u : dont){
            if(u == c) return true;
        } return false;
    };
    auto hexa = [&] (int n){
        string t;
        while(n){
            int r = n % 16;
            if(r < 10){
                t += char(r + 48);
            } else {
                t += char(r + 55);
            }
            n /= 16;
        }
        t += "%";
        reverse(begin(t), end(t));
        return t;
    };

    string ret;
    for(char c : s){
        if(in(c)){
            ret += c;
        } else {
            ret += hexa(int(c));
        }
    }
    
    return ret;
}

void dfs(string s, int level = 0) {
	struct dirent* entry = nullptr;
	DIR* dp = nullptr;
	dp = opendir(s.c_str());
	if (dp != nullptr) while (entry = readdir(dp)) {
		if (entry->d_name[0] == '.') continue;	
		for(int lv = 0; lv < level; lv++) cout << "\t";
		if (entry->d_type == DT_DIR) {
			cout << "- " << string(entry->d_name) << endl;
			dfs(s + "/" + string(entry->d_name), level+1);
		} else {
			cout << "- [" << get_name(s + "/" + string(entry->d_name)) << "](" << github_link << parse(s.substr(2)) + '/' + parse(string(entry->d_name)) << ")" << endl;
		}
	}
}

void printa_section(string s) {
	cout << "\n### " << s << "\n\n";
}

int main(int argc, char** argv) {
	struct dirent* entry = nullptr;
	DIR* dp = nullptr;
	dp = opendir(path.c_str());
	cout << "## CONTEÚDOS\n\n";
	if (dp != nullptr) while (entry = readdir(dp)) {
		if (entry->d_name[0] == '.') continue;
		if (entry->d_type != DT_DIR) continue;

		string dir(entry->d_name);
		if(dir == "Extra") continue;
		printa_section(dir);

		dfs(path + dir);

	}
	printa_section("Extra");
	dfs(path + "Extra");

	return 0;
}
