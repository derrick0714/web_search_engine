/*
 * StreamBuffer.h
 *
 *  Created on: Feb 27, 2013
 *      Author: Adam57
 */

#ifndef STREAMBUFFER_H_
#define STREAMBUFFER_H_
#include <iostream>
#include <cstring>
#include <fstream.h>
using namespace std;

class StreamBuffer {
private:
	int buffersize;
	char* mybuffer;
	int offset;
public:
//	int offset;
	StreamBuffer();
	StreamBuffer(int size);
	virtual ~StreamBuffer();
	int getsize();
	bool active();
	bool write(const void* buffer, int size);
	bool read(void* buffer, int size);
	char* getcontent(int index);
	template <class type>
	bool write(const type* buffer);
	template <class type>
	bool read(type* buffer);
	bool savetofile();

};

template <class type>
bool StreamBuffer::write(const type* buffer){
		if(buffer==NULL)
			return false;
		if(offset>=buffersize){
				cout<<"buffer is dumped, no more using"<<endl;
				return false;
			}
		if(offset+sizeof(type)<buffersize){
			cout<<"offset changing:"<<offset<<" "<<buffersize<<endl;
			memcpy(mybuffer+offset, buffer, sizeof(type));
			offset = offset+sizeof(type);
			return true;
		}
		else if(offset+sizeof(type)==buffersize){
			cout<<"offset changing:"<<offset<<" "<<buffersize<<endl;
			memcpy(mybuffer+offset, buffer, sizeof(type));
			offset = offset+sizeof(type);
			savetofile();
			return true;
		}
		else{
			savetofile();
			cout<<"save to file:"<<offset<<endl;
			offset = buffersize;
			return false;
		}
}

template <class type>
bool StreamBuffer::read(type* buffer){
		if(offset>=buffersize)
			return false;
		else
		{
		memcpy(buffer, mybuffer+offset, sizeof(type));
		offset = offset + sizeof(type);
		return true;
		}
}

#endif /* STREAMBUFFER_H_ */
