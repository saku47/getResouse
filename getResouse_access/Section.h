#pragma once

#include <string>
using namespace std;

class Section
{
private:
	// �����o�ϐ�
	string risouseName;
	int risouseTime;
	string risousePass;
	int Priority;

public:
	// �����o�֐�

	// �R���X�g���N�^
	Section( 
		string name,
		int time,
		string pass,
		int priority
	) : risouseName(name), risouseTime(time), risousePass(pass), Priority(priority) {}

	//�v���C�I���e�B�̃Z�b�g
	void s_priority(int priority) { Priority = priority; }

	//�A�N�Z�T
	string g_name() { return risouseName; }
	string g_pass() { return risousePass; }
	int g_time() { return risouseTime; }
	int g_priority() { return Priority; }

};

