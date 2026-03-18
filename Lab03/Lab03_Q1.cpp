class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {0}; // 建立數數用陣列
        int n = arr.size(); // 取vector大小，存起來以限制for迴圈
        int findMax = 0; // 找cnt用到什麼數
        int ans = -1; // 預設答案為沒有lucky integer
        // 4 steps: assignment
        // 1 step: for loop initialization
        for(int i=0;i<n;i++){ // for迴圈數數及找最大值
            // 1 step(comparison): i<n
            cnt[arr[i]]++; 
            // 3 step: arithmetic(++), array access(arr[i]), array acces(cnt[ ])
            // 1 step: comparison(arr[i]>findMax)
            if(arr[i]>findMax){ 
                findMax = arr[i]; 
                // 1 step: assignment(findMax = arr[i])
            }
            // 1 step: arithmetic(i++)
        }
        // 1 step: for loop initialization
        for (int i=1;i<=findMax;i++){ // for迴圈找lucky integer
            // 1 step: comparison(i<=findMax)
            // 1 step: comparison(i==cnt[i])
            if(i == cnt[i]){
                ans = i;
                // 1 step: assignment(ans=i)
            }
            // 1 step: arithmetic(i++)
        }

        return ans;
    }
};
