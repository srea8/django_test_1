#include <cstdio>  
#include <iostream>  
#include <string>  
#include <winsock2.h>  
#pragma comment(lib,"ws2_32.lib")  
using namespace std;  
const int PORT = 8009;  
int main()  
{  
	int n;  
	WSADATA wd;  
	n=WSAStartup(MAKEWORD(2, 2), &wd);  
	if (n)  
	{  
		cout << "WSAStartup函数错误！" << endl;  
		return -1;  
	}  
	SOCKET sock = socket(AF_INET, SOCK_DGRAM,0);  
	if (INVALID_SOCKET == sock)  
	{  
		cout << "socket建立失败!" << endl;  
		cout << "错误码是：" << WSAGetLastError() << endl;  //返回错误代码
		return -1;  
	}  
	sockaddr_in sa = { AF_INET, htons(PORT) };  
	n=bind(sock,(sockaddr*)&sa, sizeof(sa));  
	if (n == SOCKET_ERROR)  
	{  
		cout << "bind绑定端口失败！" << endl;  
		cout << "错误码是：" << WSAGetLastError() << endl;  //返回错误代码
		return -1;  
	}  
	else  
	{  
		cout << "端口发布成功:" << PORT << endl;  
	}  
	char s[256];  
	while (true)  
	{  
		n = recv(sock, s, sizeof(s), 0); //recv返回的是实际copy的字节数  
		s[n] = '\0';  
		cout << s << endl;  
	}  

	return 0;  

}  