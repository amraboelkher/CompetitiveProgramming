#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int noOfPeople , Distance , walkingSpeed , busSpeed , busSeats;
int groups;

bool check(double possibleTime){
	// now the possibleTime represents the total required time to finish the journey 
	
	/*	 
	double timePassed = 0.0;
	for(int i = 0 ;i < groups ;i ++){
		// we will go over each group and till now the current group haven't riden the bus yet so till now this group have walked a distance
		// which is equal to timePassed * walkingSpeed 
		// ok now this group will ride the bus ... if we considerd that this group will ride it for T seconds .. this will make this group 
		// go distance equal to busRide = T * busSpeed and will leave this group to walk the remaining distance in the remaining time left which is 
		// remaining time = possibleTime - timePassed - T 
		// This group also have a total remaining distance equal to distance - timePassed * walkingSpeed . therefore this remaining distance
		// should equal to the busRide distance + walkingSpeed * remaining time which is 
		// distance - timePassed * walkingSpeed = T * busSpeed + (possibleTime - timePassed - T) * walkingSpeed  
		// distance - timePassed * walkingSpeed = T * busSpeed + possibleTime * walkingSpeed - timePassed * walkingSpeed - T * walkingSpeed
		// distance - possibleTime * walkingSpeed = T * ( busSpeed - walkingSpeed ) 
		// T = (distance - possibleTime * walkingSpeed) / ( busSpeed - walkingSpeed )
		double T = (Distance - possibleTime * 1.0 * walkingSpeed) / ( 1.0 * busSpeed - walkingSpeed );
		
		timePassed += T;
	
		if(i + 1 < groups){ // that means i have to calculate the time required for the bus to come back for the next group 
			
			// before the bus moved with distance T * busSpeed .. the bus and this next group were in the same place
			// then the bus were in location T * busSpeed while the next group were in location T * walkingSpeed after T seconds
			// we will suppose that after M seconds (meeting time required) they'll meet in a location when the bus is moving towards
			// the next group right now with backwordDistance = -M * busSpeed and the next group is moving with M * walkingSpeed 
			// therefore the following equality should hold ... 
			// T * walkingSpeed + M * walkingSpeed = T * busSpeed - M * busSpeed 
			// M * walkingSpeed + M * busSpeed = T * busSpeed - T * walkingSpeed
			// M * ( walkingSpeed + busSpeed ) = T * busSpeed - T * walkingSpeed
			// M = ( T * busSpeed - T * walkingSpeed ) / ( walkingSpeed + busSpeed )  
			
			double M = ( T * 1.0 * busSpeed - T * walkingSpeed ) / ( 1.0 * walkingSpeed + busSpeed );
			
			// we've to add this time to the total time passed now 
			timePassed += M; 
		}	
	}
	*/
	
	// also we can see that both of the equations doesn't depend on the timepassed variable so we can calculate required time without a loop
	double optT = (Distance - possibleTime * 1.0 * walkingSpeed) / ( 1.0 * busSpeed - walkingSpeed ) ;
	double optM = (groups - 1) * ( optT * 1.0 * busSpeed - optT * walkingSpeed ) / ( 1.0 * walkingSpeed + busSpeed ) ;
	double optTimePassed = groups * optT + optM ;
	return optTimePassed <= possibleTime;
	
}

int main(){
	freopen("in.in" , "r" , stdin);
	

	scanf("%d%d%d%d%d" , &noOfPeople , &Distance , &walkingSpeed , &busSpeed , &busSeats);
	
	// number of groups that will ride the bus 
	groups = noOfPeople / busSeats;
	if(noOfPeople % busSeats != 0){ 
		// which means there're still some people and there number is less than the busSeats available so i will add another group for them
		groups ++;
	}
	
	// the amount of time required if all the people will only walk to finish their journey 
	double walkingAllTheJourney = (1.0 * Distance) / double(walkingSpeed) ;
	
	double left = 0.0 , right = walkingAllTheJourney , answer = 0.0;

	for(double sz = right * 0.5 ; sz > EPS ; sz *= 0.5){
		double mid = sz + answer;
		if(check(mid) == false)
			answer += sz;
	}
	
	printf("%.12lf\n" , answer);
	 
}
