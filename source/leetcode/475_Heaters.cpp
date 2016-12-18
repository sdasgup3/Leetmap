/* Problem Description
 * Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/

#include"header.h"

class Solution {
public:
    int find_nearest_heater(vector<int> &heaters, int first, int last, int k) {

      while(first < last) {
        if(last == first  +1) {
          return abs(k - heaters[first]) < abs(heaters[last] - k) ? heaters[first] : heaters[last];
        }
        int mid = first + (last - first)/2;
        if(heaters[mid] == k) {
          return heaters[mid];

        } else if(heaters[mid] > k) {
          last = mid;
        } else {
          first = mid;
        }
      }
      
      return heaters[first];
    }


    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int house_sz = houses.size();
        int heater_sz = heaters.size();
        vector<int> min_dist_of_houses_from_heaters(house_sz);

        sort(heaters.begin(), heaters.end());

        int start_pos = 0;

        for(int i = 0 ; i < house_sz; i++) {
            auto house = houses[i];
            int nearest_h = find_nearest_heater(heaters, 0, heater_sz-1, house);
            min_dist_of_houses_from_heaters[i] = abs(house - nearest_h);
        }
        
        int res = INT_MIN;
        for(auto dist : min_dist_of_houses_from_heaters) {
            res = max(res, dist);
        }
        
        return res;
    }
    int findRadius2(vector<int>& houses, vector<int>& heaters) {
        int house_sz = houses.size();
        int heater_sz = heaters.size();
        vector<int> min_dist_of_houses_from_heaters(house_sz);

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int start_pos = 0;

        for(int i = 0 ; i < house_sz; i++) {
            auto house = houses[i];

            //
            int nearest_h ;
            if(house <= heaters[0]) {
              nearest_h =  heaters[0]; 
            } else if(house > heaters[heater_sz-1]) {
              nearest_h = heaters[heater_sz-1];
            } else {
              for(int j = start_pos ; j < heater_sz-1; j++) {
                if(house <= heaters[j+1]) {
                  nearest_h = (house - heaters[j]) < (heaters[j+1] - house) ? heaters[j] : heaters[j+1];
                  start_pos = j;
                  break;
                }
              }
            }

            min_dist_of_houses_from_heaters[i] = abs(house - nearest_h);
        }
        
        int res = INT_MIN;
        for(auto dist : min_dist_of_houses_from_heaters) {
            res = max(res, dist);
        }
        
        return res;
    }
};

int main() {
  Solution S;


  //vector<int> houses({282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923});
  //vector<int> heaters({823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612});

  vector<int> houses({1,2,3});
  vector<int> heaters({2});
  cout << S.findRadius(houses, heaters);

  return 0;
}
