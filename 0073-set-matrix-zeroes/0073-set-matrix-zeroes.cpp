class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool zero = false;

        for(int i=0; i<n; i++){
            if(mat[i][0] == 0) zero = true;
            for(int j=1; j<m; j++){
                if(mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                    // for(int i_=0; i_<mat.size(); i_++) if(mat[i_][j] != 0) mat[i_][j] = -1;
                    // for(int j_=0; j_<mat[0].size(); j_++) if(mat[i][j_] != 0) mat[i][j_] = -1;
                }
            }
        }

        // for(auto i: mat){
        //     for(auto j: i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=1; j--){
                // if(i == 0 && j == 0) continue;
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    // for(int i_=1; i_<n; i_++) mat[i_][j] = 0;
                    // for(int j_=1; j_<m; j_++) mat[i][j_] = 0;
                    mat[i][j] = 0;
                }
            }
            if(zero){
                mat[i][0] = 0;
            }
        }

        // for(auto i: mat){
        //     for(auto j: i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        // if(mat[0][0] == 0) {
        //     for(int i_=0; i_<n; i_++) mat[i_][0] = 0;
        //     for(int j_=0; j_<m; j_++) mat[0][j_] = 0;
        // }

        // for(int i=0; i<mat.size(); i++){
        //     if(mat[i][0] == 0 && mat[]){
        //         for(int j=0; j<mat[i].size(); j++){
        //             mat[i][j] = 0;
        //         }
        //     }
        // }
        // for(int j=0; j<mat[0].size(); j++){
        //     if(mat[0][j] == 0) {
        //         for(int i=0; i<mat.size(); i++){
        //             mat[i][j] = 0;
        //         }
        //     }
        // }
    }
};