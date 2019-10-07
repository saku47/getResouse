#pragma once

#include <string>
using namespace std;

class Section
{
private:
	// メンバ変数
	string risouseName;
	int risouseTime;
	string risousePass;
	int Priority;

public:
	// メンバ関数

	// コンストラクタ
	Section( 
		string name,
		int time,
		string pass,
		int priority
	) : risouseName(name), risouseTime(time), risousePass(pass), Priority(priority) {}

	//プライオリティのセット
	void s_priority(int priority) { Priority = priority; }

	//アクセサ
	string g_name() { return risouseName; }
	string g_pass() { return risousePass; }
	int g_time() { return risouseTime; }
	int g_priority() { return Priority; }

};

