#ifndef __SEARCHING_ALGORIM_H__
#define __SEARCHING_ALGORIM_H__
#include <iostream>
#include <fstream>
#include <string>
#include "models/Docmap.h"
#include "models/WordMap.h"
#include "result_ctrl.h"
#include "utility/gzip.h"
#include <vector>
#include "4ops.h"
#include "parser/parser.h"

//#include "vbyte.h"

using namespace std;

struct TAGS
{
	string word;
	int count;
	TAGS()
	{
		word ="";
		count = 0;
	}
};

class SearchingAlgorim
{
public:
	SearchingAlgorim();
	~SearchingAlgorim();
public:
	void init_data();
	char* init_buffer_from_file(string file_name,int& size);
	void do_searching(char* words);
	void sort(STRU_RESULT* array, int left , int right,std::string type);
	char* get_result();
	bool get_one_word(char* source ,int& pos,string& str);
	void get_around_text(char* html, int len,int tartget_pos,string& title,string& around_text);
	bool isInThisLocation(string askLocation, string sourceLocation);
	void sort_tags(TAGS* arr,int left, int right);

private:
	DocMap 		_doc_map;
	WordMap		_word_map;
	ResultCrtl	_result;
	float 		k1;
	float 		b;
	int       	d_agv;
	int 		N;
	STRU_RESULT result_array[10];
	int 		result_count;
	char		result[1024];
	TAGS 		tags[200];
public:
	int 		_whole_time;
	int 		_searching_time;
	map<int,string> _word_map2;

};


#endif //__SEARCHING_ALGORIM_H__