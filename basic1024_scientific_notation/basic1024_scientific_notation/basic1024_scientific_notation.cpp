#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

char sign,ch,dir,zheng[10001],xiao[10001];
int a,ex;

void solve_0(){
	printf("%d.",a);
	printf("%s\n",zheng);
}

void solve_1(){
	int i;
	printf("0.");
	for(i=0;i<ex-1;++i){
		printf("0");
	}
	printf("%d",a);
	printf("%s\n",zheng);
}

void solve_2(){
	int i,len;
	len = strlen(zheng);
	printf("%d",a);
	if(len<=ex){
		printf("%s",zheng);
		for(i=0;i<ex-len;++i)printf("0");
		printf("\n");
	}else{
		for(i=0;i<ex;++i){
			printf("%c",zheng[i]);
		}
		printf(".");
		printf("%s\n",zheng+ex);
	}
}

int main(){
	scanf("%c%d.%[^E]%c%c%s",&sign,&a,zheng,&ch,&dir,xiao);
	//printf("%c  %d %s  %c  %c  %s\n",sign,a,zheng,ch,dir,xiao);
	if(sign=='-')printf("-");
	ex = stoi(xiao);
	if(ex==0){
		solve_0();
		return 0;
	}
	if(dir=='-'){
		solve_1();
	}else{
		solve_2();
	}
	return 0;
}

