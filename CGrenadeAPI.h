#pragma once
#ifndef CGRENADE_H
#define CGRENADE_H

#include <string>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <process.h>
#include <Mmsystem.h>
#include <stdint.h>
#include <signal.h>
#include <WinInet.h>
#include <comdef.h>
#include <Wbemidl.h>
#include "Vector.h"
#include <WinSock.h>
#include <Windns.h>
#pragma comment (lib, "iphlpapi.lib")
#pragma comment (lib, "Wininet.lib")
#pragma comment (lib, "urlmon.lib")
#pragma comment (lib, "wbemuuid.lib")
#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "Dnsapi.lib")

#pragma warning(disable:4996)
#pragma warning(disable:4244)

struct GrenadeInfo_t
{
	int id; // id
	std::string szName; // Name
	std::string szDescription; // Description
	std::string szWeapon; // GrenadeName
	Vector vecOrigin; // Position
	Vector vecViewangles; // Angle

	void Clear()
	{
		id = 0;
		szName.clear();
		szDescription.clear();
		szWeapon.clear();
		vecOrigin.Zero();
		vecViewangles.Zero();
	}
};

class CGrenadeAPI
{
private:
	GrenadeInfo_t GrenadeInfo[100];

	std::string szHost = "moveax.eu";
	std::string szApi = "/grenade/api/getInfo?map=";

	std::string HttpGet(std::string hostaddr, std::string api);
	std::string parseString(std::string szBefore, std::string szAfter, std::string szSource);

public:
	bool bUpdateGrenadeInfo(std::string szMapName);
	bool GetInfo(int iNum, GrenadeInfo_t& info);
};


extern CGrenadeAPI cGrenade;

#endif 
