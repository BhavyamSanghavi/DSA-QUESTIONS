    for(int i = nums.length - 1; i >= nums.length - k; i--){
        int currentValue = nums[i];
     //   System.out.println("Current: " + currentValue);
        if(mul > 1) totalSum += currentValue * mul;
        else totalSum += currentValue;
        mul--;
     //   System.out.println("TotalSum: " + totalSum);
    }
    return totalSum;
}