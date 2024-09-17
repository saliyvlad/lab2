#include <stdio.h>
// 1C = 33,8F
void main(){
	float a;
	int b;
	printf("Input temperature:");
	scanf("%f",&a);
	scanf("%c",&b);
	if (b == "f"){
	a /= 33.8;
	printf("%f", a);
}else if (b == "c"){
	a *= 33.8;
	printf("%f",a);
}else printf("Output Error");
}
