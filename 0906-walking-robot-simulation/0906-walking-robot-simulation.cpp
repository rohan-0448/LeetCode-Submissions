class Solution {
public:

    int distance(int x, int y){
        return pow(x,2) + pow(y,2);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction_x = 0, direction_y = 1;
        int curr_x = 0, curr_y = 0;
        int dist = INT_MIN;

        unordered_set<string> temp;
        for(auto i: obstacles) temp.insert(to_string(i[0]) + " " + to_string(i[1]));

        for(auto i: commands){
            if(i<0){
                if(i==-2) {
                    if(direction_y == 1){
                        direction_y = 0;
                        direction_x = -1;
                    }
                    else if(direction_y == -1){
                        direction_y = 0;
                        direction_x = 1;
                    }
                    else if(direction_x == 1){
                        direction_y = 1;
                        direction_x = 0;
                    }
                    else if(direction_x == -1){
                        direction_y = -1;
                        direction_x = 0;
                    }
                }else{
                    if(direction_y == 1){
                        direction_y = 0;
                        direction_x = 1;
                    }
                    else if(direction_y == -1){
                        direction_y = 0;
                        direction_x = -1;
                    }
                    else if(direction_x == 1){
                        direction_y = -1;
                        direction_x = 0;
                    }
                    else if(direction_x == -1){
                        direction_y = 1;
                        direction_x = 0;
                    }
                }
            }
            else{
                for(int j=0; j<i; j++){
                    curr_x += direction_x;
                    curr_y += direction_y;
                    string next = to_string(curr_x) + " " + to_string(curr_y);
                    if(temp.find(next) != temp.end()) {
                        curr_x -= direction_x;
                        curr_y -= direction_y;
                        break;
                    }
                    dist = max(dist, distance(curr_x, curr_y));
                }
            }
        }
        return (dist==INT_MIN)? 0: dist;
    }
};