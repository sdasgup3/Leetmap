int Solution::func(int num) {
    //   return (num-1)%9 +1;
     if(num <= 9) {
            return num;
        } else {
            return (num-10)%9 +1;
        }
        
}
