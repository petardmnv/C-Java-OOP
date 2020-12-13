#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define N 50
double K = 0.129;
double M3 = 1.461;
double MW = 85.07;
double MIN = 0.132;

using namespace std;
void fill_matrix_from_file(double a[][N], string filename){
	ifstream file;
	file.open(filename);
	string line;
	int i = 0;

	while(getline(file, line)){
		stringstream words(line);
		double word;
		int j = 0;

		while(words >> word){
			a[i][j] = word;
			j++;
		}
		i++;
	}

	file.close();
}

void metod_na_gaus(double a[][N], double* x, int n){
    for (int i = 0; i < n; i++){
       	for (int k = i + 1; k < n; k++){
           	if (abs(a[i][i]) < abs(a[k][i])){
               	for (int j = 0; j <= n; j++){
                   	double temp = a[i][j];
                   	a[i][j] = a[k][j];
                   	a[k][j] = temp;
               	}
           	}
       	}
    }	
	for (int i = 0; i < n - 1; i++){        
        for (int k = i + 1; k < n; k++){
            double t = a[k][i] / a[i][i];
            for (int j = 0; j <= n; j++){
                a[k][j] = a[k][j] - t * a[i][j];    
            }
        }
    }

	for (int i = n - 1; i >= 0; i--){                        
        x[i] = a[i][n];                
        for (int j = i + 1; j < n; j++){
            if (j != i){                                              
                x[i] = x[i]-a[i][j]*x[j];
            }
        }
        x[i] = x[i] / a[i][i];            
    }
}

void gaus(double a[][N], double *x, int n){
    double matrix[N][N];

    for (int i = 0; i < n; i++){
       	for (int j = 0; j < n; ++j){
       		matrix[i][j] = a[i][j];
       	}
    }
    for (int i = 0; i < n; i++){
    	matrix[i][4] = a[4][i];
    } 
    metod_na_gaus(matrix, x, 4);
}

void summarize(double a[N][N], double *x, int n){
	double result[N][N];
	for (int i = 0; i < n; ++i){
		double result1 = a[i][0] * K + a[i][1] * M3 + a[i][2] * MW + a[i][3] * MIN;
		cout << a[4][i] - result1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (j == 0){
				cout << a[i][j] - (a[i][j] * K)/x[j] << " ";
			}
			else if (j == 1){
				cout << a[i][j] - (a[i][j] * M3)/x[j] << " ";
			}
			else if (j == 2){
				cout << a[i][j] - (a[i][j] * MW)/x[j] << " ";
			}
			else{
				cout << a[i][j] - (a[i][j] * MIN)/x[j] << " ";
			}
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[]){
	double a[N][N];
	double *x = new double[4];
	fill_matrix_from_file(a, "input.txt");
	gaus(a, x, 4);
	cout << "Output:" << endl;
	summarize(a, x, 4);
	//chill dude :) kiss
	return 0;
}