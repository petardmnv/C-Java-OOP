#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<queue>

using namespace std;

vector<vector<int>> raw_info;
vector<vector<int>> paths;

void print_matrix(vector<vector<int>> v){

	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
	
			cout << v[i][j] << " ";
		}
		
		cout << endl;
	}
}


vector<vector<int>> find_paths_by_given_start_end(int position, int start_point, int end_point, vector<vector<int>> v){
	queue<vector<int>> q;

    vector<int> path;
    vector<vector<int>> found_paths;
    path.push_back(start_point);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
 
        if (last == end_point)
            found_paths.push_back(path);
 
        for (int i = 0; i < v[last].size(); i++) {

        	// is not vizited
        	int is_visited = 0;
        	for (int i = 0; i < path.size(); i++){
        		if (path[i] == v[last][i]){
        			is_visited = 1;
        		}
        	}
            if (!is_visited) {
                vector<int> newpath(path);
                newpath.push_back(v[last][i]);
                q.push(newpath);
            }
        }
    }
    return found_paths; 
}

int main(int argc, char const *argv[])
{
	if(argc == 2){
		fstream newfile;
		newfile.open(argv[1], ios::in);
		if (newfile.is_open()){
			string tp;
			while(getline(newfile, tp)){
				stringstream ss = stringstream(tp);
				vector<int> tmp;
				
				while(!ss.eof()){
					int x;
					ss >> x;
					tmp.push_back(x); 
				}

				raw_info.push_back(tmp);
		  	}
		  	newfile.close();
		}
	}else {
		cout << "Enter path file filename in args " << endl;
		return 0;
	}

	for(int i = 0; i < raw_info.size(); i++){
		vector<int> v;
	
		for(int j = 0; j < raw_info[i].size(); j++){
			
			if(raw_info[i][j] > 0){	
				v.push_back(j);
			}	
		}
		
		paths.push_back(v);
	}

	print_matrix(raw_info);
	print_matrix(paths);

	vector<int> current_path;
	
	cout << "Enter a starting point: ";
	
	int start_point;
	
	cin >> start_point;


	vector<vector<int>> f_p;
	f_p = find_paths_by_given_start_end(start_point, start_point, 4, raw_info);
	

	print_matrix(f_p);


	return 0;
}