#include <stdio.h>

int main() {
	while(1){
		int temp;
		scanf("%d", &temp);
		if(temp == 0) {
			int temp1, temp2;
			scanf("%d%d", &temp1, &temp2);
			break;
		}
		int minC;
		int cycle[110];
		int state[120] = {0};
		int num = 1;
		cycle[0] = temp;
		minC = temp;
		while(1){
			int tmp;
			scanf("%d", &tmp);
			if(tmp == 0) break;
			if(state[tmp]) continue;
			cycle[num] = tmp;
			state[tmp] = 1;
			num ++;
			if(tmp < minC) minC = tmp;
		}
		int mmm = -1;
		for(int i = 2 * minC; i <= 18000; i++){
			int keyi = 1;
			for(int j = 0; j < num; j++){
				if(i % (2*cycle[j]) >= cycle[j]-5){
					keyi = 0;
					break;
				}
			}
			if(keyi){
				mmm = i;
				break;
			}
		}
		if(mmm == -1){
			printf("Signals fail to synchronise in 5 hours\n");
		}
		else{
			int hour = mmm/3600, minute = (mmm%3600)/60, second = mmm%60;
			printf("0%d:", hour);
			if(minute < 10) printf("0");
			printf("%d:", minute);
			if(second < 10) printf("0");
			printf("%d\n", second);
		}
	}
	return 0;
}
