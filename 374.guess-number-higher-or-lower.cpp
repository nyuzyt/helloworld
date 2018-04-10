// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
    	int max = n;
		int min = 1;
		if (guess(max)==0)
			return max;
		int tmp = (max+min)/2;
		int tmpGuess = guess(tmp);
		while(tmpGuess!=0 && max>min){
			if(tmpGuess>0)
				min = tmp+1;
			else
				max = tmp-1;
			tmp =(max-min)/2+min;
			tmpGuess = guess(tmp);
		}
		return tmp;
    }
};
