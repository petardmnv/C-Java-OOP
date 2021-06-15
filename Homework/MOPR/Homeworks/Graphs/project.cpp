#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

#define INT_MAX 2147483647

using namespace std;

vector<vector<int>> shops;
vector<vector<int>> paths;
vector<vector<int>> hamiltonian_paths;

void print_matrix(vector<vector<int>> v){

	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
	
			cout << v[i][j] << " ";
		}
		
		cout << endl;
	}
}

void find_paths(int position, int starting_point, vector<int> current_path){

	current_path.push_back(position);
	
	vector<int> check_if_visited;

	for(int i = 0; i < shops.size(); i++){
		check_if_visited.push_back(0);
	}

	for(int i = 0; i < current_path.size(); i++){
	
		check_if_visited[current_path[i]] = 1;
	}

	int is_done = 1;

	for(int i = 0; i < shops.size(); i++){
		
		if(check_if_visited[i] == 0){
			is_done = 0;
		}
	}


	if(is_done){
	
		if(shops[position][starting_point] > 0){
			hamiltonian_paths.push_back(current_path);
		}
			
		return;
	}


	for(int next = 0; next < paths[position].size(); next++){
	
		if(check_if_visited[paths[position][next]] == 0){
			find_paths(paths[position][next], starting_point, current_path);
		}
	}

	return;
}

int calculate_shortest_hamiltonian(){

	vector<int> paths_sum;

	for(int i = 0; i < hamiltonian_paths.size(); i++){
		paths_sum.push_back(0);
	}
	
	for(int path = 0; path < hamiltonian_paths.size(); path++){
	
		vector<int> current_hamiltonian = hamiltonian_paths[path];
	
		for(int i = 0; i < current_hamiltonian.size() - 1; i++){
			paths_sum[path] += shops[current_hamiltonian[i]][current_hamiltonian[i + 1]];
		}
	
		paths_sum[path] += shops[current_hamiltonian[current_hamiltonian.size() - 1]][current_hamiltonian[0]];
	}
	
	int min_path = INT_MAX, index = 0;
	
	for(int i = 0; i < paths_sum.size(); i++){
	
		if(paths_sum[i] < min_path){
			min_path = paths_sum[i];
			index = i;
		}
	}
	
	cout << "Time in minutes: " << paths_sum[index] << endl;
	
	return index;
}

int main(int argc, char *argv[]){

	//the reading will be successful if there are no spaces after the last numbers in the rows 
	//and no new lines after the last line aswell

	if(argc == 2){
	
		ifstream in = ifstream(argv[1]);		
	
		string line;
    	while(getline(in, line)) {
      		stringstream ss = stringstream(line);
			vector<int> v;
			
			while(!ss.eof()){
				int x;
				ss >> x;
				v.push_back(x); 
			}

			shops.push_back(v);
    	}
    	
    	in.close();
	}

	for(int i = 0; i < shops.size(); i++){
		vector<int> v;
	
		for(int j = 0; j < shops[i].size(); j++){
			
			if(shops[i][j] > 0){	
				v.push_back(j);
			}	
		}
		
		paths.push_back(v);
	}

	//print_matrix(shops);
	//print_matrix(paths);

	
	vector<int> current_path;
	
	cout << "Enter a starting node: ";
	
	int starting_node;
	
	cin >> starting_node;
	
	find_paths(starting_node, starting_node, current_path);

	//cout << "Hamiltonians:" << endl;
	//print_matrix(hamiltonian_paths);

	int index = calculate_shortest_hamiltonian();

	cout << "Shortest path is: ";
	for(int i = 0; i < hamiltonian_paths[index].size(); i++){
		cout << hamiltonian_paths[index][i] << " "; 
	}
	cout << endl;

	return 0;
}
