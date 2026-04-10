// class Solution {
//     public int totalMoney(int n) {
//         int a = 1, d = 1;
//         int sum = 0;
//         while(n > 0){
//             int days = Math.min(n, 7);
//             sum += ((days * (2 * a + (days - 1) * d)) / 2);
//             a += 1;
//             n = n - 7;
//         }
//         return sum;
//     }
// }

class Solution{
    public int totalMoney(int n){
        int fullweeks = n / 7;
        int remainingDays = n % 7;
        int sum = 0;

        //sum of n numbers = ((n * (2 * a + (n - 1) * d))/ 2)
        sum = ((fullweeks * (2 * 28 + (fullweeks - 1) * 7))/ 2); // a = 28, d = 7
        sum += ((remainingDays * (2 * (fullweeks + 1) + (remainingDays - 1) * 1)) / 2); // a = fullweeks + 1 , d = 1
        return sum;
    }
}