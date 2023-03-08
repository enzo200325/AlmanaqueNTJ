#include <bits/stdc++.h>
#include <dirent.h>

using namespace std;

string path = "../codigos/";

bool is_comment(string line) {
	while (line.size() and (line[0] == ' ' or line[0] == '\t'))
		line = line.substr(1);
	bool comment = line.size() == 0;
	if (line.size() >= 2 and line.substr(0, 2) == "//") comment = true;
	if (line.size() >= 2 and line.substr(0, 2) == "/*") comment = true;
	return comment;
}

void printa_arquivo_codigo(string file, bool extra = false) {
	cout << "\\begin{lstlisting}\n";
	ifstream fin(file.c_str());
	string line;
	int count = 0;
	bool started_code = false;
	int depth = 0;
	stack<int> st;
	for (int line_idx = 0, line_code = 1; getline(fin, line); line_idx++) {
		st.push(line_idx);
		if (count++ < 2 and !extra) continue;

		for (char c : line) {
			if (c == '{') depth++, st.push(line_idx);
			if (c == '}') depth--, st.pop();
		}

		bool comment = is_comment(line);
		if (!comment) started_code = true;

		if (!extra and started_code) {
			cout << " ";
		}
		cout << line << endl;
		st.pop();
	}
	fin.close();
	cout << "\\end{lstlisting}\n\n";
}

void printa_arquivo(string file, bool extra = false) {
	ifstream fin(file.c_str());
	string line;
	int count = 0;
	while (getline(fin, line)) {
		if (count++ < 2 and !extra) continue;
		cout << line << endl;
	}
	fin.close();
}

string get_name(string file) {
	ifstream fin(file.c_str());
	string line;
	getline(fin, line);
	fin.close();
	if (line[2] == ' ') return line.substr(3);
	return line.substr(2);
}

void printa_cuidado(string s) {
	for (char c : s) {
		if (c == '^') cout << '\\';
		cout << c;
		if (c == '^') cout << "{}";
	}
}

bool printa_listing(string sub, string file, bool extra = false) {

	cout << "\\subsection{";
	if (!extra) printa_cuidado(get_name(file));
	else printa_cuidado(sub);
	cout << "}\n";

	printa_arquivo_codigo(file, extra);
	return true;
}

void dfs(vector<pair<string, string>>& files, string s, bool extra = false) {
	struct dirent* entry = nullptr;
	DIR* dp = nullptr;
	dp = opendir(s.c_str());
	if (dp != nullptr) while (entry = readdir(dp)) {
		if (entry->d_name[0] == '.') continue;	

		if (entry->d_type == DT_DIR) dfs(files, s + "/" + string(entry->d_name), extra);
		else {
			if (!extra) files.emplace_back(entry->d_name, s + "/" + string(entry->d_name));
			else printa_listing(entry->d_name, s + "/" + entry->d_name, extra);
		}
	}
}

void printa_section(string s) {
	cout << "\n\n";

	for (int i = 0; i < 20; i++) cout << "%";
	cout << "\n%\n% " << s << "\n%\n";
	for (int i = 0; i < 20; i++) cout << "%";
	cout << "\n\n";

	cout << "\\section{" << s << "}\n\n";
}

string lower(string s) {
	for (char& c : s) if (c >= 'A' and c <= 'Z') c ^= 32;
	return s;
}

int main(int argc, char** argv) {
	printa_arquivo("INICIO_LATEX.tex", true);
	struct dirent* entry = nullptr;
	DIR* dp = nullptr;
	dp = opendir(path.c_str());
	if (dp != nullptr) while (entry = readdir(dp)) {
		if (entry->d_name[0] == '.') continue;
		if (entry->d_type != DT_DIR) continue;

		string dir(entry->d_name);
		if (dir == "Extra") continue;
		printa_section(dir);

		vector<pair<string, string>> files;
		dfs(files, path + dir);

		sort(files.begin(), files.end(), [&](auto f1, auto f2) {
			return lower(get_name(f1.second)) < lower(get_name(f2.second));
		});

		cerr << "=== " << dir << " ===" << endl;
		for (auto [f, path] : files) {
			bool printed = printa_listing(f.substr(0, f.size() - 4), path);
			if (printed) cerr << get_name(path) << endl;
		}
		cerr << endl;
	}

	cout << "\\pagebreak" << endl;
	printa_section("Extra");
	vector<pair<string, string>> files;
	dfs(files, path + "Extra", false);

	sort(files.begin(), files.end(), [&](auto f1, auto f2) {
			return lower(get_name(f1.second)) < lower(get_name(f2.second));
			});

	cerr << "=== Extra ===" << endl;
	for (auto [f, path] : files) {
		bool printed = printa_listing(f.substr(0, f.size() - 4), path);
		if (printed) cerr << get_name(path) << endl;
	}
	cerr << endl;
	cout << "\\end{document}\n";
	return 0;
}
