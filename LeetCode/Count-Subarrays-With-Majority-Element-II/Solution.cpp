for (int x : nums) {
    bool isT=x==target;
    sum+=(-isT & cntB[balance])-(-!isT & cntB[balance-1]);
    balance+=(isT<<1)-1;// (isT)?1:-1
    cntB[balance]++;
    ans+=sum;
}