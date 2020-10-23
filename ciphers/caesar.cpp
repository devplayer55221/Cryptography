#include<iostream>
#include<string>
using namespace std;

void caesar()
{
	cout<<"Input plain text: ";
	string plain="";
	cin>>plain;
	cout<<"Enter number by which to rotate: ";
	int rot;
	cin>>rot;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string ciphertext="";
	for(int i=0;i<plain.length();i++)
	{
		if(alpha.find(plain[i])!=string::npos)
		{
			ciphertext+=alpha[(alpha.find(plain[i])+rot)%26];
		}
		else
		{
			ciphertext+=plain[i];
		}
	}
	cout<<"Cipher text: "<<ciphertext<<endl;
}


void vignere()
{
	cout<<"Input plain text: ";
	string plain="";
	cin>>plain;
	cout<<"Input key: ";
	string key="";
	cin>>key;
	int j=0;
	string expandedkey = "";
	for(int i=0;i<plain.length();i++)
	{
		expandedkey+=key[j];
		j++;
		if(j==key.length())
			j=0;
	}
	string ciphertext="";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for(int i=0;i<plain.length();i++)
	{
		if(alpha.find(plain[i])!=string::npos)
			ciphertext+=alpha[((alpha.find(plain[i]))+(alpha.find(expandedkey[i])))%26];
		else
			ciphertext+=plain[i];
	}
	cout<<"Cipher text: "<<ciphertext<<endl;
}

void atbash()
{
	cout<<"Input plain text: ";
	string plain="";
	cin>>plain;
	string ciphertext="";
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for(int i=0;i<plain.length();i++)
	{
		if(alpha.find(plain[i])!=string::npos)
			ciphertext+=alpha[alpha.length()-alpha.find(plain[i])-1];
		else
			ciphertext+=plain[i];
	}
	cout<<"Cipher text: "<<ciphertext<<endl;
}

void menu()
{
	int ch=-1;
	do
	{
		cout<<"Which cryptographic algorithm would you like to implement"<<endl;
		cout<<"1. Caesar Cipher (Modified)"<<endl;
		cout<<"2. Vignere Cipher"<<endl;
		cout<<"3. Atbash Cipher"<<endl;
		cout<<"0. End program"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: caesar();
					break;
			case 2: vignere();
					break;
			case 3: atbash();
					break;
			case 0: cout<<"Exiting"<<endl;
					break;
			default: cout<<"Redirecting..."<<endl;
					break;
		}

	}while(ch!=0);
	return;
}

int main()
{
	menu();
	return 0;
}