class Solution {
public:
    int findTheWinner(int n, int k) { //JOSEPHUS CYCLE
        return 1+solve(n,k);
    }
    int solve(int n,int k){
        if(n==1){
            return 0;
        }
        return (solve(n-1,k)+k)%n;
    }
};