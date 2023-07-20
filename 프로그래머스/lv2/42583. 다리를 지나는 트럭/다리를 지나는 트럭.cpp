#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q; 
    int time =0; 
    int next_truck_idx=0; 
    int weight_sum=0; 
    for(int i=0; i<bridge_length; i++){
        q.push(0);
    }
    while(!q.empty()){
        time++;
        weight_sum-=q.front(); 
        q.pop();
        
        if(next_truck_idx<truck_weights.size()){
            if(weight_sum+truck_weights[next_truck_idx]<=weight){
                weight_sum+=truck_weights[next_truck_idx];
                q.push(truck_weights[next_truck_idx]);
                next_truck_idx++;
            }else{
                q.push(0);
            }
        }
    }
  
    return time;
}