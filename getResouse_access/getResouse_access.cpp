// getResouse_access.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include "Section.h"
#include <iostream>

const char *logFile = "log.txt"; //ログのファイル
string fileName = "opencv-test - Microsoft Visual Studio ";  //探したいファイルの名前
char sep = ',';	 //区切り

int main()
{

	//std::cout << "start" << endl;

	std::ifstream  File(logFile); //ファイルパスを渡す

	//ファイルが開いたか確認
	if (File.fail()) {
		std::cout << "Don't Open in findFile!\n";
		return 0;
	}

	//使う変数を宣言
	list<Section> sectionList;	//リソースのリスト
	list<Section>::iterator itr;
	std::string nowtext;		//ログファイルのテキストを一時保存
	std::string nexttext;		//ログファイルのテキストを一時保存
	bool nolist = true;  //リストにあるかを確認
	int priority;


	//ログファイルが最後の行になるまで関連ファイルを調べる
	while (!File.eof()) {

		//ログを取得し，名前，時間，パスに分割する
		getline(File, nowtext); 
		Section nowline = StringSplit_class(nowtext, sep);

		//探しているファイルのログを発見したとき
		if (fileName.compare(nowline.g_name())==0 && !File.eof()) {

			//リソースのログを見ていく
			getline(File, nexttext);
			Section nextline = StringSplit_class(nexttext, sep);

			//リストの中を確認する
			for (itr = sectionList.begin(); itr != sectionList.end(); itr++) {
				//リソースがリストにあったので、重要度を更新します
				if (nextline.g_name().compare(itr->g_name()) == 0) {
					priority = itr->g_priority();
					itr->s_priority(priority + 1); //priorityを更新
					nolist = false;
					break;
				}
			}

			//リストの中に見ているリソースがないとき時
			if (nolist) {//リストに追加する
				priority = (&nextline)->g_priority();
				(&nextline)->s_priority(priority + 1);
				sectionList.push_front(nextline);
			}
			nolist = true;
		}
	}

	sectionList.sort(comp);
	std::cout << "リソースを表示" << endl;
	for (Section p : sectionList) {
		std::cout << p.g_priority() << "," << p.g_name() << "," << p.g_pass() << endl; //確認
	}


	std::cout << "finish" << endl;

	return 0;
}

