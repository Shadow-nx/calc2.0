#include <iostream>
#include <cstring>

using namespace std;

int main(int argc,char*argv[]) {
	char *x=argv[1];
	int count=1;
	int count2=0;
	for(int i=0; i<strlen(argv[1]); i++)
		if((char)argv[1][i]=='+'||(char)argv[1][i]=='-'||(char)argv[1][i]=='*'||(char)argv[1][i]=='/')
			count2++;
	char *oper=new char[count2];
	for(int i=0; i<strlen(oper); i++)
		oper[i]='0';
	int g=0;
	for(int i=0; i<strlen(argv[1]); i++)
		if((char)argv[1][i]=='+'||(char)argv[1][i]=='-'||(char)argv[1][i]=='*'||(char)argv[1][i]=='/') {
			oper[g]=(char)argv[1][i];
			g++;
		}
	for(int i=0; i<strlen(argv[1]); i++)
		if(x[i]>='0'&&x[i]<='9')
			;
		else count++;
	double *z=new double[count];
	int k=0;
	for(int i=0; i<count; i++)
		z[i]=0;
	int n=strlen(x);
	for(int i=0; i<n; i++)
		if(x[i]>='0'&&x[i]<='9')
			z[k]=z[k]*10+x[i]-'0';
		else k++;

	double result[1]= {0};
	if(strlen(oper)>1) {
		for(int i=0; i<strlen(oper); i++) {
			if((char)oper[i]=='*') {
				result[0]=z[i]*z[i+1];
				for(int j=i; j<strlen(oper)-1; j++) {
					oper[j]=oper[j+1];
					oper[j+1]='0';
				}
				for(int k=i; k<count-1; k++) {
					z[k+1]=z[k+2];
					z[k+2]=0;
					z[i]=result[0];
				}
				z[count-1]=0;
				i--;
			}
		}
		for(int i=0; i<strlen(oper); i++) {
			if((char)oper[i]=='/') {
				result[0]=z[i]/z[i+1];
				for(int j=i; j<strlen(oper)-1; j++) {
					oper[j]=oper[j+1];
					oper[j+1]='0';
				}
				for(int k=i; k<count-1; k++) {
					z[k+1]=z[k+2];
					z[k+2]=0;
					z[i]=result[0];
				}
				z[count-1]=0;
				i--;
			}
		}

		for(int i=0; i<strlen(oper); i++) {
			if((char)oper[i]=='-') {
				result[0]=z[i]-z[i+1];
				for(int j=i; j<strlen(oper)-1; j++) {
					oper[j]=oper[j+1];
					oper[j+1]='0';
				}
				for(int k=i; k<count-1; k++) {
					z[k+1]=z[k+2];
					z[k+2]=0;
					z[i]=result[0];
				}
				z[count-1]=0;
				i--;
			}
		}
		for(int i=0; i<strlen(oper); i++) {
			if((char)oper[i]=='+') {
				result[0]=z[i]+z[i+1];
				for(int j=i; j<strlen(oper)-1; j++) {
					oper[j]=oper[j+1];
					oper[j+1]='0';
				}
				for(int k=i; k<count-1; k++) {
					z[i]=result[0];
					z[k+1]=z[k+2];
					z[k+2]=0;
				}
				z[count-1]=0;
				i--;
			}
		}
	} else {
		if(oper[0]=='*')
			result[0]=z[0]*z[1];
		if(oper[0]=='/')
			result[0]=z[0]/z[1];
		if(oper[0]=='+')
			result[0]=z[0]+z[1];
		if(oper[0]=='-')
			result[0]=z[0]-z[1];
	}
	cout<<"Result:"<<result[0]<<endl;

	return 0;
}
